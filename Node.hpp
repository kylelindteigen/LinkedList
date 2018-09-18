/*
@File Node.h
@Author Kyle Lindteigen
@Assignment: EECS-268 Lab 5
@brief .hpp file for the Node class that defines all of the member functions
@Date October 10, 2017
*/
#include <string>
using namespace std;

template<typename T>
Node<T>::Node(const T& value)
{
	m_value=value;
	m_next=nullptr;
}//initializes the Node

template<typename T>
Node<T>::Node()
{
	m_next=nullptr;
}//initializes the node with no input

template<typename T>
Node<T>::~Node()
{
	if(m_next!=nullptr)
	{
		delete m_next;
	}
	//delete m_next;
}//deletes the next node

template<typename T>
Node<T>& Node<T>::operator=(const Node<T>& eq)
{
	m_next=eq.m_next;
	m_value=eq.m_value;
	return(*this);
}//sets all of the values equal

template<typename T>
Node<T>* Node<T>::getNext()
{
	return(m_next);
}//returns the next Node

template<typename T>
T Node<T>::getValue()const
{
	return(m_value);
}//returns the value of this node

template<typename T>
void Node<T>::setValue(T& value)
{
	m_value=value;
}//sets the m_value equal to the inputted value

template<typename T>
void Node<T>::setNext(Node<T>*& next)
{
	m_next=next;
}//sets the next node equal to the inputted node*
