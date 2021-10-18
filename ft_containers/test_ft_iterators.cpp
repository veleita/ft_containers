/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_iterators.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:32:07 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/18 13:33:16 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test_iterators.hpp>
#include <iterators.hpp>

// Look at this marvelous test function that works for any given container!!
template<class BidirIt>
	void my_reverse(BidirIt first, BidirIt last)
	{
		typename ft::iterator_traits<BidirIt>::difference_type n = ft::distance(first, last);
		for (--n; n > 0; n -= 2)
		{
			typename std::iterator_traits<BidirIt>::value_type tmp = *first;
			*first++ = *--last;
			*last = tmp;
		}
	}

void	test_iter_traits()
{
	typedef ft::iterator_traits<int*> traits;
	
	std::cout << typeid(traits::difference_type).name() << '\n';
	std::cout << typeid(traits::value_type).name() << '\n';
	std::cout << typeid(traits::pointer).name() << '\n';
	std::cout << typeid(traits::reference).name() << '\n';
	std::cout << typeid(traits::iterator_category).name() << '\n';

// Works for vectors!
	std::vector<int> vec (5, 0);
	vec[0] = 1;
	vec[1] = 2;
	vec[2] = 3;
	vec[3] = 4;
	vec[4] = 5;
	for (int n = 0; n < 5; n++)
		std::cout << vec[n] << ' ';
	my_reverse(vec.begin(), vec.end());
	for (int n = 0; n < 5; n++)
		std::cout << vec[n] << ' ';
	std::cout << '\n';

// And lists!
	int myints[] = {1,2,3,4,5};
	std::list<int> lst (myints, myints + sizeof(myints) / sizeof(int) );
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	my_reverse(lst.begin(), lst.end());
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';

// And arrays! What a wonder!
	int arr[] = {1, 2, 3, 4, 5};
	for (int i = 0 ; i < 5; i++)
		std::cout << arr[i] << ' ';
	my_reverse(arr, arr + 5);
	for (int i = 0 ; i < 5; i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}
