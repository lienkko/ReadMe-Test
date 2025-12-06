#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <string>
#include "algorithms.h"
template<typename Container>
void test_product() {
    Container c1 = { 1, 2, 3, 4, 5 };
    Container c2 = { 2, 3, 4 };
    Container c3 = {};
    Container c4 = { 5 };

    assert(product(c1.begin(), c1.end(), 1) == 120);
    assert(product(c2.begin(), c2.end(), 1) == 24);
    assert(product(c3.begin(), c3.end(), 5) == 5);
    assert(product(c4.begin(), c4.end(), 1) == 5);

    std::cout << "test_product passed for " << typeid(Container).name() << std::endl;
}

template<typename Container>
void test_mean() {
    Container c1 = { 1, 2, 3, 4, 5 };
    Container c2 = { 10, 20, 30 };
    Container c3 = {};
    Container c4 = { 7 };

    assert(std::abs(mean(c1.begin(), c1.end()) - 3.0) < 1e-10);
    assert(std::abs(mean(c2.begin(), c2.end()) - 20.0) < 1e-10);
    assert(std::abs(mean(c3.begin(), c3.end()) - 0.0) < 1e-10);
    assert(std::abs(mean(c4.begin(), c4.end()) - 7.0) < 1e-10);

    std::cout << "test_mean passed for " << typeid(Container).name() << std::endl;
}

template<typename Container>
void test_find_closest() {
    Container c1 = { 1, 4, 7, 10, 13 };
    Container c2 = { 5 };
    Container c3 = {};

    auto it1 = find_closest(c1.begin(), c1.end(), 6);
    assert(it1 != c1.end() && *it1 == 7);

    auto it2 = find_closest(c1.begin(), c1.end(), 9);
    assert(it2 != c1.end() && *it2 == 10);

    auto it3 = find_closest(c2.begin(), c2.end(), 100);
    assert(it3 != c2.end() && *it3 == 5);

    auto it4 = find_closest(c3.begin(), c3.end(), 5);
    assert(it4 == c3.end());

    std::cout << "test_find_closest passed for " << typeid(Container).name() << std::endl;
}

template<typename Container>
void test_alternates_even_odd() {
    Container c1 = { 1, 2, 3, 4, 5 };      
    Container c2 = { 1, 3, 5, 7 };        
    Container c3 = { 2, 4, 6, 8 };         
    Container c4 = { 1, 2, 4, 5 };         
    Container c5 = { 1, 2, 3, 4, 6, 7 };   
    Container c6 = {};                   

    assert(alternates_even_odd(c1.begin(), c1.end()) == true);
    assert(alternates_even_odd(c2.begin(), c2.end()) == false);
    assert(alternates_even_odd(c3.begin(), c3.end()) == false);
    assert(alternates_even_odd(c4.begin(), c4.end()) == false);
    assert(alternates_even_odd(c5.begin(), c5.end()) == false);
    assert(alternates_even_odd(c6.begin(), c6.end()) == true);

    std::cout << "test_alternates_even_odd passed for " << typeid(Container).name() << std::endl;
}

template<typename Container>
void test_count_n_populate() {
    Container c1 = { 1, 2, 3, 2, 4, 2, 5 };
    Container c2 = { 1, 3, 5, 7 };
    Container c3 = {};
    Container c4 = { 2, 2, 2, 2 };

    auto v1 = count_n_populate<int>(c1.begin(), c1.end(), 2);
    assert(v1.size() == 3);
    for (const auto& x : v1) assert(x == 2);

    auto v2 = count_n_populate<int>(c2.begin(), c2.end(), 2);
    assert(v2.empty());

    auto v3 = count_n_populate<int>(c3.begin(), c3.end(), 2);
    assert(v3.empty());

    auto v4 = count_n_populate<int>(c4.begin(), c4.end(), 2);
    assert(v4.size() == 4);
    for (const auto& x : v4) assert(x == 2);

    std::cout << "test_count_n_populate passed for " << typeid(Container).name() << std::endl;
}

