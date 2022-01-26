#pragma once

template <typename T>
class Node
{
public:
	Node();
	Node(T value);

	Node<T>* next;
	Node<T>* previous;
	T data;

private:

};

