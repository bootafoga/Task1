#include "pch.h"
#include "List.h"


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
void List<T>::push_front(T field) //add at first
{
	if (head == nullptr) {
		head = new Node<T>(field);
	}
	else {
		Node<T> *firstItem = this->head;
		head = new Node<T>(field);
		head->nextNode = firstItem;
	}

	sizeOfList++;
}

template<typename T>
void List<T>::pop_back() //delete the last elem
{
	if (head != nullptr) {
		Node<T> *penultimateItemSearch = this->head;
		while (penultimateItemSearch->nextNode->nextNode != nullptr) {
			penultimateItemSearch = penultimateItemSearch->nextNode;
		}
		delete penultimateItemSearch->nextNode;
		penultimateItemSearch->nextNode = nullptr;

		sizeOfList--;
	}

}

template<typename T>
void List<T>::pop_front() //delete the first elem
{
	Node<T> *firstElem = this->head;

	if (head != nullptr) {
		if (head->nextNode == nullptr) {
			delete firstElem;
			head = nullptr;
			sizeOfList--;
		}
		else {
			head = head->nextNode;
			delete firstElem;

			sizeOfList--;
		}
	}
}

template<typename T> //some shit, try to do it differently 
void List<T>::insert(T field, int index) //add by index before
{
	if (index == 0) push_front(field);
	else if (index == 1 && head->nextNode) {
		Node<T> *newItem = new Node<T>(field);
		newItem->nextNode = head->nextNode;
		head = newItem;
		sizeOfList++;
	}
	else {
		Node<T> *itemSearch = this->head;
		int currentIndex = 0;


		while (currentIndex + 1 != index && itemSearch != nullptr) {
			itemSearch = itemSearch->nextNode;
			currentIndex++;
		}
		if (currentIndex + 1 == index) {
			Node<T> *newItem = new Node<T>(field);
			newItem->nextNode = itemSearch->nextNode;
			itemSearch->nextNode = newItem;
			sizeOfList++;

		}
	}


}

template<typename T>
T List<T>::At(int index)
{
	Node<T> *itemSearch = this->head;
	int currentIndex = 0;
	while (itemSearch != nullptr) {
		if (currentIndex == index) return itemSearch->field;
		currentIndex++;
	}

	if (currentIndex == index) return itemSearch->field;
}

template<typename T>
void List<T>::remove(int index)
{
	if (index == 0) pop_front();
	else if (index == this->sizeOfList) pop_back;
	else {
		Node<T> *itemSearch = this->head;
		int currentIndex = 0;
		while (currentIndex + 1 != index && itemSearch->nextNode != nullptr) {
			itemSearch = itemSearch->nextNode;
			currentIndex++;
		}
		if (currentIndex + 1 == index) {
			delete itemSearch->nextNode;
			itemSearch->nextNode = nullptr;
			sizeOfList--;
		}

	}
}

template<typename T>
void List<T>::set(T field, int index)
{
	Node<T> *itemSearch = this->head;
	int currentIndex = 0;
	while (currentIndex != index && itemSearch->nextNode != nullptr) {
		itemSearch = itemSearch->nextNode;
		currentIndex++;
	}
	if (currentIndex == index) itemSearch->field = field;
}


template<class T> ostream &operator<<(ostream &out, List<T> list)
{
	int currentIndex = 0;
	while (currentIndex < list.getSize()) {
		out << " {" << list.At(currentIndex) << "} ";
	}

	return out;
}

/*template<typename T>
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
}*/
