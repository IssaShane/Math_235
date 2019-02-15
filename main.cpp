#include "vector.h"
#include "_vector.h"
#include "matrix.h"
#include "system.h"
#include <iostream>

using namespace std;

void test() {
  List<_vector> Basis;
  Vector v1;
  Matrix m1;
  v1.add(1);
  v1.add(2);
  m1.add(v1);
  m1.add(v1);
  _vector b1 = v1;
  _vector b2 = m1;
  Basis.add(b1);
  Basis.add(b2);
  cout << "not failed yet" << endl;
}

int main() {
  test();
  //System sys;
  //sys.run();
  return 0;
}
