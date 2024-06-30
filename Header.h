#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node* next;



	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int d, Node* n)
	{
		data = d;
		next = n;
	}

	Node(int d)
	{
		data = d;
		next = NULL;
	}

	void setData(int d)
	{
		data = d;
	}

	void setNext(Node* n)
	{
		next = n;

	}

	int getData()
	{
		return data;
	}

	Node* getNext()
	{
		return next;
	}

};

template <typename T>
class SLinkedList {
public:

	Node<T>* head;
	SLinkedList()
	{
		head = NULL;
	}

	void insert(int d)
	{
		Node<T>* temp = new Node<T>;
		temp->setData(d);
		temp->setNext(NULL);

		if (head == NULL) // if there is the first entry
		{
			head = temp; //the temp Node will be the new head Node
		}
		else
		{
			Node<T>* p = head; //make a Node ptr that points to the head Node ptr
			while (p->getNext() != NULL) //if the next Node is not null then
			{
				p = p->getNext(); //the p Node ptr points to the next ptr
			}

			p->setNext(temp);// reached the last Node, plant the temp Node ptr here
		}
		temp = NULL;
		delete temp;//delete
		
	}

	void insertAtHead(int d)
	{
		Node<T>* temp = new Node<T>;
		temp->setData(d);
		temp->setNext(NULL);

		if (head == NULL) // if there is the first entry
		{
			head = temp; //the temp Node will be the new head Node
		}
		else
		{
			temp->next = head;
			head = temp;
			
		}
		temp = NULL;
		delete temp;//delete
	}

	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}

		return false;
	}

	int search(int d)
	{
		Node<T>* p = head;//Node ptr p will point to head
		int c = 0;//counter c 
		while (p != NULL)//search till the end of list
		{
			if (p->data == d)//if the data is found
				break;
			p = p->next;
			c++;//increment
		}
		return c;
	}

	void update(int d, int l)
	{
		Node<T>* temp = new Node<T>; //new temmp Node ptr
		temp->data = l;//data pf temp will have the vlue of v
		temp->next = NULL;//the next Node it is pointing to is null
		Node<T>* p = head;//a new Node ptr called p will point to the same thing as head
		 //Node pointer q
		while (p != NULL && p->data != d)//loop until p is null and and the data of p is equal t o given c
		{//i.e. if there is no c in data or we find c
			p = p->next;
		}

		p->data = l;

	}
	void InsertAtIndex(int l, int d)
	{
		Node<T>* temp = new Node<T>; //create new temp Node ptr
		temp->data = d; //assign given data
		temp->next = NULL; //next ptr is null for now
		Node<T>* p = head; //new Node ptr that poiunts to the head Node ptr
		Node<T>* q = head->next; //and new q Node [tr that points to the Node next to the head Node
		for (int i = 1; i < l - 1; i++) //from the first Node to the Node before the specified location
		{
			p = q; // p will point to q which points to the next Node
			q = q->next;// q will point to the next Node
		}
		p->next = temp; //thus the next p will point to temp
		temp->next = q; //the next will be q
		temp = NULL;
		delete[] temp; //delete temp
	}
	void remove(int d)
	{
		Node<T>* pre = head, * curr = head;
		while (curr->data != d && curr->next != NULL)//loop until the you find the data v or till you reahc end of list
		{
			pre = curr;// pre will be the next current
			curr = curr->next; //curr will point to the next Node
		}
		pre->next = curr->next; ///the next of pre will point to the next of curr
		delete curr;
		curr = NULL;
	}
	void print()
	{
		if (head == NULL)//if the head ptr is empty
		{
			cout << "EMPTY";//indicate that it is empty
		}
		Node<T>* p = head;//make a Node ptr that points to head
		while (p != NULL)//loop until the list ends
		{
			
			p = p->next;//move onto next Node
		}
		cout << endl;
	}
	void mergeLists(SLinkedList A);
};

/////////TASK 2/////////
template <typename T>
void SLinkedList<T>:: mergeLists(SLinkedList<T> L1)
{	
	Node<T>* temp1 = this->head;
	Node<T>* temp2 = L1.head;
	Node<T>* t;
	SLinkedList L3;
	while (temp1->next != NULL && temp2->next != NULL)
	{
		t = temp1->next;
		temp1->next = temp2;
		temp2->next = t;
		temp1 = temp1->next->next;


	}


}



