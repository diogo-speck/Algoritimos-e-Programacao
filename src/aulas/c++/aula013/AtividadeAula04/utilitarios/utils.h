#pragma once

template<typename T>
bool estaentre(T valor, T minimo, T maximo);

template<typename T>
T limitar(T valor, T minimo, T maximo);

template<typename T>
T maior(T a, T b);

template<typename T>
T menor(T a, T b);

template<typename T>
void trocar(T &a, T &b);



template<typename T>
bool estaentre(T valor, T minimo, T maximo){
    if(minimo<valor && valor<maximo){
        return true;
    }else{
        return false;
    }
}

template<typename T>
T limitar(T valor, T minimo, T maximo){
    if (valor>maximo){
        return maximo;
    }else if(valor<minimo){
        return minimo;
    }else{
        return valor;
    }
}

template<typename T>
T maior(T a, T b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

template<typename T>
T menor(T a, T b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

template<typename T>
void trocar(T (&a), T (&b)){
    T c = a;
    a = b;
    b = c;
}