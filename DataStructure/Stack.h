#ifndef STACK_H
#define STACK_H

#include<iostream>
#include"Node.h"

template <typename T> std::ostream& operator<<(std::ostream&, const Stack<T>&);
template <typename T>
class Stack {
	friend  std::ostream& operator<<<T>(std::ostream&, const Stack<T>&);
private:
	Node<T>* m_top = nullptr;
public:
	Stack() = default;
	Stack(const Stack&) = delete;
	Stack(const int stack_size);
	Stack& operator=(const Stack&) = delete;
	~Stack() { clear(); }
	bool isEmpty()const { return m_top == nullptr; }
	int size();
	void clear();
	void push(const T& val);
	void pop();
	const T& top() { return m_top->m_data; }
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
	Node<T>* p = stack.m_top;
	vector<Node<T>> vec;
	os << "[";
	if (p == nullptr) {

	}

	else {
		while (p != nullptr) {
			vec.push_back(*p);
			p = p->next();
		}

		for (auto it = vec.end() - 1; it >= vec.begin(); it--) {
			os << it->data() << "|";
			if (it == vec.begin()) break;
		}
	}
	os << "TOP";
	return os;
}

template<typename T>
Stack<T>::Stack(const int stack_size) :m_top(nullptr) {
	unsigned seed = time(0);
	srand(seed);
	for (int i = 0; i < stack_size; i++) {
		this->push(rand() % 100);
	}
}

template<typename T>
int Stack<T>::size() {
	Node<T>* p = m_top;
	int counter = 0;
	while (p != nullptr) {
		counter++;
		p = p->m_next;
	}
	return counter;
}

template <typename T>
void Stack<T>::clear() {
	Node<T>* p = nullptr;
	while (m_top != nullptr) {
		p = m_top;
		m_top = m_top->m_next;
		delete p;
	}
}

template <typename T>
void Stack<T>::push(const T& val) {
	Node<T>* node = new Node<T>(val);
	node->m_next = m_top;
	m_top = node;
}

template <typename T>
void Stack<T>::pop() {
	Node<T>* p = m_top;
	m_top = m_top->m_next;
	delete p;
}






#endif // !1
