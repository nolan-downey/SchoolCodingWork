#ifndef SORDYNARRBAD_H
#define SORDYNARRBAD_H

#include <iostream>
#include "DynArr.h"

template<class T>
class SorDynArrBad : public DynArr<T>{
	
		private:

		
		public:
		
			SorDynArrBad(const int sizeIn = 0) : DynArr<T>(sizeIn) {}
			
			~SorDynArrBad() {
				// Do Nothing
			}
				
			
			void Insert(const T& value){
				
				if(this->size >= this->capac){
					this->capac = this->capac * 2;
				}
				
				T* tmp = new T[this->capac];

				unsigned int sort_iter = 0, iter = 0;
				
				while( iter < this->size && value > this->data[iter] ){
					tmp[++sort_iter] = this->data[iter++];
				}
				
				// Insert the new value 
				tmp[++sort_iter] = value;
				
				// Insert remaining values
				while( iter < this->size ){
					tmp[++sort_iter] = this->data[iter++];
				}
				
				this->size++;
				delete [] this->data;
				this->data = tmp;		
				
			}
	
};

#endif