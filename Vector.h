#ifndef Vector_H
#define Vector_H
#include <string>

template<typename dtype>
class Vector {
public:
  unsigned int length;  //4bytes  -- 32bits
  dtype* values;        //8bytes  -- 64bits
                        //12bytes -- 96bits total
  Vector();
  Vector(const unsigned int n);
  ~Vector();

  //operators
  dtype operator[] (const unsigned int i) const; //getting
  dtype& operator[] (const unsigned int i);      //setting
  //Vector<dtype>* operator[] (const Vector<unsigned int>* indexes) const; //getting
  //Vector<dtype>* operator[] (const Vector<unsigned int>* indexes);       //setting

    //assignment
  void operator= (const dtype constant) const;
  //Vector<dtype>& operator= (const Vector<dtype>& vec) const;
    //addition
  Vector<dtype>& operator+ (const dtype constant) const;
  Vector<dtype>& operator+ (const Vector<dtype>& vec) const;
  void operator+= (const dtype constant);
  void operator+= (const Vector<dtype>& vec);
    //subtraction
  Vector<dtype>& operator- (const dtype constant) const;
  Vector<dtype>& operator- (const Vector<dtype>& vec) const;
  void operator-= (const dtype constant);
  void operator-= (const Vector<dtype>& vec);
    //multiplication
  Vector<dtype>& operator* (const dtype constant) const;
  Vector<dtype>& operator* (const Vector<dtype>& vec) const;
  void operator*= (const dtype constant);
  void operator*= (const Vector<dtype>& vec);
    //division
  Vector<dtype>& operator/ (const dtype constant) const;
  Vector<dtype>& operator/ (const Vector<dtype>& vec) const;
  void operator/= (const dtype constant);
  void operator/= (const Vector<dtype>& vec);
    //exponentiation
  Vector<dtype>& operator^ (const dtype constant) const;
  Vector<dtype>& operator^ (const Vector<dtype>& vec) const;
  void operator^= (const dtype constant);
  void operator^= (const Vector<dtype>& vec);


  //methods
  void quickSort(int ascending = 1);
  std::string toString();

};
#include "Vector.cc"
#endif
