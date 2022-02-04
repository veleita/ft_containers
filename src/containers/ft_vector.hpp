/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:07:48 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/04 18:22:05 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <cstring>
#include <ft_vector_iterator.hpp>
#include <ft_utils.hpp>

namespace ft
{
	/*
	 * Reference: https://www.cplusplus.com/reference/vector/vector/
	 */
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		/* TYPE DEFINITIONS */
		typedef Alloc allocator_type;
		typedef T value_type;
		typedef size_t size_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename ft::vector_iterator<value_type> iterator;
		typedef typename ft::vector_iterator<value_type> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<iterator>
			const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type
			difference_type;

		/* CONSTRUCTORS
			 *
			 * Parameters:
			 * 				alloc	:	The allocator class to use with this object.
			 * 				count	:	The number of elements in the constructed vector.
			 * 				value	:	The value of the elements in the constructed vector.
			 * 				source	:	The vector of which the constructed vector is to be a copy.
			 * 				first	:	Position of the first element in the range of elements to be copied.
			 * 				last	:	Position of the element beyond the last in the range of elements to be copied.
			 */

		// Default constructor
		explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc),
			  _start(nullptr),
			  _last_element(nullptr),
			  _end(nullptr)
		{
		}

		// Fill constructor
		explicit vector(size_type count, const value_type &value = value_type(),
						const allocator_type &alloc = allocator_type())
			: _alloc(alloc)
		{
			_start = _alloc.allocate(count); // allocate() returns a pointer to the initial element in the block of storage.
			_last_element = _start;

			while (count--)
			{
				_alloc.construct(_last_element, value);
				_last_element++;
			}

			_end = _last_element;
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
			_end = _last_element;
		};

		// Copy constructor
		vector(const vector &source)
			: _alloc(source._alloc), _start(nullptr),
			  _last_element(nullptr), _end(nullptr)
		{
			this->insert(this->begin(), source.begin(), source.end());
		};


		/* GETTERS */

		allocator_type get_allocator() const {	return (this->_alloc);	}

		value_type	*data() {	return (this->_start);	};

		/* ACCESS */

		reference operator[](size_type n)   {   return *(_start + n);   }
        const_reference operator[](size_type n) const
        {
           return *(_start + n);
        }

		/* at(): access specified element with bounds checking */
		reference at(size_type n)
		{
			/* throw std::out_of_range exception if n is out of range */
			return (operator[](n));
		}

		const_reference at(size_type n) const
		{
			/* throw std::out_of_range exception if n is out of range */
			return (operator[](n));
		}

		/* front(): access the first element */
		reference front()
		{
			return *_start;
		}

		const_reference front() const
		{
			return *_start;
		}

		/* back(): access the last element */
		reference back()
		{
			return *(_last_element - 1);
		}

		const_reference back() const
		{
			return *(_last_element - 1);
		}


		/* ITERATORS */

		iterator begin() { return (iterator(_start)); }
		const_iterator begin() const { return (iterator(_start)); }

		iterator end() { return (_last_element); }
		const_iterator end() const { return (_last_element); }

		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator rbegin() const
		{
			return (reverse_iterator(this->end()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->begin()));
		}
		const_reverse_iterator rend() const
		{
			return (reverse_iterator(this->begin()));
		}


		/* CAPACITY */

		/* size(): Returns the number of elements in the vector */
		size_type size() const { return (this->_last_element - this->_start); }

		/* max_size(): Return maximum size */
		size_type max_size() const { return (_alloc.max_size()); }

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
				_alloc.construct(new_start + i, *(_start + i));
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

		/* Insert(): Inserts elements */
		iterator insert(iterator pos, value_type const &value)
		{
			size_type relative_pos = pos - this->begin();
			if (!this->empty()) // make room for the new element
			{
				if (this->size() + 1 > this->capacity())
					reserve(this->capacity() * 2);
				std::memmove(_start + relative_pos + 1, _start + relative_pos,
					(this->size() - relative_pos) * sizeof(value_type));
			}
			else
				reserve(1);
			_alloc.construct(_start + relative_pos, value);
			_last_element++;
			return (_start + relative_pos);
		}

		void insert(iterator pos, size_type count, value_type const &value)
		{
			size_type relative_pos = pos - this->begin();
			if (!this->empty()) // make room for the new element
			{
				while (this->size() + count > this->capacity())
					reserve(this->capacity() * 2);
				std::memmove(_start + relative_pos + count, _start + relative_pos,
					(this->size() - relative_pos) * sizeof(value_type));
			}
			else
				reserve(count);
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_start + relative_pos + i, value);
			_last_element += count;
		}

		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last,
			typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
		{
			size_type relative_pos = pos - this->begin();
			size_type count = last - first;
			if (!this->empty()) // make room for the new element
			{
				while (this->size() + count > this->capacity())
					reserve(this->capacity() * 2);
				std::memmove(_start + relative_pos + count, _start + relative_pos,
					(this->size() - relative_pos) * sizeof(value_type));
			}
			else
				reserve(count);
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_start + relative_pos + i, *first++);
			_last_element += count;
		}

		/* erase(): erases elements */
		iterator erase( iterator pos )
		{
			size_type relative_pos = pos - this->begin();
			_alloc.destroy(_start + relative_pos);
			std::memmove(_start + relative_pos, _start + relative_pos + 1,
					(this->size() - relative_pos) * sizeof(value_type));
			_last_element--;
			return (_start + relative_pos);
		}

		iterator erase( iterator first, iterator last )
		{
			size_type count = last - first;
			size_type relative_pos = first - this->begin();
			for (size_type i = 0; i < count; i++)
				_alloc.destroy(_start + relative_pos + i);
			std::memmove(_start + relative_pos, _start + relative_pos + count,
					(this->size() - relative_pos) * sizeof(value_type));
			_last_element -= count;
			return (_start + relative_pos);
		}

		/* push_back(): adds element at the end of the vector */
		void push_back(const value_type &val)
		{
			/* throw exception when capacity < 1 */
			if (_last_element == _end)
				reserve(this->capacity() == 0 ? 1 : this->capacity() * 2);
			_alloc.construct(_last_element, val);
			_last_element++;
		}

		/* pop_back(): removes the element at the end of the vector */
		void pop_back()
		{
			/* throw exception when capacity < 1 */
			_alloc.destroy(_last_element);
			_last_element--;
		}

		/* resize(): changes the number of elements stored */
		void resize( size_type count, value_type value = value_type() )
		{
			if (count > this->size())
			{
				reserve(count);
				this->insert(this->end(), count - this->size(), value);
			}
			else if (count < this->size())
				this->erase(begin() + count, this->end());
		}

		/* assign(): Assigns new contents to the vector, replacing its current contents
			 * and modifying its size accordingly */
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = nullptr)
		{
			this->clear();
			this->insert(this->begin(), first, last);
		}

		void assign(size_type n, const value_type &val)
		{
			this->clear();
			this->insert(this->begin(), n, val);
		}

		/* swap(): swaps the contents */
		void swap( vector& other )
		{
			pointer _start_cpy 	  = this->_start;
			pointer _last_element_cpy = this->_last_element;
			pointer _end_cpy 	  = this->_end;

			this->_start = other._start;
			this->_last_element = other._last_element;
			this->_end = other._end;

			other._start = _start_cpy;
			other._last_element = _last_element_cpy;
			other._end = _end_cpy;
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
