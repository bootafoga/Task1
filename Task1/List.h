#pragma once

template <typename T>
class List{

public:
	List();
	~List();

	void push_back(T field);
	T& operator[](const int index); //i have to convert access to an element throught a method,
									//not a standart operator

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
	int sizeOfList;
};

