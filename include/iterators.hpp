/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:15:24 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/17 18:45:30 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include <iterator>	// iterators
# include <vector>		// vector
# include <list>		// list

namespace ft
{

	/*
	 * ITERATOR TRAITS
	 *
	 * Reference:
	 * 				- https://www.cplusplus.com/reference/iterator/iterator_traits/
	 * 				- https://en.cppreference.com/w/cpp/iterator/iterator_traits
	 */
	template <class I>
		struct iterator_traits
		{
			typedef typename I::difference_type		difference_type;
			typedef typename I::value_type			value_type;
			typedef typename I::pointer 			pointer;
			typedef typename I::reference 			reference;
			typedef typename I::iterator_category 	iterator_category;
		};

	template <class T>
		struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t 					difference_type;
		typedef T 								value_type;
		typedef T* 								pointer;
		typedef T& 								reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T>
		struct iterator_traits<const T*>
	{
		typename std::ptrdiff_t 					difference_type;
		typename T 									value_type;
		typename const T* 							pointer;
		typename const T& 							reference;
		typename std::random_access_iterator_tag	iterator_category;
	};

};

#endif
