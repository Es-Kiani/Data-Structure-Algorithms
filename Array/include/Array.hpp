#ifndef ARRAY_H
#define ARRAY_H

class Array
{
private:
    int *_array = nullptr;
    int _length;
    int _elementsCount;

public:
    Array(int);
    void insert(int);
    void removeAt(int);
    int indexOf(int);
    void print();
    int max();
    Array intersect(Array);
    void reverse();
    void insertAt(int,int);
};

#endif