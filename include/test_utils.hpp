/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:38:15 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/15 17:57:20 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
# define TEST_UTILS_HPP

#include <iostream>		// cout
#include <type_traits>	// is_integral
#include <utility>		// pair
#include <utils.hpp>

class A {};
enum E : int {};
 
void	test_is_integral();

void	test_enable_if();

void	test_pair();
void	test_make_pair();

bool 	is_palindrome(const std::string& s);
void 	test(const std::string& s);
void	test_equal();

#endif
