#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <iostream>
#include <vector>
#include <list>

#if NAMESPACE == std
#include <type_traits> // is_integral
#include <utility>     // pair
#elif NAMESPACE == ft
#include <ft_utils.hpp>
#endif

class A
{
};

enum E : int
{
};

void test_is_integral();
void test_enable_if();
void test_pair();
void test_make_pair();
void test_equal();
void test_lexicographical_compare();

#endif