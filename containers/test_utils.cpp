/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:04:03 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/17 16:50:49 by mzomeno-         ###   ########.fr       */
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
    std::cout << "class: " << std::is_integral<A>::value << '\n';
	std::cout << "enum: " << std::is_integral<E>::value << '\n';
	std::cout << "char: " << std::is_integral<char>::value << std::endl;
	std::cout << "int: " << std::is_integral<int>::value << std::endl;
	std::cout << "const int: " << std::is_integral<const int>::value << '\n';
	std::cout << "float: " << std::is_integral<float>::value << std::endl;
    std::cout << "bool: " << std::is_integral<bool>::value << '\n';

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
    std::pair<int, float> p1;
	std::cout << "Value-initialized: " << "(" << p1.first << ", " << p1.second << ")\n";

    std::pair<int, double> p2(42, 3.1415);
	std::cout << "Initialized with two values: " << "(" << p2.first << ", " << p2.second << ")\n";
    std::pair<char, int> p3(p2);
	std::cout << "Implicitly converted: " << "(" << p3.first << ", " << p3.second << ")\n";
}

void	test_make_pair()
{
	std::cout << "make_pair()" << std::endl;
    std::cout << "-----------------" << std::endl;
	std::pair <int,int> foo;
	std::pair <int,int> bar;

	foo = std::make_pair (10,20);
	bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}


bool is_palindrome(const std::string& s)
{
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}
 
void test(const std::string& s)
{
    std::cout << "\"" << s << "\" "
        << (is_palindrome(s) ? "is" : "is not")
        << " a palindrome\n";
}

void	test_equal()
{
	test("radar");
    test("hello");
}
