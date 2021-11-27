/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:42:27 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/11/27 17:59:19 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <test_vector.hpp>
#include <iostream>
#include <vector.hpp>

void test_vector()
{
	/* constructors */
	ft::vector<int> ft_default_vector;

	ft::vector<int> *ft_pointer_default_vector = new ft::vector<int>;
	delete ft_pointer_default_vector;

	ft::vector<int> ft_empty_vector(0);
	ft::vector<int> ft_fill_vector(10);
	ft::vector<int> ft_fill_vector_sized_and_valued(19, 42);

	int array[] = { 45, 87846, 12, 965, 5 };
	ft::vector<int> ft_vector_from_array (array,
			array + (sizeof(array) / sizeof(int)));

	/* reserve */
	ft::vector<int>::size_type sz;
	
	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	
	ft::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i < 100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
	  		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	/* assign */
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign (it, first.end() - 1); // the 5 central values of first

	int myints[] = {1776, 7, 4};
	third.assign (myints, myints + 3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';

/*	std::cout << "0 - vector(): [";
	for (ft::vector<int>::iterator it = v0.begin(); it != v0.end(); ++it)
			std::cout << " " << *it;
	std::cout << " ]\n";
	// Vector with 3 elements of default value 0
	ft::vector<int> v1(3);

	std::cout << "1 - vector(count): [";
		for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
			std::cout << " " << *it;
		std::cout << " ]\n";
		// Vector with 5 elements of value 2
		ft::vector<int> v2(5, 2);

	std::cout << "2 - vector(count, value): [";
	for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
	    std::cout << " " << *it;
	std::cout << " ]\n";
	// Vector with 4 elements of value 1 and with v2's allocator
	ft::vector<int> v3(4, 1, v2.get_allocator());

	std::cout << "3 - vector(count, value, alloc): [";
	for (ft::vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
	    std::cout << " " << *it;
	std::cout << " ]\n";

	// Vector copying elements in v3 in range 1 - 3
	ft::vector<int> v4(v3.begin() + 1, v3.begin() + 4);
	std::cout << "4 - vector(first, last): [";
	for (ft::vector<int>::iterator it = v4.begin(); it != v4.end(); ++it)
	    std::cout << " " << *it;
	std::cout << " ]\n";
	// Copy of v4
	ft::vector<int> v5(v2);

	std::cout << "5 - vector(source): [";
	for (ft::vector<int>::iterator it = v5.begin(); it != v5.end(); ++it)
	    std::cout << " " << *it;
	std::cout << " ]\n";
*/	
}
