#ifndef SORTEDSLL_H
#define SORTEDSLL_H

#include "SLList.h"

template<class T>
class SortedSLL : public SLList<T> {

	private:

	public:

		SortedSLL() : SLList<T>() {}

		~SortedSLL() {
			//Do Nothing
		}

		void Insert(T value) {

			typename SLList<T>::node* temp = new typename SLList<T>::node(value) ;

			if( this->IsEmpty() ) {
				this->head = temp;
			}
			else{

				typename SLList<T>::node* prev = NULL;
				typename SLList<T>::node* curr = this->head;

				while( curr != NULL && temp->data > curr->data ) {

					prev = curr;
					curr = curr->next;
				}

				if( prev == NULL ) {

					temp->next = curr;
					this->head = temp;
				}
				else{
					prev->next = temp;
					temp->next = curr;
				}

			}
		}
		/********************************************
		* Function Name  : operator<<
		* Pre-conditions : std::ostream& output, const SortedSLL<T>& theList
		* Post-conditions: std::ostream&
		*
		* Overloaded friend ostream operator for SLList
		********************************************/
		friend std::ostream& operator<<( std::ostream& output, const SortedSLL<T>& theList ){

		   typename SLList<T>::node* curr;

		   if (theList.IsEmpty())
		   {
			  output << "The list is empty";
		   }
		   else
		   {
			  /* set the current pointer to the first
			  ** node of the list */
			  curr = theList.head;

			  /* Until the end of the list */
			  while (curr != NULL)
			  {
				  /* print the current data item */
				  output << curr->data << " ";

				  /* move to the next node */
				  curr = curr -> next;
			  }
		   }

		   return output;
		}

};
#endif
