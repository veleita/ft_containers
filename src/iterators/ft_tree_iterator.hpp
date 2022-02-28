/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:02:50 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/28 19:08:21 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include <ft_iterator.hpp>
#include <ft_iterator_traits.hpp>
#include <ft_reverse_iterator.hpp>

namespace ft
{
	template < typename T >
	class tree_iterator
	{
		public:
		/* Type definitions */
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename std::bidirectional_iterator_tag		iterator_category;
		
		/* Iterator content */
		NodePointer node;
		NodePointer root;

		/* Default constructor */
		explicit tree_iterator(pointer node = nullptr)
			: node(node)
		{
		}

		/* Copy constructor */
		template <class U>
		tree_iterator(const tree_iterator<U> &copy)
			: node(copy.node)
		{
		}

		/* Assignation */
		template <class U>
		tree_iterator &operator=(const tree_iterator<U> &rhs)
		{
			this->node = rhs.node;
			this->root = rhs.root;
			return (*this);
		}

		/* Destructor */
		virtual ~vector_iterator() {}

		/* Getters */
		pointer	getNode() const {	return node;	}
		pointer	getRoot() const {	return root;	}

		/* Operators */
		reference operator*(void) const { return node->data; }
		pointer operator->(void) const { return &(node->data); }

		NodePointer	min(NodePointer branch)
		{
			while (branch->left)
				branch = branch->left;
			return branch;
		}

		NodePointer	max(NodePointer branch)
		{
			while (branch->right)
				branch = branch->right;
			return branch;
		
		tree_iterator &operator++(void)
		{
			if (node->right)
				node = min(node->right);
			else
				while (node->parent && node == node->parent->left)
					node = node->parent;
			return (*this);
		}

		tree_iterator operator++(int)
		{
			tree_iterator saved_state = *this;
			operator++();
			return (saved_state);
		}

		tree_iterator &operator--(void)
		{
			if (node->left)
				node = max(node->left);
			else
				while (node->parent && node == node->parent->right)
					node = node->parent;
			return (*this);
		}

		tree_iterator operator--(int)
		{
			vector_iterator saved_state = *this;
			operator--();
			return (saved_state);
		}
	};
};

template <typename U, typename V, typename P1, typename P2>
bool	operator==(const ree_iterator<U,P1>& lhs, const tree_iterator<V,P2>& rhs)
{
	return lhs.getNode() == rhs.getNode();
}

template <typename U, typename V, typename P1, typename P2>
bool	operator!=(const tree_iterator<U,P1>& lhs, const tree_iterator<V,P2>& rhs)
{
	return lhs.getNode() != rhs.getNode();
}

template <typename U, typename V, typename P1, typename P2>
bool		operator>(const tree_iterator<U,P1>& lhs, const tree_iterator<V,P2>& rhs)
{
		return lhs.getNode() > rhs.getNode();
}