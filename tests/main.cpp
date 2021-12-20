/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_original.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:05:11 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/25 13:06:39 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "test_iterator.hpp"

typedef void (*test)(void);

int main()
{
	std::cout << std::boolalpha;

	std::cout << "UTILS TEST\n";
	std::cout << "===========================\n";
	test utils[6] = {&test_is_integral, &test_enable_if, &test_pair,
					 &test_make_pair, &test_equal, &test_lexicographical_compare};

	for (int i = 0; i < 6; i++)
	{
		(*utils[i])();
		std::cout << std::endl;
	}

	std::cout << "ITERATOR TEST\n";
	std::cout << "===========================\n";
	test iterator[1] = {&test_iter_traits};

	for (int i = 0; i < 1; i++)
	{
		(*iterator[i])();
		std::cout << std::endl;
	}

	return 0;
}
