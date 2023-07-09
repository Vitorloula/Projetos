#ifndef ARVORE_BINARIA_CPP
#define ARVORE_BINARIA_CPP

#include <iostream>
#include "arvore_binaria.h"
using namespace std;

template<typename A>
Arvore_binaria<A>::Arvore_binaria() {
    raiz = nullptr;
}

template<typename A>
Arvore_binaria<A>::Arvore_binaria(A value) {
    raiz = new No<A>(value, nullptr, nullptr);
}

template<typename A>
Arvore_binaria<A>::Arvore_binaria(A value, Arvore_binaria<A>& v, Arvore_binaria<A>& r) {
    raiz = new No<A>(value, v.getRaiz(), r.getRaiz());
    
    v.setRaiz(nullptr);
    r.setRaiz(nullptr);
}

template<typename A>
No<A>* Arvore_binaria<A>::getRaiz(){
    return raiz;
}
    
template<typename A>
void Arvore_binaria<A>::setRaiz(No<A>* newRaiz){
    raiz = newRaiz;
}

template<typename A>
void clear_no(No<A> *node) {
    if(node != nullptr) {
        clear_no(node->getEsquerda());
        clear_no(node->getDireita());
        delete node;
    }
}


template<typename A>
void Arvore_binaria<A>::clear() {
    clear_no(raiz);
    raiz = nullptr;
}

template<typename A>
Arvore_binaria<A>::~Arvore_binaria() {
    clear();
}

template<typename A>
bool Arvore_binaria<A>::is_empty() {
    return raiz == nullptr;
}

template<typename A>
void Arvore_binaria<A>::print_values() {
    print_value(raiz);
    cout << endl;
}

template<typename A>
void print_value(No<A> *node) {
    if(node != nullptr) {
        cout << node->getValor() << " ";
        print_value(node->getEsquerda());
        print_value(node->getDireita());
    }
}

template<typename A>
bool contain(No<A> *node, A value) {
    if(node == nullptr) 
        return false;
    else 
        return node->getValor() == value ||
            contain(node->getEsquerda(), value) ||
            contain(node->getDireita(), value);
}

template<typename A>
bool Arvore_binaria<A>::is_leaf() {
    return !is_empty() && raiz->getEsquerda() == nullptr && raiz->getDireita() == nullptr;
}

template<typename A>
bool Arvore_binaria<A>::contains(A value) {
    return contain(raiz, value);
}

#endif