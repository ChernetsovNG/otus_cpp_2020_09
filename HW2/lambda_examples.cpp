#include <iostream>

void f(int &x) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << x << std::endl;
}

void f(const int &x) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << x << std::endl;
}

class String {
public:
    String() = default;

    String(int) = delete;

    String(const char *str_, int size_) {
        std::cout << "Invoke constructor String(const char *, int)" << std::endl;
        str = new char[size_];
        for (int i = 0; i < size_; ++i) {
            str[i] = str_[i];
        }
        size = size_;
    }

    String(const String &s_) {
        std::cout << "Invoke String copying constructor" << std::endl;
        const char *str_ = s_.str;
        int size_ = s_.size;
        str = new char[size_];
        for (int i = 0; i < size_; ++i) {
            str[i] = str_[i];
        }
        size = size_;
    }

    ~String() {
        std::cout << "Invoke destructor String" << std::endl;
        delete[] str;
    }

    const char *get() {
        return str;
    }

    [[nodiscard]] int length() const {
        return size;
    }

private:
    char *str = "Default";
    int size = 7;
};

int foo(bool c) {
    int x, y;
    y = c ? x : 42;
    return y;
}

template<typename T1, typename T2>
struct A {
    void func(void) {
        T1 dummy;
        internal_func(dummy);
    }

private:
    template<typename V>
    void internal_func(V) { std::cout << "all\n"; }

    void internal_func(int) { std::cout << "int\n"; }
};

int main() {
    A<int, double> a;
    A<float, double> b;

    a.func();
    b.func();
}

int main1() {
    int x = 100, y = 200;

    auto closure = [x = 101](int a, int b) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return a + b + x;
    };
    std::cout << closure(13, 15) << std::endl;

    auto closure2 = [=](int a, int b) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return a + b + x + y;
    };
    std::cout << closure2(13, 15) << std::endl;

    return 0;
}
