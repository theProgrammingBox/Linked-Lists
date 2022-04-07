#include "Header.h"

int main()
{
	StudentNode* head = NULL;
	StudentNode* tail = NULL;

	Input(head, tail);

	Output(head);
	
	Search(head);
	
	cout << "Average GPA: " << Average(head) << "\n\n";

	RemoveFront(head);
	
	return 0;
}