#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <iostream>
#include <string>

#if NAMESPACE == std
#include <vector>
#endif

#if NAMESPACE == ft
#include <ft_vector.hpp>
#include <ft_vector_iterator.hpp>
#endif

void test_v_constructors();
void test_v_iterators();

#endif