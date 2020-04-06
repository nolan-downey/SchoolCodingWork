#ifndef BTREENODE_H
#define BTREENODE_H

#include <iostream>

//A BTree node
template<class T>
class BTreeNode
{

    public:

        int order; //Order of the tree
        int degree; //Minimum degree (defines the range for number of keys)
        bool lead; //Is true when node is leaf. Otherwise false
        int numKeys; //Current number of keys
        T *keys; //An array of keys
        BTreeNode<T> **childPtrs; //An array of child pointers

        //Terminates the program if memory is not allocated
        void checkMemory() {

            if (this == NULL) {
                std::cerr << "Out of Memory" << std::endl;
                exit (-1);
            }
        }

        //BTreeNode Constructor
        BTreeNode<T> (int orderIn, boolisLead) :
            order(orderIn), degree( (order+1)/2 ), lead(isLead), numKeys(0),
            keys(new T[order-1]), childPtrs(new BTreeNode<T>*[order]) {

              checkMemory();
            }

        void traverse()
        {
            int i;
            for (i = 0; i < numKeys; i++) {

                if (leaf == false)
                  childPtrs[i]->traverse();
                std::cout << " " << keys[i];
            }

            if (leaf == false)
              childPtrs[i]->traverse();
        }

        BTreeNode<T>* search(T key){

            int i = 0;
            while (i < numKeys && key > keys[i])
              i++;

            if (i < numKeys) {
                if (keys[i] == key)
                  return this;
            }

            if (leaf == true)
              return NULL;

            return childPtrs[i]->search(key);
        }

        void insertNonFull (T key) {

            int i = numKeys - 1;

            //If this is a leaf node
            if (leaf == true) {

                while (i >= 0 && keys[i] > key) {

                    keys[i+1] = keys[i];
                    i--;
                }

                //Insert the new key at found location
                keys[i+1] = key;
                numKeys = numKeys + 1;
            }
            else {

                while (i >= 0 && keys[i] > key)
                  i--;

                if (childPtrs[i+1]->numKeys == order - 1) {

                    splitChild(i+1, childPtrs[i+1]);

                    if (keys[i+1] < key)
                      i++;
                }

                childPtrs[i+1]->insertNonFull(key);
            }
        }

        void splitChild(int i, BTreeNode<T> *y) {

            //Step 1
            BTreeNode<T> *z = new BTreeNode<T>(y->order, y->leaf);
            z->numKeys = degree - 1;

            //Step 2
            for (int j = 0; j < degree - 1; j++)
              z->keys[j] = y->keys[j+degree];

            //Step 3
            if (y->leaf == false) {
                for (int j = 0; j < degree; j++)
                  z->childPtrs[j] = y->childPtrs[j+degree];
            }

            //Step 4
            y->numKeys = degree - 1;

            //Step 5
            for (int j = numKeys; j >= i+1; j--)
              childPtrs[j+1] = childPtrs[j];

            //Step 6
            childPtrs[i+1] = z;

            //Step 7
            for (int j = numKeys-1; j >= i; j--)
              keys[j+1] = keys[j];

            //Step 8
            keys[i] = y->keys[degree-1];

            //Step 9
            numKeys = numKeys + 1;
        }

        void merge (int index) {

            BTreeNode<T>* child = childPtrs[index];
            BTreeNode<T>* sibling = childPtrs[index + 1];

            child->keys[degree-1] = keys[index];

            for(i = 0; i < sibling->numKeys; i++) {

                child->keys[i+degree] = sibling->keys[i];
            }

            if ( !child->leaf ) {

                for(int i = 0; i < sibling->numKeys; i++;) {

                    child->childPtrs[i+degree] = sibling->childPtrs[i];
                }
            }

            for (int i = index+1; i < numKeys; i++) {

                keys[i-1] = keys[i];
            }

            for (int i = index+2; i <= numKeys; i++) {

                childPtrs[i-1] = childPtrs[i];
            }

            child->numKeys += sibling->numKeys+1;
            numKeys--;

            delete (sibling);
            return;
        }

        void borrowFromPrev (int index) {

            BTreeNode<T>* child = childPtrs[index];
            BTreeNode<T>* sibling = childPtrs[index - 1];

            for (int i = child->numKeys-1; i >= 0; i--) {

                child->keys[i+1] = child->keys[i];
            }

            if (!child->leaf) {

                for(int i = child->numKeys; i >= 0; i--) {

                    child->childPtrs[i+1] = child->childPtrs[i];
                }
            }

            child->keys[0] = keys[index - 1];

            if( !child->leaf ) {

                child->childPtrs[0] = sibling->childPtrs[sibling->numKeys];
            }

            keys[index-1] = sibling->keys[sibling->numKeys-1];

            child->numKeys++;
            sibling->numKeys--;

            return;
        }

        void borrowFromNext ( int index ) {

            BTreeNode<T>* child = childPtrs[index];
            BTreeNode<T>* sibling = childPtrs[index+1];

            child->keys[ child->numKeys ] = keys[index];

            if (!child->leaf) {

                child->childPtrs[ child->numKeys+1] = sibling->childPtrs[0];
            }

            keys[index] = sibling->keys[0];

            for (int i = 1; i < sibling->numKeys; i++) {

                sibling->keys[i-1] = sibling->keys[i];
            }

            if (!sibling->leaf) {

                for(int i = 1; i <= sibling->numKeys; i++) {

                    sibling->childPtrs[i-1] = sibling->childPtrs[i];
                }
            }

            child->numKeys++;
            sibling->numKeys--;

            return;
        }

        void fill (int index) {

            if (index != 0 && childPtrs[index-1]->numKeys >= degree) {

                borrowFromPrev( index );
            }

            else if( index != numKeys && childPtrs[index+1]->numKeys >= degree ) {

                borrowFromNext( index );
            }
            else {

                if ( index != numKeys )
                  merge (index);
                else
                  merge( index - 1);
            }

            return;
        }
};

#endif
