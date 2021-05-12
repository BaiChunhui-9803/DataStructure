#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include"Node.h"

template <typename T> std::ostream& operator<<(std::ostream&, const Queue<T>&);
template<typename T>
class Queue {
	friend std::ostream& operator<< <T>(std::ostream&, const Queue<T>&);
private:
	Node<T>* m_front = nullptr, * m_rear = nullptr;
public:
	~Queue() { clear(); }
	Queue(const int queue_size);
	bool isEmpty()const { return m_front == m_rear; }
	int size();
	void clear();
	void push(const T& val);
	void pop();
	Node<T>* find(const T& val); //返回第一次出现的元素位置
	Node<T>* link(Queue<T>& Q2);

	//deleted functions
	Queue() = default;
	Queue(const Queue&) = delete;
	Queue& operator=(const Queue&) = delete;


};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
	Node<T>* p = queue.m_front;
	os << "FRONT……";
	while (p != nullptr) {
		os << p->data() << "…";
		p = p->next();
	}
	os << "…REAR";
	return os;
}

template<typename T>
Queue<T>::Queue(const int queue_size) :m_front(nullptr), m_rear(nullptr) {

	for (int i = 0; i < queue_size; i++) {
		this->push(rand() % 100);
	}
}

template<typename T>
int Queue<T>::size() {
	Node<T>* p = m_front;
	int counter = 0;
	while (p != nullptr) {
		counter++;
		p = p->m_next;
	}
	return counter;
}

template<typename T>
void Queue<T>::clear() {
	Node<T>* p = nullptr;
	while (m_front != nullptr) {
		p = m_front;
		m_front = m_front->m_next;
		delete p;
	}
	m_rear = nullptr;
}

template<typename T>
void Queue<T>::push(const T& val) {
	Node<T>* node = new Node<T>(val);
	if (m_front == nullptr) {
		m_front = m_rear = node;
	}
	else {
		m_rear->m_next = node;
		m_rear = m_rear->m_next;
	}
}

template<typename T>
void Queue<T>::pop() {
	Node<T>* p = m_front;
	if (m_front == nullptr) {
		m_front = m_rear;
	}
	else {
		m_front = m_front->m_next;
		delete p;
	}
}

template<typename T>
Node<T>* Queue<T>::find(const T& val) {
	Node<T>* p = m_front;
	while (p != nullptr && p->m_data != val)
		p = p->m_next;
	return p;
}

template<typename T>
Node<T>* Queue<T>::link(Queue<T>& Q2)
{
	Node<T>* pos = Q2.m_front;

	while (pos != nullptr) {
		Node<T>* p_node = new Node<T>(pos->m_data);
		if (m_front == nullptr) {
			m_front = m_rear = p_node;
		}
		m_rear->m_next = p_node;
		m_rear = p_node;
		pos = pos->m_next;
	}
	return this->m_front;
}

#endif // !QUEUE_H

