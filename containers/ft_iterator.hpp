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

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator> // iterators
#include <vector>	// vector
#include <list>		// list

namespace ft
{

	/* ITERATORS */

	/* Iterator base class: https://www.cplusplus.com/reference/iterator/iterator/ */
	template <
		class Category, class T, class Distance = ptrdiff_t, class Pointer = T *,
		class Reference = T &>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	/* VECTOR ITERATOR
	* Implementation defined random-access iterator for vector class
	* https://www.cplusplus.com/reference/iterator/RandomAccessIterator/ */
	template <typename T>
	class vector_iterator
	{
	public:
		/*-- Iterator traits --*/
		typedef typename ft::iterator_traits<T>::value_type value_type;
		typedef typename ft::iterator_traits<T>::difference_type difference_type;
		typedef typename std::random_access_iterator_tag iterator_category;
		typedef typename ft::iterator_traits<T>::pointer pointer;
		typedef typename ft::iterator_traits<T>::reference reference;

	private:
		pointer _ptr;

	public:
		/*-- Coplien --*/
		vector_iterator() : _ptr(0) {}
		~vector_iterator() {}
		template <typename U>
		vector_iterator(const vector_iterator<U> &u)
		{
			_ptr = u.base();
		}

		template <typename U>
		vector_iterator &operator=(const vector_iterator<U> &u)
		{
			_ptr = u.base();
			return *this;
		}

		/*-- Getter --*/
		pointer base() const { return _ptr; }

		/*-- Constructor --*/
		explicit vector_iterator(T x) : _ptr(x) {}

		/*-- Operators overload --*/
		reference operator*() const { return *_ptr; }
		pointer operator->() const { return _ptr; }
		vector_iterator operator+(difference_type n) const { return vector_iterator(this->_ptr + n); }
		vector_iterator operator-(difference_type n) const { return vector_iterator(this->_ptr - n); }
		reference operator[](difference_type n) const { return *(*this + n); }

		vector_iterator &operator+=(difference_type n)
		{
			this->_ptr += n;
			return *this;
		}

		vector_iterator &operator-=(difference_type n)
		{
			this->_ptr -= n;
			return *this;
		}

		vector_iterator &operator++()
		{
			this->_ptr++;
			return *this;
		}

		vector_iterator operator++(int)
		{
			vector_iterator tmp(*this);
			operator++();
			return tmp;
		}

		vector_iterator &operator--()
		{
			this->_ptr--;
			return *this;
		}

		vector_iterator operator--(int)
		{
			vector_iterator tmp(*this);
			operator--();
			return tmp;
		}
	};

	template <typename U, typename V>
	bool operator==(const vector_iterator<U> &lhs, const vector_iterator<V> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename U, typename V>
	bool operator!=(const vector_iterator<U> &lhs, const vector_iterator<V> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename U, typename V>
	bool operator>(const vector_iterator<U> &lhs, const vector_iterator<V> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename U, typename V>
	bool operator<(const vector_iterator<U> &lhs, const vector_iterator<V> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename U, typename V>
	bool operator>=(const vector_iterator<U> &lhs, const vector_iterator<V> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename U, typename V>
	bool operator<=(const vector_iterator<U> &lhs, const vector_iterator<V> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename U, typename V>
	ptrdiff_t operator-(const vector_iterator<U> &lhs, const vector_iterator<V> &rhs)
	{
		return lhs.base() - rhs.base();
	}

	template <typename U>
	vector_iterator<U> operator+(typename vector_iterator<U>::difference_type n, const vector_iterator<U> &rhs)
	{
		return (vector_iterator<U>)(rhs.base() + n);
	}

	/* Predefined iterator
	 * Reverses the direction in which a random-access iterator iterates through a range
	 * https://www.cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/ */
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename NAMESPACE::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename NAMESPACE::iterator_traits<Iterator>::value_type value_type;
		typedef typename NAMESPACE::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename NAMESPACE::iterator_traits<Iterator>::pointer pointer;
		typedef typename NAMESPACE::iterator_traits<Iterator>::reference reference;

		reverse_iterator() : _baseIterator() {}
		explicit reverse_iterator(iterator_type it) : _baseIterator(it) {}
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : _baseIterator(rev_it.base()) {}

		iterator_type base() const { return (_baseIterator); }

		reference operator*() const
		{
			iterator_type prev = _baseIterator - 1;
			return (prev);
		}
		reference operator+(difference_type n) const { return (reverse_iterator(_baseIterator - n)); }
		reference operator-(difference_type n) const { return (reverse_iterator(_baseIterator + n)); }
		reference operator+=(difference_type n) const
		{
			_baseIterator -= n;
			return (*this);
		}
		reference operator-=(difference_type n) const
		{
			_baseIterator += n;
			return (*this);
		}
		reference &operator++() const
		{
			_baseIterator++;
			return (*this);
		}
		reference &operator++(int) const
		{
			reverse_iterator temp = *this;
			_baseIterator++;
			return temp;
		}
		reference &operator--() const
		{
			return --(*this);
		}
		reference &operator--(int) const
		{
			reverse_iterator temp = *this;
			_baseIterator--;
			return temp;
		}
		reference operator->() const { return &(operator*()); }
		reference operator[](difference_type n) const { return (this->base()[-n]); };

	private:
		iterator_type _baseIterator;
	};
};

#endif
