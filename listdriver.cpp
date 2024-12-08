//========================================================
// CS 173
// Fall 2024
// listdriver.cpp
// This file tests the List class.
//========================================================

#include <iostream>
#include "List.h"

int main ( void )
{
	List<int> 	list1;
	cout << "list1 = " << list1 << endl;
	
	for ( int i = 1; i <= 10; i++ )
		list1.append(i);

	cout << "list1 = " << list1 << endl;

	List<int> list2(list1);
	cout << "list2 = " << list2 << endl;
	
	cout << "\nlist1.insert(50,10);\nlist1.insert(0,0)\n";
	cout << "list1.remove(1);\n"; 
	list2[2] = 100;
	list1.insert(50,10);
	list1.insert(0,0);
	list1.remove(1);
	cout << "list2 = " << list2 << endl;
	cout << "list1 = " << list1 << endl;
	
	cout << "\nlist3 new empty\n";
	List<int> list3;
	cout << "list3 size = " << list3.length() << endl;
	if ( list3.isEmpty() )
		cout << "list3 empty\n";
	else
		cout << "list3 not empty\n";

	cout << "\nlist3 = list1+list2\n";
	list3 = list1 + list2;
	cout << "list3 = " << list3 << endl;
	
	
	cout << "list3 size = " << list3.length() << endl;
	if ( list3.isEmpty() )
		cout << "list3 empty\n";
	else
		cout << "list3 not empty\n";

	cout << "\nlist3.clear()\n";
	list3.clear();

	cout << "list3 size = " << list3.length() << endl;
	if ( list3.isEmpty() )
		cout << "list3 empty\n";
	else
		cout << "list3 not empty\n";
		
	List<char> l5;
	for ( char c = 'a'; c < 'p'; c++ )
		l5.insert(c,0);
	cout << "l5 = " << l5 << endl;
	l5[0] = 'Z';
	l5.remove(1);
	cout << "l5 = " << l5 << endl;
	
	return 0;
}

