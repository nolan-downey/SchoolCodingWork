#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "BST.h"

template< class T>
class SplayTree : public BST<T> {

  private:
    void splay( typename BST<T>::node*& valueNode, typename BST<T>::node*& curr ){

      if( valueNode->data < curr->data && curr->left == NULL ){

        typename BST<T>::node* temp = this->root;
        this->root = valueNode;
        valueNode->right = temp;

      }
      else if( curr->data < valueNode->data && curr->right == NULL ){

        typename BST<T>::node* temp = this->root;
        this->root = valueNode;
        valueNode->left = temp;

      }
      else{

        //We must Zig-Zig or Zig-Zag. Pass curr and parent
        if( valueNode->data < curr->data ) {
          splay( valueNode, curr->left, this->root);
        }
        else if( valueNode->data > curr->data ){
          splay( valueNode, curr->right, this->root);
        }
        else{
          //Duplicate - Do Nothing
        }
      }

    }

    void splay( typename BST<T>::node*& valueNode, typename BST<T>::node*& parent, typename BST<T>::node*& grand){

      // Step 1: Recursively Seek Location
      if( parent->left != NULL && valueNode->data < parent->data ){

        splay( valueNode, parent->left, parent);

      }
      if( parent->right != NULL && parent->data < valueNode->data ){

        splay( valueNode, parent->right, parent);

      }

      /* When recurse back up, we need to swap current and parent */
      /* Four cases */

      // Case 1: Zig-Zig Left
      if( grand->data > parent->data && parent->data > valueNode->data ){

        // Step 2: Once found, create temp nodes pointing parent and grandparent
        typename BST<T>::node* tempPar = parent;
        typename BST<T>::node* tempGrand = grand;

        // Step 3: Splay the Node as shown in Video 4
        tempPar->left = valueNode->right;
        valueNode->right = tempPar;
        tempGrand->left = tempPar->right;
        tempPar->right = tempGrand;
        grand = valueNode;

      }

      // Case 2: Zig-Zag Left
      else if( grand->data > parent->data && parent->data < valueNode->data ){

        typename BST<T>::node* tempPar = parent;
        typename BST<T>::node* tempGrand = grand;

        tempPar->right = valueNode->left;
        valueNode->left = tempPar;
        tempGrand->left = valueNode->right;
        valueNode->right = tempGrand;
        grand = valueNode;

      }

      // Apply and Solve - Right Zig-Zig and Right Zig-Zag goes here

      // Case 3: Zig-Zig Right
      else if( grand->data < parent->data && parent->data < valueNode->data ){
        // Step 2: Once found, create temp nodes pointing parent and grandparent
        typename BST<T>::node* tempPar = parent;
        typename BST<T>::node* tempGrand = grand;

        // Step 3: Splay the Node
        tempPar->right = valueNode->left;
        valueNode->left = tempPar;
        tempGrand->right = tempPar->left;
        tempPar->left = tempGrand;
        grand = valueNode;
      }

      // Case 4: Zig-Zag Right
      else if( grand->data < parent->data && parent->data > valueNode->data ){
        // Step 2: Once found, create temp nodes pointing parent and grandparent
        typename BST<T>::node* tempPar = parent;
        typename BST<T>::node* tempGrand = grand;

        // Step 3: Splay the Node
        tempPar->left = valueNode->right;
        valueNode->right = tempPar;
        tempGrand->right = valueNode->left;
        valueNode->left = tempGrand;
        grand = valueNode;
      }
    }

    void contains( const T& value, typename BST<T>::node*& curr ) {

        if( value < curr->data && curr->left == NULL ) {
          return;
        }
        else if( value > curr->data && curr->right == NULL ) {
          return;
        }
        //Left Node is the Value
        else if( curr->left != NULL && curr->left->data == value ) {
          typename BST<T>::node* tempRoot = curr;
          typename BST<T>::node* tempLeft = curr->left;

          tempRoot->left = tempLeft->right;
          tempLeft->left = tempRoot;
          curr = tempLeft;
        }
        //Right Node is the Value
        else if( curr->right != NULL && curr->right->data == value ) {
          typename BST<T>::node* tempRoot = curr;
          typename BST<T>::node* tempRight = curr->right;

          tempRoot->right = tempRight->left;
          tempRight->right = tempRoot;
          curr = tempRight;
        }

        else{
            // Zig-Zig Left
            if( curr->left != NULL && value < curr->left->data && value < curr->data ) {

                contains( value, curr->left->left, curr->left, this->root );
            }
            // Zig-Zag Left
            else if( curr->left != NULL && value > curr->left->data && value < curr->data ) {

                contains( value, curr->left->right, curr->left, this->root );
            }
            // Zig-Zig Right
            else if( curr->right != NULL && value > curr->right->data && value > curr->data ) {

                contains( value, curr->right->right, curr->right, this->root );
            }
            // Zig-Zag Right
            else if( curr->right != NULL && value < curr->right->data && value > curr->data ) {

                contains( value, curr->right->left, curr->right, this->root );
            }

        }


    }

