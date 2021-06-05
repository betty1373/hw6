#pragma once
using namespace std;
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
using index_t = pair<size_t,size_t>;
  
template<typename T, T>
class Matrix;
#include "controller.h"
/// @file
/// @brief  Class base matrix object 
/// @author btv <example@example.com>         
template<typename T, T defaultV = -1>
class Matrix {
/// @brief  Class matrix cell's storage 
        map<index_t, Value<T,defaultV>> m_storage;        
    public:
        Matrix() {}
        ~Matrix() {}
/// @brief  Iteraror for access to values 
        using iterator =  typename map<index_t, Value<T,defaultV>>::iterator;
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
void test() {
        const size_t msize = 9;
        Matrix<int,0> matrix;
        
        for (auto i=0;i<=msize;i++) {
            matrix[i][i] = i;
            matrix[i][msize-i] = msize-i;
        }

        for (auto i=1;i<msize;i++) {
             for (auto j=1;j<msize;j++) {
                cout<< matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << matrix.size() << endl;

        for (const auto &[key,value] : matrix) {
            size_t x,y;
            tie(x,y) = make_tuple(key.first,key.second);
            
            cout <<"["<< x <<","<< y<<"]=" << value << endl;
        }
}
int version();
