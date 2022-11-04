//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_PRODUTO_H
#define MEGABYTESTORE_PRODUTO_H


class Produto {
protected:
    int id, quantidade;
    double valor;
public:
    Produto(int id, int quantidade, double valor);

    int getId();
    void setId(int novoId);

    int getQuantidade();
    void setQuantidade(int novaQuantidade);


    double getValor();
    void setValor(double novoValor);
};


#endif //MEGABYTESTORE_PRODUTO_H
