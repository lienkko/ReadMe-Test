#include "algorithms.h"

//1.

// product
template int product<std::vector<int>::iterator, int>(
    std::vector<int>::iterator, std::vector<int>::iterator, int const&);
template int product<std::list<int>::iterator, int>(
    std::list<int>::iterator, std::list<int>::iterator, int const&);
template double product<std::vector<double>::iterator, double>(
    std::vector<double>::iterator, std::vector<double>::iterator, double const&);
template double product<std::list<double>::iterator, double>(
    std::list<double>::iterator, std::list<double>::iterator, double const&);

// mean
template double mean<std::vector<int>::iterator>(
    std::vector<int>::iterator, std::vector<int>::iterator);
template double mean<std::list<int>::iterator>(
    std::list<int>::iterator, std::list<int>::iterator);
template double mean<std::vector<double>::iterator>(
    std::vector<double>::iterator, std::vector<double>::iterator);
template double mean<std::list<double>::iterator>(
    std::list<double>::iterator, std::list<double>::iterator);

// find_closest
template std::vector<int>::iterator find_closest<std::vector<int>::iterator, int>(
    std::vector<int>::iterator, std::vector<int>::iterator, int const&);
template std::list<int>::iterator find_closest<std::list<int>::iterator, int>(
    std::list<int>::iterator, std::list<int>::iterator, int const&);
template std::vector<double>::iterator find_closest<std::vector<double>::iterator, double>(
    std::vector<double>::iterator, std::vector<double>::iterator, double const&);
template std::list<double>::iterator find_closest<std::list<double>::iterator, double>(
    std::list<double>::iterator, std::list<double>::iterator, double const&);

// alternates_even_odd
template bool alternates_even_odd<std::vector<int>::iterator>(
    std::vector<int>::iterator, std::vector<int>::iterator);
template bool alternates_even_odd<std::list<int>::iterator>(
    std::list<int>::iterator, std::list<int>::iterator);

//2.

// count_n_populate
template std::vector<int> count_n_populate<int, std::vector<int>::iterator>(
    std::vector<int>::iterator, std::vector<int>::iterator, int const&);
template std::vector<int> count_n_populate<int, std::list<int>::iterator>(
    std::list<int>::iterator, std::list<int>::iterator, int const&);
template std::vector<double> count_n_populate<double, std::vector<double>::iterator>(
    std::vector<double>::iterator, std::vector<double>::iterator, double const&);
template std::vector<double> count_n_populate<double, std::list<double>::iterator>(
    std::list<double>::iterator, std::list<double>::iterator, double const&);

// split_parted
template std::pair<std::vector<int>, std::vector<int>> split_parted<int, std::vector<int>::iterator>(
    std::vector<int>::iterator, std::vector<int>::iterator, int const&);
template std::pair<std::vector<int>, std::vector<int>> split_parted<int, std::list<int>::iterator>(
    std::list<int>::iterator, std::list<int>::iterator, int const&);
template std::pair<std::vector<double>, std::vector<double>> split_parted<double, std::vector<double>::iterator>(
    std::vector<double>::iterator, std::vector<double>::iterator, double const&);
template std::pair<std::vector<double>, std::vector<double>> split_parted<double, std::list<double>::iterator>(
    std::list<double>::iterator, std::list<double>::iterator, double const&);