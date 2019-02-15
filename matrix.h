#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "_vector.h"
#include "vector.h"

class Matrix : public _vector {
  private:
    List<Vector> columns;

  public:
    Matrix();
    Matrix(const Matrix &);
    ~Matrix();
    void add(Vector &v);
    virtual void print() const override;
    virtual bool zero() override;
    virtual int getAt(int) const override;
    void setVectorAt(int, Vector&);
    virtual int getSize() const override;
    Vector getVectorAt(int) const;
    Matrix& operator = (const Matrix&);

    //operators
    Matrix operator + (const Matrix&);
    Matrix & operator += (const Matrix &);
    Matrix & operator -= (const Matrix &);
    int operator * (const Matrix &);
    Matrix operator * (int);
    Matrix & operator *= (int);
};

#endif
