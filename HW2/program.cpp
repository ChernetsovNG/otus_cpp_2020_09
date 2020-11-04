#include <iostream>
#include <map>
#include <vector>

#define UNUSED(x) (void)(x)

// Аллокатор параметризуется количеством выделяемых за раз элементов
template<typename T, int N>
struct Allocator {

    Allocator() = default;

    ~Allocator() {
        // при уничтожении аллокатора очищаем блок памяти размера N
        std::cout << "deallocate memory block of size " << N << std::endl;
        delete[] pointer;
        pointer = nullptr;
    };

    using value_type = T;

    template<typename U>
    struct rebind {
        using other = Allocator<U, N>;
    };

    T *allocate(std::size_t n) {
        // при первой аллокации выделяем блок памяти размера N
        if (pointer == nullptr) {
            std::cout << "allocate memory block of size " << N << std::endl;
            pointer = new T[N];
        }
        if (!is_memory_enough(n)) {
            throw std::invalid_argument("Not enough memory to accommodate " + std::to_string(n) + " elements");
        }
        // возвращаем указатель на память, начиная с индекса index
        std::cout << "allocate: [n = " << n << ", index = " << index << "]" << std::endl;
        T *result = reinterpret_cast<T *>(pointer + index);
        index += n;
        return result;
    }

    void deallocate(T *p, std::size_t n) {
        UNUSED(p);
        std::cout << "deallocate: [n = " << n << ", index = " << index << "]" << std::endl;
        index -= n;
        if (index < 0) index = 0;
    }

private:
    std::size_t index = 0;
    T *pointer = nullptr;

    // достаточно ли памяти для размещения n элементов?
    bool is_memory_enough(std::size_t n) {
        return N - index >= n;
    }
};

// Реализовать свой контейнер, который по аналогии с контейнерами stl параметризуется аллокатором. Контейнер должен
// иметь две возможности - добавить новый элемент и обойти контейнер в одном направлении
template<typename T, typename Alloc = std::allocator<T>>
struct MyVector {

    MyVector() {
        capacity = 1;
        length = 0;
        allocator = Alloc();
        arr = std::allocator_traits<Alloc>::allocate(allocator, 1);
    };

    ~MyVector() = default;

    long push_back(T data) {
        if (length == capacity) {
            T *old = arr;
            capacity *= 2;
            arr = std::allocator_traits<Alloc>::allocate(allocator, capacity);
            std::copy(old, old + length, arr);
            std::allocator_traits<Alloc>::deallocate(allocator, old, length);
        }
        arr[length++] = data;
        return length;
    }

    T &operator[](long index) {
        if (index >= length) {
            throw std::invalid_argument(std::to_string(index));
        }
        return *(arr + index);
    }

    struct Iterator {
        explicit Iterator() : ptr(nullptr) {}

        explicit Iterator(T *p) : ptr(p) {}

        bool operator==(const Iterator &rhs) const {
            return ptr == rhs.ptr;
        }

        bool operator!=(const Iterator &rhs) const {
            return ptr != rhs.ptr;
        }

        T operator*() const {
            return *ptr;
        }

        Iterator &operator++() {
            ++ptr;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp(*this);
            ++*this;
            return temp;
        }

    private:
        T *ptr;
    };

    // Begin Iterator
    [[nodiscard]] Iterator begin() const {
        return Iterator(arr);
    }

    // End Iterator
    [[nodiscard]] Iterator end() const {
        return Iterator(arr + length);
    }

private:
    T *arr;
    long capacity;
    long length;
    Alloc allocator;
};

constexpr int factorial(const int n) {
    if (n < 0) {
        throw std::invalid_argument("bad factorial argument: " + std::to_string(n));
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void part1() {
    std::cout << "--- Part1 start ---" << std::endl;

    // создание экземпляра std::map<int, int>
    std::map<int, int> map;

    // заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i <= 9; ++i) {
        map.emplace(i, factorial(i));
    }

    // вывод на экран всех значений (ключ и значение разделены пробелом) хранящихся в контейнере
    std::cout << "Print map key value pairs" << std::endl;
    for (const auto&[key, value] : map) {
        std::cout << key << " " << value << std::endl;
    }

    std::cout << "--- Part1 end ---" << std::endl;
}

void part2() {
    std::cout << "--- Part2 start ---" << std::endl;

    std::vector<int, Allocator<int, 10>> v;

    // создание экземпляра std::map<int, int> с новым аллокатором, ограниченным 10 элементами
    std::map<int, int, std::less<>, Allocator<std::pair<const int, int>, 10>> map;

    // заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i <= 9; ++i) {
        map.emplace(i, factorial(i));
    }

    // вывод на экран всех значений (ключ и значение разделены пробелом) хранящихся в контейнере
    std::cout << "Print map key value pairs" << std::endl;
    for (const auto&[key, value] : map) {
        std::cout << key << " " << value << std::endl;
    }

    std::cout << "--- Part2 end ---" << std::endl;
}

void part3() {
    std::cout << "--- Part3 start ---" << std::endl;

    // создание экземпляра своего контейнера для хранения значений типа int
    MyVector<int> vector;

    // заполнение 10 элементами от 0 до 9
    for (int i = 0; i <= 9; ++i) {
        vector.push_back(i);
    }

    // вывод на экран всех значений, хранящихся в контейнере
    std::cout << "Print vector values" << std::endl;
    for (auto it = std::begin(vector); it != std::end(vector); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "--- Part3 end ---" << std::endl;
}

void part4() {
    std::cout << "--- Part4 start ---" << std::endl;

    // создание экземпляра своего контейнера для хранения значений типа int с новым аллокатором, ограниченным 10 элементами
    // (за счёт расширения массива в векторе в 2 раза нужно аллоцировать бОльший блок памяти, иначе её не хватит для расширения)
    MyVector<int, Allocator<int, 24>> vector;

    // заполнение 10 элементами от 0 до 9
    for (int i = 0; i <= 9; ++i) {
        vector.push_back(i);
    }

    // вывод на экран всех значений, хранящихся в контейнере
    std::cout << "Print vector values" << std::endl;
    for (auto it = std::begin(vector); it != std::end(vector); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "--- Part4 end ---" << std::endl;
}

int main() {
    std::cout << "--- HW2 START ---" << std::endl;

    // 1. std::map
    part1();

    // 2. std::map с custom аллокатором
    part2();

    // 3. свой контейнер со стандартным аллокатором
    part3();

    // 4. свой контейнер с custom аллокатором
    part4();

    std::cout << "--- HW2 END ---" << std::endl;
}
