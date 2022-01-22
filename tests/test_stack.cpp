/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <1veleita1@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:26:22 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/01/22 08:26:16 by mzomeno-         ###   ########.fr       */
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
    {
        std::cout << "Empty:\n";
	}
	{
        std::cout << "Size:\n";
	}
	{
        std::cout << "Top:\n";
	}
	{
        std::cout << "Push:\n";
	}
	{
        std::cout << "Pop:\n";
	}
}
