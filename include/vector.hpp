/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:07:48 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/26 13:49:54 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{
	/*
	 * Reference: https://www.cplusplus.com/reference/vector/vector/
	 */
	template < class T, class Alloc = std::allocator<T> >
		class vector
		{
			 /* ATTRIBUTES */

			/*
			 *  Member type allocator_type is the type of the allocator used
			 *  by the container, defined in vector as an alias of its second
			 *  template parameter (Alloc).
			 */
			typedef Alloc			allocator_type;

			/* Member type value_type is the type of the elements in the
			 * container, defined in vector as an alias of its first
			 * template parameter (T).
			 */
			typedef T				value_type;

			typedef unsigned int	size_type;


			/* CONSTRUCTORS
			 *
			 * Reference: 
			 * 				https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-160#vector
			 * 				https://www.cplusplus.com/reference/vector/vector/vector/
			 * 				https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
			 *
			 * Parameters:
			 * 				alloc		:	The allocator class to use with this object.
			 * 				count		:	The number of elements in the constructed vector.
			 * 				value		:	The value of the elements in the constructed vector.
			 * 				source		:	The vector of which the constructed vector is to be a copy.
			 * 				first		:	Position of the first element in the range of elements to be copied.
			 * 				last		:	Position of the element beyond the last in the range of elements to be copied.
			 */
			
			// Specify the allocator to use. Default constructor
			explicit vector (const allocator_type& alloc = allocator_type());

			// Fill constructor
			explicit vector (size_type count, const value_type& value = value_type(),
                 const allocator_type& alloc = allocator_type());

			// Range constructor
			template <class InputIterator>
		         vector (InputIterator first, InputIterator last,
        	         const allocator_type& alloc = allocator_type());

			// Copy constructor
			vector (const vector& source);
		}
};

#endif
