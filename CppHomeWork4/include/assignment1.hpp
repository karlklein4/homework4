#pragma once
#include <functional>
#include <string>
#include <vector>

namespace Homework {
    using Tasks = std::vector<std::pair<std::string, bool>>;
    Tasks assignment1();

    template <typename T>
    concept Number = std::is_arithmetic_v<T> && !std::is_same_v<T, char>;

    template <Number T>
    T fun(T a, T b) {
        return a * b;
    }

    template <Number T>
    class A {
    private:
        T number;

    public:
        A(T num) : number(num) {}

        T get_power_of_2() const {
            return number * number;
        }
    };
}