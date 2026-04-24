#include <bits/stdc++.h>

class Base {
    public:
    void f() { std::cout << "Base --\n"; }
    void f(int x) { std::cout << "Base int\n"; }
    void f(double x) { std::cout << "Base double\n"; }
};

class Derived : public Base {
    public:
    void f(int x) {  }
};

int main() {
    Derived* obj = new Derived();
    obj->f(3.14);
    obj->f();
}