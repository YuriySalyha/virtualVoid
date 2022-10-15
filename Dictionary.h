#ifndef Dictionary_h
#define Dictionary_h
#include <string>

template<class T, class U>
class keyValuePair {
public:
	T key;
	U value;
	keyValuePair <T, U>* next;
};

template<class T, class U>
class Dictionary {
	keyValuePair<T, U>* first;
	keyValuePair<T, U>* last;
public:
	Dictionary<T, U>()
	{
		first = NULL;
	}
	void add(T key, U value) {
		if (!this->first)
		{
			this->first = new keyValuePair<T, U>;
			this->first->value = value;
			this->first->key = key;
			this->first->next = NULL;
			this->last = this->first;
		}
		else
		{
			if (this->first == this->last)
			{
				this->last = new keyValuePair<T, U>;
				this->last->value = value;
				this->last->key = key;
				this->last->next = NULL;
				this->first->next = this->last;
			}
			else
			{
				keyValuePair<T, U>* item = new keyValuePair<T, U>;
				item->value = value;
				item->key = key;
				item->next = NULL;
				this->last->next = item;
				this->last = item;
			}
		}
	}
	// 3223 + 332
	Dictionary operator +( keyValuePair<T, U> var) {
		add(var);
		return this;
	}
	void operator +(Dictionary<T, U> list) {
		this->last->next = list.first;
	}
	void add(keyValuePair<T, U> value) {
		if (checkKey) {
			return;
		}
		value->next = NULL;
		if (!this->first)
		{
			this->first = new keyValuePair<T, U>;
			this->first = value;
			this->last = this->first;
		}
		else
		{
			if (this->first == this->last)
			{
				this->last = new keyValuePair<T, U>;
				this->last = value;
				this->first->next = this->last;
			}
			else
			{
				this->last->next = value;
				this->last = value;
			}
		}
	}
	bool checkKey(U key) {
		int len = lenght();
		keyValuePair<T, U>* current = this->first;
		for (int i = 0; i < len; i++)
		{
			if (key == current->key) {
				return true;
			}
			current = current->next;
		}
		return false;
	}
	std::string toString() {
		std::string output = "";
		int len = lenght();
		keyValuePair<T, U>* current = this->first;
		for (int i = 0; i < len; i++) {
			output += std::to_string(current->key) + ", " + std::to_string(current->value) + "; ";
			current = current->next;
		}
		return output;
	}
	void sortByValue(bool increase = true) {
		keyValuePair<T, U>* current = this->first;
		keyValuePair<T, U> newList;
		int leng = lenght() + 1;
		int max = 0;
		current = this->first;
		for (int i = 0; i < leng; i++) {
			if (max < current->value && increase == false) {
				max = current->value;
			}
			if (max > current->value && increase == true) {
				max = current->value;
			}
			current = current->next;
		}
		int level;
		if (increase) {
			level = max - 1;
		}
		else {
			level = max + 1;
		}
		for (int j = 0; j < leng - 1; j++) {
			int counter = 1;
			current = this->first;
			int number;
			bool indicator = true;
			int maxIdex;
			for (int i = 0; i < leng; i++) {
				if (indicator) {
					if (increase && current->value > level) {
						max = current->value;
						indicator = false;
					}
					if (!increase && current->value < level) {
						max = current->value;
						indicator = false;
					}
				}
				else if (max == current->value) {
					counter++;
				}
				if (current->value < level && current->value > max && increase == false) {
					counter = 1;
					max = current->value;
					maxIdex = i;
				}
				if (current->value > level && current->value < max && increase == true) {
					counter = 1;
					max = current->value;
					maxIdex = i;
				}
				current = current->next;
			}
			for (int q = 0; q < counter; q++) {
				newList.add(first[maxIdex]);
			}
			if (increase) {
				level = max + 1;
			}
			else {
				level = max - 1;
			}
		}
		return newList;
	}
	// operator+
	U operator [](T index)
	{
		return this->get(index);
	}
	int lenght() {
		keyValuePair<T, U>* current = this->first;
		if (current == NULL) {
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
	U get(T index) {
		keyValuePair<T, U>* current2 = this->first;
		int len = lenght();
		for (int i = 0; i < len; i++) {
			if (index == current2->key) {
				return current2->value;
			}
			current2 = current2->next;
		}
		
	}
};
#endif