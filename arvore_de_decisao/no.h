#ifndef NO_H
#define NO_H

#include <string>

using namespace std;

template<typename A>
class No {
private:
    A valor;
    No<A> *esquerda; 
    No<A> *direita; 
public:

    No(A val, No<A> *l, No<A> *r);
    
    A getValor();
    No<A>* getEsquerda();
    No<A>* getDireita();
    
    
    void setValor(A newValue);
    void setLeft(No<A>* newLeft);
    void setRight(No<A>* newRight);
};
#include "no.cpp"
#endif