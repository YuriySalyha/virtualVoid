#ifndef Queue_h
#define Queue_h
#include "Element.h"
#include "iCollection.h"

template <class T>
class Queue : iCollection<T>
{
public:
	void add(T data) override {
		Element<T>* item = new Element<T>;
		item->value = data;
		item->next = this->first;
		this->first = item;
	}
	T operator [](int index) override
	{
		return this->get(index);
	}
	int lenght() override
	{
		return 0;
	}
private:
	T get(int index)override
	{
		if (index == 0)
		{
			return this->first->value;
		}
		else
		{
			this->current = this->first;
			for (int i = 0; i < index; i++)
			{
				this->current = this->current->next;
			}
			return this->current->value;
		}
	}
};
#endif