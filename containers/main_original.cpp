/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_original.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:05:11 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/17 16:39:57 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test_utils.hpp>

int main()
{
	std::cout << std::boolalpha;

	test_is_integral();
	std::cout << std::endl;

	test_enable_if();
	std::cout << std::endl;

	test_pair();
	std::cout << std::endl;

	test_pair();
	std::cout << std::endl;

	test_make_pair();
	std::cout << std::endl;

	test_equal();
	std::cout << std::endl;

	return 0;
}