template<typename Container>
void test_split_parted() {
    Container c1 = { 1, 5, 3, 8, 2, 7, 4, 6 };
    Container c2 = { 1, 2, 3 };
    Container c3 = { 4, 5, 6 };
    Container c4 = {};

    auto result1 = split_parted<int>(c1.begin(), c1.end(), 5);
    for (const auto& x : result1.first) assert(x < 5);
    for (const auto& x : result1.second) assert(x >= 5);
    assert(result1.first.size() + result1.second.size() == c1.size());

    auto result2 = split_parted<int>(c2.begin(), c2.end(), 5);
    assert(result2.first.size() == 3);
    assert(result2.second.empty());

    auto result3 = split_parted<int>(c3.begin(), c3.end(), 4);
    assert(result3.first.empty());
    assert(result3.second.size() == 3);

    auto result4 = split_parted<int>(c4.begin(), c4.end(), 5);
    assert(result4.first.empty());
    assert(result4.second.empty());
    Container c5 = { 1, 2, 3, 4, 5 };
    auto result5 = split_parted<int>(c5.begin(), c5.end(), 3);
    std::vector<int> expected_first = { 1, 2 };
    std::vector<int> expected_second = { 3, 4, 5 };
    assert(result5.first == expected_first);
    assert(result5.second == expected_second);

    std::cout << "test_split_parted passed for " << typeid(Container).name() << std::endl;
}

void test_different_types() {
    std::vector<double> vd = { 1.1, 2.2, 3.3, 4.4 };
    assert(std::abs(product(vd.begin(), vd.end(), 1.0) - 35.1384) < 1e-4);
    assert(std::abs(mean(vd.begin(), vd.end()) - 2.75) < 1e-10);

    auto closest_d = find_closest(vd.begin(), vd.end(), 3.0);
    assert(closest_d != vd.end() && std::abs(*closest_d - 3.3) < 1e-10);

    std::cout << "test_different_types passed" << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Тестирование с std::vector<int>" << std::endl;
    test_product<std::vector<int>>();
    test_mean<std::vector<int>>();
    test_find_closest<std::vector<int>>();
    test_alternates_even_odd<std::vector<int>>();
    test_count_n_populate<std::vector<int>>();
    test_split_parted<std::vector<int>>();

    std::cout << "\n Тестирование с std::list<int>" << std::endl;
    test_product<std::list<int>>();
    test_mean<std::list<int>>();
    test_find_closest<std::list<int>>();
    test_alternates_even_odd<std::list<int>>();
    test_count_n_populate<std::list<int>>();
    test_split_parted<std::list<int>>();

    std::cout << "\nТестирование с разными типами " << std::endl;
    test_different_types();

    std::cout << "\nВсе тесты пройдены успешно! " << std::endl;

    std::cout << "\nДемонстрация работы функций " << std::endl;
    std::vector<int> demo1 = { 1, 2, 3, 4, 5 };
    std::cout << "Product of {1,2,3,4,5} = "
        << product(demo1.begin(), demo1.end(), 1) << std::endl;
    std::list<double> demo2 = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    std::cout << "Mean of {1,2,3,4,5} = "
        << mean(demo2.begin(), demo2.end()) << std::endl;
    std::vector<int> demo3 = { 10, 20, 30, 40, 50 };
    auto closest = find_closest(demo3.begin(), demo3.end(), 28);
    std::cout << "Closest to 28 in {10,20,30,40,50} = " << *closest << std::endl;
    std::list<int> demo4 = { 1, 2, 3, 4, 5 };
    std::cout << "{1,2,3,4,5} alternates even/odd? "
        << (alternates_even_odd(demo4.begin(), demo4.end()) ? "Yes" : "No") << std::endl;
    std::vector<int> demo5 = { 1, 2, 2, 3, 2, 4 };
    auto result5 = count_n_populate<int>(demo5.begin(), demo5.end(), 2);
    std::cout << "Found " << result5.size() << " occurrences of 2" << std::endl;
    std::list<int> demo6 = { 3, 1, 4, 1, 5, 9, 2 };
    auto result6 = split_parted<int>(demo6.begin(), demo6.end(), 4);
    std::cout << "Split by 4: less = {";
    for (size_t i = 0; i < result6.first.size(); ++i) {
        std::cout << result6.first[i] << (i < result6.first.size() - 1 ? "," : "");
    }
    std::cout << "}, greater/equal = {";
    for (size_t i = 0; i < result6.second.size(); ++i) {
        std::cout << result6.second[i] << (i < result6.second.size() - 1 ? "," : "");
    }
    std::cout << "}" << std::endl;

    return 0;
}