/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:15:24 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/11/12 13:44:02 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include <iterator>	// iterators
# include <vector>		// vector
# include <list>		// list

namespace ft
{
//	struct random_access_iterator_tag {};

	/*
	 * ITERATOR TRAITS
	 *
	 * Reference:
	 * 				- https://www.cplusplus.com/reference/iterator/iterator_traits/
	 * 				- https://en.cppreference.com/w/cpp/iterator/iterator_traits
	 * 				- https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/iterator/iterator_tags.html
	 */

	/* Definition + specializations */
	template <class I>
		struct iterator_traits
		{
			/* Result of subtracting one iterator from another */
			typedef typename I::difference_type		difference_type;

			/* Type of the element the iterator points at */
			typedef typename I::value_type			value_type;

			/* *value_type */
			typedef typename I::pointer 			pointer;

			/* &value_type */
			typedef typename I::reference 			reference;

			/* The category of the iterator, can be one of these:
			 *
			 * 	- input_iterator_tag	- output_iterator_tag
			 * 	- forward_iterator_tag	- bidirectional_iterator_tag
			 * 	- random_access_iterator_tag (the coolest)
			 */
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
		typedef std::ptrdiff_t 					difference_type;
		typedef T 									value_type;
		typedef const T* 							pointer;
		typedef const T& 							reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	/* Methods */
	template< class InputIt >
		typename std::iterator_traits<InputIt>::difference_type
		distance( InputIt first, InputIt last )
		{
			typename std::iterator_traits<InputIt>::difference_type result = 0;
    		while (first != last)
			{
				++first;
				++result;
			}
			return result;
		};
	
	/*
	 * ITERATORS
	 *
	 * Reference:
	 * 				- https://www.cplusplus.com/reference/iterator/iterator/
	 * 				- https://www.cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/
	 */
/*
	template< 
		class Category, class T, class Distance = ptrdiff_t, class Pointer = T*,
		class Reference = T&
			> struct iterator
			{
                typedef T           value_type;
                typedef Distance    difference_type;
                typedef Pointer     pointer;
                typedef Reference   reference;
                typedef Category    iterator_category;
			};
*/
	template <class Iterator>
		class reverse_iterator
		{
			public:
            	typedef Iterator    												iterator_type;
            	typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
            	typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
            	typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
            	typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
            	typedef typename ft::iterator_traits<Iterator>::reference			reference;

				reverse_iterator() : _baseIterator()	{}
				explicit reverse_iterator (iterator_type it) : _baseIterator(it)	{}
				template <class Iter>
					reverse_iterator (const reverse_iterator<Iter>& rev_it) : _baseIterator(rev_it.base())	{}
				
				iterator_type base() const	{	return(_baseIterator);	}
				
				reference operator*() const
				{
					iterator_type prev = _baseIterator - 1;
					return (prev);
				}
				reference operator+(difference_type n) const	{	return (reverse_iterator(_baseIterator - n));	}
				reference operator-(difference_type n) const	{	return (reverse_iterator(_baseIterator + n));	}
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
				reference operator->() const	{	return &(operator*());	}
				reference operator[](difference_type n) const	{	return (this->base()[-n]);	};

			private:
				iterator_type	_baseIterator;
		};
};

#endif
