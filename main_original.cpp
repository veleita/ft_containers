/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:20:19 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/12 18:51:54 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits>

/*
 *	is_integral test

class A {};
 
enum E : int {};
 
template <class T>
T f(T i)
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    return i;
}
*/

/*
 *	enable_if test
*/

// The return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}


int main()
{
	/*
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
    
	f(123);		// If the arguments for f() are not integrals, code does not compile
    
	std::cout << "enable_if()" << std::endl;
    std::cout << "-----------------" << std::endl;
	int i = 3;    // code does not compile if type of i is not integral

	std::cout << std::boolalpha;
	std::cout << "i is odd: " << is_odd(i) << std::endl;
    */
 
	std::cout << "pair< , >" << std::endl;
    std::cout << "-----------------" << std::endl;
	

    std::pair<int, float> p1;
	std::cout << "Value-initialized: " << "(" << p1.first << ", " << p1.second << ")\n";
 
    std::pair<int, double> p2(42, 3.1415);
	std::cout << "Initialized with two values: " << "(" << p2.first << ", " << p2.second << ")\n";

    std::pair<char, int> p3(p2);
	std::cout << "Implicitly converted: " << "(" << p3.first << ", " << p3.second << ")\n";
	
	std::cout << std::endl;

	return (0);
}
