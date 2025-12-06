#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <numeric> 

// Часть 1


template<typename It, typename T>
T product(It beg, It end, T const& init) {
    return std::accumulate(beg, end, init, std::multiplies<T>());
}


template<typename It>
double mean(It beg, It end) {
    double sum = 0.0;
    int count = 0;

    std::for_each(beg, end, [&sum, &count](const auto& elem) {
        sum += elem;
        ++count;
        });

    return count > 0 ? sum / count : 0.0;
}

template<typename It, typename R>
It find_closest(It beg, It end, R const& value) {
    if (beg == end) return end;

    return std::min_element(beg, end, [value](const auto& a, const auto& b) {
        return std::abs(a - value) < std::abs(b - value);
        });
}

template<typename It>
bool alternates_even_odd(It beg, It end) {
    if (beg == end) return true;

    It it = std::adjacent_find(beg, end, [](const auto& a, const auto& b) {
        return (a % 2 == 0) == (b % 2 == 0);
        });

    return it == end;
}

// Часть 2


template<typename T, typename It>
std::vector<T> count_n_populate(It beg, It end, T const& val) {
    auto count = std::count(beg, end, val);
    return std::vector<T>(count, val);
}


template<typename T, typename It>
std::pair<std::vector<T>, std::vector<T>> split_parted(It beg, It end, T const& val) {
    std::vector<T> temp(beg, end);
    auto middle = std::stable_partition(temp.begin(), temp.end(),
        [val](const T& elem) { return elem < val; });
    return {
        std::vector<T>(temp.begin(), middle),
        std::vector<T>(middle, temp.end())
    };
}

#endif // ALGORITHMS_H
