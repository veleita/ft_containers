/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search_tree.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:53:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/16 11:56:02 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# define RED 	0
# define BLACK 	1

# include <iostream>

namespace ft
{
	/* Reference: 
	 * 		https://www.geeksforgeeks.org/binary-search-tree-data-structure/
	 * 		https://www.programiz.com/dsa/red-black-tree
	 */
	
	/* A red-black tree is a Binary Search Tree that follows there properties:
	 * 		1. Red/Black Property: Every node is colored, either red or black.
	 * 		2. Root Property: The root is black.
	 * 		3. Leaf Property: Every leaf (NIL) is black.
	 * 		4. Red Property: If a red node has children then, the children are
	 * 			always black.
	 * 		5. Depth Property: For each node, any simple path from this node
	 * 			to any of its descendant leaf has the same black-depth.
	 */
	template<class T>
	class RedBlackTree
	{
		public:
			// Variables
    		T		_data;
    		BST		*_left, *_right;
			bool	_color;

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

	    	void inorderTraverse(BST *node)
			{
				if (node == nullptr)
					return;
				inorder(node->left);
				std::cout << node->data << std::endl;
				inorder(node->right);
			}

			void deleteNode(BST *node, T data)
			{}

			// ITERATORS
			// SEARCH
			// INSERT
	};
};

#endif
