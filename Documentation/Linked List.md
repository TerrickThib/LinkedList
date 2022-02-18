**Terrick Thibodeaux**  
S218032
Linked List  
Algorithms and Data Structures C++ 
# I.Requirments  
**1.Description of Problem**  

**Problem Statement:**  
The ablity to Insert numbers into a list at any point you want and or sort that list  

**Problem Spesfication:** 
- Should be able to PushForward a number   

- Should be able to PushBack a number   

- Should be able to insert a number at a given index  

- Should be able to remove a number form the list  

- Should be able to remove a value from the list  

- Also should be able to use bubble sort to sort list  

**Input Information:**  
- In put values using functions given  

**Output Information:**  
- Value inserted into list or list sorted  

# II.Design  
1. *System Architecture*   

Uses LinkedList to orgnise a list   

2. *Object Information*  
- **File Name:** Node.h  

Name: Node()  
Discription: Is the base Constructer  
Visablity: Public  

Name: Node(T value)  
Discription: Is the base constucter that takes in T value  
Visablity: Public    

- **File Name:** List.h  

Name: List()  
Description: Is the base constucter  
Visablity: Public  

Name: List(const List<T>& other)  
Descrition: Is the base Comstructer  
Visablity: Pubic  

Name: destroy()  
Description: deletes all nodes in the list  
Visablity: Public  

Name: begin() const  
Description: returns an iterator pointing to the first node in the list  
Visablity: Public  

Name: end() const  
Decription: returns the next item after the last node in the list  
Visablity: Public  

Name: contains(const T object) const  
Description: checks to see if the given item is in the list  
Visablity: Public  

Name: pushFront(const T& value)  
Description: adds a new node to the beginning of the list  
Visablity: Public  

Name: pushBack(const T& value)  
Description: adds a new node to the end of the list  
Visablity: Public  

Name: insert(const T& value, int index)  
Description: adds a new node at the given index  
Visablity: Public   

Name: remove(const T& value)  
Description: removes the first node with the given value  
Visablity: Public  

Name: print() const  
Description: prints the values for all the nodes  
Visablity: Public  

Name: initialize()  
Description: set the default values for the first node pointer, the last node pointer, and the node count  
Visablity: Public  

Name: isEmpty() const  
Description: returns whether or not the list has any nodes in it  
Visablity: Public  

Name: getData(Iterator<T>& iter, int index)  
Desccription: sets the given iterator to point to a node at the given index 
Visablity: Public  

Name: getLength() const  
Description: returns the amount of nodes in the list  
Visablity: Public  

Name: List<T>& operator =(const List<T>& otherList)  
Description: Copys values from one list to another  
Visablity: Public  

Name: sort()
Description: Sorts list using bubble sort  
Visablity: Public  





