#include "matrix.h"

Matrix::Matrix() {}

Matrix::Matrix(const Matrix & other) {
  for (int i = 0; i < getSize(); i++) columns.remove(i);
  for (int j = 0; j < other.getSize(); j++) {
    Vector new_vec = other.getVectorAt(j);
    add(new_vec);
  }
}

Matrix::~Matrix() {}

void Matrix::add(Vector &v) { columns.add(v); }

void Matrix::print() const {
  for (int i = 0; i < columns.getAt(0).getSize(); i++) {
    std::cout << "| ";
    for (int j = 0; j < columns.getSize(); j++) {
      std::cout << columns.getAt(j).getAt(i) << " ";
    }
    std::cout << "|" <<std::endl;
  }
}

bool Matrix::zero() {
  for (int i = 0; i < columns.getSize(); i++) {
    if (!columns.getAt(i).zero()) return false;
  }
  return true;
}

int Matrix::getAt(int i) const {
  return 0;
}

Vector Matrix::getVectorAt(int i) const {
  return columns.getAt(i);
}

void Matrix::setVectorAt(int i, Vector & v) { columns.setAt(i, v); }

int Matrix::getSize() const {
  return columns.getSize();
}

Matrix & Matrix::operator = (const Matrix & other) {
  for (int i = 0; i < getSize(); i++) columns.remove(i);
  for (int j = 0; j < other.getSize(); j++) {
    Vector new_vec = other.getVectorAt(j);
    add(new_vec);
  }
  return *this;
}

Matrix Matrix::operator + (const Matrix & other) {
  Matrix new_m;
  if (other.getSize() != getSize()) return *this;

  for (int i = 0; i < other.getSize(); i++) {
    Vector temp = getVectorAt(i);
    Vector addition = other.getVectorAt(i);
    Vector result = temp;
    temp += addition;
    new_m.setVectorAt(i, result);
  }
  return new_m;
}

Matrix & Matrix::operator += (const Matrix & other) {
  if (other.getSize() != getSize()) return *this;

  for (int i = 0; i < other.getSize(); i++) {
    Vector temp = getVectorAt(i);
    Vector addition = other.getVectorAt(i);
    temp += addition;
    this->setVectorAt(i, temp);
  }
  return *this;
}

Matrix & Matrix::operator -= (const Matrix & other) {
  if (other.getSize() != getSize()) return *this;

  for (int i = 0; i < other.getSize(); i++) {
    Vector temp = getVectorAt(i);
    Vector addition = other.getVectorAt(i);
    temp -= addition;
    this->setVectorAt(i, temp);
  }
  return *this;
}

int Matrix::operator * (const Matrix & other) {
  int total = 0;
  for (int i = 0; i < this->getSize(); i++) {
    total += this->getVectorAt(i) * other.getVectorAt(i);
  }
  return total;
}

Matrix Matrix::operator * (int c) {
  Matrix m;
  for (int i = 0; i < this->getSize(); i++) {
    Vector temp = getVectorAt(i);
    temp *= c;
    m.add(temp);
  }
  return m;
}

Matrix & Matrix::operator *= (int c) {
  for (int i = 0; i < this->getSize(); i++) {
    Vector temp = this->getVectorAt(i);
    temp *= c;
    this->setVectorAt(i, temp);
  }
  return *this;
}
