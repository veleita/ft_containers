/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:15:24 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/11/27 18:52:14 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iterator> // iterators
#include <vector>	// vector
#include <list>		// list

#include <ft_iterator.hpp>
#include <ft_iterator_traits.hpp>
#include <ft_reverse_iterator.hpp>

namespace ft
{

	/* Implementation defined random-access iterator for vector class:
	** https://www.cplusplus.com/reference/iterator/RandomAccessIterator/ */
	template <typename T>
	class vector_iterator
	{
	public:
		/* Type definitions */
		typedef typename ft::iterator<std::random_access_iterator_tag, T>
			base_iterator;
		typedef typename ft::iterator_traits<base_iterator>::iterator_category
			iterator_category;
		typedef typename ft::iterator_traits<base_iterator>::value_type
			value_type;
		typedef typename ft::iterator_traits<base_iterator>::difference_type
			difference_type;
		typedef T *pointer;
		typedef T &reference;

		/* Default construtor */
		vector_iterator(void)
			: _elem(0)
		{
		}

		/* Constructor from pointer */
		vector_iterator(pointer elem)
			: _elem(elem)
		{
		}

		/* Copy constructor */
		vector_iterator(const vector_iterator &copy)
			: _elem(copy._elem)
		{
		}

		/* Assignation */
		vector_iterator &operator=(const vector_iterator &rhs)
		{
			this->_elem = rhs._elem;
			return (*this);
		}

		/* Destructor */
		virtual ~vector_iterator() {}

		/* Logical perators */
		reference operator*(void) const { return *_elem; }
		pointer operator->(void) const { return _elem; }

		vector_iterator &operator++(void)
		{
			_elem++;
			return (*this);
		}

		vector_iterator operator++(int)
		{
			vector_iterator saved_state = *this;
			operator++();
			return (saved_state);
		}

		vector_iterator &operator--(void)
		{
			_elem--;
			return (*this);
		}

		vector_iterator operator--(int)
		{
			vector_iterator saved_state = *this;
			operator--();
			return (saved_state);
		}

		vector_iterator operator+(difference_type n) const
		{
			return (_elem + n);
		}

		vector_iterator operator-(difference_type n) const
		{
			return (_elem - n);
		}

		vector_iterator &operator+=(difference_type n)
		{
			_elem += n;
			return (*this);
		}

		vector_iterator &operator-=(difference_type n)
		{
			_elem -= n;
			return (*this);
		}

		reference operator[](difference_type n) const
		{
			return (*(operator+(n)));
		}

	private:
		pointer _elem;
	};
};

/* Comparison perators */

template <typename U, typename V>
bool operator==(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() == rhs.operator->());
}

template <typename U, typename V>
bool operator!=(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() != rhs.operator->());
}

template <typename U, typename V>
bool operator<(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() < rhs.operator->());
}

template <typename U, typename V>
bool operator<=(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() <= rhs.operator->());
}

template <typename U, typename V>
bool operator>(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() > rhs.operator->());
}

template <typename U, typename V>
bool operator>=(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() >= rhs.operator->());
}

#endif