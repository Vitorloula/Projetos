
#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H
#include "no.h"

template<typename A>
class Arvore_binaria {
private:
    // Ponteiro para o nó raiz da árvore binária
    No<A>* raiz; 
    
public:
    //Construtor de uma árvore binária vazia
    Arvore_binaria(); 
    
    //Construtor de uma arvore com o valor do nó raiz
    Arvore_binaria(A value);    
    
    //Construtor de uma árvore binária com o valor do nó raiz  
    //e as duas sub-árvores esquerda e direita, respectivamente.
    Arvore_binaria(A value, Arvore_binaria<A>& l, Arvore_binaria<A>& r);
    
    //Retorna o nó raiz
    No<A>* getRaiz();
    
    //Atualiza o nó raiz
    void setRaiz(No<A>* newRaiz);
    
    //Retorna true se e somente se a árvore estiver vazia
    bool is_empty();
    
    //Retorna true se e somente se a árvore é uma folha
    bool is_leaf();
    
    //Verifica se um determinado valor está contido na árvore
    bool contains(A value);
    
    //Imprime todos os valores armazenado na árvore
    void print_values();
    
    //Remove todos os elementos da árvore, ou seja, deixa a árvore vazia
    void clear();
    
    // destrutor: libera memoria alocada
    ~Arvore_binaria();
};

#include "arvore_binaria.cpp"
#endif