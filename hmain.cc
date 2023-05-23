#include <iostream>

class Parent {
 public:
  virtual void print() const = 0;
};

class Child : public Parent {
 public:
  void print() const { std::cout << sizeof(*this) << "child" << std::endl; }

 private:
  double b = 6;
};

class AnotherChild : public Parent {
 public:
  void print() const {
    std::cout << sizeof(*this) << "another child" << std::endl;
  }

 private:
  char i = 13;
};

int main() { return 0; }
