#include "../include/assignment3.hpp"
#include <typeinfo>
#include <type_traits>
#include <functional>
#include <vector>
#include <array>
#include <memory>
#include <iostream>
#include <numeric>

// Algoritmid
Homework::Tasks Homework::assignment3()
{
    using namespace std::literals;

    std::vector<int> numbers1{5, 2, 8, 1, 3};
    // Sorteeri vektor numbers0 kasutades STL algoritmi

    std::string str{"Hello, World!"s};
    // Pööra string str ümber kasutades STL algoritmi

    std::vector<int> src{1, 2, 3, 4, 5};
    std::vector<int> dest(src.size()); // {} kasutus siin ei ole erandlikult sobilik
    // Kopeeri vektorist src vektorisse dest kasutades STL algoritmi

    std::vector<int> numbers2{5, 2, 8, 1, 3, 2, 2};
    // Eemalda vektorist numbers2 kõik elemendid, mille väärtus on 2 kasutades STL algoritmi
    // Vajab 2 STL algoritmi

    std::vector<int> numbers3{5, 2, 8, 1, 3, 2, 2};
    // Asenda vektoris numbers kõik elemendid, mille väärtus on 2, väärtusega 9 kasutades STL algoritmi

    std::vector<int> numbers4{1, 1, 2, 2, 3, 3, 4, 4};
    // Eemalda vektorist numbers kõik järjestikused duplikaadid kasutades STL algoritmi
    // Vajab 2 STL algoritmi

    std::vector<int> numbers5{1, 2, 3, 4, 5};
    // Kalkuleeri vektori numbers summa kasutades STL algoritmi ja salvesta see muutujasse sum

    std::vector<int> numbers6{1, 2, 3, 4, 5};
    std::string str1{};
    // Salvesta vektori numbers elemendid stringi str1 kujul "1,2,3,4,5," kasutades STL algoritmi
    auto it = std::find(numbers1.begin(), numbers1.end(), 8);
    int sum = std::accumulate(numbers5.begin(), numbers5.end(), 0);

    // Kontroll, et muutujad on õiget tüüpi ja väärtusega
    Tasks results;
    results.reserve(16ull);

    results.push_back({"numbers0 is sorted", std::is_sorted(numbers1.begin(), numbers1.end())});
    results.push_back({"str is reversed", str == "!dlroW ,olleH"});
    results.push_back({"it points to 8", *it == 8});
    results.push_back({"dest is a copy of src", dest == src});
    results.push_back({"numbers2 has no 2s", std::find(numbers2.begin(), numbers2.end(), 2) == numbers2.end()});
    results.push_back({"numbers3 has no 2s", std::find(numbers3.begin(), numbers3.end(), 2) == numbers3.end()});
    results.push_back({"numbers3 has 9s", std::find(numbers3.begin(), numbers3.end(), 9) != numbers3.end()});
    results.push_back({"numbers4 has no duplicates", std::adjacent_find(numbers4.begin(), numbers4.end()) == numbers4.end()});
    results.push_back({"sum is 15", sum == 15});
    results.push_back({"str1 is \"1,2,3,4,5,\"", str1 == "1,2,3,4,5,"});

    return results;
}