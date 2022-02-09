/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:51:39 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/09 10:53:36 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <ft_iterator_traits.hpp>
# include <ft_utils.hpp>
# include <ft_binary_search_tree.hpp>

namespace ft
{
	/* Reference: https://www.cplusplus.com/reference/map/map/ */

	template < class Key,                                 // map::key_type
			 class T,                                     // map::mapped_type
			 class Compare = less<Key>,                   // map::key_compare
			 class Alloc = allocator<pair<const Key,T> >  // map::allocator_type
			 >
	class map
	{
		public:

			/* TYPE DEFINITIONS */
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef pair<const key_type, mapped_type>			value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference   	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename ft::map_iterator<value_type>		iterator;
			typedef typename ft::map_iterator<const value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>		reverse_iterator;
			typedef typename ft::reverse_iterator<iconst_iterator>
				const_reverse_iterator;
			gypedef typename ft::iterator_traits<iterator>::difference_type
				difference_type;
			typedef size_t										size_type;
	

			/* CONSTRUCTORS
			 *
			 * Parameters:
			 * 				comp	:	If key_compare uses the default less (which
			 * 							has no state), this parameter is not relevant.
			 * 							Otherwise, check the documentation.
			 *
			 * 				alloc	:	If allocator_type is an instantiation of the
			 * 							default allocator (which has no state), this
			 * 							parameter is not relevant. Otherwise, y'know.
			 *
			 * 				first	:	Position of the first element in the range of
			 * 							elements to be copied.
			 *
			 * 				last	:	Position of the element beyond the last in the
			 * 							range of elements to be copied.
			 * 				x		:	The vector of which the constructed vector is
			 * 							to be a copy.
			 */

			// Default constructor
			explicit map (const key_compare& comp = key_compare(),
             				 const allocator_type& alloc = allocator_type())
			{}

			// Range constructor
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
			{}

			// Copy constructor
			map (const map& x)
			{}
	};
};
