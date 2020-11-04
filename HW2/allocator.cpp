#include <iostream>

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
