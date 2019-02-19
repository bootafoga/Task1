#pragma once
#include <iostream>
using namespace std;

template <typename T>
class List {
public:

	List() {
		sizeOfList = 0;
		head = nullptr;
	}

	void push_back(T field);
	void push_front(T field);
	void pop_back();
	void pop_front();
	void insert(T field, int index);
	T At(int index);
	void remove(int index);
	int getSize() { return sizeOfList; }
	void set(T field, int index);
	bool isEmpty() { return (sizeOfList == 0); }
	friend ostream& operator<< (ostream &out, List<T> list);

private:

	template <typename T>
	class Node {
	public:
		Node *nextNode;
		T field;
		Node(T field, Node *nextNode = nullptr) {
			this->field = field;
			this->nextNode = nextNode;
		}
	};

	Node<T> *head;
	int sizeOfList = 0;
};

