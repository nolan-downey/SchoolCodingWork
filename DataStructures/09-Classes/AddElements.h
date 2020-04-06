#ifndef ADDELEMENTS_H
#define ADDELEMENTS_H

#include <iostream>
#include <string>

template <class T>
class AddElements{

	private:

		// Student Code Goes Here
		T element;

	public:

		// Student Code Goes Here
		AddElements() : element() {}

		AddElements(const T& tempElem) : element(tempElem) {}

		T getElement() const{

			return element;
		}

		void addElement(const T& addVal){
			element += addVal;
		}

		void concatenate(const T& addVal){
			element += addVal;
		}

		friend std::ostream& operator<<(std::ostream& out, const AddElements<T>& printAE) {

			out << printAE.element;

			return out;
		}
};


#endif
