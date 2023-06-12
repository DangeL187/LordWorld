#include <iostream>
#include <vector>
#include <array>
#include <memory>
using namespace std;

std::vector<int*> v;

void f() {
    int* p = new int;
    *p = 13;
    v.push_back(p);
    delete p;
}

int main() {
  int x = 187;
  int* xx = &x;
  v.push_back(xx);
  while(true) {
    f();
    for (auto& i: v) {
      std::cout << *i << endl;
    }
    v.erase(v.begin() + 1);
  }

    return 0;
}
