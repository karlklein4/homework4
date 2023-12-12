#include "../include/assignment1.hpp"
#include <typeinfo>
#include <type_traits>
#include <functional>
#include <vector>
#include <array>
#include <memory>
#include <iostream>

namespace Homework {
    auto lamall = [](int a, int b) { return a + b; };

    template <typename T, typename U>
    T fun(T a, U b) {
        return a + b;
    }

    template <typename T>
    class A {
    private:
        T value;

    public:
        A(T val) : value(val) {}

        double get_power_of_2() const {
            return value * value;
        }
    };

    Homework::Tasks assignment1() {
        using namespace std::literals;

        // Loo lambda funktsioon lamall, mis võtab argumendiks 2 arvu ja tagastab selle
        // Arv (Number) võib olla nii komaga kui ilma aga ei ole tekst või muu klassi objekt

        // Kasuta fun funktsiooni, et luua muutuja fun1, mis võtab argumendiks arvud 5 ja 6
        auto fun1 = fun<int, int>(5, 6);

        // Loo klass A instants, võttes argumendiks arvu 5.5 ja salvesta muutujasse a
        A<double> a(5.5);

        // Loo muutuja b, mis saadakse a funktsiooniga get_power_of_2
        auto b = a.get_power_of_2();

        // Kontroll, et muutujad on õiget tüüpi ja väärtusega
        Tasks results;
        results.reserve(16ull);

        results.push_back({"lamall is a lambda", (std::is_class_v<decltype(lamall)>) && (std::is_invocable_v<decltype(lamall), int, int>)});
        results.push_back({"lamall returns sum of its args", (lamall(1, 2) == 3)});

        results.push_back({"fun is a template function", (std::is_function_v<decltype(fun<int, int>)>)});
        results.push_back({"fun1 is 30", (fun1 == 30)});

        results.push_back({"A is a class", (std::is_class_v<A<double>>)});
        results.push_back({"A has member function get_power_of_2", (std::is_member_function_pointer_v<decltype(&A<double>::get_power_of_2)>)});
        results.push_back({"A's get_power_of_2 is const", (std::is_same_v<decltype(&A<double>::get_power_of_2), double (A<double>::*)() const>)});
        results.push_back({"a is of type A", (std::is_same_v<decltype(a), A<double>>)});
        results.push_back({"b is 30.25", (b == 30.25)});

        return results;
    }
}