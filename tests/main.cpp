/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:05:11 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/03 16:04:59 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "test_utils.hpp"
#include "test_iterator.hpp"
#include "test_vector.hpp"
#include "test_stack.hpp"

typedef void (*test)(void);

int main()
{

	struct timeval	tv;
	unsigned long	before;
	unsigned long	after;
	unsigned long	execution_time;

	std::cout << std::boolalpha;

	gettimeofday(&tv, NULL);
	before = tv.tv_sec * 1000000 + tv.tv_usec;

	std::cout << "UTILS TEST\n";
	std::cout << "===========================\n\n";
	test utils[6] = {
				&test_is_integral,
				&test_enable_if,
				&test_pair,
				&test_make_pair,
				&test_equal,
				&test_lexicographical_compare
			};

	for (int i = 0; i < 1; i++)
	{
		(*utils[i])();
		std::cout << "---------------------------\n\n";
	}


	std::cout << "\nITERATOR TEST\n";
	std::cout << "===========================\n";
	test iterator[1] = {&test_iter_traits};

	for (int i = 0; i < 1; i++)
	{
		(*iterator[i])();
		std::cout << "---------------------------\n\n";
	}


	std::cout << "\nVECTOR TEST\n";
	std::cout << "===========================\n";
	test vector[5] = {
						&test_v_constructors,
						&test_v_iterators,
                     	&test_v_access,
						&test_v_capacity,
						&test_v_modifiers
					};

	for (int i = 0; i < 5; i++)
	{
		(*vector[i])();
		std::cout << "---------------------------\n\n";
	}

/*
	std::cout << "\nSTACK TEST\n";
	std::cout << "===========================\n";
	test stack[2] = {
						&test_s_constructors,
                		&test_s_member_functions
					//	&test_s_operators
					};

	for (int i = 0; i < 2; i++)
	{
		(*stack[i])();
		std::cout << "---------------------------\n\n";
	}
*/

	gettimeofday(&tv, NULL);
	after = tv.tv_sec * 1000000 + tv.tv_usec;
	execution_time = before - after;
	#if ORIGINAL == 1
		std::cout << "Execution time for STL version is ";
	#else
		std::cout << "Execution time for FT version is ";
	#endif
	std::cout << execution_time/1000000 << " secs and "
				<< execution_time%1000000 << " usecs\n";

	return 0;
}
