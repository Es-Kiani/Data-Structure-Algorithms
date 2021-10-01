#ifndef STACK_H
#define STACK_H

// ? FIFO: First In First Out
class Stack
{
private:
    /* data */
public:
    Stack(/* args */);
    ~Stack();
    void push(int);
    int pop();
    int peek();
    bool isEmpty();
    int search();
};

#endif