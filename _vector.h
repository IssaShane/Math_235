#ifndef _VECTOR_H
#define _VECTOR_H

#include <iostream>

class Vector;

class _vector {
  public:
    _vector();
    virtual void print() const = 0;
    virtual bool zero() = 0;
    /*
    virtual _vector & operator + (_vector&) = 0;
    virtual _vector & operator += (_vector &) = 0;
    virtual _vector & operator * (int) = 0;
    virtual _vector & operator *= (int) = 0;
    */
    virtual int getAt(int) const = 0;
    virtual int getSize() const = 0;
};

#endif
