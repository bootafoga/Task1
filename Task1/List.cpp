#include "pch.h"
#include "List.h"

template <typename T>
List<T>::List()
{
	sizeOfList = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T field)
{
	if (head == nullptr) {
		head = new Node<T>(field);
	}
	else {
		Node<T> *lastItemSearch = this->head;
		while (lastItemSearch->nextNode != nullptr) {
			lastItemSearch = lastItemSearch->nextNode;
		}
		lastItemSearch->nextNode = new Node<T>(field);
	}

	sizeOfList++;
}

template<typename T>
T & List<T>::operator[](const int index)
{
	//have i to use there try catch?

	Node<T> *itemSearch = this->head;
	int currentIndex = 0;
	while (currentIndex != index && itemSearch != nullptr) {
		itemSearch = itemSearch->nextNode;
		currentIndex++;
	}
	
	if (currentIndex == index) return itemSearch->field;
}
