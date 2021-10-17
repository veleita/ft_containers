/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterators.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:28:04 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/17 18:43:41 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test_iterators.hpp>

void	test_iter_traits()
{
	typedef std::iterator_traits<int*> traits;
	
	std::cout << typeid(traits::difference_type).name() << '\n';
	std::cout << typeid(traits::value_type).name() << '\n';
	std::cout << typeid(traits::pointer).name() << '\n';
	std::cout << typeid(traits::reference).name() << '\n';
	std::cout << typeid(traits::iterator_category).name() << '\n';
}
