

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class node
{
public:
	string data;
	node * next;
};

//Create a linkedList class here
class linkedList
{
private:
	node*head;

public:
	linkedList()
	{
		head = nullptr;
	}
	void addFront(string a)
	{
		node *babyNode; //pointer
		babyNode = new node; //create new node
		(*babyNode).next = head; //set pointer to point at head
		(*babyNode).data = a;
		head = babyNode;
	}
	void display()
	{
		node*temp = head;
		do
		{
			cout << (*temp).data << endl;
			temp = (*temp).next;
		} while (temp != nullptr);
	}
	void removeFront()
	{
		node*doom = head;
		head = (*head).next;
		delete doom;
	}
	void addBack(string a)
	{
		node*back;
		back = new node;
		back->data = a;
		back->next = nullptr;

		if (head == nullptr)
		{
			head = back;
		}
		else
		{
			node * temp;
			temp = head;
			while ((*temp).next != nullptr)
			{
				temp = (*temp).next;
			}
			temp->next = back;
		}
	}
	void remove(string a)
	{
		node*temp;
		temp = head;
		if (head->data == a)
		{
			temp = head->next;
			head->next = nullptr;
			head = temp;
		}
		else
		{
			while (temp->next != nullptr && temp->next->data != a)
			{
				temp = temp->next;
			}
			node *remove = temp->next;
			temp->next = temp->next->next;
			delete remove;
		}
	}
	void sort()
	{
		node*prev;
		prev= head;
		node*current = head->next;
		if (head == nullptr)
		{
			cout << "Empty list" << endl;
		}

		else
		{
			while (prev->next != nullptr)
			{
				if (prev->data > current->data)
				{
					node*temp = new node;
					temp->data = prev->data;
					prev->data = current->data;
					current->data = temp->data;
					delete temp;
				}
				else if (current->next == nullptr)
				{
					prev = prev->next;
					current = prev->next;
				}
				else
				{
					current = current->next;
				}
			}
		}
		
	}


		
		
};


int main()
{
	//part 0:  Implement adding items to the front and displaying the list
	linkedList list1;

	list1.addFront("pichacu");
	list1.addFront("elmo");
	list1.addFront("charmander");
	list1.addFront("ekans");

	list1.display(); //ekans charmander elmo pichacu


	//part 0.1:  Implement removal from front
	list1.removeFront();
	list1.removeFront();

	list1.addFront("snorlax");

	list1.display(); //snorlax elmo pichacu


	//part 1:  implement "addBack"
	linkedList list2;
	list2.addBack("rattata");
	list2.addBack("raticate");
	list2.addBack("arcanine");
	list2.addFront("arbok");
	list2.addFront("eevee");

	list2.display(); //eevee arbok rattata raticate arcanine

	
	//part 2: implement "remove"
	list2.remove("arcanine");
	list2.remove("rattata");
	list2.remove("eevee");

	list2.addFront("dugtrio");
	list2.addBack("charizard");

	list2.display(); //dugtrio arbok raticate charizard
	
	//part 3: implement "sort"
	list1.sort();
	list2.sort();

	list1.display(); //elmo pichacu snorlax
	list2.display(); //arbok charizard dugtrio raticate
	

	return 0;
}