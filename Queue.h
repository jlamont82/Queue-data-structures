#pragma once
#ifndef QUEUE_H
#define QUEUE_H
template <class Type>
class Queue             // queue class
{
private:
    Type* Contents;
    int queue_size;
    int Front, Back;

public:
    Queue(int queue_size = 10);
    ~Queue();
    bool Empty() const;
    bool Full() const;
    bool Remove(Type& front_element);
    bool Add(const Type& new_element);

    int Find(Type element)                      // function to find in queue which accepts the Person in the argument
    {
        for (int i = 0; i < queue_size; ++i)
        {
            if (element == Contents[Front + i]) return i;
        }

        return -1;
    }

    int Size()
    {
        return Back - Front;
    }
};
#endif
