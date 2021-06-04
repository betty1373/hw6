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

/// @author btv <example@example.com> 
   
template<typename T, T defaultV = -1>
class Matrix {
        map<index_t, Value<T,defaultV>> m_storage;        
    public:
        Matrix() {}
        ~Matrix() {}
        using iterator =  typename map<index_t, Value<T,defaultV>>::iterator;

        Controller<T,defaultV> operator[](size_t row) {return Controller<T,defaultV>(*this,row); }
        
        iterator begin() { return m_storage.begin(); }
        iterator end() {return m_storage.end(); } 
        iterator find(const index_t& ind) {return m_storage.find(ind);}
        auto &get_storage() { return m_storage;}
        size_t size() const { return m_storage.size(); }     
};    
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
