#ifndef BINODE_H
#define BINODE_H

template <typename T> class BiTree;
template <typename T>
class BiNode {
	friend class BiTree<T>;
private:
	T m_data;
	BiNode* m_left = nullptr, * m_right = nullptr;
public:
	BiNode(const BiNode&) = delete;
	BiNode& operator=(const BiNode&) = delete;

	BiNode(const T& val) :m_data(val) {}
	const T& data()const { return m_data; }
	T& data() { return m_data; }
	BiNode* left() { return m_left; }
	BiNode* right() { return m_right; }

};


#endif