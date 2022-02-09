/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:51:39 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/08 12:22:18 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <ft_iterator_traits.hpp>
# include <ft_utils.hpp>

namespace ft
{
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
			typedef typename ft::iterator_traits<iterator>::difference_type
				difference_type;
			typedef size_t										size_type;
	};
};
