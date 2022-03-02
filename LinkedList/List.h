#pragma once
#include "Node.h"
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

	const List<T>& operator =(const List<T>& otherList);

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
	destroy();
}

template<typename T>
inline void List<T>::destroy()
{
	Node<T>* currentNode = m_first;
	Node<T>* tempNode;

	for (int i = 0; i < getLength(); i++)
	{
		tempNode = currentNode->next;
		delete currentNode;
		currentNode = tempNode;
	}

	initialize();
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
		if (*iter == object)//if iterator = object return true other whise return false
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
	
	if (m_last != nullptr)//If last isnt null the new node is last next
	{
		m_last->next = newNode;//Sets last next to be newNode
		newNode->previous = m_last;//Sets new nodes previous to be last
	}

	m_last = newNode;//Set newNode to be last
		
	if (m_first == nullptr)//If first is nullptr
	{
		m_first = newNode;//Then set first to be newnode
	}
	
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	//Creates a new nodes
	Node<T>* newNode = new Node<T>(value);
	Node<T>* currentNode = new Node<T>();

	//If the given index is below zero or greater than node count then it is out the list
	if (index < 0 || index > m_nodeCount)
		return false;

	//If index is 0 or its is empty then pushfront the value
	if (isEmpty() || index == 0)
	{
		pushFront(value);
		return true;
	}

	//If index is equel to nodeCount then push the value to the back
	else if (index == m_nodeCount)
	{
		pushBack(value);
		return true;
	}

	currentNode = m_first;

	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->next;//Set currentnode to be current nodes next
	}

	newNode->next = currentNode; //new nodes next is current node
	newNode->previous = currentNode->previous; //new nodes previous is current nodes previous  
	newNode->previous->next = newNode; //new nodes previous newxt is new node
	currentNode->previous = newNode; // current nodes previous is new node
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	Node<T>* nodeTobeRemoved = new Node<T>;
	nodeTobeRemoved = m_first;
	
	//Loops through the nodes and checks if the data matches the value 
	for (int i = 0; i < getLength(); i++)
	{
		if (nodeTobeRemoved->data == value)//If node to be removed is equal to value
		{
			if (nodeTobeRemoved == m_first)//If the current node matches the first in the list
			{
				m_first = nodeTobeRemoved->next;//first is node to be removed next
				m_first->previous = nullptr;//First previous is nullptr
				delete nodeTobeRemoved;
			}
			else if (nodeTobeRemoved == m_last)//if the current node matches the last in the list
			{
				m_last = nodeTobeRemoved->previous;//Last is node to be removed previous
				m_last->next = nullptr;//last next is nullptr
				delete nodeTobeRemoved;
			}
			else
			{
				//Nodes to be removed previous next is its next
				nodeTobeRemoved->previous->next = nodeTobeRemoved->next;
				//Nodes next previous is nodes previous
				nodeTobeRemoved->next->previous = nodeTobeRemoved->previous;
				delete nodeTobeRemoved;
			}
			m_nodeCount--;
			return true;
		}
		else  //If node to be removed is nodes next
			nodeTobeRemoved = nodeTobeRemoved->next;
	}
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
inline bool List<T>::isEmpty() const
{
	if (getLength() == 0)//If length is 0 return true
	{
		return true;
	}
	else
		return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	if (index < 0 || index > getLength())
	{
		return false;
	}

	iter = begin(); // sets the iterater to the beging

	for (int i = 0; i < index; i++)
	{
		++iter;
	}

	return true;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	destroy(); ///gets ride of the list data 

	//Creates a nod that is the same as the other list first
	Node<T>* otherNode = otherList.m_first;

	for (int i = 0; i < otherList.getLength(); i++)//Iterates through the other list 
	{
		insert(otherNode->data, i);//inserts data to the other node
		otherNode = otherNode->next;
	}

	return *this;
	
}

template<typename T>
inline void List<T>::sort()
{
	Node<T>* tempNode = new Node<T>();
	Node<T>* currentNode = new Node<T>();

	for (int i = 0; i < m_nodeCount - 1; i++)//Iterats through the length minus 1
	{
		currentNode = m_first; 

		for (int j = 0; j < m_nodeCount - i - 1; j++)//while i is less than the node count minus 1
		{
			if (currentNode->data > currentNode->next->data)//If currentnode is equel to current nodes next
			{
				tempNode->data = currentNode->next->data;//temp equels current nodes next
				currentNode->next->data = currentNode->data;//current nodes next is current node
				currentNode->data = tempNode->data;//current node is equel to temp node
			}
			currentNode = currentNode->next;
		}

	}
}
