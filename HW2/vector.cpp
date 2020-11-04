#include <iostream>

// Реализовать свой контейнер, который по аналогии с контейнерами stl параметризуется аллокатором. Контейнер должен
// иметь две возможности - добавить новый элемент и обойти контейнер в одном направлении
template<typename T, typename Alloc = std::allocator<T>>
struct MyVector {

    MyVector() {
        capacity = 1;
        length = 0;
        allocator = Alloc();
        arr = allocate_memory();
    };

    ~MyVector() = default;

    long push_back(T data) {
        if (length == capacity) {
            T *old = arr;
            capacity *= 2;
            arr = allocate_memory();
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

    T *allocate_memory() {
        return std::allocator_traits<Alloc>::allocate(allocator, capacity);
    }
};
