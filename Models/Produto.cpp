//
// Created by Vinicius on 27/10/2022.
//

#include "Produto.h"

Produto::Produto(int id, int quantidade, double valor) {
    setId(id);
    setQuantidade(quantidade);
    setValor(valor);
}

int Produto::getId() {
    return id;
}

void Produto::setId(int novoId) {
    id = novoId;
}

int Produto::getQuantidade() {
    return quantidade;
}

void Produto::setQuantidade(int novaQuantidade) {
    quantidade = novaQuantidade;
}

double Produto::getValor() {
    return valor;
}

void Produto::setValor(double novoValor) {
    valor = novoValor;
}

