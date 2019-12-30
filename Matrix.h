#ifndef Matrix_H
#define Matrix_H

template<typename dtype>
class Matrix {
public:
  unsigned int ncols;
  unsigned int nrows;
  Vector<dtype>* columns;
  std::string* colnames;

  Matrix(std::string filename, unsigned int nrows, unsigned int ncols, int header = 1);
  Matrix(unsigned int nrows, unsigned int ncols);
  ~Matrix();

  //operators
    //addition
  Matrix<dtype>& operator+ (const dtype constant) const;
  Matrix<dtype>& operator+ (const Matrix<dtype>& mtx) const;
  void operator+= (const dtype constant);
  void operator+= (const Matrix<dtype>& mtx);
    //subtraction
  Matrix<dtype>& operator- (const dtype constant) const;
  Matrix<dtype>& operator- (const Matrix<dtype>& mtx) const;
  void operator-= (const dtype constant);
  void operator-= (const Matrix<dtype>& mtx);
    //multiplication
  Matrix<dtype>& operator* (const dtype constant) const;
  Matrix<dtype>& operator* (const Matrix<dtype>& mtx) const;
  void operator*= (const dtype constant);
  void operator*= (const Matrix<dtype>& mtx);
    //division
  Matrix<dtype>& operator/ (const dtype constant) const;
  Matrix<dtype>& operator/ (const Matrix<dtype>& mtx) const;
  void operator/= (const dtype constant);
  void operator/= (const Matrix<dtype>& mtx);
    //exponentiation
  Matrix<dtype>& operator^ (const dtype constant) const;
  Matrix<dtype>& operator^ (const Matrix<dtype>& mtx) const;
  void operator^= (const dtype constant);
  void operator^= (const Matrix<dtype>& mtx);

  //methods
  Matrix<dtype>& row_row_dot(const Matrix<dtype>& mtx);
  Matrix<dtype>& row_col_dot(const Matrix<dtype>& mtx);
  Matrix<dtype>& col_col_dot(const Matrix<dtype>& mtx);

  std::string toString();
private:
  static const char* fmt;
};
#include "Matrix.cc"
#endif
