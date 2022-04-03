#include "LinkedList.h"

void LinkedList::Node::SetNext(Node* nextPtr)
{
	next = nextPtr;
}

bool LinkedList::IsEmpty() const
{
	return size==0;
}

void LinkedList::InsertEnd(int value)
{
	
	if (IsEmpty()) {
		Node* node = new Node{ value };
		head = node;
	}
	else {
		Node* node = new Node{ value };
		Node* last = GetLastElement();
		last->next = node;
	}
	size++;
}

int LinkedList::GetAndRemoveLastElement()
{

	int lastValue = 0;

	if (!IsEmpty()) {
		size--;
		Node* saveHead = head;
		Node* last = nullptr;
		Node* prevLast = nullptr;

		while (head != nullptr) {
			prevLast = last;
			last = head;
			head = head->next;
		}

		head = saveHead;

		//delete prevLast next
		if (prevLast != nullptr) {
			prevLast->next = nullptr;
		}

		lastValue = last!=nullptr ? last->value : 0;

		//delete last
		delete last;

		//if size==0 then head nullptr
		if (IsEmpty()) {
			head = nullptr;
		}
	}

	return lastValue;
}

LinkedList::Node* LinkedList::GetLastElement()
{

	Node* last = nullptr;

	if (!IsEmpty()) {
		
		Node* saveHead = head;

		while (head != nullptr) {
			last = head;
			head = head->next;
		}

		head = saveHead;
		return last;
	}
}

void LinkedList::Clear()
{
	while (!IsEmpty()) {
		GetAndRemoveLastElement();
	}
}

int LinkedList::GetSize() const
{
	return size;
}

int* LinkedList::GetValues()
{
	int *nodeValues = new int[size];
	int index = 0;
	Node* saveHead = head;

	while (head != nullptr) {
		*(nodeValues + index) = head->value;
		head = head->next;
		index++;
	}

	head = saveHead;
	return nodeValues;
}
