#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include "vector.h"
#include "matrix.h"

class System {
  private:
    Vector vecs[10];
    Matrix matrices[10];

  public:
    System();
    void run();
};

#endif
