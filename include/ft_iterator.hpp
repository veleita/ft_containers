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

	/* Implementation defined random-access iterator for vector class
	 * https://www.cplusplus.com/reference/iterator/RandomAccessIterator/ */
	template <class T>
	class vector_iterator
	{
	public:
		/* TYPEDEFS */
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type difference_type;
		typedef T *pointer;
		typedef T &reference;

		/* CONSTRUCTORS */
		vector_iterator() : _value(0) {}
		vector_iterator(pointer it) : _value(it) {}
		vector_iterator(vector_iterator &copy) : _value(copy._value) {}

		/* OPERATOR OVERLOADS */
		vector_iterator &operator=(const vector_iterator &rhs)
		{
			if (*this != rhs)
				this->_value = rhs._value;
			return (*this);
		}

		bool &operator==(const vector_iterator &rhs) { return (this->_value == rhs._value); }
		bool &operator!=(const vector_iterator &rhs) { return (this->_value != rhs._value); }

		reference &operator*() { return (*this->_value); }
		pointer &operator->() { return (this->_value); }
		reference &operator[](difference_type n) { return (*(this + n)); }

		vector_iterator &operator++()
		{
			this->_value++;
			return (*this);
		}
		vector_iterator &operator++(int)
		{
			vector_iterator &tmp = *this;
			this->_value++;
			return (tmp);
		}
		vector_iterator &operator--()
		{
			this->_value++;
			return (*this);
		}
		vector_iterator &operator--(int)
		{
			vector_iterator &tmp = *this;
			this->_value++;
			return (tmp);
		}

		vector_iterator &operator+(difference_type n) { return (this->_value + n); }
		vector_iterator &operator-(difference_type n) { return (this->_value - n); }
		vector_iterator &operator+(const vector_iterator &rhs)
		{
			return (this->_value + rhs._value);
		}
		vector_iterator &operator-(const vector_iterator &rhs)
		{
			return (this->_value - rhs._value);
		}

		bool &operator<(const vector_iterator &rhs) { return (this->_value < rhs._value); }
		bool &operator>(const vector_iterator &rhs) { return (this->_value > rhs._value); }
		bool &operator<=(const vector_iterator &rhs) { return (this->_value <= rhs._value); }
		bool &operator>=(const vector_iterator &rhs) { return (this->_value >= rhs._value); }

		vector_iterator &operator+=(difference_type n)
		{
			&(this->_value) = &(this->_value) + n;
			return (*this);
		}
		vector_iterator &operator-=(difference_type n)
		{
			&(this->_value) = &(this->_value) - n;
			return (*this);
		}

		/* DESTRUCTOR */
		~vector_iterator() {}

	private:
		/* ATTRIBUTES */
		pointer _value;
	};

	/* Predefined iterator
	 * Reverses the direction in which a random-access iterator iterates through a range
	 * https://www.cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/ */
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;

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
