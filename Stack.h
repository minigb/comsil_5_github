#include "LinkedList.h"

template <typename Type>
class Stack : public LinkedList<Type>{
public:
	bool Delete (Type& element){
		if (this->first == NULL) return false;

		element = this->first->data;
		Node<Type>* temp = this->first;
		this->first = this->first->link;
		delete temp;

		this->current_size--;

		return true;
	}
};
