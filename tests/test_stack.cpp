/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <1veleita1@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:26:22 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/04 19:50:52 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_stack.hpp"

template <class T>
static void print_stack_info(NAMESPACE::stack<T> &stk)
{
    std::cout << "Empty stack: " << stk.empty() << std::endl;
    std::cout << "Stack size: " << stk.size() << std::endl;
    std::cout << "Stack content: ";
	while (stk.empty() == false)
	{
		std::cout << stk.top();
		stk.pop();
		if (stk.size() > 0)
			std::cout << ", ";
	}
}

void test_s_constructors()
{
    std::cout << "CONSTRUCTORS\n";
    {
        std::cout << "Default:\n";
        NAMESPACE::stack<int> default_stack;
		print_stack_info(default_stack);
    }

    {
        std::cout << "Pointer:\n";
        NAMESPACE::stack<int> *pointer_default_stack = 
			new NAMESPACE::stack<int>;
		print_stack_info(*pointer_default_stack);
        delete pointer_default_stack;
    }
}

void test_s_member_functions()
{
    std::cout << "MEMBER FUNCTIONS\n";
	NAMESPACE::stack<int> stk;
    std::cout << "Empty stack? " << stk.empty() << std::endl;
	NAMESPACE::stack<int> stk_filled;
	for (unsigned int i = 0; i < 42; i++)
		stk_filled.push(rand() % 10);
	print_stack_info(stk_filled);
	NAMESPACE::stack<int> stk_big;
	for (unsigned int i = 0; i < 420000; i++)
		stk_filled.push(rand() % 10);
	print_stack_info(stk_filled);
}

void test_s_operators()
{
	std::cout << "== and !=\n";
	NAMESPACE::stack<int> stk;
	NAMESPACE::stack<int> stk_2;
    for (int i = 0; i < 42; i++)
    {
		stk.push(i);
        stk_2.push(i * 2);
	}
	std::cout << (stk == stk_2) << std::endl;
	std::cout << (stk != stk_2) << std::endl;
	
	NAMESPACE::stack<int> stk_3;
    for (int i = 0; i < 42; i++)
		stk_3.push(i);
	std::cout << (stk == stk_3) << std::endl;
	std::cout << (stk != stk_3) << std::endl;
}	
