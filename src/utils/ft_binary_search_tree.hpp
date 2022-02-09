/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search_tree.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:53:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/09 12:52:40 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include <iostream>

namespace ft
{
	/* Reference: https://www.geeksforgeeks.org/binary-search-tree-data-structure/ */

	template<class T>
	class BST
	{
		public:
			// Variables
    		T 	_data;
    		BST *_left, *_right;

    		// Constructors
    		BST()	: 	_data(0), _left(nullptr), _right(nullptr)
			{}

    		BST(T data)	:	_data(data), _left(nullptr), _right(nullptr)
			{}

    		// Functions
    		BST* insert(BST *node, T data)
			{
				if (node == nullptr)
					return new BST(data);	// Return inserted node

				if (data > node->data)
					node->right = insert(node->right, data);
				else if (data < node->data)
					node->left = insert(node->left, data);
				else				// Duplicate value
					return (node);
			}

	    	void inorder(BST *node)
			{
				if (node == nullptr)
					return;
				inorder(node->left);
				std::cout << node->data << std::endl;
				inorder(node->right);
			}

			void deleteNode(BST *node, T data)
			{}
	};
};

#endif
