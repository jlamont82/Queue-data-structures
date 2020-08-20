#pragma once
#ifndef QUEUETEMPLATE_H
#define QUEUETEMPLATE_H
#include "queue.h"

// Constructor
template <class Type>
Queue<Type> ::Queue(int queue_size) : queue_size(queue_size), Contents(new Type[queue_size + 1]), Front(0), Back(0)
{}

// Destructor
template <class Type>
Queue<Type> :: ~Queue()
{
    //delete[] Contents;
}
// Tests
template <class Type>
bool Queue<Type> ::Empty() const
{
    return (Front == Back);
}

template <class Type>
bool Queue<Type> ::Full() const
{
    return ((1 + Back) % (queue_size + 1) == Front);
}

// Remove and Add
template <class Type>
bool Queue<Type> ::Remove(Type& front_element)
{
    if (Empty()) return false;

    front_element = Contents[Front];
    Front = (Front + 1) % (queue_size + 1);     
    return true;
}

template <class Type>
bool Queue<Type> ::Add(const Type& new_element)
{
    if (Full()) return false;

    Contents[Back] = new_element;
    Back = (Back + 1) % (queue_size + 1);
    return true;
}

#endif