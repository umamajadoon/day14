#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    operator int() const {
        return value;
    }
};

int main() {
    MyClass obj(42);
    int i = obj;
    std::cout << "The integer value is: " << i << std::endl;
    return 0;
}