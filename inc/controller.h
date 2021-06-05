#pragma once
#include "value.h" 

using namespace std;
/// @file
/// @brief  Class mediator between matrix object and their cells
/// @author btv <example@example.com>      
    template<typename T, T defaultV = -1>
    class Controller {
        Matrix<T, defaultV> &m_matrix;
        Value<T, defaultV> m_new;
        size_t m_r {};
    public: 
        explicit Controller(Matrix<T,defaultV> &matrix, size_t row):
                m_matrix(matrix),
                m_new(Value<T, defaultV>(m_matrix,defaultV)),
                m_r(row)
        {}
/// @brief  Operator [] for access to matrix cell
        Value<T,defaultV> &operator[](size_t col) {
            index_t ind = make_pair(m_r,col);
            if (auto it = m_matrix.find(ind);
                     it!= m_matrix.end()) {
                it->second.set_index(m_r,col);
                return it->second;
            } 
            else {
                m_new.set_index(m_r,col);
                return m_new;
            }
        }              
    }; 

