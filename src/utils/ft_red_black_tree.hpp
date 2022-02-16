/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search_tree.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:53:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/16 17:18:40 by mzomeno-         ###   ########.fr       */
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
	 * 		https://edutechlearners.com/download/Introduction_to_algorithms-3rd%20Edition.pdf
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
		private:
			// Variables
    		T				_data;
    		RedBlackTree	*_left, *_right, *_parent;
			bool			_color;


		public:
    		// Constructors
    		RedBlackTree()	: 	_data(0), _left(nullptr), _right(nullptr), _parent(nullptr), color(BLACK)
			{}

    		RedBlackTree(T data)	:	_data(data), _left(nullptr), _right(nullptr), _parent(nullptr), color(BLACK)
			{}


    		// Functions

			void leftRotate(RedBlackTree *rotationCenter)
			{
				RedBlackTree *newNode = rotationCenter->right;	// Identify the newly inserted node
				
				rotationCenter->right = newNode->left;			// rCenter right-subtree -> nNode left-subtree
				newNode->left->parent = rotationCenter;
	
				newNode->parent = rotationCenter->parent;		// newNode takes rotationCenter's place
				if (rotationCenter == rotationCenter->parent->left)
					rotationCenter->parent->left = newNode;
				else
					rotationCenter->parent->right = newNode;

				newNode->left = rotationCenter;					// rCenter is now nNode's left child
				rotationCenter->parent = newNode;
			}

			void rightRotate(RedBlackTree *rotationCenter)
			{
				RedBlackTree *newNode = rotationCenter->left;	// Identify the newly inserted node
				
				rotationCenter->left = newNode->right;			// rCenter left-subtree -> nNode right-subtree
				newNode->right->parent = rotationCenter;

				newNode->parent = rotationCenter->parent;		// newNode takes rotationCenter's place
				if (rotationCenter == rotationCenter->parent->left)
					rotationCenter->parent->left = newNode;
				else
					rotationCenter->parent->right = newNode;

				newNode->right = rotationCenter;				// rCenter is now nNode's right node
				rotationCenter->parent = newNode;
			}


			// Balance it with ROTATE and RECOLOR
    		RedBlackTree* insert(RedBlackTree *node, T data)
			{
				if (node == nullptr)
					return new RedBlackTree(data);	// Return inserted node

				if (data > node->data)
					node->right = insert(node->right, data);
				else if (data < node->data)
					node->left = insert(node->left, data);
				else				// Duplicate value
					return (node);
			}

	    	void inorderTraverse(RedBlackTree *node)
			{
				if (node == nullptr)
					return;
				inorder(node->left);
				std::cout << node->data << std::endl;
				inorder(node->right);
			}

			void deleteNode(RedBlackTree *node, T data)
			{}

			// ITERATORS
			// SEARCH
			// INSERT
	};
};

#endif
