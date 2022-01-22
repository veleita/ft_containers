/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <1veleita1@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:26:22 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/01/22 08:02:10 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_stack.hpp"

void test_s_constructors()
{
    std::cout << "CONSTRUCTORS\n";
    {
        std::cout << "Default:\n";
        NAMESPACE::stack<int> default_stack;
    }

    {
        std::cout << "Pointer:\n";
        NAMESPACE::stack<int> *pointer_default_stack = 
			new NAMESPACE::stack<int>;
        delete pointer_default_stack;
    }
}
