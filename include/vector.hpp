/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:07:48 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/25 19:04:26 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{
	/*
	 * Reference:
	 * 			https://www.cplusplus.com/reference/vector/vector/
	 */
	template < class T, class Alloc = std::allocator<T> >
		class vector
		{
			/*
			 * An alias to the second template parameter (Alloc).
			 * Defaults to std::allocator<T>
			 */
			typedef Alloc	allocator_type;

			/*
			 * About the keyword 'explicit': https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
			 */

			/*
			 * Default constructor
			 */
			explicit vector (const allocator_type& alloc = allocator_type());
			
		}
};

#endif
