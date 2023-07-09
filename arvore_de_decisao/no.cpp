#ifndef NO_CPP
#define NO_CPP

#include "no.h"

template<typename A>
No<A>::No(A val, No<A> *e, No<A> *d){
    valor = val;
    esquerda = e;
    direita = d;
}

template<typename A>
A No<A>::getValor(){
    return this->valor;
}

template<typename A>
void No<A>::setValor(A newValor){
    this->valor = newValor;
}

template<typename A>
No<A>* No<A>::getEsquerda(){
    return this->esquerda;
}

template<typename A>
void No<A>::setLeft(No<A>* newEsquerda){
    this->esquerda = newEsquerda;
}

template<typename A>
No<A>* No<A>::getDireita(){
    return this->direita;
}

template<typename A>
void No<A>::setRight(No<A>* newDireita){
    this->direita = newDireita;
}

#endif