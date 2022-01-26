#pragma once

template <typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();

	void destroy();

	Iterator<T> begin() const;

	Iterator<T> end() const;

	bool contains(const T object) const;

	void pushFront(const T& value);

	void pushBack(const T& value);

	bool insert(const T& value, int index);

	bool remove(const T& value);

	void print() const;

	void initialize();

	bool isEmpty() const;

	bool getData(Iterator<T>& iter, int index);

	int getLength() const;  

	const List<T>& operator = (const List<T>& otherList);

	void sort();

private:
	Node<T>* m_first / m_head;	
	Node<T>* m_last / m_tail;
	int m_nodeCount;
	
};

template<typename T>
inline List<T>::List()
{
	m_nodeCount = 0;
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline void List<T>::destroy()
{

}
