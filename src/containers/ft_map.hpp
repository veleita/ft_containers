/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:51:39 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/25 16:33:35 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <ft_iterator_traits.hpp>
# include <ft_utils.hpp>
# include <ft_red_black_tree.hpp>

namespace ft
{
	/* Reference: https://www.cplusplus.com/reference/map/map/ */

	template < class key_type,                                 		// map::key_type
			 class T,                                     			// map::mapped_type
			 class Compare = std::less<key_type>,					// map::key_compare
			 class Alloc = allocator<ft::pair<const key_type,T> >	// map::allocator_type
			 >
	class map
	{
		public:

			/* TYPE DEFINITIONS */
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference   	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::red_black_tree<value_type, key_compare>	tree_type;
			typedef typename tree_type::iterator				iterator;
			typedef typename tree_type::const_iterator			const_iterator;
			typedef typename ft::reverse_iterator<iterator>		reverse_iterator;
			typedef typename ft::reverse_iterator<iconst_iterator>
				const_reverse_iterator;
			gypedef typename ft::iterator_traits<iterator>::difference_type
				difference_type;
			typedef size_t										size_type;
	
			class value_compare
			{
			};

		private:
			
			/* MEMBER ATTRIBUTES */
			allocator_type	_alloc;
			key_compare		_k_comp;
			value_compare	_v_comp;
			tree_type		_tree;


		
		public:

			/* COPLEN'S FUNCTIONS
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

			 // WHICH VARIABLES ARE GOING TO NEED TO FILL?

			explicit map (const key_compare& comp = key_compare(),
             				 const allocator_type& alloc = allocator_type())
			{}

			template <class InputIterator>
				map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
			{}

			map (const map& x)
			{}

			map& operator=( const map& other )
			{}

			~map()
			{}
			 */


			/* ACCESS */

			allocator_type get_allocator() const
			{	return this->_alloc;	}

			/* BST SEARCH
			mapped_type& at( const key_type& key )
			{}

			const mapped_type& at( const key_type& key ) const
			{}
			*/

			/* ITERATORS */
			
			/* BST ITERATORS
			iterator begin()
			{}

			const_iterator begin() const
			{}

			iterator end()
			{}

			const_iterator end() const
			{}

			reverse_iterator rbegin()
			{}

			const_reverse_iterator rbegin() const
			{}

			reverse_iterator rend()
			{}

			const_reverse_iterator rend() const
			{}
			*/

			/* CAPACITY */

			/* BST TRAVERSE
			bool empty() const
			{}

			size_type size() const
			{}

			size_type max_size() const
			{}
			*/

			/* MODIFIERS */

			/* BST DELETE AND INSERT
			void clear()
			{}
			
			ft::pair<iterator, bool> 	insert( const value_type& value )
			{}

			iterator 					insert( iterator hint, const value_type& value )
			{}

			void 		erase( iterator pos )
			{}

			void 		erase( iterator first, iterator last )
			{}

			size_type 	erase( const key_type& key )
			{}

			void swap( map& other )
			{}
			*/


			/* LOOKUP */

			/* BST SEARCH
			// returns the number of elements matching specific key
			size_type count( const key_type& key ) const
			{}

			// finds element with specific key
			iterator find( const key_type& key )
			{}

			const_iterator find( const key_type& key ) const
			{}

			// returns range of elements matching a specific key
			ft::pair<iterator,iterator> 			equal_range( const key_type& key )
			{}

			ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const
			{}

			// returns an iterator to the first element not less than the given key
			iterator 		lower_bound( const key_type& key )
			{}

			const_iterator 	lower_bound( const key_type& key ) const
			{}

			// returns an iterator to the first element greater than the given key
			iterator 		upper_bound( const key_type& key )
			{}

			const_iterator 	upper_bound( const key_type& key ) const
			{}
			*/

			/* OBSERVERS */

			// returns the function that compares keys
			key_compare key_comp() const
			{	return _k_comp;	}
			
			// returns the function that compares keys in objects of type value_type
			ft::map::value_compare value_comp() const
			{	return _v_comp;	}
	};

	/* NON-MEMBER FUNCTIONS */

	template< class Key, class T, class Compare, class Alloc >
		bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
							const ft::map<Key,T,Compare,Alloc>& rhs )
		{}

	template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
              			   const ft::map<Key,T,Compare,Alloc>& rhs )
		{}

	template< class Key, class T, class Compare, class Alloc >
		bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
        			        const ft::map<Key,T,Compare,Alloc>& rhs )
		{}

	template< class Key, class T, class Compare, class Alloc >
		bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
        			        const ft::map<Key,T,Compare,Alloc>& rhs )
		{}

	template< class Key, class T, class Compare, class Alloc >
		bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
        			        const ft::map<Key,T,Compare,Alloc>& rhs )
		{}

	template< class Key, class T, class Compare, class Alloc >
		bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
        			        const ft::map<Key,T,Compare,Alloc>& rhs )
		{}

	template< class Key, class T, class Compare, class Alloc >
		void swap( ft::map<Key,T,Compare,Alloc>& lhs,
        		   ft::map<Key,T,Compare,Alloc>& rhs )
		{}
};
