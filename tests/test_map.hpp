/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:33:07 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/05/03 15:57:00 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MAP_HPP
# define TEST_MAP_HPP

#if NAMESPACE == std
# include <map>
#endif

#if NAMESPACE == ft
# include <ft_map.hpp>
# endif

void test_m_constructors();
void test_m_iterators();
void test_m_capacity();
void test_m_access();
void test_m_modifiers();
void test_m_observers();
void test_m_operations();

#endif
