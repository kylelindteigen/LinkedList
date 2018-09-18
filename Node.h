/*
@File Node.h
@Author Kyle Lindteigen
@Assignment: EECS-268 Lab 5
@brief .h file for the Node class that houses all of the member variables and functions
@Date October 10, 2017
*/
#ifndef NODE_H
#define NODE_H
#include<string>

template<typename T>
class Node
{
	public:

		/* Removes the entry at a given position from this list.
		@pre  None.
		@post  sets m_next equal to nullptr and m_value to the value parameter
		@param a value the user wants in this Node of type T
		*/

		Node(const T& value);

		/* Removes the entry at a given position from this list.
		@pre  None.
		@post  Initializes m_next by setting it equal to nullptr and doesn't touch
			m_value since we can't know what it is
		*/

		Node();

		/* Removes the entry at a given position from this list.
		@pre  None.
		@post  If 1 <= position <= getLength() and the removal is successful,
			the entry at the given position in the list is removed, other
			items are renumbered accordingly, and the returned value is true.
		@param position  The list position of the entry to remove.
		@throw  PrecondViolatedExcep if removal cannot be performed.
		*/

		~Node();

		/*  Overloads the = operator for the node class
		@pre  None.
		@post  sets both m_value and m_next equal to one another
		@param  setting two Nodes equal to one another
		*/

		Node<T>& operator=(const Node<T>& eq);

		/*
		@return Returns the Node that this Node is pointing to
		*/

		Node<T>* getNext();

		/*
		@return  returns the value of this Node
		*/

		T getValue()const;

		/* Sets the value in this node to the value given
		@pre  None.
		@post  Sets m_value to the given Value
		@param  a value of type T that the user wants to set in this Node
		*/

		void setValue(T& value);

		/* sets the Next Node to the given Node
		@pre  None.
		@post  Sets the m_next variable in this funtion to a given Node that the user passes
		@param  A Node that you want this Node to point to
		*/

		void setNext(Node<T>*& next);
	private:
		Node* m_next;
		T m_value;
};
#include "Node.hpp"
#endif
