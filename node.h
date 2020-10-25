#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>

template <class T, class S>
class node
{
	public:
		node* next;
		node()
		{
			next = nullptr;
			com = "===";
			desc = "???";
		}
		node(const node<T, S> &n)
		{
			com = n.com;
			desc = n.desc;
		}
		node& operator =(const node &n)
		{
			return *this;
		}
		node(T c, S d)
		{
			com = c;
			desc = d;
			next = nullptr;
		}
		void printNode()
		{
			node* temp = this;
			while (temp)
			{
				std::cout << temp->com << std::endl << temp->desc << std::endl << std::endl;
				temp = temp->next;
			}
		}

		T getCom() { return com; }
		S getDesc() { return desc; }

	private:
		T com;
		S desc;
};



#endif