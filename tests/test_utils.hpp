#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <iostream>
#include <vector>
#include <list>

#if NAMESPACE == std
#include <type_traits> // is_integral
#include <utility>     // pair
#endif

#if NAMESPACE == ft
#include <ft_utils.hpp>
#include <ft_binary_search_tree.hpp>
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
void test_binary_search_tree();

#endif
