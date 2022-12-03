//
// Created by luanr on 29/11/2022.
//

#include "ProductBuyCommand.h"

namespace MenuCommand {
    ProductBuyCommand::ProductBuyCommand(MemoryStorage::ProductsStorage productsStorage) {
        this->cart = Models::Cart();
        this->productsStorage = productsStorage;
    }

    void ProductBuyCommand::Execute() {
        auto* buyMenu = new MenuSystem::Menu("==Comprar==");

        stringstream contetCreator;
        contetCreator << "Carrinho: " + to_string(cart.getAmmount()) + "\n";
        contetCreator << "Total R$: " + to_string(cart.getTotal()) + "\n";
        buyMenu->SetContent(contetCreator.str());

        buyMenu->AddMenu(MenuInfoItem(1, "Mostrar todos.", [this]() {ShowAllProducts();}));
        buyMenu->AddMenu(MenuInfoItem(2, "Mostrar carrinho.", [this]() {ShowCartItems();}));
        buyMenu->AddMenu(MenuInfoItem(3, "Adicionar ao carrinho.", [this]() {
            LineReader lineReader(ReaderOptions("Entre com um valor valido", false));
            int productId = lineReader.ReadInt("Digite o ID do produto que deseja adicionar:");

            Models::Product* productResult = productsStorage.getById(productId);
            if(productResult == nullptr) {
                std::cout << "Este produto não existe." << std::endl;
                return;
            }

            int quantidade = lineReader.ReadInt("Digite a quantidade:");
            if(quantidade > productResult->getQuantity()) {
                std::cout << "Nao ha produtos suficientes em estoque." << std::endl;
                return;
            }

            cart.AddOrder(Models::Order(productId, quantidade, productResult->getValue()));
        }));
        buyMenu->AddMenu(MenuInfoItem(4, "Fazer checkout", [this]() { Checkout(); }));
        buyMenu->AddMenu(MenuInfoItem(0, "Cancelar", [this]() {
            finish = true;
        }));

        buyMenu->Start([this]() {
            return !finish;
        });
    }

    void ProductBuyCommand::ShowAllProducts() {
        std::cout << "================" << std::endl;
        for (Models::Product* product : productsStorage.getProducts()) {
            std::cout << product->ToString()  + " x" + to_string(product->getQuantity()) + " R$ " + to_string(product->getValue());
        }
    }
    void ProductBuyCommand::ShowCartItems() {
        for (Models::Order order : cart.getOrders()) {
            Models::Product* product = productsStorage.getById(order.getProductId());
            std::cout << product->ToString() + " x" + to_string(order.getQuantity()) + " R$ " + to_string(product->getValue()) << std::endl;
        }
    }

    void ProductBuyCommand::Checkout() {
        Menu* checkoutMenu = new Menu("Pagamento");
        checkoutMenu->SetContent("Total a pagar: R$ " + to_string(cart.getTotal()));
        checkoutMenu->AddMenu(MenuInfoItem(1, "Pix", [this, checkoutMenu]() {
            cout << QR_CODE_PIX << endl;

            finish = true;
            checkoutMenu->Stop();
        }));
        checkoutMenu->AddMenu(MenuInfoItem(0, "Voltar", [checkoutMenu]() {
            checkoutMenu->Stop();
        }));

        checkoutMenu->Start();
    }
} // MenuCommand