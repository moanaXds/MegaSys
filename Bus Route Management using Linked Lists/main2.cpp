#include "q2.h"


int main() 
{
	LinkedList route;
	Stop* head = nullptr;

	Stop* l1 = route.makeStop(1, "Gate 1", 0, 800, 5);
	Stop* l2 = route.makeStop(2, "Gate 2", 1, 820, 6);
	Stop* l3 = route.makeStop(3, "Gate 3", 2, 840, 7);
	Stop* l4 = route.makeStop(4, "Gate 4", 3, 900, 8);


	route.pushBack(&head, l1);
	route.pushBack(&head, l2);
	route.pushBack(&head, l3);
	route.pushBack(&head, l4);


	route.printRoute(head);

	cout << "\n----------------\n";

	Stop* removed = NULL;

	if (route.removeById(&head, 3, &removed))
	{
		cout << "Removed stop with ID: " << removed->id << endl;
		delete removed;
	}

	route.printRoute(head);

	cout << "\n----------------\n";


	Stop* newStop = route.makeStop(5, "Gate 5", 4, 920, 5);

	Stop* position = route.findById(head, 2);

	if (route.insertAfter(position, newStop))
	{
		cout << "Inserted new stop after ID: " << position->id << endl;
	}

	
	route.printRoute(head);

	cout << "\n----------------\n";


	// Test updateSched
	if (route.updateSched(head, 2, 830, 7)) 
	{
		cout << "Updated schedule for stop ID: 2" << endl;
	}
	
	route.printRoute(head);

	cout << "\n----------------\n";

	head = route.rotateLeft(head, 2);

	cout << "\n----------------\n";

	head = route.reverseSegment(head, 2, 4);
	
	route.printRoute(head);

	cout << "\n----------------\n";

	int count = route.propagateDelay(head, 1, 5);

	cout << "updated :" << count << " stops with delay of 5 min from stop ID 1:\n";
	route.printRoute(head);

	route.destroyRoute(&head);



	return 0;
}
