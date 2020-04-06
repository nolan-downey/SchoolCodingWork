#ifndef RBTREE_H
#define RBTREE_H

#include "RBTNode.h"

template<class T>
class RBTree {

private:
// Red-Black Tree root node
RBTNode<T> *root;

void leftRotate(RBTNode<T>*& x) {

    RBTNode<T> *nParent = x->right;

    if (x == root)
    root = nParent;

    x->moveDown(nParent);

    x->right = nParent->left;

    if (nParent->left != NULL)
    nParent->left->parent = x;

    nParent->left = x;
    }

    void rightRotate(RBTNode<T>*& x) {

      RBTNode<T> *nParent = x->left;

      if (x == root)
          root = nParent;

      x->moveDown(nParent);

      x->left = nParent->right;

      if (nParent->right != NULL)
      nParent->right->parent = x;

      nParent->right = x;
      }

      void swapColors(RBTNode<T>*& x1, RBTNode<T>*& x2) {
        COLOR temp;
        temp = x1->color;
        x1->color = x2->color;
        x2->color = temp;
        }

      void swapValues(RBTNode<T>*& u, RBTNode<T>*& v) {
        T temp;
        temp = u->value;
        u->value = v->value;
        v->value = temp;
      }

      void fixRedRed(RBTNode<T>*& x) {

          if (x == root) {

              x->color = BLACK;
              return;
          }

          RBTNode<T>* parent = x->parent;
          RBTNode<T>* grandparent = parent->parent;
          RBTNode<T>* uncle = x->uncle();

          if (parent->color != BLACK) {

            if (uncle != NULL && uncle->color == RED) {

                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                fixRedRed(grandparent);
            }
          }

          else{

              if (parent->isOnLeft()){
                  if(x->isOnLeft()){
                      swapColors(parents, grandparents);
                  }

                  else{
                      leftRotate(parent);
                      swapColors(x, grandparent);
                  }

                  rightRotate(grandparent);
              }

            else{
                if (x->isOnLeft()){
                    rightRotate(parent);
                    swapColors(x, grandparent);
                }

                else {
                    swapColors( parents, grandparent);
                }

                leftRotate(grandparent);
            }
          }
      }

      void inorder(RBTNode<T>*& x) {

          if (x == NULL){
            return;
          }

          inorder(x->left);
          std::cout << x->value << std::endl;
          inorder(x->right);
      }

      void levelOrder(RBTNode<T>*& x){
        if (x == NULL)
          return;

        std::queue<RBTNode<T> *> q;
        RBTNode<T> *curr;

        q.push(x);

        while( !q.empty()) {
            curr = q.front();
            q.pop();

            std::cout << curr->value << " ";

            if (curr->left != NULL)
              q.push(curr->left);
            if (curr->right != NULL)
              q.push(curr->right);
        }
      }

public:

RBTree() : root(NULL) { }

RBTNode<T>* getRoot() { return root; }

RBTNode<T>* search(T n) {

    RBTNode<T> *temp = root;

    while (temp != NULL) {
    if (n < temp->value) {
    if (temp->left == NULL)
    break;
    else
    temp = temp->left;
    }
    else if (n == temp->value) {
    break;
    }
    else {
    if (temp->right == NULL)
    break;
    else
    temp = temp->right;
    }
    }

    return temp;
    }

void insert( T n) {
    RBTNode<T>* newNode new RBTNode<T>(n);

    if (root == NULL) {

        newNode->color = BLACK;
        root = newNode;
    }

    RBTNode<T>* temp = search(n);

    if (temp->value == n) {
        return;
    }

    newNode->parent = temp;

    if (n < temp->value) {
        temp->left = newNode;
    }

    else {
      temp->right = newNode;
    }

    fixRedRed(newNode);
}

void printInOrder() {

    std::cout << "In-order: " << std::endl;

    if (root == NULL) {
        std::cout << "The tree is empty." << std::endl;
    }

    else{
        inorder(root);
    }

    std::cout << std::endl;
}

void printLevelOrder(){

    std::cout << "Level order: " << std::endl;
    if (root == NULL)
      std::cout << "Tree is empty" << std::endl;
    else
      levelOrder(root);
    std::cout << std::endl;
}


};

#endif
