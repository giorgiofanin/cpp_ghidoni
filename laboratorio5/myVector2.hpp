#ifndef MYVECTOR2_HPP
#define MYVECTOR2_HPP

#include <iostream>
#include "myVector2.h"

template <typename T>

myVector2<T>::myVector2()
{
    sz = 0;
    bufferSz = 0;
    elem = nullptr;
}

template <typename T>  
myVector2<T>::myVector2(std::initializer_list<double> lst){
    sz = lst.size();
    bufferSz = sz *2;
    elem = new T[bufferSz];

    std::copy(lst.begin(), lst.end(), elem);
}

template <typename T> 
myVector2<T>::myVector2(int size,T *p)
{
    sz = size;
    bufferSz = sz *2;
    elem = p;

    if (size != 0)
    {
        elem = new T[bufferSz];
        for (int i = 0; i < size; i++)
        {
            elem[i] = p[i];
        }
    }
    else{
        throw myVector2<T>::Invalid{};
    }
}

template <typename T> 
myVector2<T>::myVector2(myVector2<T>&& a){
    sz = a.sz;
    elem = a.elem;

    a.sz = 0;
    a.elem = nullptr;
}

template <typename T>
T& myVector2<T>::operator[](int pos)
{
    return elem[pos];
}

template <typename T> 
T myVector2<T>::operator[](int pos) const
{
    return elem[pos];
}


template <typename T>
T& myVector2<T>::at(int pos){
    if(pos<0 || pos>=size()){
        throw myVector2<T>::out_of_range{};
    }
    else{
        return elem[pos];
    }
}


template <typename T> 
T myVector2<T>::at(int pos) const{
    if(pos<0 || pos>=size()){
        throw myVector2<T>::out_of_range{};
    }
    else{
        return elem[pos];
    }
}
template <typename T> 
void myVector2<T>::push_back(T value){
    
    if(sz == bufferSz){
        bufferSz*=2;
        double* newElem =  new double[bufferSz];
        std::copy(elem,elem+sz,newElem);
        delete[] elem;
        elem = newElem;
    }
    elem[sz++]= value;
    
}

template <typename T> 
myVector2<T>& myVector2<T>::operator=(myVector2<T>&& a){
    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    bufferSz = a.bufferSz;
    a.elem = nullptr;
    a.sz = 0;
    a.bufferSz = 0;
    return * this;
}


// myVector2& operator=(const myVector2& a){
//     double* newP =  new double[a.bufferSz*2];
//     std::copy(a.elem,a.elem+a.sz,p);
//     delete[] elem;
//     elem = p;
//     bufferSz = a.bufferSz*2;
//     sz = a.sz;
//     return *this;
// }

template <typename T> 
void myVector2<T>::reserve(int n){
    if(bufferSz-sz>= n){
        return;
    }
    bufferSz+=n;

    double* newP =  new double[bufferSz];
    //copy

    delete[] elem;
    elem = newP;
}

template <typename T> 
void myVector2<T>::pop_back(){
    
    if(sz > 0){
        --sz;
    }
    else{
        throw myVector2<T>::Invalid{};
    }
}


#endif