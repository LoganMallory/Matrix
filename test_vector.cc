#include "Vector.h"
#include "Matrix.h"
#include <iostream>
int main(){
  /*
  Vector<double>* vec1 = new Vector<double>(10);
  Vector<double>* vec2 = new Vector<double>(10);

  std::cout << vec1->toString() << std::endl;
  vec1->values[0] = -2.85;
  std::cout << vec1->toString() << std::endl;

  for(int i=0; i<10; i++) vec1->values[i] = i*1.5;
  std::cout << vec1->toString() << std::endl;

  *vec1 ^= 2;
  std::cout << vec1->toString() << std::endl;

  vec1->values[0] = -1.25;
  std::cout << vec1->toString() << std::endl;


  Matrix<double> mymatrix(10, 2);
  mymatrix.columns[0] = *vec1;
  mymatrix.columns[1] = *vec2;

  std::cout << mymatrix.toString() << std::endl;
  */
  Matrix<double> mymatrix("testmatrix_double.csv", 10, 4);
  std::cout << mymatrix.toString() << std::endl;
  mymatrix ^= 2;
  std::cout << mymatrix.toString() << std::endl;

  Matrix<double> mymatrix2 = mymatrix * mymatrix;
  std::cout << mymatrix2.toString() << std::endl;
  return 0;
}
