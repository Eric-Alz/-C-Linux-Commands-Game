		/*
		node();
		node(T c, S d);
		node(const node &n);
		node& operator =(const node &n);
		void printNode();
		T getCom();
		S getDesc();
		*/

/*
#include "node.h"

template <class T, class S>
node<T, S>::node()
{
    next = nullptr;
	com = "===";
	desc = "???";
}

template<class T, class S>
node<T, S>::node(T c, S d)
{
    com = c;
    desc = d;
}

template <class T, class S>
node<T, S>::node(const node<T, S>& n)
{
    next = nullptr;
	com = n.com;
	desc = n.desc;
}

template <class T, class S>
node<T, S>& node<T, S>::operator =(const node<T, S>& n)
{
    return *this;
}

template <class T, class S>
void node<T, S>::printNode() { std::cout << "Command: " << com << std::endl << "Description: " << desc << std::endl; }

template <class T, class S>
T node<T, S>::getCom() { return com; }

template <class T, class S>
S node<T, S>::getDesc() { return desc; }
 */