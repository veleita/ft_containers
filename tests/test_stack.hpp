/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <1veleita1@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:48:14 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/04 19:51:34 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_STACK_HPP
#define TEST_STACK_HPP

# include <iostream>

# if NAMESPACE == std
#  include <stack>
# endif

# if NAMESPACE == ft
#  include <ft_stack.hpp>
# endif

void test_s_constructors();
void test_s_member_functions();
void test_s_operators();

#endif
