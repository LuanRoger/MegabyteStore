//
// Created by Vinicius on 27/10/2022.
//

#include "Product.h"

namespace Models {
    Product::Product(int id, int quantidade, double valor) {
        setId(id);
        setQuantidade(quantidade);
        setValor(valor);
    }

    int Product::getId() {
        return id;
    }

    void Product::setId(int novoId) {
        id = novoId;
    }

    int Product::getQuantidade() {
        return quantidade;
    }

    void Product::setQuantidade(int novaQuantidade) {
        quantidade = novaQuantidade;
    }

    double Product::getValor() {
        return valor;
    }

    void Product::setValor(double novoValor) {
        valor = novoValor;
    }
}