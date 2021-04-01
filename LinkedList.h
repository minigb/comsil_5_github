#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template <typename Type>
class Node{
public:
	Type data = 0;
	Node *link = NULL;

	Node(Type element){
		data = element;
		link = NULL;
	}
};

//LinkedList Class
template <typename Type>
class LinkedList{
protected:
	Node<Type> *first;
	int current_size;
public:
	LinkedList(){
		first = NULL;
		current_size = 0;
	};

	int GetSize(){
		return current_size;
	};

	void Insert(Type element) {
		Node<Type> *newnode = new Node<Type>(element); //Don't forget to input <Type> here
		newnode->link = first;
		first = newnode;
		current_size++;
	}
		
	virtual bool Delete(Type& element) {
		if (first == NULL)
			return false;

		Node<Type> *current = first;
		Node<Type> *previous = 0;

		while (1) {
			if (current->link == NULL) {
				if (previous)
					previous->link = current->link;
				else
					first = first->link;
				break;
			}
			previous = current;
			current = current->link;
		}
		element = current->data;
		delete current;
		current_size--;

		return true;
	}

	void Print() {
		Node<Type> *i;
		int index = 1;

		if (current_size != 0) {
			for (i = first; i != NULL; i = i->link) {
				if (index == current_size) {
					cout << "[" << index << "|";
					cout << i->data << "]";
				}

				else {
					cout << "[" << index << "|";
					cout << i->data << "]->";
					index++;
				}
			}
			cout << endl;
		}
	}
};
#endif
