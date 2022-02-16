#include <Windows.h>
#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> willwork = List<int>();

	willwork.pushFront(3);
	willwork.pushFront(5);
	willwork.print();

	return 0;
}