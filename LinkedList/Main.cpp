#include <Windows.h>
#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> willwork = List<int>();

	willwork.pushFront(3);
	willwork.pushFront(5);
	willwork.pushBack(56);
	willwork.insert(33, 2);

	willwork.print();

	system("pause");

	willwork.sort();
	willwork.print();

	system("pause");
	willwork.remove(5);
	willwork.print();
	return 0;
}