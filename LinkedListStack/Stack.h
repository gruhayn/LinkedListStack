#pragma once
#include "LinkedList.h"

class Stack
{

public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;

	Stack() = default;

	Stack(Stack& other) {
		*this = other;
	}

	Stack& operator=(Stack& other) {
		list.Clear();
		int* values = other.list.GetValues();

		for (int i = 0; i < other.list.GetSize(); i++) {
			list.InsertEnd(*(values + i));
		}

		delete[] values;
		return *this;
	}

	~Stack() {
		list.Clear();
	}

private:
	LinkedList list;
};