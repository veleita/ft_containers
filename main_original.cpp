/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:20:19 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/12 16:57:35 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits>

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
    std::cout << "class: " << std::is_integral<A>::value << '\n';
	std::cout << "enum: " << std::is_integral<E>::value << '\n';
	std::cout << "char: " << std::is_integral<char>::value << std::endl;
	std::cout << "int: " << std::is_integral<int>::value << std::endl;
	std::cout << "const int: " << std::is_integral<const int>::value << '\n';
	std::cout << "float: " << std::is_integral<float>::value << std::endl;
    std::cout << "bool: " << std::is_integral<bool>::value << '\n';
    
	f(123);
    
	std::cout << std::endl;

	return (0);
}
