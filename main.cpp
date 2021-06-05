#include "matrix.h"
#include <cassert>
/// @file

/// @brief Main function. Print Ip's from various types.
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
