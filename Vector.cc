/*
NOTES:
  In some cases, using SSE optimization can provide just as much speedup as going from a single core to a quad core processor.
    - https://stackoverflow.com/questions/47025373/fastest-implementation-of-exponential-function-using-sse
    - https://github.com/RJVB/sse_mathfun
    - https://stackoverflow.com/questions/8902971/logarithm-with-sse-or-switch-to-fpu/8907932#8907932
    - http://supercomputingblog.com/optimization/getting-started-with-sse-programming/
*/
#include <stdio.h>
int verbose = 1;
//constructors
template<typename dtype>
Vector<dtype>::Vector(){
  this->values = NULL;
  this->length = 0;
}
template<typename dtype>
Vector<dtype>::Vector(const unsigned int n){
  if(verbose) printf("Vector(unsigned int n)\n");
  this->values = new dtype[n]();
  this->length = n;
}
template<typename dtype>
Vector<dtype>::~Vector(){
  if(verbose) printf("~Vector()\n");
  delete this->values;
}
template<typename dtype>
dtype Vector<dtype>::operator[] (const unsigned int i) const {
  if(verbose) printf("Vector::operator[] (const unsigned int i)\n");
  return this->values[i];
}
template<typename dtype>
dtype& Vector<dtype>::operator[] (const unsigned int i){
  if(verbose) printf("Vector::&operator[] (const unsigned int i)\n");
  return this->values[i];
}

//operators
  //assignment
template<typename dtype>
void Vector<dtype>::operator= (const dtype constant) const{
  for(unsigned int i = 0; i < this->length; i++) this->values[i] = constant;
}
/*
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator= (const Vector<dtype>& vec) const{

}
*/
  //addition
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator+ (const dtype constant) const{
  if(verbose) printf("Vector::operator+ (const dtype constant)\n");
  Vector<dtype>* newvec = new Vector<dtype>(this->length);
  for(unsigned int i=0; i<this->length; i++) newvec->values[i] = this->values[i] + constant;
  return *newvec;
}
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator+ (const Vector<dtype>& vec) const{
  if(verbose) printf("Vector::operator+ (const Vector<dtype>& vec)\n");
  Vector<dtype>* newvec = new Vector<dtype>(this->length);
  for(unsigned int i=0; i<this->length; i++) newvec->values[i] = this->values[i] + vec.values[i];
  return *newvec;
}
template<typename dtype>
void Vector<dtype>::operator+= (const dtype constant){
  if(verbose) printf("Vector::operator+= (const dtype constant)\n");
  for(unsigned int i=0; i<this->length; i++) this->values[i] += constant;
}
template<typename dtype>
void Vector<dtype>::operator+= (const Vector<dtype>& vec){
  if(verbose) printf("Vector::operator+= (const Vector<dtype>& vec)\n");
  for(unsigned int i=0; i<this->length; i++) this->values[i] += vec.values[i];
}

//subtraction
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator- (const dtype constant) const{
  if(verbose) printf("Vector::operator- (const dtype constant)\n");
  Vector<dtype>* newvec = new Vector<dtype>(this->length);
  for(unsigned int i=0; i<this->length; i++) newvec->values[i] = this->values[i] - constant;
  return *newvec;
}
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator- (const Vector<dtype>& vec) const{
  if(verbose) printf("Vector::operator- (const Vector<dtype>& vec)\n");
  Vector<dtype>* newvec = new Vector<dtype>(this->length);
  for(unsigned int i=0; i<this->length; i++) newvec->values[i] = this->values[i] - vec.values[i];
  return *newvec;
}
template<typename dtype>
void Vector<dtype>::operator-= (const dtype constant){
  if(verbose) printf("Vector::operator-= (const dtype constant)\n");
  for(unsigned int i=0; i<this->length; i++) this->values[i] -= constant;
}
template<typename dtype>
void Vector<dtype>::operator-= (const Vector<dtype>& vec){
  if(verbose) printf("Vector::operator-= (const Vector<dtype>& vec)\n");
  for(unsigned int i=0; i<this->length; i++) this->values[i] += vec.values[i];
}

