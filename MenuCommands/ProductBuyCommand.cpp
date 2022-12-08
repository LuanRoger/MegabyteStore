//
// Created by luanr on 29/11/2022.
//

#include "ProductBuyCommand.h"

namespace MenuCommand {
    ProductBuyCommand::ProductBuyCommand(MemoryStorage::ProductsStorage* productsStorage, SalesController* salesController) {
        this->cart = Models::Cart();
        this->productsStorage = productsStorage;
        this->salesController = salesController;
    }

    void ProductBuyCommand::Execute() {
        auto* buyMenu = new MenuSystem::Menu("==Comprar==");

        buyMenu->AddMenu(MenuInfoItem(1, "Mostrar todos os produtos.", [this]() {ShowAllProducts();}));
        buyMenu->AddMenu(MenuInfoItem(2, "Mostrar carrinho.", [this]() {ShowCartItems();}));
        buyMenu->AddMenu(MenuInfoItem(3, "Adicionar ao carrinho.", [this]() { AddProductToCart(); }));
        buyMenu->AddMenu(MenuInfoItem(4, "Remover do carrinho", [this]() {
            LineReader lineReader(ReaderOptions("Entre com um valor válido.", false));
            int productId = lineReader.ReadInt("Digite o ID do produto que deseja remover do carrinho:");

            bool result = cart.RemoveProduct(productId);

            if(!result) {
                std::cout << "Não foi possivel remover este item do carrinho."<< std::endl;
                return;
            }

            std::cout << "Produto removido com sucesso." << std::endl;
        }));
        buyMenu->AddMenu(MenuInfoItem(5, "Limpar carrinho", [this]() {
            LineReader lineReader(ReaderOptions("Entre com um valor válido.", false));
            bool clarCartResult = lineReader.ReadBool("Deseja limpar o carrinho (s/n)?");

            if(!clarCartResult) return;
            cart.Clear();
            std::cout << "Carrinho limpo." << std::endl;
        }));
        buyMenu->AddMenu(MenuInfoItem(6, "Fazer checkout", [this]() { Checkout(); }));
        buyMenu->AddMenu(MenuInfoItem(0, "Cancelar", [this]() {
            finish = true;
        }));

        buyMenu->Start([this]() {
            return !finish;
        });
    }

    void ProductBuyCommand::AddProductToCart() {
        LineReader lineReader(ReaderOptions("Entre com um valor valido", false));
        int productId = lineReader.ReadInt("Digite o ID do produto que deseja adicionar:");

        Models::Product* productResult = productsStorage->getById(productId);
        if(productResult == nullptr) {
            std::cout << "Este produto não existe." << std::endl;
            return;
        }

        int quantity = lineReader.ReadInt("Digite a quantity:");
        int productQuantityInCard = cart.getProductQuantityInCard(productId);
        if(quantity + productQuantityInCard > productResult->getQuantity()) {
            std::cout << "Não há produtos suficientes em estoque." << std::endl;
            return;
        }

        cart.AddOrder(Models::Order(productId, quantity, productResult->getValue()));
    }

    void ProductBuyCommand::ShowAllProducts() {
        std::cout << "================" << std::endl;
        for (Models::Product* product : productsStorage->getProducts()) {
            std::cout << product->ToString()  + " x" + std::to_string(product->getQuantity()) +
            " R$ " + std::to_string(product->getValue()) + "/u" << std::endl;
        }
        std::cout << "================" << std::endl;
    }
    void ProductBuyCommand::ShowCartItems() {
        std::cout << "Carrinho:" + std::to_string(cart.getAmmount()) << std::endl;
        std::cout << "Total R$:" + std::to_string(cart.getTotal()) << std::endl;

        std::cout << "================" << std::endl;
        for (Models::Order order : cart.getOrders()) {
            Models::Product* product = productsStorage->getById(order.getProductId());
            std::cout << product->ToString() + " x" + std::to_string(order.getQuantity()) +
            " R$ " + std::to_string(order.getTotal()) << std::endl;
        }
        std::cout << "================" << std::endl;
    }

    void ProductBuyCommand::Checkout() {
        if(cart.getTotal() <= 0 || cart.getAmmount() <= 0) {
            std::cout << "Não há produtos no carrinho." << std::endl;
            return;
        }

        Menu* checkoutMenu = new Menu("Pagamento");
        checkoutMenu->SetContent("Total a pagar: R$ " + std::to_string(cart.getTotal()));
        checkoutMenu->AddMenu(MenuInfoItem(1, "Pix", [this, checkoutMenu]() {
            std::cout << QR_CODE_PIX << std::endl;

            std::system("pause");

            finish = true;
            checkoutMenu->Stop();
        }));
        checkoutMenu->AddMenu(MenuInfoItem(0, "Voltar", [checkoutMenu]() {
            checkoutMenu->Stop();
        }));
        checkoutMenu->SetOnMenuStop([this]() { UpdateStorage(); });

        checkoutMenu->Start();
    }
    void ProductBuyCommand::UpdateStorage() {
        for (Models::Order order : cart.getOrders()) {
            productsStorage->RemoveByOrder(order);
            salesController->IncrementItems(cart.getAmmount());
            salesController->IncrementProfit(cart.getTotal());
        }
    }
} // MenuCommand