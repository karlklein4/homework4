#pragma once
#include <functional>
#include <string>
#include <map>

namespace Homework {
    using Tasks = std::vector<std::pair<std::string, bool>>;
    Tasks assignment2();

    struct A;

    struct A {
        
    };

    class B : public A {
        
    };

    struct D {
        A a;
        int i;
    };

    class E {
    private:
        int number = 0;

    public:
        constexpr int get_number() const {
            return number;
        }

        constexpr void set_number(int i) {
            number = i;
        }
    };
}