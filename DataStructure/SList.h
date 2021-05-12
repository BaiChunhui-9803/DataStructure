#ifndef SLIST_H
#define SLIST_H

#include<iostream>
#include"Node.h"

template <typename T> std::ostream& operator<<(std::ostream&, const SList<T>&);
template<typename T>
class SList {
	friend std::ostream& operator<< <T>(std::ostream&, const SList<T>&);
private:
	Node<T>* m_head = nullptr, * m_tail = nullptr;
public:
	~SList() { clear(); }
	SList(const int list_size);
	bool isEmpty()const { return m_head == m_tail; }
	int size();
	void clear();
	void push_back(const T& val);
	Node<T>* insert(Node<T>* pos, const T& val); //在pos后面插入一个结点
	void erase(const T& val); //删除第一次出现的元素
	Node<T>* find(const T& val); //返回第一次出现的元素位置
	void print();
	void print(Node<T>* begin, Node<T>* end);
	Node<T>* link(SList<T>& L2);

	//deleted functions
	SList() = default;
	SList(const SList&) = delete;
	SList& operator=(const SList&) = delete;

	
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const SList<T>& list) {
	Node<T>* p = list.m_head;
	while (p != nullptr) {
		os << p->data() << "->";
		p = p->next();
	}
	os << "NULL";
	return os;
}

template<typename T>
SList<T>::SList(const int list_size) :m_head(nullptr), m_tail(nullptr) {

	for (int i = 0; i < list_size; i++) {
		this->push_back(rand() % 100);
	}
}

template<typename T>
int SList<T>::size() {
	Node<T>* p = m_head;
	int counter = 0;
	while (p != nullptr) {
		counter++;
		p = p->m_next;
	}
	return counter;
}

template<typename T>
void SList<T>::clear() {
	Node<T>* p = nullptr;
	while (m_head != nullptr) {
		p = m_head;
		m_head = m_head->m_next;
		delete p;
	}
	m_tail = nullptr;
}

template<typename T>
void SList<T>::push_back(const T& val) {
	Node<T>* node = new Node<T>(val);
	if (m_head == nullptr) {
		m_head = m_tail = node;
	}
	else {
		m_tail->m_next = node;
		m_tail = m_tail->m_next;
	}
}

template<typename T>
void SList<T>::clear() {
	Node<T>* p = nullptr;
	while (m_head != nullptr) {
		p = m_head;
		m_head = m_head->m_next;
		delete p;
	}
	m_tail = nullptr;
}
template<typename T>
Node<T>* SList<T>::insert(Node<T>* pos, const T& val) {

	Node<T>* node = new Node<T>(val);
	node->m_next = pos->m_next;
	pos->m_next = node;
	if (pos == m_tail)
		m_tail = node;
	return node;
}
template<typename T>
void SList<T>::erase(const T& val) { //删除第一次出现的元素
	Node<T>* p = m_head, * q = p;
	while (p != nullptr && p->m_data != val) {
		q = p;//q指向p
		p = p->m_next;//p后移
	}
	if (p)
		q->m_next = p->m_next;
	if (p == m_tail)
		m_tail = q;
	if (p == m_head && p)			//如果 p 为表头元素，修改 head 指针
		m_head = p->m_next;
	delete p;
}

template<typename T>
Node<T>* SList<T>::find(const T& val) {
	Node<T>* p = m_head;
	while (p != nullptr && p->m_data != val)
		p = p->m_next;
	return p;
}

template<typename T>
void SList<T>::print() {
	Node<T>* p = m_head;
	if (p != nullptr) {
		while (p->m_next) {
			std::cout << p->m_data << " -> ";
			p = p->m_next;
		}
	}
	std::cout << "NULL" << std::endl;
}

template<typename T>
void SList<T>::print(Node<T>* begin, Node<T>* end) {
	Node<T>* p = begin;
	if (p != nullptr) {
		while (p->m_next && p != end->m_next) {
			std::cout << p->m_data << " -> ";
			p = p->m_next;
		}
	}
}

template<typename T>
Node<T>* SList<T>::link(SList<T>& L2)
{
	Node<T>* pos = L2.m_head;

	while (pos != nullptr) {
		Node<T>* p_node = new Node<T>(pos->m_data);
		if (m_head == nullptr) {
			m_head = m_tail = p_node;
		}
		m_tail->m_next = p_node;
		m_tail = p_node;
		pos = pos->m_next;
	}
	return this->m_head;
}



#endif