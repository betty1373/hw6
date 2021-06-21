#include "matrix.h"
#include <cassert>
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
           auto [x,y] = key;
            
            cout <<"["<< x <<","<< y<<"]=" << value << endl;
        }
}
/// @file
/// @brief Main function. Testing as working sparse matrix with default value
/// @author btv<example@example.com>
int main(int, char *[]) {

   Matrix<int,-1> matrix;
   assert(matrix.size()==0);

   auto a = matrix[0][0];
   assert(a== -1);
   assert(matrix.size()==0);

   matrix[100][100] = 314;
  
   assert(matrix[100][100] ==314);
   assert(matrix.size()==1);

   for (const auto &[key,value] : matrix) {
      size_t x,y;
      tie(x,y) = make_tuple(key.first,key.second);
      cout <<"["<< x <<","<< y<<"]=" << value << endl;
   }
   ((matrix[100][100]=314)=0)=217;
   cout << matrix[100][100]<< endl;
   test();
   return 0;
}  
