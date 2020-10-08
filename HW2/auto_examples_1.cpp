#include <iostream>

void question_1();

template<typename T>
void func1(T param) {
    // some very interesting code
    std::cout << param << std::endl;
}

template<typename T>
void func2(T &param) {
    // some very interesting code
    std::cout << param << std::endl;
}

template<typename T>
void func3(T *param) {
    // some very interesting code
    std::cout << param << std::endl;
}

template<typename T>
void func4(T &&param) {
    // some very interesting code
    std::cout << param << std::endl;
}

int main(int argc, char *argv[]) {
    question_1();
}

void question_1() {
    int i = 10;
    const int ci = 15;
    const int &cir = ci;
    int *pi = &i;
    const int *cpi = &i;

    func1(i);  // 1.1. int
    func1(ci);  // 1.2. int
    func1(cir);  // 1.3. int
    func1(42);   // 1.4. int
    func1(pi);  // 1.5. int
    func1(cpi);  // 1.6. int
    // func1({1});  // 1.7. not compile
    // func1({1, 2, 3});  // 1.8. not compile

    func2(i);  // 2.1. int &
    func2(ci);  // 2.2. const int &
    func2(cir);  // 2.3. const int &
    // func2(42);   // 2.4. not compile
    func2(pi);  // 2.5. int *&
    func2(cpi);  // 2.6. const int *&

    // func3(i); // 3.1. not compile
    // func3(ci); // 3.2. not compile
    // func3(cir); // 3.3. not compile
    // func3(42); // 3.4. not compile
    func3(pi); // 3.5. param type ?
    func3(cpi); // 3.6. param type ?

    func4(i); // 4.1. int &
    func4(ci); // 4.2. const int &
    func4(cir); // 4.3. const int &
    func4(42); // 4.4. int &&
    func4(pi); // 4.5. int *&
    func4(cpi); // 4.6. const int *&
}
