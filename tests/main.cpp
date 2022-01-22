/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:05:11 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/01/22 06:48:50 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "test_utils.hpp"
#include "test_iterator.hpp"
#include "test_vector.hpp"

typedef void (*test)(void);

int main()
{
	#if ORIGINAL == 1
		std::cout << "Executing STL version...\n";
	#else
		std::cout << "Executing FT version...\n";
	#endif

	struct timeval	tv;
	unsigned long	before;
	unsigned long	after;
	unsigned long	execution_time;

	std::cout << std::boolalpha;

	std::cout << "UTILS TEST\n";
	std::cout << "===========================\n\n";
	test utils[1] = {
				&test_is_integral,
			//	&test_enable_if,
			//	&test_pair,
			//	&test_make_pair,
			//	&test_equal,
			//	&test_lexicographical_compare
			};

	gettimeofday(&tv, NULL);
	before = tv.tv_sec * 1000000 + tv.tv_usec;

	for (int i = 0; i < 1; i++)
	{
		(*utils[i])();
		std::cout << "---------------------------\n\n";
	}
	gettimeofday(&tv, NULL);
	after = tv.tv_sec * 1000000 + tv.tv_usec;
	execution_time = before - after;
    std::cout << " Execution time for utils is "
				<< execution_time/1000000 << " seconds\n";


	std::cout << "\nITERATOR TEST\n";
	std::cout << "===========================\n";
	test iterator[1] = {&test_iter_traits};

	gettimeofday(&tv, NULL);
	before = tv.tv_sec * 1000000 + tv.tv_usec;

	for (int i = 0; i < 1; i++)
	{
		(*iterator[i])();
		std::cout << "---------------------------\n\n";
	}
	gettimeofday(&tv, NULL);
	after = tv.tv_sec * 1000000 + tv.tv_usec;
	execution_time = before - after;
    std::cout << " Execution time for iterators is "
				<< execution_time/1000000 << " seconds\n";


	std::cout << "\nVECTOR TEST\n";
	std::cout << "===========================\n";
	test vector[5] = {
						&test_v_constructors,
						&test_v_iterators,
                      	&test_v_access,
						&test_v_capacity,
						&test_v_modifiers
					};

	gettimeofday(&tv, NULL);
	before = tv.tv_sec * 1000000 + tv.tv_usec;

	for (int i = 0; i < 5; i++)
	{
		(*vector[i])();
		std::cout << "---------------------------\n\n";
	}
	gettimeofday(&tv, NULL);
	after = tv.tv_sec * 1000000 + tv.tv_usec;
	execution_time = before - after;
    std::cout << " Execution time for vector is "
				<< execution_time/1000000 << " seconds\n";

	return 0;
}
