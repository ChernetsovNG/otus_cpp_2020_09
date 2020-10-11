#include <string>
#include <tuple>
#include <cassert>

auto getPerson() {
    const std::string name = "Petia";
    const std::string secondName = "Ivanoff";
    const std::size_t age = 23;
    const std::string department = "Sale";
    return std::tuple(name, secondName, age, department);
}

template<typename... E>
constexpr std::tuple<E &...>
custom_tie(E &... args) noexcept {
    return std::tuple<E &...>(args...);
}

int main(int argc, char *argv[]) {
    std::string name, secondName, department;
    std::size_t age;

    std::tuple(1, 2, 3);
    custom_tie(name, secondName, age, department) = getPerson();

    assert(name == "Petia");
    assert(secondName == "Ivanoff");
    assert(age == 23);
    assert(department == "Sale");

    return 0;
}
