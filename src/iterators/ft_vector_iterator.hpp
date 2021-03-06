/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:15:24 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/03/04 09:36:34 by mzomeno-         ###   ########.fr       */
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

// Valid expressions
// 	*a = t Can be dereferenced as an lvalue if in a dereferenceable state


namespace ft
{

	/* Implementation defined random-access iterator for vector class:
	** cplusplus.com/reference/iterator/RandomAccessIterator/ */
	template <typename T>
	class vector_iterator
	{
	public:
		/* Type definitions */
		typedef typename iterator_traits<T>::value_type			value_type;
		typedef typename iterator_traits<T>::difference_type	difference_type;
		typedef typename iterator_traits<T>::pointer			pointer;
		typedef typename iterator_traits<T>::reference			reference;
		typedef typename iterator_traits<T>::iterator_category	iterator_category;

		/* Iterator content */
		pointer _elem;
		

		/* Default constructor */
		explicit vector_iterator(pointer elem = NULL)	// 	X a	
			: _elem(elem)
		{
		}

		/* Copy constructor */
		template <class U>
		vector_iterator(const vector_iterator<U> &copy)	// 	X b(a)
			: _elem(copy._elem)
		{
		}

		/* Assignation */
		template <class U>
		vector_iterator &operator=(const vector_iterator<U> &rhs)	// 	b = a
		{
			this->_elem = rhs._elem;
			return (*this);
		}

		/* Destructor */
		virtual ~vector_iterator() {}

		/* Logical operators */
		reference operator*(void) const { return *_elem; }	// 	*a
		pointer operator->(void) const { return _elem; }	// 	a->

//	*a++
//	*a--
		vector_iterator &operator++(void)	// 	++a
		{
			_elem++;
			return (*this);
		}

		vector_iterator operator++(int)	//	a++
		{
			vector_iterator saved_state = *this;
			operator++();
			return (saved_state);
		}

		vector_iterator &operator--(void)	// 	--a
		{
			_elem--;
			return (*this);
		}

		vector_iterator operator--(int)	//	a--
		{
			vector_iterator saved_state = *this;
			operator--();
			return (saved_state);
		}

		vector_iterator operator+(difference_type n) const	//	a + n
		{
			return (vector_iterator(_elem + n));
		}

		vector_iterator operator-(difference_type n) const	//	a - n
		{
			return (vector_iterator(_elem - n));
		}

		vector_iterator &operator+=(difference_type n)	//	a += n
		{
			_elem += n;
			return (*this);
		}

		vector_iterator &operator-=(difference_type n)	//	a -= n
		{
			_elem -= n;
			return (*this);
		}

		reference operator[](difference_type n) const	//	a[n]
		{
			return (*(operator+(n)));
		}

	};
};

// MAYBE THESE SHOULD GO ON THE BASE ITERATOR SO THEY ARE DEFINED FOR ANY
// TYPE OF ITERATOR. ITERATOR_TRAITS NEED THESE OPERATORS POR DISTANCE()

/* Comparison operators */
template <typename U, typename V>	// 	a == b
bool operator==(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() == rhs.operator->());
}

template <typename U, typename V>	// 	a != b
bool operator!=(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() != rhs.operator->());
}

template <typename U, typename V>	//	a < b
bool operator<(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() < rhs.operator->());
}

template <typename U, typename V>	//	a > b
bool operator<=(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() <= rhs.operator->());
}

template <typename U, typename V>	//	a <= b
bool operator>(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() > rhs.operator->());
}

template <typename U, typename V>	//	a >= b
bool operator>=(const ft::vector_iterator<U> &lhs, const ft::vector_iterator<V> &rhs)
{
	return (lhs.operator->() >= rhs.operator->());
}

/* Algorithmic operators */

template <typename U, typename V>	//	a - b
typename ft::vector_iterator<U>::difference_type operator-(const ft::vector_iterator<U>& lhs,
		const ft::vector_iterator<V>& rhs)
{
	return lhs.operator->() - rhs.operator->();
}

template <typename U, typename V>	//	n + a
ft::vector_iterator<U> operator+(typename ft::vector_iterator<U>::difference_type n,
		const ft::vector_iterator<U>& rhs)
{
	return (ft::vector_iterator<U>)(rhs.operator->() + n);
}

template <typename U, typename V>	//	n - a
ft::vector_iterator<U> operator-(typename ft::vector_iterator<U>::difference_type n,
		const ft::vector_iterator<U>& rhs)
{
	return (ft::vector_iterator<U>)(rhs.operator->() - n);
}

#endif
