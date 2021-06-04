#pragma once
    using namespace std;
/// @file

/// @brief  Prints IP, represented as a integral type
/// @tparam T - integral type (bool, char, short, uint, int, long, etc...)
/// @param  value - IP address
/// @author btv <example@example.com>
   
template<typename T, T defaultV = -1>
class Value {       
        Matrix<T, defaultV> &m_matrix;
        T m_value {defaultV};
        index_t m_index;
        //size_t m_r {};
        //size_t m_c {};
    public:
        explicit Value(Matrix<T, defaultV> &matrix, T value)
                :m_matrix (matrix), m_value (value) 
        {}  
        void set_index(size_t row,size_t col) {
            m_index = make_pair(row,col);
            //m_r = row;
           // m_c = col;
        }
        auto &operator=(T const &value) {  
           // index_t ind = make_pair(m_r,m_c);
            auto it = m_matrix.find(m_index);     
            if (value==defaultV) {               
                if (it!= m_matrix.end())
                    m_matrix.get_storage().erase(it);
            }
            else { 
                 if (it!= m_matrix.end()) {
                     it->second.m_value = value;
                 }
                 else {             
                    m_matrix.get_storage().insert(make_pair(m_index,Value(m_matrix,value)));
                 }
            }
            return *this;
        } 
        operator const T &() const noexcept {
           // index_t ind = make_pair(m_r,m_c);
             auto it = m_matrix.find(m_index);   
             return (it!= m_matrix.end()) ? it->second.m_value : defaultV;
        }
      
        friend bool operator==(Value<T,defaultV> &left, T const &right) {
            return left.m_value==right;
        }        
       
       friend std::ostream &operator<<(std::ostream &os, Value<T, defaultV> const &p) {
            return os << ((p.m_value == defaultV) ? defaultV : p.m_value);
        }
};