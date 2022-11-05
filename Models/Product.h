//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_PRODUCT_H
#define MEGABYTESTORE_PRODUCT_H


class Product {
protected:
    int id, quantidade;
    double valor;
public:
    Product(int id, int quantidade, double valor);

    int getId();
    void setId(int novoId);

    int getQuantidade();
    void setQuantidade(int novaQuantidade);


    double getValor();
    void setValor(double novoValor);
};


#endif //MEGABYTESTORE_PRODUCT_H
