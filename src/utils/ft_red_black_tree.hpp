/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search_tree.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:53:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/18 13:24:56 by mzomeno-         ###   ########.fr       */
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
    		RedBlackTree()	: 	_data(0), _left(nullptr), _right(nullptr), _parent(nullptr), color(RED)
			{}

    		RedBlackTree(T data)	:	_data(data), _left(nullptr), _right(nullptr), _parent(nullptr), color(RED)
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

				newNode->right = rotationCenter;				// rCenter is now nNode's right child
				rotationCenter->parent = newNode;
			}

			void balanceTree(RedBlackTree *newNode)
			{
				RedBlackTree *parent = newNode->parent;
				if (parent->color == BLACK)						// Case 1 -> everything good
					return ;
				RedBlackTree *grandParent = parent->parent;
				RedBlackTree *uncle = 
					(parent == grandParent->right) ? 
					grandParent->left :
					grandParent->right;
				if (uncle && uncle->color == RED)				// Case 2 -> parent and uncle are red
				{
					parent->color = BLACK;
					uncle->color = BLACK;
					if (grandParent != root)
					{
						grandParent->color == RED;
						if (grandParent->parent->color == RED)	// Recursive call if grandParent
							balanceTree(root, parent);			// and greatgrandparent are both red
				}
				else											// Case 3 -> parent is red, uncle is
				{												// black or null

				}


				while (parent->color == RED)
				{
					if (parent == parent->parent->left)
						newNode = parent->parent->right;
				}
			}

			// Balance it with ROTATE and RECOLOR
			void insert(RedBlackTree *root, RedBlackTree *newNode)
			{
				if (root == nullptr)				// case empty tree
				{
					root = newNode;
					newNode->color = BLACK;
					return ;
				}
				RedBlackTree *lastNode = nullptr;	// we will use this to iterate through the tree
				while (root)
				{
					lastNode = root;				// in the last iteration, root will be nullptr
					if (newNode->key < root->key)	// and so aux would be its "parent"
						root = root->left;
					else if (newNode->key > root->key)
						root = root->right;
					else							// case newNode is a duplicate
						return;
				}
				newNode->parent = lastNode;			// newNode gets attached to the tree
				if (newNode->key < lastNode->key)
					lastNode->left = newNode;
				else
					lastNode->right = newNode;
				balanceTree(newNode;)
			}

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
