#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class linkedList
{
    public:
        //constructor/destructor
        linkedList();
        ~linkedList();

        //member functions
        void printList();
        void push(node<std::string, std::string>* n);
        void addCom();
        void removeCom();
        void writeCmdsToFile();
        void incLength();
        void decLength();

        //getters
        int getLength();
        node<std::string, std::string>* getHead();
        std::string getListComFromIndex(int index);
        std::string getListDescFromIndex(int index);
        
    private:
        node<std::string, std::string> *head; // no tail node in structure since I will not be appending in this application
        int length;

};

#endif