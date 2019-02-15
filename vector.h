#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "_vector.h"
#include "list.h"

class Vector : public _vector {
  public:
    Vector();
    Vector (const Vector &);
    Vector(int x);
    ~Vector();
    virtual void print() const override;
    void print(std::ostream & out);
    virtual bool zero() override;
    void add(int x);
    //List & getContents();
    int getSize() const override;
    int getAt(int) const override;
    void setAt(int, int);
    virtual Vector operator + (Vector & other);
    virtual Vector & operator += (Vector&);
    virtual Vector & operator -= (Vector&);
    virtual Vector operator * (int);
    virtual Vector & operator *= (int);
    Vector & operator = (const Vector&);
    int operator * (const Vector&);


  private:
    List<int> contents;
};
std::ostream & operator << (std::ostream &out, Vector & v);


#endif
