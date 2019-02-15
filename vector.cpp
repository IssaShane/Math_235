#include "vector.h"

Vector::Vector() {
  //contents.add(0);
  //std::cout << "default constructor" << std::endl;
}

Vector::Vector(int x) {

  contents.add(x);
}

Vector::Vector(const Vector & other) {
  //std::cout << "copy constructor" << std::endl;
  for (int j = 0; j < getSize(); j++) contents.remove(j);
  for (int i = 0; i < other.getSize(); i++) {
    add(other.getAt(i));
  }
}

Vector::~Vector() {
  //delete contents;
}

// print() outputs the contents of this to the screen in a vertical
//  format with bars on either side
// requirements: none
// effects: outputs
// efficiency: O(n)
void Vector::print() const {
  for (int i = 0; i < contents.getSize(); i++) {
    std::cout << "| " << contents.getAt(i) << " |" << std::endl;
  }
}

// print(out) outputs the contents of this to the ostream out in a vertical
//   format with bars on either side
// requirements: none
// effects: outputs
// efficiency: O(n)
void Vector::print(std::ostream & out) {
  for (int i = 0; i < contents.getSize(); i++) {
    out << "| " << contents.getAt(i) << " |" << std::endl;
  }
}

// zero() returns true iff there are no values in contents
// requirements: none
// effects: none
// efficiency: O(1)
bool Vector::zero() {
  for (int i = 0; i < contents.getSize(); i++) {
    if (contents.getAt(i) != 0) return false;
  }
  return true;
}

// add(x) appends x to the end of this vector's contents
// requirements: x is a valid int
// effects: mutates data
// efficiency: O(n)
void Vector::add(int x) {
  //std::cout << "adding " << x << std::endl;
  //std::cout << "we calling add over here bois" << std::endl;
  contents.add(x);

}

// getSize() returns the amount of values in this vector
// requirements: none
// effects: none
// efficiency: O(1)
int Vector::getSize() const {
  //std::cout << "size: " << contents.getSize() << std::endl;
  return contents.getSize();
}

// getAt(i) returns the ith value in this vector
// requirements: i < this->getSize()
// effects: none
// efficiency: O(n)
int Vector::getAt(int i ) const {
  return contents.getAt(i);
}

// setAt(i, n) changes the ith value of this vector to n
// requirements: n is a valid int
//               i < this->getSize()
// effects: mutates data
// efficiency: O(n)
void Vector::setAt(int i, int n) {
  contents.setAt(i, n);
}

// operator + (other) returns the value of a vector with entries equal
//   to the sum of the entries of this vector and other
// requirements: other is a valid Vector& rvalue
// effects: none
// efficiency: O(~nlogn)
Vector Vector::operator + (Vector & other) {
  Vector new_vec;
  if (getSize() != other.getSize()) return *this;
  for (int i = 0; i < getSize(); i++) {
    int temp = contents.getAt(i);
    temp += other.getAt(i);
    new_vec.add(temp);
  }
  return new_vec;
}

// operator += (other) adds the value of each entry of other to the entries
//   of this vector
// requirements: other is a valid Vector&
// effects: mutates all entries of this vector
// efficiency: O(n²)
Vector & Vector::operator += (Vector & other) {
  //std::cout << "+= operator: " << std::endl;
  if (getSize() != other.getSize()) return *this;
  for (int i = 0; i < getSize(); i++) {
    int temp = contents.getAt(i);
    temp += other.getAt(i);
    contents.setAt(i, temp);
  }
  return *this;
}

Vector & Vector::operator -= (Vector & other) {
  if (getSize() != other.getSize()) return *this;
  for (int i = 0; i < getSize(); i++) {
    int temp = contents.getAt(i);
    temp -= other.getAt(i);
    contents.setAt(i, temp);
  }
  return *this;
}

// operator * (c) returns the value of a vector where all entries are scaled
//   by c
// requirements: c is a valid int
// effects: none
// efficiency: O(~nlogn)
Vector Vector::operator * (int c) {
  Vector v;
  for (int i = 0; i < getSize(); i++) {
    int temp = getAt(i);
    temp *= c;
    v.add(temp);
  }
  return v;
}

// operator *= (c) multiplies each entry of this vector by c
// requirements: c is a valid int
// effects: mutates entries of this vector
// efficiency: O(~nlogn)
Vector & Vector::operator *= (int c) {
  for (int i = 0; i < getSize(); i++) {
    int temp = getAt(i);
    temp *= c;
    contents.setAt(i, temp);
  }
  return *this;
}

// operator * (other) returns the value of the standard inner product between
//   this vector and other
// requirements: this->getSize() = ohter.getSize()
// effects: none
// efficiency; O(~nlogn)
int Vector::operator * (const Vector & other) {
  int retval = 0;
  if (getSize() != other.getSize()) return 0;
  for (int i = 0; i < getSize(); i++) {
    retval += (getAt(i) * other.getAt(i));
  }
  return retval;
}

// operator = (other) assigns each entry of this vector to the values of the
//   entries of other. In the event of a size descrepency, this vector will be
//   changed to the size of other
// requirements: other is a valid Vector& lvalue
// effects: mutates data
// efficiency: O(~nlogn)
Vector & Vector::operator = (const Vector & other) {
  //std::cout << "vector assignment operator" << std::endl;
  for (; this->getSize() != 0; ) {
    //std::cout << "removing" << std::endl;
    contents.remove(0);
  }
  //std::cout << "done removing" << std::endl;
  for (int i = 0; i < other.getSize(); i++) {
    this->add(other.getAt(i));
    //std::cout << "adding" << std::endl;
  }
  //std::cout << "end of vector assignemtn operator" << std::endl;
  return *this;
}

// operator << (out, v) does the smae thing as v.print(out)
std::ostream & operator << (std::ostream & out, Vector & v) {
  v.print(out);
  return out;
}
