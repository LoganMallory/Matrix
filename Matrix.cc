#include <cstdio>
#include <iostream>
template<> const char* Matrix<int>::fmt = "%d,";
template<> const char* Matrix<long>::fmt = "%ld,";
template<> const char* Matrix<float>::fmt = "%d,";
template<> const char* Matrix<double>::fmt = "%lf,";

//TODO: copy colnames during matrix operations

template<typename dtype>
Matrix<dtype>::Matrix(std::string filename, unsigned int nrows, unsigned int ncols, int header){
  if(verbose) printf("Matrix(string filename)\n");
  this->nrows = nrows;
  this->ncols = ncols;
  this->columns = new Vector<dtype>[ncols];
  FILE* stream = fopen(filename.c_str(), "r");

  for(unsigned int i = 0; i < ncols; i++) this->columns[i] = *(new Vector<dtype>(nrows));

  if(header){
    this->colnames = new std::string[ncols];
    unsigned int i    = 0;
    unsigned char j   = 0;
    char singlechar   = '\0';
    this->colnames[0] = "";
    while(fscanf(stream, "%c", &singlechar) && i < ncols){
      if(singlechar != ',' && singlechar != '\n') this->colnames[i] += singlechar;
      else this->colnames[++i] = "";
    }
  }
  for(unsigned int rownum = 0; rownum < nrows; rownum++){
    for(unsigned long colnum = 0; colnum < ncols; colnum++){
      fscanf(stream, fmt, &this->columns[colnum][rownum]);
    }
  }
  fclose(stream);
}
template<typename dtype>
Matrix<dtype>::Matrix(unsigned int nrows, unsigned int ncols){
  if(verbose) printf("Matrix(unsigned int nrows, unsigned int ncols)\n");
  this->nrows    = nrows;
  this->ncols    = ncols;
  this->columns  = new Vector<dtype>[ncols];
  this->colnames = NULL;
}
template<typename dtype>
Matrix<dtype>::~Matrix(){
  if(verbose) printf("~Matrix()\n");
  delete[] this->columns;
}
template<typename dtype>
Matrix<dtype>& Matrix<dtype>::operator+ (const dtype constant) const{
  if(verbose) printf("Matrix::operator+ (const dtype constant)\n");
  Matrix<dtype>* newmatrix = new Matrix<dtype>(this->nrows, this->ncols);
  for(unsigned int i = 0; i < this->ncols; i++) newmatrix->columns[i] = this->columns[i] + constant;
  return *newmatrix;
}
template<typename dtype>
Matrix<dtype>& Matrix<dtype>::operator+ (const Matrix<dtype>& mtx) const{
  if(verbose) printf("Matrix::operator+ (const Matrix<dtype>& mtx)\n");
  Matrix<dtype>* newmatrix = new Matrix<dtype>(this->nrows, this->ncols);
  for(unsigned int i = 0; i < this->ncols; i++) newmatrix->columns[i] = this->columns[i] + mtx.columns[i];
  return *newmatrix;
}
template<typename dtype>
void Matrix<dtype>::operator+= (const dtype constant){
  if(verbose) printf("Matrix::operator+= (const dtype constant)\n");
  for(unsigned int i = 0; i < this->ncols; i++) this->columns[i] += constant;
}
template<typename dtype>
void Matrix<dtype>::operator+= (const Matrix<dtype>& mtx){
  if(verbose) printf("Matrix::operator+= (const Matrix<dtype>& mtx)\n");
  for(unsigned int i = 0; i < this->ncols; i++) this->columns[i] += mtx.columns[i];
}
  //subtraction
template<typename dtype>
Matrix<dtype>& Matrix<dtype>::operator- (const dtype constant) const{
  if(verbose) printf("Matrix::operator- (const dtype constant)\n");
  Matrix<dtype>* newmatrix = new Matrix<dtype>(this->nrows, this->ncols);
  for(unsigned int i = 0; i < this->ncols; i++) newmatrix->columns[i] = this->columns[i] - constant;
  return *newmatrix;
}
template<typename dtype>
Matrix<dtype>& Matrix<dtype>::operator- (const Matrix<dtype>& mtx) const{
  if(verbose) printf("Matrix::operator- (const Matrix<dtype>& mtx)\n");
  Matrix<dtype>* newmatrix = new Matrix<dtype>(this->nrows, this->ncols);
  for(unsigned int i = 0; i < this->ncols; i++) newmatrix->columns[i] = this->columns[i] - mtx.columns[i];
  return *newmatrix;
}
template<typename dtype>
void Matrix<dtype>::operator-= (const dtype constant){
  if(verbose) printf("Matrix::operator-= (const dtype constant)\n");
  for(unsigned int i = 0; i < this->ncols; i++) this->columns[i] -= constant;
}
template<typename dtype>
void Matrix<dtype>::operator-= (const Matrix<dtype>& mtx){
  if(verbose) printf("Matrix::operator-= (const Matrix<dtype>& mtx)\n");
  for(unsigned int i = 0; i < this->ncols; i++) this->columns[i] -= mtx.columns[i];
}
  //multiplication
