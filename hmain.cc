#include <iostream>

class Expr {

public:
Expr();
void *operator new(size_t, void *p)
};



int main() {
  char a = 0;
  std::cout<<"wrinte"<<std::endl;
  std::cin >> a;
  if (a == 9) {
      std::cout<<"ok"<<std::endl;
    } else {
      std::cout<<"fail"<<std::endl;
    }
  return 0; }




