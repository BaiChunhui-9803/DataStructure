#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>
#include"BiNode.h"


template<typename T>
class BinaryTree {
public:
	BinaryTree() = default;
	BinaryTree(const int n_layer);
	BinaryTree(const BinaryTree& value) = delete;
	BinaryTree& operator=(const BinaryTree& value) = delete;
	~BinaryTree() { destroy(m_root); }
	bool empty() const { return m_root == nullptr; }
	int size() const { return size(m_root); }
	BiNode<T>* root() const { return m_root; }
	BiNode<T>* insert(const T& value) { return insert_(m_root, value); }
	BiNode<T>* search(const T& value)const;

	void preOrder(BiNode<T>* p, void(*visit)(T&));
	void inOrder(BiNode<T>* p, void(*visit)(T&));
	void postOrder(BiNode<T>* p, void(*visit)(T&));
	void destroy(BiNode<T>* p);

	void remove(BiNode<T>* p);
	BiNode<T>* parent(BiNode<T>* node) const;


private:
	int size(BiNode<T>* p) const;
	BiNode<T>* search_(BiNode<T>* p, const T& value) const;
	BiNode<T>* insert_(BiNode<T>*& p, const T& value);

	BiNode<T>* parent(BiNode<T>* p, BiNode<T>* node) const;
	BiNode<T>* minChild(BiNode<T>* p) const;

private:
	BiNode<T>* m_root = nullptr;
};

template<typename T>
BinaryTree<T>::BinaryTree(const int n_layer)
{
	for (int i = 0; i < n_layer; i++) {
		for (int j = 0; j < pow(2, i); j++) {
			insert(T(pow(2, n_layer - i) * j + pow(2, n_layer - i - 1)));
		}
	}
}

template<typename T>
inline BiNode<T>* BinaryTree<T>::search(const T& value)const {
	return search_(m_root, value);
}

template<typename T>
BiNode<T>* BinaryTree<T>::parent(BiNode<T>* node) const {
	if (m_root == nullptr || node == nullptr || node == m_root)
		return nullptr;
	return parent(m_root, node);
}

template<typename T>
void BinaryTree<T>::preOrder(BiNode<T>* p, void(*visit)(T&)) {
	if (p != nullptr)
	{
		visit(p->m_data);
		preOrder(p->m_left, visit);
		preOrder(p->m_right, visit);
	}
}


template<typename T>
void BinaryTree<T>::inOrder(BiNode<T>* p, void(*visit)(T&)) {
	if (p != nullptr)
	{
		inOrder(p->m_left, visit);
		visit(p->m_data);
		inOrder(p->m_right, visit);
	}
}

template<typename T>
void BinaryTree<T>::postOrder(BiNode<T>* p, void(*visit)(T&)) {
	if (p != nullptr)
	{
		postOrder(p->m_left, visit);
		postOrder(p->m_right, visit);
		visit(p->m_data);
	}
}

template<typename T>
void BinaryTree<T>::destroy(BiNode<T>* p) {
	if (p != nullptr)
	{
		destroy(p->m_left);
		destroy(p->m_right);
		delete p;
	}
}

template<typename T>
void BinaryTree<T>::remove(BiNode<T>* p) {
	if (p == nullptr)//���ֲ��ҷ��ؿգ���ʾ�޴�Ԫ��
		std::cout << " �޴�Ԫ��" << std::endl;
	else {
		std::cout << " ɾ��Ԫ��" << p->m_data << std::endl;
		if (p->m_left == nullptr && p->m_right == nullptr)//ɾ��Ҷ�ӽڵ�
		{
			auto p_parent = parent(p);
			if (p_parent != nullptr)//��Ҷ�ӽڵ㲻���������������һ�����ʱ
			{
				if (p_parent->m_left == p)
					p_parent->m_left = nullptr;
				else
					p_parent->m_right = nullptr;
				delete p;
			}
			else//��Ҷ�ӽڵ����������������һ�����ʱ
			{
				m_root = nullptr;
				delete p;
			}
		}
		else if (p->m_right == nullptr)//��ɾ���ڵ���������ʱ
		{
			auto p_m_left = p->m_left;
			p->m_data = p_m_left->m_data;
			p->m_left = p_m_left->m_left;
			p->m_right = p_m_left->m_right;
			delete p_m_left;
		}
		else//��ɾ�������������ʱ
		{
			auto p_minchild = minChild(p->m_right);
			auto p_mc_parent = parent(p_minchild);
			p->m_data = p_minchild->m_data;
			if (p == p_mc_parent)
				p->m_right = p_minchild->m_right;
			else
				p_mc_parent->m_left = p_minchild->m_right;
			delete p_minchild;
		}
	}
}

template<typename T>
int BinaryTree<T>::size(BiNode<T>* p) const {
	if (p == nullptr)
		return 0;
	else
		return 1 + size(p->m_left) + size(p->m_right);
}

template<typename T>
BiNode<T>* BinaryTree<T>::search_(BiNode<T>* p, const T& value)const {
	while (p != nullptr && p->m_data != value)
	{
		if (value < p->m_data)
			p = p->m_left;
		else
			p = p->m_right;
	}
	return p;
}

template<typename T>
BiNode<T>* BinaryTree<T>::insert_(BiNode<T>*& p, const T& value) {
	if (p == nullptr) {
		return p = new (std::nothrow) BiNode<T>(value);
	}
	else if (value < p->m_data)
		return insert_(p->m_left, value);
	else
		return insert_(p->m_right, value);
}

template<typename T>
BiNode<T>* BinaryTree<T>::parent(BiNode<T>* p, BiNode<T>* node)const {
	//std::pair<Node<T>*, bool> result(nullptr, false);;
	Node<T>* result = nullptr;
	if (p != nullptr)
	{
		if (p->m_left == node || p->m_right == node)
			return p;
		result = parent(p->m_left, node);
		if (result == nullptr)
			result = parent(p->m_right, node);
	}
	return result;
}

template<typename T>
BiNode<T>* BinaryTree<T>::minChild(BiNode<T>* p) const {
	if (p != nullptr)
	{
		if (p->m_left != nullptr)
			return minChild(p->m_left);
		return p;
	}
	return nullptr;
}

template<typename T>
void visit(T &value) {
	std::cout << value << " ";
}


#endif // !1
