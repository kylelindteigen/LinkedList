/*
@File LinkedList.h
@Author Kyle Lindteigen
@Assignment: EECS-268 Lab 5
@brief .h file for the LinkedList class houses all of the class info such as private variables and public member functions
@Date October 10, 2017
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include "ListInterface.h"
#include "PrecondViolatedExcep.h"
#include "Stack.h"
#include <string>

template<typename T>
class LinkedList : public ListInterface<T>
{
	public:

		/* Initializes variables
		@pre  None.
		@post  initializes variables by setting m_front=nullptr and m_length=0
		*/

		LinkedList();

		/* copy class
		@pre  None.
		@post  m_length equal to aList's m_length and copys aList's m_front and sets the copy
			equal to m_front
		@param aList, a list that you are copying to the original
		*/

		LinkedList(const LinkedList<T>& aList);

		/* dealocates the memory of this class
		@post  deletes m_front
		*/

		~LinkedList();

		/* Returns true if the list is empty or false if it is not
		@pre  None.
		@post  if m_front==nullptr then it returns true if not then returns false
		*/

		bool isEmpty()const;

		/* Returns the length of the list
		@pre  None.
		@post  returns m_length
		*/

		int getLength()const;

		/* Removes the entry at a given position from this list.
		@pre  None.
		@post  If 1 <= position <= getLength() then it goes to the node one before the position
			and then sets the desired entry equal to the next node and then sets the node that
			used to be at that position equal to the node after the new entry
		@param position, the position where you want to insert your value.
		@param newEntry, the entry that you want in the new position
		@throw  PrecondViolatedExcep if the position is invalid
		*/

		void insert(int newPosition, const T& newEntry) throw(PrecondViolatedExcep);

		/* Removes the entry at a given position from this list.
		@pre  None.
		@post  If 1 <= position <= getLength() it goes through the list and deletes the entry
			at that position and then sets the node after it to where it was
		@param position  The list position of the entry to remove.
		@throw  PrecondViolatedExcep if the position is invalid
		*/

		void remove(int position) throw(PrecondViolatedExcep);

		/* deletes the entire list
		@pre  None.
		@post  deletes m_front
		*/

		void clear();

		/* Returns the Entry at the position that the user wants
		@pre  None.
		@post  If 1 <= position <= getLength() then goes through the linked list and returns
			the value at the desired position
		@param position, position that the user wants the entry of
		@throw  PrecondViolatedExcep if the position is invalid
		*/

		T getEntry(int position)const throw(PrecondViolatedExcep);

		/* sets the entry at the given position and removes everything after that position
		@pre  None.
		@post  If 1 <= position <= getLength()+1 then goes through the LinkedList and sets the newEntry
			at the desired position and deletes everything after that
		@param position, the position that you want to set the new entry at
		@param newEntry, the new entry that you want to set at the position
		@throw  PrecondViolatedExcep if setEntry can't be performed
		*/

		void setEntry(int position, const T& newEntry)throw(PrecondViolatedExcep);

		/* operator overloads the equal operation for this class
		@pre  None.
		@post  sets the m_front node equal to the eq m_front node and sets the m_lengths equal
		@param another LinkedList variable
		*/

		LinkedList<T>& operator=(const LinkedList<T>& eq);
	private:
		Node<T>* m_front;
		int m_length;
};
#include "LinkedList.hpp"
#endif
