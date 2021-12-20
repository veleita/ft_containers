#ifndef TEST_ITERATOR_HPP
#define TEST_ITERATOR_HPP

#include <iostream>
#include <vector> // vector
#include <list>   // list
#include <array>  // list

#if NAMESPACE == std
#include <iterator> // iterator_traits
#include <utility>  // pair
#elif NAMESPACE == ft
#include <ft_iterator.hpp>
#endif

void test_iter_traits();

#endif