#ifndef Element_h
#define Element_h
template<class T>
class Element
{
public:
    Element<T>* next;
    T value;
};
#endif