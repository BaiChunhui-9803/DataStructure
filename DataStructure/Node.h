#ifndef NODE_H
#define NODE_H

#include<iostream>

template<typename T> class SList;
template<typename T> class Stack;
template<typename T> class Queue;
template<typename T> std::ostream& operator<<(std::ostream&, const SList<T>&);

template<typename T>
class Node {
	friend class SList<T>;
	friend class Stack<T>;
	friend class Queue<T>;
	T m_data;
	Node* m_next = nullptr;
public:
	Node(const Node& rhs) = delete;
	Node& operator =(const Node& rhs) = delete;

	Node(const T& val) :m_data(val) {	}
	const T& data()const { return m_data; }
	T& data() { return m_data; }
	Node* next() { return m_next; }
};




#endif
