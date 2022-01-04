/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:07:48 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/11/27 18:42:30 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <ft_iterator.hpp>
#include <ft_utils.hpp>

namespace ft
{
	/*
	 * Reference: https://www.cplusplus.com/reference/vector/vector/
	 */
	template <class T, class Alloc = std::allocator<T>>
	class vector
	{
	public:
		/* ATTRIBUTES
			  *
			  * Reference:
* https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-140
* https://stackoverflow.com/questions/18385418/c-meaning-of-a-statement-combining-typedef-and-typename
			  */

		/*  Member type allocator_type is the type of the allocator used
			 *  by the container, defined in vector as an alias of its second
			 *  template parameter (Alloc).
			 */
		typedef Alloc allocator_type;

		/* Member type value_type is the type of the elements in the
			 * container, defined in vector as an alias of its first
			 * template parameter (T).
			 */
		typedef T value_type;

		typedef size_t size_type;

		/* A type that provides a reference to an element stored in a vector
			 * Defaults to value_type&
			 */
		typedef typename allocator_type::reference reference;

		/* A type that provides a reference to a const element in a vector
			 * Defaults to const value_type&
			 */
		typedef typename allocator_type::const_reference const_reference;

		/* A type that provides a pointer to an element stored in a vector
			 * Defaults to value_type*
			 */
		typedef typename allocator_type::pointer pointer;

		/* A type that provides a pointer to a const element stored in a vector
			 * Defaults to const value_type*
			 */
		typedef typename allocator_type::const_pointer const_pointer;

		/* A random access iterator to value_type
			 * Convertible to const_iterator */
		typedef typename ft::vector_iterator<value_type>
			iterator;

		/* A random access iterator to const value_type */
		typedef typename ft::vector_iterator<value_type>
			const_iterator;

		typedef typename ft::reverse_iterator<vector_iterator<T>>
			reverse_iterator;

		typedef typename ft::reverse_iterator<vector_iterator<T>>
			const_reverse_iterator;

		/* Number of elements between two pointers */
		typedef typename NAMESPACE::iterator_traits<vector_iterator<T>>::difference_type
			difference_type;

		/* CONSTRUCTORS
			 *
			 * Reference: 
* https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-160#vector
* https://www.cplusplus.com/reference/vector/vector/vector/
* https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
* https://www.cplusplus.com/reference/memory/allocator/allocate/
			 *
			 * Parameters:
			 * 				alloc	:	The allocator class to use with this object.
			 * 				count	:	The number of elements in the constructed vector.
			 * 				value	:	The value of the elements in the constructed vector.
			 * 				source	:	The vector of which the constructed vector is to be a copy.
			 * 				first	:	Position of the first element in the range of elements to be copied.
			 * 				last	:	Position of the element beyond the last in the range of elements to be copied.
			 */

		// Specify the allocator to use. Default constructor
		explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _start(nullptr), _end(nullptr){};

		// Fill constructor
		explicit vector(size_type count, const value_type &value = value_type(),
						const allocator_type &alloc = allocator_type())
			: _alloc(alloc)
		{
			_start = _alloc.allocate(count); // allocate() returns a pointer to the initial element in the block of storage.
			pointer it = _start;

			while (count--)
			{
				_alloc.construct(it, value);
				it++;
			}

			_end = it;
		};

		// Range constructor
		// Only enable if InputIterator isn't integral type (!is_integral)
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type(),
			   typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = nullptr)
			: _alloc(alloc)
		{
			difference_type range = NAMESPACE::distance(first, last);
			_start = _alloc.allocate(range); // allocate() returns a pointer to the
			_last_element = _start;			 // initial element in the block of storage.
			while (range-- > 0)
				_alloc.construct(_last_element++, *first++);
		};

		// Copy constructor
		// MUST COPY SOURCE CONTENT WITH insert()
		vector(const vector &source)
			: _alloc(source._alloc), _start(source._start),
			  _last_element(source._last_element), _end(source._end){};

		/* GETTERS */
		allocator_type get_allocator() const { return (this->_alloc); }

		/* ITERATORS */
		iterator begin() { return (iterator(_start)); }
		const_iterator begin() const { return (iterator(_start)); }

		iterator end() { return (_last_element + 1); }
		const_iterator end() const { return (_last_element + 1); }

		/* CAPACITY */

		/* size(): Returns the number of elements in the vector */
		size_type size() const { return (this->_last_element - this->_start); }

		/* max_size(): Return maximum size */
		size_type max_size() const { return (_alloc.max_size()); }

		/* Resizes the container so that it contains n elements */
		void resize(size_type n, value_type val = value_type())
		{
			size_type prev_size = this->size();

			if (n > prev_size)
			{
				this->reserve(n);
				for (size_type i = prev_size; i < n; i++)
					_alloc.construct(_last_element++, val);
			}
			else if (n < prev_size)
			{
				for (size_type i = n; i < prev_size; i++)
					this->alloc->destroy(--_last_element);
			}
		}

		/* capacity(): Return size of allocated storage */
		size_type capacity() const { return (this->_end - this->_start); }

		/* Returns whether the vector is empty (i.e. whether its size is 0) */
		bool empty() const
		{
			return (this->size() == 0);
		}

		/* reserve(): Request a change in capacity */
		void reserve(size_type n)
		{
			if (this->capacity() >= n)
				return;

			T *new_start = _alloc.allocate(n); // new_start is initialized as a pointer to the first element
			size_type prev_size = this->size();
			size_type prev_capacity = this->capacity();

			for (size_type i = 0; i < prev_size; i++)
			{
				_alloc.construct(new_start + i, _start + i);
				_alloc.destroy(_start + i);
			}
			_alloc.deallocate(_start, prev_capacity);

			_start = new_start;
			_last_element = new_start + prev_size;
			_end = new_start + n;
		}

		/* MODIFIERS */

		/* Clear(): Removes all elements */
		void clear()
		{
			size_type i = this->size();
			while (i > 0)
			{
				_last_element--;
				_alloc.destroy(_last_element);
				i--;
			}
		}

		void push_back(const value_type &val)
		{
			/* test what happens when capacity < 1
				if (capacity == 0)
					reserve(1);
				*/
			if (_last_element == _end)
				reserve(this->capacity() * 2);
			_alloc.construct(_last_element, val);
			_last_element++;
		}

		/* Assign(): Assigns new contents to the vector, replacing its current contents
			 * and modifying its size accordingly */
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = nullptr)
		{
			this->clear();

			size_type n = NAMESPACE::distance(first, last);
			this->reserve(n);
			while (n--)
				_alloc.construct(_last_element++, *(first++));
		}

		void assign(size_type n, const value_type &val)
		{
			this->reserve(n);
			this->clear();

			while (n--)
				_alloc.construct(_last_element++, val);
		}

	private:
		allocator_type _alloc;
		pointer _start;
		pointer _last_element;
		pointer _end;
	};

	template <>
	class vector<bool>
	{
	};
};

#endif
