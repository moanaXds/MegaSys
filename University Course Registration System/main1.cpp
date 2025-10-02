#include "q1.h"

int main()
{
	SinglyLinkedList l1;
	l1.Add_Student_to_Waitlist("samad", 1234,100, "Normal");
	l1.Add_Student_to_Waitlist("Ali", 1212, 190, "Normal");
	l1.Display_Waitlist();

	l1.Remove_Student_from_Waitlist("amad", 1211, 100, "Scholarship");
	l1.Display_Waitlist();

	l1.Allocate_Seat();
	l1.SwapRequests(1234, 1212);
	l1.FindingStudentPosition(1212);
	l1.Display_Waitlist();

	l1.Report();

	return 0;
}