#pragma once

class LinkedList
{
	class Node {
	public:
		void SetNext(Node* nextPtr);

	public:
		int value=0;
		Node* next = nullptr;
	};

public:
	bool IsEmpty() const;
	void InsertEnd(int value);
	int GetAndRemoveLastElement();
	Node* GetLastElement();
	void Clear();
	int GetSize() const;
	int* GetValues();

private:
	int size = 0;
	Node* head=nullptr;

};