//multiplication
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator* (const dtype constant) const{
  if(verbose) printf("Vector::operator* (const dtype constant)\n");
  Vector<dtype>* newvec = new Vector<dtype>(this->length);
  for(unsigned int i=0; i<this->length; i++) newvec->values[i] = this->values[i] * constant;
  return *newvec;
}
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator* (const Vector<dtype>& vec) const{
  if(verbose) printf("Vector::operator* (const Vector<dtype>& vec)\n");
  Vector<dtype>* newvec = new Vector<dtype>(this->length);
  for(unsigned int i=0; i<this->length; i++) newvec->values[i] = this->values[i] * vec.values[i];
  return *newvec;
}
template<typename dtype>
void Vector<dtype>::operator*= (const dtype constant){
  if(verbose) printf("Vector::operator*= (const dtype constant)\n");
  for(unsigned int i=0; i<this->length; i++) this->values[i] *= constant;
}
template<typename dtype>
void Vector<dtype>::operator*= (const Vector<dtype>& vec){
  if(verbose) printf("Vector::operator*= (const Vector<dtype>& vec)\n");
  for(unsigned int i=0; i<this->length; i++) this->values[i] *= vec.values[i];
}

//division
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator/ (const dtype constant) const{
  if(verbose) printf("Vector::operator/ (const dtype constant)\n");
  Vector<dtype>* newvec = new Vector<dtype>(this->length);
  for(unsigned int i=0; i<this->length; i++) newvec->values[i] = this->values[i] / constant;
  return *newvec;
}
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator/ (const Vector<dtype>& vec) const{
  if(verbose) printf("Vector::operator/ (const Vector<dtype>& vec)\n");
  Vector<dtype>* newvec = new Vector<dtype>(this->length);
  for(unsigned int i=0; i<this->length; i++) newvec->values[i] = this->values[i] / vec.values[i];
  return *newvec;
}
template<typename dtype>
void Vector<dtype>::operator/= (const dtype constant){
  if(verbose) printf("Vector::operator/= (const dtype constant)\n");
  for(unsigned int i=0; i<this->length; i++) this->values[i] /= constant;
}
template<typename dtype>
void Vector<dtype>::operator/= (const Vector<dtype>& vec){
  if(verbose) printf("Vector::operator/= (const Vector<dtype>& vec)\n");
  for(unsigned int i=0; i<this->length; i++) this->values[i] /= vec.values[i];
}

//exponentiation
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator^ (const dtype constant) const{
  if(verbose) printf("Vector::operator^ (const dtype constant)\n");
  Vector<dtype>* newvec = new Vector<dtype>(this->length);
  for(unsigned int i=0; i<this->length; i++){
    newvec->values[i] = this->values[i];
    for(unsigned int j=0; j<constant-1; j++) newvec->values[i] *= this->values[i];
  }
  return *newvec;
}
template<typename dtype>
Vector<dtype>& Vector<dtype>::operator^ (const Vector<dtype>& vec) const{
  if(verbose) printf("Vector::operator^ (const Vector<dtype>& vec)\n");
  Vector<dtype>* newvec = new Vector<dtype>(this->length);
  for(unsigned int i=0; i<this->length; i++){
    newvec->values[i] = this->values[i];
    for(unsigned int j=0; j<vec.values[i]-1; j++) newvec->values[i] *= this->values[i];
  }
  return newvec;
}
template<typename dtype>
void Vector<dtype>::operator^= (const dtype constant){
  if(verbose) printf("Vector::operator^= (const dtype constant)\n");
  for(unsigned int i=0; i<this->length; i++){
    dtype base = this->values[i];
    for(unsigned int j=0; j<constant-1; j++) this->values[i] *= base;
  }
}
template<typename dtype>
void Vector<dtype>::operator^= (const Vector<dtype>& vec){
  if(verbose) printf("Vector::operator^= (const Vector<dtype>& vec)\n");
  for(unsigned int i=0; i<this->length; i++){
    dtype base = this->values[i];
    for(unsigned int j=0; j<vec.values[i]-1; j++) this->values[i] *= base;
  }
}


//methods
template<typename dtype>
void Vector<dtype>::quickSort(int ascending){

}
template<typename dtype>
std::string Vector<dtype>::toString(){
  if(this->length < 1) return "[]";
  std::string printstring = "[" + std::to_string(this->values[0]);
  for(unsigned int i=1; i<this->length; i++)printstring += ", " + std::to_string(this->values[i]);
  return printstring + "]";
}
