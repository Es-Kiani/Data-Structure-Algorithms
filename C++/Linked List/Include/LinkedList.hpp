#ifndef LINDEKLIST_H
#define LINDEKLIST_H

class Node
{
public:
    int _data;
    Node *_next;
    Node();
};

class Linkedlist : protected Node
{
private:
    Node *_head, *_tail;
    unsigned long int _size;

public:
    Linkedlist();
    void add_First(int);
    void add_Last(int);
    void delete_First();
    void delete_Last();
    bool contains(int);
    int indexOf(int);
    void inverse();
    int KthNodeFromEnd(long int);
    int middleNode();
};

#endif