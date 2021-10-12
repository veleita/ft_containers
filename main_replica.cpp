/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_replica.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:33:07 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/12 16:57:12 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits>
#include "utils.hpp"

/*
**	is_integral test
*/

class A {};
 
enum E : int {};
 
template <class T>
T f(T i)
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    return i;
}

int main()
{
    std::cout << "is_integral()" << std::endl;
    std::cout << "-----------------" << std::endl << std::endl;
    std::cout << std::boolalpha;
    std::cout << "class: " << ft::is_integral<A>::value << '\n';
	std::cout << "enum: " << ft::is_integral<E>::value << '\n';
	std::cout << "char: " << ft::is_integral<char>::value << std::endl;
	std::cout << "int: " << ft::is_integral<int>::value << std::endl;
	std::cout << "const int: " << ft::is_integral<const int>::value << '\n';
	std::cout << "float: " << ft::is_integral<float>::value << std::endl;
    std::cout << "bool: " << ft::is_integral<bool>::value << '\n';
    
	f(123);
    
	std::cout << std::endl;

	return (0);
}
