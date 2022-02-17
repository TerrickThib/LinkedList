#pragma once
#include "Iterator.h"
#include <iostream>
using namespace std;

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
	Node<T>* m_first;	
	Node<T>* m_last;
	int m_nodeCount;
	
};

template<typename T>
inline List<T>::List()
{
	initialize();
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	m_first = other.m_first;
	m_last = other.m_last;
	m_nodeCount = other.m_nodeCount;
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline void List<T>::destroy()
{

	while(m_first != NULL)
	{
		Iterator<T>operator--;
		m_first = next;
	}
	m_first = NULL;
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last);
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	bool itemfound = false;
	for (Iterator<T>iter = begin();iter != end(); iter++)//set iterator to begining of list and while not at the end of list iterarate through
	{
		if (iter = object)//if iterator = object return true other whise return false
			return true;
		return false;
	}
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T>* newNode = new Node<T>(value); //Creates a new node with the value

	if (m_first != nullptr)//If first isnt null then new node is first previous
	{
		m_first->previous = newNode;//Sets firsts previous to be the new node
		newNode->next = m_first;//Set the new node's next to be first node
	}

	m_first = newNode; //Set newNode to be first

	if (m_last == nullptr)//If last is nullprt 
	{
		m_last = newNode;//Then set last to be newNode
	}

	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T>* newNode = new Node<T>(value); //Creates a new node with the value
	if(m_last != nullptr)//If last isnt null the new node is last next
		newNode = m_last->next;
	m_last = newNode;
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	return false;
}

template<typename T>
inline void List<T>::print() const
{
	Node<T> * current;
	current = m_first;

	while (current != nullptr)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}

template<typename T>
inline void List<T>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	if (index& iter < 0 || index& iter >= getLength())
		return T();

	return m_nodeCount[index];
}
