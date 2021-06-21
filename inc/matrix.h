#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
using index_t = std::pair<size_t,size_t>;
  
template<typename T, T>
class Matrix;
#include "controller.h"
/// @file
/// @brief  Class base matrix object 
/// @author btv <example@example.com>         
template<typename T, T defaultV = -1>
class Matrix {
/// @brief  Class matrix cell's storage 
        std::map<index_t, Value<T,defaultV>> m_storage;        
    public:
        Matrix() {}
        ~Matrix() {}
/// @brief  Iteraror for access to values 
        using iterator =  typename std::map<index_t, Value<T,defaultV>>::iterator;
        iterator begin() { return m_storage.begin(); }
        iterator end() {return m_storage.end(); } 
        iterator find(const index_t& ind) {return m_storage.find(ind);}
/// @brief  Operator [] for access to matrix rows
        Controller<T,defaultV> operator[](size_t row) {return Controller<T,defaultV>(*this,row); } 
/// @brief  Functions for access to matrix cell's storage     
        auto &get_storage() { return m_storage;}
        size_t size() const { return m_storage.size(); }     
}; 
/// @brief Function for testing matrix class   

int version();
