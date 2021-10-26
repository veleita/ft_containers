/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:03:11 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/26 17:09:59 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test_vector.hpp>

void test_vector()
{
	std::cout << "CONSTRUCTORS\n";
	std::cout << "----------------------------------------------\n";

	// Empty vector
	std::vector<int> v0;
	std::cout << "0 - vector(): [";
	for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); ++it)
	    std::cout << " " << *it;
	std::cout << " ]\n";
	
	// Vector with 3 elements of default value 0
	std::vector<int> v1(3);
	std::cout << "1 - vector(count): [";
	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	    std::cout << " " << *it;
	std::cout << " ]\n";
	
	// Vector with 5 elements of value 2
	std::vector<int> v2(5, 2);
	std::cout << "2 - vector(count, value): [";
	for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
	    std::cout << " " << *it;
	std::cout << " ]\n";

	// Vector with 4 elements of value 1 and with v2's allocator
	std::vector<int> v3(4, 1, v2.get_allocator());
	std::cout << "3 - vector(count, value, alloc): [";
	for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
	    std::cout << " " << *it;
	std::cout << " ]\n";

	// Vector copying elements in v3 in range 1 - 3
	std::vector<int> v4(v3.begin() + 1, v3.begin() + 4);
	std::cout << "4 - vector(first, last): [";
	for (std::vector<int>::iterator it = v4.begin(); it != v4.end(); ++it)
	    std::cout << " " << *it;
	std::cout << " ]\n";

	// Copy of v4
	std::vector<int> v5(v4);
	std::cout << "5 - vector(source): [";
	for (std::vector<int>::iterator it = v5.begin(); it != v5.end(); ++it)
	    std::cout << " " << *it;
	std::cout << " ]\n";

}
