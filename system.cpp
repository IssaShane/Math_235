#include "system.h"

using namespace std;

System::System() {

}

void System::run() {
  char c;
  while(true) {
    cin >> c;
    if (c == 'd') {
      char d;
      cin >> d;
      if (d == 'v') {
        int i;
        cin >> i;
        int j;
        cin >> j;
        vecs[i] = vecs[j];
      }
      else if (d == 'm') {
        int i, j;
        cin >> i;
        cin >> j;
        matrices[i] = matrices[j];
      }
    }
    else if (c == 'a') {
      char d, i;
      cin >> d;
      cin >> i;
      int j = i - '0';
      if ( d == 'v') {
        int e;
        cin >> e;
        vecs[j].add(e);
      }
      else if (d == 'm') {
        int e;
        cin >> e;
        matrices[j].add(vecs[e]);
      }
    }
    else if (c == 'x') {
      char d;
      int i, j;
      cin >> d;
      cin >> i;
      cin >> j;
      if (d == 'v') vecs[i] *= j;
      else if (d == 'm') matrices[i] *= j;
    }
    else if (c == '+') {
      char d;
      int i, j;
      cin >> d;
      cin >> i;
      cin >> j;
      if (d == 'v') vecs[i] += vecs[j];
      else if (d == 'm') matrices[i] += matrices[j];
    }
    else if (c == '-') {
      char d;
      int i, j;
      cin >> d;
      cin >> i;
      cin >> j;
      if (d == 'v') vecs[i] -= vecs[j];
      else if (d == 'm') matrices[i] -= matrices[j];
    }
    else if (c == '*') {
      char d;
      int i, j;
      cin >> d;
      cin >> i;
      cin >> j;
      if (d == 'v') cout << "<v" << i << ", v" << j << "> = " << vecs[i]*vecs[j] << endl;
      else if (d == 'm') cout << "<m" << i << ", m" << j << "> = " << matrices[i]*matrices[j] << endl;
    }
    else if (c == 'p') {
      char d;
      int j;
      cin >> d;
      cin >> j;
      if (d == 'v') cout << vecs[j];
      else if (d == 'm') matrices[j].print();
    }
    else if (c == 'q') break;
  }
}
