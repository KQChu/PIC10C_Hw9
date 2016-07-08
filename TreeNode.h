/**	@file TreeNode.h
	@brief This file contains the declarations and definitions for the templated TreeNode class
 */

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <functional>

/**	@class TreeNode
	@brief The TreeNode class creates nodes to be used to form the BinarySearchTree object.  Each TreeNode contains a T data value and pointers to the left child, right child, and parent nodes.  Functions have been implemented recursively to insert, print using the CMP parameter, and find a TreeNode of particular T value using the CMP parameter.  The TreeNode class grants friendship to BinarySearchTree and TreeIterator classes, which allows them to access the TreeNode's members.
 */

template<typename T, typename CMP = std::less<T>> class TreeNode;
template<typename T, typename CMP> class BinarySearchTree;
template<typename T, typename CMP> class TreeIterator;

template<typename T, typename CMP>
class TreeNode {
    template<typename T_bst, typename CMP_bst>
    friend class BinarySearchTree;
    
    template<typename T_ti, typename CMP_ti>
    friend class TreeIterator;
public:
    void insert_node(TreeNode<T,CMP>* new_node);
    void print_nodes() const;
    bool find(T value) const;
    virtual ~TreeNode<T, CMP>() {};
private:
    T data;
    CMP isless;
    TreeNode<T, CMP>* left;
    TreeNode<T, CMP>* right;
    TreeNode<T, CMP>* node_parent;
};

/** Utilizing the constraints of a BinarySearchTree (left child must be smaller and right child must be larger) and CMP comparison guidelines, recursively determines appropriate location for input TreeNode pointer and adds to system
	@param new_node is a pointer to the TreeNode object being added to the system
 */
template<typename T, typename CMP>
void TreeNode<T, CMP>::insert_node(TreeNode<T, CMP>* new_node) {
    //if new_node data is smaller than current node data must continue to the left
    if (isless(new_node->data, data)) {
        //if left of current node is nullptr can set that location to new_node
        if (left == nullptr) {
            left = new_node;
            left->node_parent = this;
        }
        //call insert_node recursively to further cycle through BinarySearchTree system and find correct position
        else {
            left->insert_node(new_node);
        }
    }
    //if new_node data is larger than current node data must continue to the right
    else if (isless(data, new_node->data)) {
        //if right of current node is nullptr can set that location to new_node
        if (right == nullptr) {
            right = new_node;
            right->node_parent = this;
        }
        //call insert_node recursively to further cycle through BinarySearchTree system and find correct position
        else {
            right->insert_node(new_node);
        }
    }
    //if TreeNode of same data value already in system do not add
    else {
        return;
    }
}

/**	Recursively cycles through BinarySearchTree system to reach all nodes and print T data value
 */
template<typename T, typename CMP>
void TreeNode<T, CMP>::print_nodes() const {
    //if left is not nullptr continue in that direction
    if (left != nullptr) {
        left->print_nodes();
    }
    std::cout << data << std::endl;
    //if right is not nullptr continue in that direction
    if (right != nullptr) {
        right->print_nodes();
    }
}

/**	Utilizing the constraints of a BinarySearchTree (left child must be smaller and right child must be larger) and CMP comparison guidelines, recursively determines whether TreeNode of input T value exists within system.
	@return bool value 0 if TreeNode with input value not in system and 1 if TreeNode with input value is in system
 */
template<typename T, typename CMP>
bool TreeNode<T, CMP>::find(T value) const {
    //if input value is smaller than current node data must continue to the left
    if (isless(value, data)) {
        //if left is nullptr cannot continue therefore return false
        if (left == nullptr) {
            return false;
        }
        //call find recursively to further cycle through BinarySearchTree system and search for TreeNode
        else {
            return left->find(value);
        }
    }
    //if input value is larger than current node data must continue to the right
    else if (isless(data, value)) {
        //if right is nullptr cannot continue therefore return false
        if (right == nullptr) {
            return false;
        }
        //call find recursively to further cycle through BinarySearchTree system and search for TreeNode
        else {
            return right->find(value);
        }
    }
    //if data==value return true
    else {
        return true;
    }
}

#endif
#pragma once