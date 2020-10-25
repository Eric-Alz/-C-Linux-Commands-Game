#include "linkedList.h"

// constructor/destructor
linkedList::linkedList() // O(1)
{
    head = nullptr;
	length = 0;
}

linkedList::~linkedList() // O(n)
{
    node<std::string, std::string>* current = this->head;
	node<std::string, std::string>* temp;
    while (current)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
}

// member functions
void linkedList::printList() // O(n)
{
	int count = 0;
	node<std::string, std::string>* temp = head;
	while (temp)
	{
		std::cout << "Node: " << count << std::endl << temp->getCom() << std::endl << temp->getDesc() << std::endl << std::endl;
		temp = temp->next;
		count++;
	}
}

void linkedList::push(node<std::string, std::string>* node) // O(1)
{
	if (!head){
        head = node;
    }
	else
	{
		node->next = head;
		head = node;
	}
}

void linkedList::addCom() // O(1)
{
	std::string com, des;
	std::cout << "Enter command name: " << std::endl;
	std::cin >> com;
	std::cout << "Enter command description" << std::endl;
	getline(std::cin >> std::ws, des); //credit to stack overflow for this line
	push(new node<std::string, std::string>(com, des));
}

void linkedList::removeCom() // O(n)
{
	//read in command name user wants to delete
	std::string targetStr, currentStr;
	std::cout << "Enter name of command you would like to remove: " << std::endl;
	std::cin >> targetStr;
	node<std::string, std::string>* temp = head, * deleteNode;

	// find command user wants to delete
	while (temp->next)
	{
		currentStr = (temp->next)->getCom();
		if (currentStr == targetStr)
		{
			deleteNode = temp->next; // save adress of node that needs to be deleted
			temp->next = (temp->next)->next;
			delete deleteNode; // delete node of command being deleted ot avoid memory leak
			std::cout << "Command successfully deleted!" << std::endl;
			return;
		}
		temp = temp->next;
	}
	std::cout << "Command not found..." << std::endl;
}

void linkedList::writeCmdsToFile() // O(n)
{
	//open file
	std::ofstream file;
	file.open("commands.csv");

	//write commands/descriptions to file
	node<std::string, std::string>* temp = head;
	while (temp)
	{
		file << temp->getCom() << "," << temp->getDesc();
		if (temp->next) file << "\n";
		temp = temp->next;
	}
	file.close();
}

// setters/getters
void linkedList::incLength() { length++; } // O(1)
void linkedList::decLength() { length--; } // O(1)
int linkedList::getLength() { return length; } // O(1)
node<std::string, std::string>* linkedList::getHead(){ return head; } // O(1)

std::string linkedList::getListComFromIndex(int index) // O(n)
{
	node<std::string, std::string>* temp = head;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    return temp->getCom();
}

std::string linkedList::getListDescFromIndex(int target) // O(n)
{
	node<std::string, std::string>* temp = head;
    for (int i = 0; temp; i++)
	{
		if (i == target) return temp->getDesc();
        temp = temp->next;
	}
    return "";
}