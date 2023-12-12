#include "../include/assignment2.hpp"
#include <typeinfo>
#include <type_traits>
#include <functional>
#include <vector>
#include <array>
#include <memory>
#include <iostream>
#include <set>
#include <unordered_map>

// Andmestruktuurid
Homework::Tasks Homework::assignment2()
{
    using namespace std::literals;

    // Loo massiiv arr mis sisaldab 4 arvu 1, 2 ja 3
    std::array<int, 4> arr = {1, 2, 3, 2};

    // Lisa massiivi arr lõppu arv 2
    arr.fill(2);

    // Loo vector vec, mis sisaldab 3 arvu 1, 2 ja 3
    std::vector<int> vec = {1, 2, 3};

    // Eemalda vectorist vec viimane element
    if (!vec.empty()) {
        vec.pop_back();
    }

    // Loo hashmap nimega map, mis sisaldab 3 paari, millest igaüks sisaldab arve [1,2,3] ja nende arvude ruutu
    std::unordered_map<int, int> map = {{1, 1}, {2, 4}, {3, 9}};

    // Loo set nimega number_set, kuhu lisatakse antud jada { 2, 2, 3, 2, 1 }
    std::set<int> number_set = {2, 2, 3, 2, 1};

    // Kontroll, et muutujad on õiget tüüpi ja väärtusega
    Tasks results;
    results.reserve(32ull);

    results.push_back({"arr is an array", (std::is_array_v<decltype(arr)>)});
    results.push_back({"arr has 5 elements", (arr.size() == 5)});
    results.push_back({"arr has 1, 2, 3, 2, 2", (arr[0] == 1) && (arr[1] == 2) && (arr[2] == 3) && (arr[3] == 2) && (arr[4] == 2)});

    results.push_back({"vec is a vector", (std::is_same_v<decltype(vec), std::vector<int>>)});
    results.push_back({"vec has 2 elements", (vec.size() == 2)});
    results.push_back({"vec has 1, 2", (vec[0] == 1) && (vec[1] == 2)});

    results.push_back({"map is a hashmap", (std::is_same_v<decltype(map), std::unordered_map<int, int>>)});
    results.push_back({"map has 3 elements", (map.size() == 3)});
    results.push_back({"map has 1->1, 2->4, 3->9", (map[1] == 1) && (map[2] == 4) && (map[3] == 9)});

    results.push_back({"number_set is a set", (std::is_same_v<decltype(number_set), std::set<int>>)});
    results.push_back({"number_set has 3 elements", (number_set.size() == 3)});
    results.push_back({"number_set has 1, 2, 3", (number_set.find(1) != number_set.end()) && (number_set.find(2) != number_set.end()) && (number_set.find(3) != number_set.end())});

    return results;
}