template<typename dtype>
Matrix<dtype>& Matrix<dtype>::operator* (const dtype constant) const{
  if(verbose) printf("Matrix::operator* (const dtype constant)\n");
  Matrix<dtype>* newmatrix = new Matrix<dtype>(this->nrows, this->ncols);
  for(unsigned int i = 0; i < this->ncols; i++) newmatrix->columns[i] = this->columns[i] * constant;
  return *newmatrix;
}
template<typename dtype>
Matrix<dtype>& Matrix<dtype>::operator* (const Matrix<dtype>& mtx) const{
  if(verbose) printf("Matrix::operator* (const Matrix<dtype>& mtx)\n");
  Matrix<dtype>* newmatrix = new Matrix<dtype>(this->nrows, this->ncols);
  for(unsigned int i = 0; i < this->ncols; i++) newmatrix->columns[i] = this->columns[i] * mtx.columns[i];
  return *newmatrix;
}
template<typename dtype>
void Matrix<dtype>::operator*= (const dtype constant){
  if(verbose) printf("Matrix::operator*= (const dtype constant)\n");
  for(unsigned int i = 0; i < this->ncols; i++) this->columns[i] *= constant;
}
template<typename dtype>
void Matrix<dtype>::operator*= (const Matrix<dtype>& mtx){
  if(verbose) printf("Matrix::operator*= (const Matrix<dtype>& mtx)\n");
  for(unsigned int i = 0; i < this->ncols; i++) this->columns[i] *= mtx.columns[i];
}
  //division
template<typename dtype>
Matrix<dtype>& Matrix<dtype>::operator/ (const dtype constant) const{
  if(verbose) printf("Matrix::operator/ (const dtype constant)\n");
  Matrix<dtype>* newmatrix = new Matrix<dtype>(this->nrows, this->ncols);
  for(unsigned int i = 0; i < this->ncols; i++) newmatrix->columns[i] = this->columns[i] / constant;
  return *newmatrix;
}
template<typename dtype>
Matrix<dtype>& Matrix<dtype>::operator/ (const Matrix<dtype>& mtx) const{
  if(verbose) printf("Matrix::operator/ (const Matrix<dtype>& mtx)\n");
  Matrix<dtype>* newmatrix = new Matrix<dtype>(this->nrows, this->ncols);
  for(unsigned int i = 0; i < this->ncols; i++) newmatrix->columns[i] = this->columns[i] / mtx.columns[i];
  return *newmatrix;
}
template<typename dtype>
void Matrix<dtype>::operator/= (const dtype constant){
  if(verbose) printf("Matrix::operator/= (const dtype constant)\n");
  for(unsigned int i = 0; i < this->ncols; i++) this->columns[i] /= constant;
}
template<typename dtype>
void Matrix<dtype>::operator/= (const Matrix<dtype>& mtx){
  if(verbose) printf("Matrix::operator/= (const Matrix<dtype>& mtx)\n");
  for(unsigned int i = 0; i < this->ncols; i++) this->columns[i] /= mtx.columns[i];
}
  //exponentiation
template<typename dtype>
Matrix<dtype>& Matrix<dtype>::operator^ (const dtype constant) const{
  if(verbose) printf("Matrix::operator^ (const dtype constant)\n");
  Matrix<dtype>* newmatrix = new Matrix<dtype>(this->nrows, this->ncols);
  for(unsigned int i = 0; i < this->ncols; i++) newmatrix->columns[i] = this->columns[i]^constant;
  return *newmatrix;
}
template<typename dtype>
Matrix<dtype>& Matrix<dtype>::operator^ (const Matrix<dtype>& mtx) const{
  if(verbose) printf("Matrix::operator^ (const Matrix<dtype>& mtx)\n");
  Matrix<dtype>* newmatrix = new Matrix<dtype>(this->nrows, this->ncols);
  for(unsigned int i = 0; i < this->ncols; i++) newmatrix->columns[i] = this->columns[i]^mtx.columns[i];
  return *newmatrix;
}
template<typename dtype>
void Matrix<dtype>::operator^= (const dtype constant){
  if(verbose) printf("Matrix::operator^= (const dtype constant)\n");
  for(unsigned int i = 0; i < this->ncols; i++) this->columns[i]^=constant;
}
template<typename dtype>
void Matrix<dtype>::operator^= (const Matrix<dtype>& mtx){
  if(verbose) printf("Matrix::operator^ (const Matrix<dtype>& mtx)\n");
  for(unsigned int i = 0; i < this->ncols; i++) this->columns[i]^=mtx.columns[i];
}
template<typename dtype>
std::string Matrix<dtype>::toString(){
  std::string printstr = "";
  std::string padstr;
  std::string numstr;
  if(this->colnames != NULL){
    for(unsigned int i = 0; i < this->ncols; i++){
      printstr += this->colnames[i];
      for(int j = 0; j < 10 - this->colnames[i].length(); j++) printstr += " ";
    }
    printstr += "\n";
  }
  for(unsigned int i = 0; i < this->nrows; i++){
    for(unsigned int j = 0; j < this->ncols; j++){
      printstr += "[";
      numstr    = std::to_string(this->columns[j][i]);
      numstr    = numstr.substr(0,8);
      printstr   += numstr;
      printstr += "]";
    }
    printstr += "\n";
  }
  return printstr;
}
