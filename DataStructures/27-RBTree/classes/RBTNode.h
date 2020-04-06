#ifndef RBTNODE_H
#define RBTNODE_H

#include <iostream>

enum COLOR { RED, BLACK };

template<class T>
class RBTNode {

public:

    T value;     // Data value
    COLOR color; // Node COLOR
    RBTNode<T> *left, *right, *parent; // Child and parent nodes


    RBTNode<T>(T valueIn) :
    value(valueIn), color(RED), left(NULL), right(NULL), parent(NULL) { }


    ~RBTNode() {}

    RBTNode<T>(const RBTNode<T>& copy){

    if(this != &copy){
    this->value = copy->value;
    this->color = copy->color;
    }
    }

    RBTNode<T>& operator=(const RBTNode<T>& assign){

    if(this != &assign){
    this->value = assign->value;
    this->color = assign->color;
    }
    return *this;
    }

    bool isOnLeft() { return this == parent->left; }

    bool isOnRight() { return this == parent->right; }

    RBTNode<T> *uncle() {
    // If no parent or grandparent, then no uncle
    if (parent == NULL or parent->parent == NULL)
    return NULL;

    // uncle on right
    if (parent->isOnLeft())
    return parent->parent->right;

    // uncle on left
    else
    return parent->parent->left;
    }

    RBTNode<T> *sibling() {
    // sibling null if no parent
    if (parent == NULL)
    return NULL;

    if (isOnLeft())
    return parent->right;

    if (isOnRight())
    return parent->left;
    }

    bool hasRedChild() {
      return (left != NULL and left->color == RED) ||
      (right != NULL and right->color == RED);
    }

    void moveDown(RBTNode<T> *nParent) { 
      if (parent != NULL) {

          // Case 1
      if ( isOnLeft() ) {
      parent->left = nParent;
      }
      // Case 2
      if ( isOnRight() ){
      parent->right = nParent;
      }
      }
      // Either Case:
      nParent->parent = parent;
      parent = nParent;
      }
};


#endif
