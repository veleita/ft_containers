/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_black_tree.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:53:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/28 15:40:01 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# define RED 	0
# define BLACK 	1

# include <iostream>
# include <ft_utils.hpp>

namespace ft
{
	/* Reference: 
	 * 		geeksforgeeks.org/binary-search-tree-data-structure/
	 * 		programiz.com/dsa/red-black-tree
	 * 		edutechlearners.com/download/Introduction_to_algorithms-3rd%20Edition.pdf
	 * 		cs.usfca.edu/~galles/visualization/RedBlack.html
	 * 		brilliant.org/practice/red-black-trees <3
	 * 		stackoverflow.com/questions/14148756/what-does-template-rebind-do
	 */
	
	/* A red-black tree is a Binary Search Tree that follows there properties:
	 * 		1. Red/Black Property: Every node is _colored, either red or black.
	 * 		2. Root Property: The root is black.
	 * 		3. Leaf Property: Every leaf (NIL) is black.
	 * 		4. Red Property: If a red node has children then, the children are
	 * 			always black.
	 * 		5. Depth Property: For each node, any simple path from this node
	 * 			to any of its descendant leaf has the same black-depth.
	 *
	 *
	 *		NOTE TO FUTURE ZOME !!!
	 *		
	 *		T is map::value_type = ft::pair<key_type, mapped_type>
	 *		Compare = std::less is the func used to compare the key (data.first)
	 *		
	 *		To-do
	 *
	 *		how to access the node's key
	 *		how to use std::less (Compare)
	 *		how do bst iterators work ?!!
	 *		tests for bs_tree
	 *			- Construct
	 *			- Traverse (print?)
	 *			- Search
	 *			- Insert (check every case)
	 *			- Node class					👍
	 *			- Some kind of getter for color and key (?)
	 */

	template < typename T >
		class Node
		{
			public:
				typedef T	value_type;

				value_type	data;
				bool		color;
				Node		*parent, left, right;

				Node()	:	data(), color(BLACK), parent(nullptr), left(nullptr), right(nullptr)
				{}

				Node(value_type const &data)	
					:	data(data), color(BLACK), parent(nullptr), left(nullptr), right(nullptr)
				{}

				Node(Node const &copy)
					:	
						data(copy.data), 
						color(copy.color), 
						parent(copy.parent), 
						left(copy.left), 
						right(copy.right)
				{}

				Node &operator=(Node const &lhs)
				{
					if (lhs != *this)
					{
						this->data = lhs.data;
						this->color = lhs.color;
						this->parent = lhs.parent;
						this->left = lhs.left;
						this->right = lhs.right;
					}
					return *this;
				}
			
				~Node() {}
		}

	template< class T, class Compare = std::less<key_type>, class Alloc = std::allocator<T> >
	class RedBlackTree
	{
		public:
			// Typedef
			typedef T										value_type;
			typedef size_t									size_type;
			typedef ft::Node<value_type>					Node;
			typedef Allocator::template rebind<Node>::other	node_alloc;
			typedef typename node_alloc::pointer			pointer;
			typedef typename node_alloc::const_pointer		const_pointer;

			// Variables
    		pointer			root;
			size_type		size;
			node_alloc		nodeAlloc;
			Alloc			dataAlloc;
			Compare			compareFunc;
    		
			// Constructors
    		RedBlackTree()	: 	_data(0), _left(nullptr), _right(nullptr), _parent(nullptr), _color(RED)
			{}

    		RedBlackTree(T data)	:	_data(data), _left(nullptr), _right(nullptr), _parent(nullptr), _color(RED)
			{}


    		// Methods

			// L-ROTATE
			//
			// 				|G|							|P|
			// 			   /   \                       /   \
			// 			|U|    |P|         =>        |G|   |rC|
			// 			      /   \                 /   \
			// 			    |lC|  |rC|            |U|   |lC|
			//
			void leftRotate(RedBlackTree *G)
			{
				RedBlackTree *P = G->right;						// Identify the two nodes to rotate
				
				G->right = P->left;								// P's lC (left child) is now at G's right, bc G < P
				P->left->parent = G;
	
				P->parent = G->parent;							// P takes G's place
				if (G == G->parent->left)						// link P to its former grandparent
					G->parent->left = P;
				else
					G->parent->right = P;

				P->left = G;									// G is now P's left child
				G->parent = P;
			}

			// R-ROTATE
			//
			// 				|G|							|P|
			// 			   /   \                       /   \
			// 			|P|    |U|         =>       |lC|   |G|
			// 		   /   \                              /   \
			// 	     |lC|  |rC|                         |rC|   |U|
			//
			void rightRotate(RedBlackTree *G)
			{
				RedBlackTree *P = G->left;						// Identify the two nodes to rotate
				
				G->left = P->right;								// P's rC (right child) is now at G's right, bc G > P
				P->right->parent = G;
	
				P->parent = G->parent;							// P takes G's place
				if (G == G->parent->left)						// link P to its former grandparent
					G->parent->left = P;
				else
					G->parent->right = P;

				P->right = G;									// G is now P's right child
				G->parent = P;
			}

			// Case 1: parent black
			// Case 2: parent and uncle red
			// Case 3: parent red, uncle black, new between parent and grandparent
			//	A)									B)
			//		|G|			|G|			or			|G|		|G|
			//	   /   	       /                           \       \
			//	 |P|    =>   |N|                           |P| =>  |N|
			//	    \   	/							  /           \
			//	   |N|    |P|							|N|           |P|
			//
			// Case 4: parent red, uncle black, parent between new and grandparent
			//		A)									B)
			//			|G|			|P|			or			|G|				|P|
			//		   /   	       /   \                       \       	   /   \
			//		 |P|    =>   |N|   |G|                     |P| 	=>   |G|   |N|
			//		/   										  \
			//	  |N|    										  |N|
			//
			void balanceTree(RedBlackTree *newNode)
			{
				RedBlackTree *parent = newNode->parent;
				if (parent->getColor == BLACK)						// Case 1 -> everything good
					return ;
				RedBlackTree *grandParent = parent->parent;
				RedBlackTree *uncle = 
					(parent == grandParent->right) ? 
					grandParent->left :
					grandParent->right;
				if (uncle && uncle->getColor == RED)				// Case 2 -> _color parent and uncle black
				{
					parent->getColor = BLACK;
					uncle->getColor = BLACK;
					if (grandParent != root)
					{
						grandParent->getColor == RED;
						if (grandParent->parent->getColor == RED)	// Recursive call if grandParent
							balanceTree(root, parent);			// and greatgrandparent are both red
				}
				else											// Case 3 -> rotate newNode with its parent
				{
					if (newNode->key > parent->key && parent->key < grandParent->key)		// A
						leftRotate(parent);
					else if (newNode->key < parent->key && parent->key > grandParent->key)  // B
						rightRotate(parent);
																// Case 4 -> rotate parent with grandparent
					if (newNode->key < grandParent->key)	// A
						rightRotate(grandParent);
					else									// B
						leftRotate(grandParent);
					parent->getColor = BLACK;
					grandParent->getColor = RED;
				}
			}

			void insert(RedBlackTree *root, RedBlackTree *newNode)
			{
				if (root == nullptr)				// case empty tree
				{
					root = newNode;
					newNode->getColor = RED;
					return ;
				}
				RedBlackTree *lastNode = nullptr;	// we will use this to iterate through the tree
				while (root)
				{
					lastNode = root;				// in the last iteration, root will be nullptr
					if (newNode->key < root->key)	// and lastNode will be its "parent"
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
