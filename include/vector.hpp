/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:07:48 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/11/15 16:00:39 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>
# include <iterators.hpp>

namespace ft
{
	/*
	 * Reference: https://www.cplusplus.com/reference/vector/vector/
	 */
	template < class T, class Alloc = std::allocator<T> >
		class vector
		{
			public:

			 /* ATTRIBUTES
			  *
			  * Reference:
			  * 			https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-140
			  * 			https://stackoverflow.com/questions/18385418/c-meaning-of-a-statement-combining-typedef-and-typename
			  */

			/*  Member type allocator_type is the type of the allocator used
			 *  by the container, defined in vector as an alias of its second
			 *  template parameter (Alloc).
			 */
			typedef Alloc			allocator_type;

			/* Member type value_type is the type of the elements in the
			 * container, defined in vector as an alias of its first
			 * template parameter (T).
			 */
			typedef T				value_type;

			typedef size_t			size_type;

			/* A type that provides a reference to an element stored in a vector
			 * Defaults to value_type&
			 */
			typedef typename		allocator_type::reference		reference;

			/* A type that provides a reference to a const element in a vector
			 * Defaults to const value_type&
			 */
			typedef typename		allocator_type::const_reference	const_reference;

			/* A type that provides a pointer to an element stored in a vector
			 * Defaults to value_type*
			 */
			typedef typename		allocator_type::pointer 		pointer;

			/* A type that provides a pointer to a const element stored in a vector
			 * Defaults to const value_type*
			 */
			typedef typename		allocator_type::const_pointer 	const_pointer;

			/* A random access iterator to value_type
			 * Convertible to const_iterator
			 * IMPLEMENT RANDOM_ACCESS_ITERATOR
			typedef typename		ft::vector_iterator				iterator;
			 */

			/* A random access iterator to const value_type
			 * IMPLEMENT RANDOM_ACCESS_ITERATOR
			typedef typename		ft::vector_iterator				const_iterator;
			 */

			/* IMPLEMENT RANDOM_ACCESS_ITERATOR
			typedef typename		ft::reverse_iterator<iterator>
				reverse_iterator;

			typedef typename		ft::reverse_iterator<const_iterator>
				const_reverse_iterator;
			 */

			/* Number of elements between two pointers
			typedef		ft::iterator_traits< iterator >::difference_type
				difference_type;
			*/


			/* CONSTRUCTORS
			 *
			 * Reference: 
			 * 				https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-160#vector
			 * 				https://www.cplusplus.com/reference/vector/vector/vector/
			 * 				https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
			 * 				https://www.cplusplus.com/reference/memory/allocator/allocate/
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
			explicit vector (const allocator_type& alloc = allocator_type()) 
				:	_alloc(alloc), _count(0), _start(nullptr), _end(nullptr)
			{};

			// Fill constructor
			explicit vector (size_type count, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
			:	_alloc(alloc), _count(count)
			{
				_start = _alloc.allocate(_count);	// allocate() returns a pointer to the initial element in the block of storage.
				pointer	it = _start;
				
				while (count--)
				{
					_alloc.construct(it, value);
					it++;
				}

				_end = it;
			};

			// Range constructor
			template <class InputIterator>
		         vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
				 :	_alloc(alloc)
				 {
					 (void)first;
					 (void)last;
					 /*
					 reinterpret_cast< difference_type >_count = ft::distance(first, last); 
					 _start = _alloc.allocate(_count);	// allocate() returns a pointer to the initial element in the block of storage.
					 _end = _start;
					 while (first != last)
						 _alloc.construct(_end++, *first++);
						 */
				 };

			// Copy constructor
			// MUST COPY SOURCE CONTENT WITH insert()
			vector (const vector& source)
				:	_alloc(source._alloc), _count(source._count), _start(source._start), _end(source._end)
			{};


			/* GETTERS */
			allocator_type get_allocator() const	{	return (this->_alloc);	}


			private:

				allocator_type	_alloc;
				size_type		_count;
				pointer			_start;
				pointer			_end;
		};
	
	template <>
		class vector<bool>
		{
		};
};

#endif
