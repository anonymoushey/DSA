#include <iostream>
class Base {
public:
virtual ~Base();
virtual void pureimp() = 0;
};
Base::~Base() {}
void Base :: pureimp() {
std::cout << "Base::pureimp() “ << “called\n";
}
class Derived: public Base {
public:
virtual void pureimp();
};
inline void Derived::pureimp() {
Base::pureimp();
std::cout << "Derived::pureimp()” << “called\n";
}
int main() {
Derived derived;
derived.pureimp();
 derived.Base::pureimp();
}