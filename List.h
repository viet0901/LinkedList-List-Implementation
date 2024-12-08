//========================================================
// CS 173
// Fall 2024
// List.h
// This file contains the List class declaration.  
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef LIST_H
#define LIST_H

#define DEFAULT_LIST_CAPACITY 10


template <class T> 
class List
{
	public:
				List		(  );
				List		( const List<T> &mylist );
				~List		(  );
	List<T>		operator=	( const List<T> &mylist );
	void		append		( const T &item	);
	T &			operator[]	( int index );
	void		insert		( const T &item, int index );
	void		remove		( int index );
	List<T>		operator+	( const List<T> &mylist ) const;
	int			length		(  ) const;
	bool		isEmpty		(  ) const;
	void		clear		(  );

	friend ostream & operator<< ( ostream &os, List<T> &mylist )
	{
		Node *ptr = mylist.head;
		os << "[ ";
		while ( ptr != NULL )
		{
			if ( ptr->next != NULL )
				os << ptr->item << ", ";
			else
				os << ptr->item << " ";
			ptr = ptr->next;
		}
		os << "]";
		return os;	
	}

	private:
		// struct for Node for linked list
		struct Node
		{
			T		item;
			Node 	*next;
		};
		
		Node	*head;		// the pointer for the linked list
};


#include "List.cpp"

#endif


