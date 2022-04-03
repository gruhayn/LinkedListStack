#include "Stack.h"

void Stack::Push(int val)
{
	list.InsertEnd(val);
}

int Stack::Pop()
{
	return list.GetAndRemoveLastElement();
}

int Stack::Size() const
{
	return list.GetSize();
}

bool Stack::Empty() const
{
	return list.IsEmpty();
}
