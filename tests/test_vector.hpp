/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <1veleita1@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:48:32 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/04 20:36:42 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

#if NAMESPACE == std
#include <vector>
#endif

#if NAMESPACE == ft
#include <ft_vector.hpp>
#include <ft_vector_iterator.hpp>
#endif

void test_v_constructors();
void test_v_iterators();
void test_v_access();
void test_v_capacity();
void test_v_modifiers();
void test_v_operators();

#endif
