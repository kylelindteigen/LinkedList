/*
@File LinkedList.hpp
@Author Kyle Lindteigen
@Assignment: EECS-268 Lab 5
@brief hpp file for LinkedList class that just houses all of the member functions
@Date October 10, 2017
*/
#include <string>
#include <iostream>
#include "Node.h"
#include "ListInterface.h"
#include "Stack.h"

template<typename T>
LinkedList<T>::LinkedList()
{
	m_front=nullptr;
	m_length=0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& aList)
{
	Node<T> temp();
	m_length=aList.m_length;
	temp=aList.m_front;
	m_front=temp;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	delete m_front;
}

template<typename T>
bool LinkedList<T>::isEmpty()const
{
	if(m_front==nullptr)
	{
		return(1);
	}
	return(0);
}

template<typename T>
int LinkedList<T>::getLength()const
{
	return(m_length);
}

template<typename T>
void LinkedList<T>::insert(int position, const T& newEntry) throw(PrecondViolatedExcep)
{
	Node<T>* temp=nullptr;
	Node<T>* temp2=nullptr;
	Node<T>* temp3=nullptr;
	if(position<1||position>(m_length+1))
	{
		throw(PrecondViolatedExcep("The inputted position is larger than the length"));
	}
	else if(m_front==nullptr)
	{
		m_front=new Node<T>(newEntry);
		m_length++;
	}
	else if(position==1)
	{
		temp2=m_front;
		m_front=new Node<T>(newEntry);
		m_front->setNext(temp2);
		m_length++;
	}
	else
	{
		temp2=m_front;
		for(int i=1;i<position-1;i++)
		{
			temp2=temp2->getNext();
		}
		if(m_front->getNext()==nullptr)
		{
			temp=new Node<T>(newEntry);
			m_front->setNext(temp);
			m_length++;
			temp=nullptr;
		}
		else
		{
			temp=temp2->getNext();
			temp3=new Node<T>(newEntry);
			temp2->setNext(temp3);
			temp3->setNext(temp);
			m_length++;
			temp=nullptr;
			temp2=nullptr;
			temp3=nullptr;
		}
	}//inserts the new entry into the position
}

template<typename T>
void LinkedList<T>::remove(int position)throw(PrecondViolatedExcep)
{
	Node<T>* temp=nullptr;
	Node<T>* temp2=nullptr;
	Node<T>* temp3=nullptr;
	if(position<1||position>m_length)
	{
		throw(PrecondViolatedExcep(""));
	}//throws error if the position is too long or short
	else if(m_front->getNext()==nullptr)
	{
		delete m_front;
		m_front=nullptr;
	}
	else if(position==1)
	{
		temp=m_front->getNext();
		m_front->setNext(temp2);
		delete m_front;
		m_front=temp;
		m_length--;
	}//removes the first node and then moves everything after it up one
	else
	{
		temp=m_front;
		for(int i=1; i<position-1; i++)
		{
			temp=temp->getNext();
		}
		temp2=temp->getNext();
		temp3=temp2->getNext();
		temp->setNext(temp3);
		if(position!=m_length)
		{
			temp=nullptr;
			temp2->setNext(temp);
		}
		delete temp2;
		m_length--;
	}
}

template<typename T>
void LinkedList<T>::clear()
{
	while(!this->isEmpty())
	{
		this->remove(1);
	}
	//delete m_front;
}

template<typename T>
T LinkedList<T>::getEntry(int position)const throw(PrecondViolatedExcep)
{
	Node<T>* temp=m_front;
	if(position<1||position>m_length+1)
	{
		throw(PrecondViolatedExcep(""));
	}
	else
	{
		for(int i=1; i<position; i++)
		{
			temp=temp->getNext();
		}
		return(temp->getValue());
	}//returns the Node at the position given
}

template<typename T>
void LinkedList<T>::setEntry(int position, const T& newEntry)throw(PrecondViolatedExcep)
{
	if(position<1||position>m_length)
	{
		throw(PrecondViolatedExcep(""));
	}//if the position is not a position of one of the entry then throws error
	Node<T>* temp=m_front;
	for(int i=1; i<position; i++)
	{
		temp=temp->getNext();
	}
	delete temp;
	Node<T>* temp2=new Node<T>(newEntry);
	if(position==1)
	{
		m_front=temp2;
	}
	else
	{
		temp=m_front;
		for(int i=1; i<position-1; i++)
		{
			temp=temp->getNext();
		}
		temp->setNext(temp2);
	}//sets the new entry at the position equal to the new entry
	m_length=position;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& eq)
{
	m_front=eq.m_front;
	m_length=eq.m_length;
	return(*this);
}
