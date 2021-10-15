/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:45:21 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/15 19:14:27 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test_utils.hpp>

template <class T>
T f(T i)
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    return i;
}

void	test_is_integral()
{
	std::cout << "is_integral()" << std::endl;
    std::cout << "-----------------" << std::endl << std::endl;
    std::cout << "class: " << ft::is_integral<A>::value << '\n';
	std::cout << "enum: " << ft::is_integral<E>::value << '\n';
	std::cout << "char: " << ft::is_integral<char>::value << std::endl;
	std::cout << "int: " << ft::is_integral<int>::value << std::endl;
	std::cout << "const int: " << ft::is_integral<const int>::value << '\n';
	std::cout << "float: " << ft::is_integral<float>::value << std::endl;
    std::cout << "bool: " << ft::is_integral<bool>::value << '\n';

	f(123);		// If the arguments for f() are not integrals, code does not compile

}

// The return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

void	test_enable_if()
{
	std::cout << "enable_if()" << std::endl;
    std::cout << "-----------------" << std::endl;
	int i = 3;    // code does not compile if type of i is not integral
	std::cout << std::boolalpha;
	std::cout << "i is odd: " << is_odd(i) << std::endl;
}

void	test_pair()
{
	std::cout << "pair< , >" << std::endl;
    std::cout << "-----------------" << std::endl;
    ft::pair<int, float> p1;
	std::cout << "Value-initialized: " << "(" << p1.first << ", " << p1.second << ")\n";

    ft::pair<int, double> p2(42, 3.1415);
	std::cout << "Initialized with two values: " << "(" << p2.first << ", " << p2.second << ")\n";
    ft::pair<char, int> p3(p2);
	std::cout << "Implicitly converted: " << "(" << p3.first << ", " << p3.second << ")\n";
}

void	test_make_pair()
{
	std::cout << "make_pair()" << std::endl;
    std::cout << "-----------------" << std::endl;
	ft::pair <int,int> foo;
	ft::pair <int,int> bar;

	foo = ft::make_pair (10,20);
	bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}
