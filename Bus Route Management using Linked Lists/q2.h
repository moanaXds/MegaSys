
#include<iostream>
#include <cstring>

using namespace std;

class Stop {
public:
	int id;
	char name[32];
	int km;
	int schedtime;
	int dwell;
	Stop* next;

	Stop(int id, const char* name, int startkm, int schedtime, int dwell)
	{
		strcpy_s(this->name, name);
		this->id = id;
		this->km = startkm;
		this->schedtime = schedtime;
		this->dwell = dwell;
		this->next = nullptr;
	}

};

class LinkedList {
private:
	Stop* tail;

public:
	LinkedList()
	{
		tail = NULL;
	}

	Stop* makeStop(int id, const char* name, int km, int schedArr, int dwell)
	{
		Stop* newstop = new Stop(id, name, km, schedArr, dwell);

		return newstop;
	}



	void destroyRoute(Stop** head)
	{
		Stop* temp = *head;
		while (temp != NULL)
		{
			Stop* nex = temp->next;
			delete temp;
			temp = nex;
		}
		*head = NULL;
		this->tail = NULL;
	}

	void pushFront(Stop** head, Stop* node)
	{
		node->next = *head;
		*head = node;

		if (tail == nullptr)
		{
			tail = node;
		}
	}

	void pushBack(Stop** head, Stop* node)
	{
		if (*head == nullptr)
		{
			*head = node;
			tail = node;

			return;
		}

		tail->next = node;
		tail = node;
	}

	int insertAfter(Stop* pos, Stop* node)
	{
		if (pos != NULL)
		{
			node->next = pos->next;
			pos->next = node;
		}
		else
		{
			return 0;
		}
	}



	int removeById(Stop** head, int ids, Stop** out)
	{
		if (*head == nullptr) return 0;

		Stop* prev = nullptr;
		Stop* curr = *head;

		while (curr != nullptr && curr->id != ids)
		{
			prev = curr;
			curr = curr->next;
		}

		if (curr == nullptr)
		{
			*out = nullptr;
			return 0;
		}

		if (prev == nullptr)
		{
			*head = curr->next;
		}
		else
		{
			prev->next = curr->next;
		}

		if (curr == tail)
		{
			tail = prev;
		}

		curr->next = nullptr;
		*out = curr;

		return 1;
	}



	// return Node at id
	Stop* findById(Stop* head, int ids)
	{
		Stop* temp = head;
		while (temp != NULL && temp->id != ids)
		{
			temp = temp->next;
		}
		return temp;
	}

	// update schedArr and dwell of given ids

	int updateSched(Stop* head, int ids, int newSchedArr, int newDwell)
	{
		Stop* temp = head;
		while (temp != NULL && temp->id != ids)
		{
			temp = temp->next;
		}

		if (temp == NULL)return 0;

		temp->schedtime = newSchedArr;
		temp->dwell = newDwell;
		return 1;

	}

	int length(Stop* head)
	{
		int c = 0;
		Stop* temp = head;
		while (temp != NULL)
		{
			c++;
			temp = temp->next;
		}
		return c;
	}
	void printRoute(Stop* head)
	{
		Stop* temp = head;
		int i = 1;
		while (temp != NULL)
		{
			cout << "\n\n-----------ROUT NO :" << i << " DETAILS----------\n\n";

			cout << "name :" << temp->name << endl;
			cout << "Id :" << temp->id << endl;
			cout << "Km :" << temp->km << endl;
			cout << "Scheduled time" << temp->schedtime << endl;
			cout << "Minutes :" << temp->dwell << endl;

			temp = temp->next;
			i++;
		}
	}

	//===========================================================         part 2          ========================================

	Stop* reverseSegment(Stop* head, int idL, int idR)
	{
		if (head == NULL || idL <= 0 || idR <= 0)return head;

		Stop* pre = NULL;
		Stop* curr = head;
		Stop* nex = NULL;
		int i = 1;

		while (i < idL && curr != NULL)
		{
			pre = curr;
			curr = curr->next;
			i++;
		}
		// Store data of non reversed part
		Stop* store = pre;
		Stop* store2 = curr;

		// Start reversing from updated i

		while (curr != NULL && i <= idR)
		{
			nex = curr->next;
			curr->next = pre;
			pre = curr;                 // pre <- curr <- nex 
			curr = nex;
			i++;

		}

		// Finally connect non reversed and reversed Lists

		if (store != NULL)
		{
			store->next = pre;
		}
		else
		{
			head = pre;
		}

		store2->next = curr;

		return head;
	}


	Stop* rotateLeft(Stop* head, int k)
	{
		if (k <= 0)return head;
		int len = 0;

		Stop* temp = head;
		while (temp != NULL)
		{
			len++;
			temp = temp->next;
		}

		// Now we know total no of elements in list

		Stop* pre = NULL;    // at k
		Stop* curr = head;  // at k+1

		int i = 0;
		while (i < k && curr != NULL)
		{
			pre = curr;
			curr = curr->next;
			i++;
		}

		Stop* newHead = curr;

		Stop* tail1 = curr;

		while (tail1->next != NULL)
		{
			tail1 = tail1->next;
		}

		tail1->next = head;
		pre->next = NULL;
		return newHead;

	}


	int propagateDelay(Stop* head, int idX, int D)
	{
		if (head == NULL || D <= 0)return 0;

		Stop* temp = head;

		// Reaching at matching id position

		while (temp != NULL && temp->id != idX)
		{
			temp = temp->next;
		}

		// delay (add 5 to all time after idx)

		Stop* store = temp;
		int count = 0;

		while (store != NULL)
		{
			store->schedtime = store->schedtime + D;
			count++;

			store = store->next;
		}
		return count;
	}
}; 
