#include<iostream>

using namespace std;

class Node {

public:
	int id;
	string name;
	int code;
	string pstatus;
	Node* next;

	Node(string name, int id, int code, string status)
	{
		this->id = id;
		this->name = name;
		this->code = code;
		this->pstatus = status;
		next = NULL;
	}
};



class SinglyLinkedList {

	Node* head;
	Node* tail;

public:
	SinglyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void Add_Student_to_Waitlist(string name, int id, int code, string status)
	{
		Node* newnode = new Node(name, id, code, status);

		if (!head)
		{
			head = newnode;
			tail = newnode;
			return;
		}

		if (status == "Normal")
		{
			tail->next = newnode;
			tail = newnode;
		}


		else if (status == "Scholarship")
		{
			Node* temp = head;

			// insert at head
			if (head->pstatus == "Normal")
			{
				newnode->next = head;
				head = newnode;
				return;
			}

			// insert before normal
			while (temp->next != NULL && temp->next->pstatus != "Normal")
			{
				temp = temp->next;
			}
			if (temp->next != NULL)
			{
				newnode->next = temp->next;
				temp->next = newnode;
			}

			// insert at tail
			if (newnode->next == NULL)tail = newnode;
		}

	}


	void Remove_Student_from_Waitlist(string name1, int id1, int code1, string status1)
	{
		if (head == NULL)return;

		Node* pre = head;
		Node* temp = pre->next;

		//if at head

		if (head->id == id1)
		{
			Node* hd = head;
			head = head->next;
			hd->next = NULL;
			delete hd;

		}
		while (temp && temp->id != id1)
		{
			pre = temp;
			temp = temp->next;
		}
		// not found
		if (!temp) return;

		pre->next = temp->next;

		// if tail removed
		if (temp == tail)tail = pre;

		delete temp;

		cout << "Student of id :" << id1 << "has been removed successfully!\n";
	}

	int num = 0;

	void Allocate_Seat()
	{

		if (head == NULL)return;

		Node* temp = head;
		head = head->next;

		cout << "Seat Allocated to Student id: " << temp->id << endl;
		delete temp;

		num++;
	}


	void SwapRequests(int ida, int idb)
	{
		if (ida == idb)return;

		Node* pre1 = NULL;
		Node* pre2 = NULL;
		Node* temp1 = head;
		Node* temp2 = head;

		while (temp1 && temp1->id != ida)
		{
			pre1 = temp1;
			temp1 = temp1->next;
		}

		while (temp2 && temp2->id != idb)
		{
			pre2 = temp2;
			temp2 = temp2->next;
		}

		// if any not found
		if (!temp1 || !temp2) return;

		// now linked
		if (pre1)
		{
			pre1->next = temp2;
		}
		else
		{
			head = temp2;
		}

		if (pre2)
		{
			pre2->next = temp1;
		}
		else
		{
			head = temp1;
		}


		//swap

		Node* temp = temp1->next;
		temp1->next = temp2->next;
		temp2->next = temp;

		//fix tail
		if (!temp1->next) tail = temp1;
		if (!temp2->next) tail = temp2;
	}


	int FindingStudentPosition(int id1)
	{
		Node* temp = head;
		int pos = 1;

		while (temp != NULL)
		{
			if (temp->id == id1)
			{
				return pos;
			}
			temp = temp->next;
			pos++;
		}
		return -1;

	}


	void Report()
	{
		Node* temp = head;
		int waiting = 0;
		int scholar = 0;
		int normal = 0;

		cout << "\n--------------------  Waiting list ---------------------\n";

		while (temp != NULL)
		{
			waiting++;

			if (temp->pstatus == "Normal")
			{
				cout << "Normal: " << temp->name << " ID: " << temp->id << endl;
				normal++;
			}
			else
			{
				cout << "Scholarship: " << temp->name << " ID: " << temp->id << endl;
				scholar++;
			}
			temp = temp->next;
		}

		cout << "\n--------------------  Summary list ---------------------\n";
		cout << "No of student still waiting :" << waiting << endl;
		cout << "No of Scholarship student in waiting :" << scholar << endl;
		cout << "No of Normal student in waiting :" << waiting << endl;
		cout << "No of student who got seat :" << num << endl;

	}


	void Display_Waitlist()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << "Name  :  " << temp->name << endl;
			cout << "Id  :  " << temp->id << endl;
			cout << "Status  :  " << temp->pstatus << endl;
			cout << "Code  :  " << temp->code << endl;
			cout << "\n--------------------\n";
			temp = temp->next;
		}
	}
};
