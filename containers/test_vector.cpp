/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:03:11 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/11/27 17:38:19 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <test_vector.hpp>
#include <iterator>
#include <vector>
#include <iostream>

void test_vector()
{
	/* constructors */
	std::vector<int> ft_default_vector;

	std::vector<int> *ft_pointer_default_vector = new std::vector<int>;
	delete ft_pointer_default_vector;

	std::vector<int> ft_empty_vector(0);
	std::vector<int> ft_fill_vector(10);
	std::vector<int> ft_fill_vector_sized_and_valued(19, 42);

	int array[] = { 45, 87846, 12, 965, 5 };
	std::vector<int> ft_vector_from_array (array, array + sizeof(array) / sizeof(int));

	/* reserve */
	std::vector<int>::size_type sz;
	
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i < 100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	
	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
	  		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	/* assign */
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it = first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
}
