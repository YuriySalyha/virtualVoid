#ifndef Stack_h
#define Stack_h
#include "Element.h"
#include "iCollection.h"
template<class T>
class Stack : iCollection<T>
{
public:
    void add(T data) override
    {
        if (!this->first)
        {
            this->first = new Element<T>;
            this->first->value = data;
            this->first->next = NULL;
            this->last = this->first;
        }
        else
        {
            if (this->first == this->last)
            {
                this->last = new Element<T>;
                this->last->value = data;
                this->last->next = NULL;
                this->first->next = this->last;
            }
            else
            {
                Element<T>* item = new Element<T>;
                item->value = data;
                item->next = NULL;
                this->last->next = item;
                this->last = item;
            }
        }
    }
    T operator [](int index) override
    {
        return this->get(index);
    }
    int lenght() 
    {
        Element<T>* current = this->first;
        if (!current == NULL) {
            return 0;
        }
        int counter = 1;
        while (current->next != NULL)
        {
            counter++;
            current = current->next;
        }
        return counter;
    }
private:
    T get(int index) override
    {
        index = lenght() - index - 1;
        if (index == 0)
        {
            return this->first->value;
        }
        else
        {
            Element<T>* current = this->first;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->value;
        }
    }
};
#endif