    void contains( const T& value, typename BST<T>::node*& child, typename BST<T>::node*& parent, typename BST<T>::node*& grand) {

        if(child == NULL)
          return;

        else if( child->data != value ){

            if( child->left == NULL && value < child->data ){
                return;
              }
            else if( child->right == NULL && value > child->data ) {
                return;
            }
            else if( child->left != NULL && value < child->data ) {

                contains( value, child->left, child, parent );
            }
            else if( child->right != NULL && value > child->data ) {

                contains( value, child->right, child, parent );
            }
        }

        //Recurse Back Up the Tree
        typename BST<T>::node* tempPar = parent;
        typename BST<T>::node* tempGrand = grand;
        typename BST<T>::node* valueNode = child;

        if( parent->data == value ) {

            if( parent->data < grand->data ) {

                tempGrand->left = tempPar->right;
                tempPar->right = tempGrand;
                grand = tempPar;
            }
            else {

              tempGrand->right = tempPar->left;
              tempPar->left = tempGrand;
              grand = tempPar;
            }
        }

        else if( child != NULL && child->data == value ) {

            /* When recurse back up, we need to swap current and parent */
            /* Four cases */

            // Case 1: Zig-Zig Left
            if( grand->data > parent->data && parent->data > valueNode->data ){

              tempPar->left = valueNode->right;
              valueNode->right = tempPar;
              tempGrand->left = tempPar->right;
              tempPar->right = tempGrand;
              grand = valueNode;

            }

            // Case 2: Zig-Zag Left
            else if( grand->data > parent->data && parent->data < valueNode->data ){

              tempPar->right = valueNode->left;
              valueNode->left = tempPar;
              tempGrand->left = valueNode->right;
              valueNode->right = tempGrand;
              grand = valueNode;

            }

            // Case 3: Zig-Zig Right
            else if( grand->data < parent->data && parent->data < valueNode->data ){

              tempPar->right = valueNode->left;
              valueNode->left = tempPar;
              tempGrand->right = tempPar->left;
              tempPar->left = tempGrand;
              grand = valueNode;
            }

            // Case 4: Zig-Zag Right
            else if( grand->data < parent->data && parent->data > valueNode->data ){

              tempPar->left = valueNode->right;
              valueNode->right = tempPar;
              tempGrand->right = valueNode->left;
              valueNode->left = tempGrand;
              grand = valueNode;
            }
        }
    }

  public:

    SplayTree() : BST<T>() {}

    ~SplayTree() {}

    void Insert( const T& value ) {

      typename BST<T>::node* newNode = new typename BST<T>::node(value);

        /* Step 1: If the tree is empty, set as root */
                if( this->IsEmpty() ){
this->root = newNode;
}

        /* Step 2: Otherwise, we will need to splay */
        else{

          splay(newNode, this->root);

        }

        // Step 3
        if( this->root->left != NULL && this->root->left->data == value ){
          typename BST<T>::node* left = this->root->left;
          typename BST<T>::node* left_child = this->root->left->right;
          this->root->left = left_child;
          left->right = this->root;
          this->root = left;
        }

        // Step 4
        if( this->root->right != NULL && this->root->right->data == value ){
          typename BST<T>::node* right = this->root->right;
          typename BST<T>::node* right_child = this->root->right->left;
          this->root->right = right_child;
          right->left = this->root;
          this->root = right;
        }

      }

      bool contains( const T& x ) {

          if( this->IsEmpty() )
            return false;

          contains( x, this->root );

          return this->root->data == x;
      }

      const T& returnRootVal() {

          return this->root->data;

      }


};

#endif
