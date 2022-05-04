/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:04:03 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/05/04 16:07:19 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

/* IS_INTEGRAL */

template <class T>
T f(T i)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	return i;
}

void test_is_integral()
{
	std::cout << "is_integral()" << std::endl;
	std::cout << "-----------------" << std::endl
			  << std::endl;
	std::cout << "class: " << NAMESPACE::is_integral<A>::value << '\n';
	std::cout << "enum: " << NAMESPACE::is_integral<E>::value << '\n';
	std::cout << "char: " << NAMESPACE::is_integral<char>::value << std::endl;
	std::cout << "int: " << NAMESPACE::is_integral<int>::value << std::endl;
	std::cout << "const int: " << NAMESPACE::is_integral<const int>::value << '\n';
	std::cout << "float: " << NAMESPACE::is_integral<float>::value << std::endl;
	std::cout << "bool: " << NAMESPACE::is_integral<bool>::value << '\n';

	f(123); // If the arguments for f() are not integrals, code does not compile
}

/* ENABLE_IF */

// The return type (bool) is only valid if T is an integral type:
template <class T>
typename NAMESPACE::enable_if<NAMESPACE::is_integral<T>::value, bool>::type
is_odd(T i) { return bool(i % 2); }

void test_enable_if()
{
	std::cout << "enable_if()" << std::endl;
	std::cout << "-----------------" << std::endl;
	int i = 3; // code does not compile if type of i is not integral
	std::cout << "i is odd: " << is_odd(i) << std::endl;
}

/* PAIR */

void test_pair()
{
	std::cout << "pair< , >" << std::endl;
	std::cout << "-----------------" << std::endl;
	NAMESPACE::pair<int, float> p1;
	std::cout << "Value-initialized: "
			  << "(" << p1.first << ", " << p1.second << ")\n";

	NAMESPACE::pair<int, double> p2(42, 3.1415);
	std::cout << "Initialized with two values: "
			  << "(" << p2.first << ", " << p2.second << ")\n";
	NAMESPACE::pair<char, int> p3(p2);
	std::cout << "Implicitly converted: "
			  << "(" << p3.first << ", " << p3.second << ")\n";
}

/* MAKE_PAIR */

void test_make_pair()
{
	std::cout << "make_pair()" << std::endl;
	std::cout << "-----------------" << std::endl;
	NAMESPACE::pair<int, int> foo;
	NAMESPACE::pair<int, int> bar;

	foo = NAMESPACE::make_pair(10, 20);
	bar = NAMESPACE::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}

/* EQUAL */

bool is_palindrome(const std::string &s)
{
	return NAMESPACE::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

void test(const std::string &s)
{
	std::cout << "\"" << s << "\" "
			  << (is_palindrome(s) ? "is" : "is not")
			  << " a palindrome\n";
}

void test_equal()
{
	std::cout << "equal()" << std::endl;
	std::cout << "-----------------" << std::endl;
	test("radar");
	test("hello");
}

/* LEXIICOGRAPHICAL_COMPARE */

bool mycomp(char c1, char c2)
{
	return std::tolower(c1) < std::tolower(c2);
}

void test_lexicographical_compare()
{
	char foo[] = "Apple";
	char bar[] = "apartment";

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << NAMESPACE::lexicographical_compare(foo, foo + 5, bar, bar + 9) << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << NAMESPACE::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp) << '\n';

	std::vector<double> first(4, 100);
	std::vector<int> second(4, 100);

	std::cout << "Comparing different vector types: " << NAMESPACE::lexicographical_compare(first.begin(), first.end(), second.begin(), second.end())
			  << '\n';

	std::list<int> lst(4, 100);

	std::cout << "Comparing different container types: " << NAMESPACE::lexicographical_compare(first.begin(), first.end(), lst.begin(), lst.end())
			  << '\n';
}


/* RED_BLACK_TREE 

ft::Node<>	*search(ft::Node<>	*root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->key == key)
		return root;
   
	// Key is greater than root's key
   	if (root->key < key)
   		return search(root->right, key);

	// Key is smaller than root's key
   	return search(root->left, key);
}

void test_rb_tree()
{
	RedBlackTree rb_tree<>;
}

*/
