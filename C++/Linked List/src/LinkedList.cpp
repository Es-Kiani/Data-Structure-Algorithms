#include "../include/LinkedList.hpp"
#include <iostream>
using namespace std;

Node::Node()
{
    _data = NULL;
    _next = nullptr;
}

Linkedlist::Linkedlist() : Node()
{
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

void Linkedlist::add_First(int got_Value)
{
    Node *new_Node = new Node;
    new_Node->_data = got_Value;
    if (_head == nullptr)
        _tail = new_Node;
    else
        new_Node->_next = _head;

    _head = new_Node;
    _size++;
    return;
}

void Linkedlist::add_Last(int got_Value)
{
    Node *new_Node = new Node;
    new_Node->_data = got_Value;

    if (_head == nullptr)
        _head = new_Node;
    else
        _tail->_next = new_Node;

    _tail = new_Node;
    _size++;
    return;
}

void Linkedlist::delete_First()
{
    if (_head == nullptr)
    {
        cerr << "Your Linked List Is Empty!/n";
        return;
    }
    else if (_head == _tail)
    {
        Node *deleted_Head = _head;
        _head = nullptr;
        _tail = nullptr;
        delete deleted_Head;
    }
    else
    {
        Node *deleted_Head = _head;
        _head = _head->_next;
        delete deleted_Head;
    }
    cout << "First Item Deleted.";
    _size--;
    return;
}

void Linkedlist::delete_Last()
{
    if (_head == nullptr)
    {
        cerr << "Your Linked List Is Empty!/n";
        return;
    }
    else if (_head == _tail)
    {
        Node *deleted_Head = _head;
        _head = nullptr;
        _tail = nullptr;
        delete deleted_Head;
    }
    else
    {
        Node *deleted_Tail = _tail;

        bool isFindTargetNode = false;
        Node *present_Node = _head;
        while (!isFindTargetNode)
        {
            if (present_Node->_next == _tail)
            {
                _tail = present_Node;
                _tail->_next = nullptr;
                delete deleted_Tail;
                isFindTargetNode = true;
            }
            else
                present_Node = present_Node->_next;
        }
    }
    cout << "Last Item Deleted";
    _size--;
    return;
}

int Linkedlist::indexOf(int target_Data)
{
    if (_head == nullptr)
    {
        cerr << "Your Linked List Is Empty!";
        return -1;
    }
    else
    {
        int index = 0;
        Node *present_Node = _head;
        while (1)
        {
            if (present_Node->_data == target_Data)
                return index;
            else if (present_Node == _tail)
                return -1;
            else
            {
                present_Node = present_Node->_next;
                index++;
            }
        }
        /*
        while (index != _size - 1)
        {
            if (present_Node->_data == target_Data)
                return index;
            else
            {
                present_Node = present_Node->_next;
                index++;
            }
        }
        return -1;
        */
    }
}

bool Linkedlist::contains(int target_Data)
{
    if (_head == nullptr)
    {
        cerr << "Your Linked List Is Empty!";
        return false;
    }
    else
    {
        //! Dirty Code
        // Node *present_Node = _head;
        // while (1)
        // {
        //     if (present_Node->_data == target_Data)
        //         return true;
        //     else if (present_Node == _tail)
        //         return false;
        //     else
        //         present_Node = present_Node->_next;
        // }

        //* Clean Code
        return indexOf(target_Data) >= 0 ? true : false;
    }
}

void Linkedlist::inverse()
{
    // For Non Single or Empty List
    if (_head != _tail)
    {
        Linkedlist new_List;
        Node *present_Node = _head;
        while (present_Node != nullptr)
        {
            new_List.add_First(present_Node->_data);
            present_Node = present_Node->_next;
        }
        // delete this;
        this->_head = new_List._head;
        this->_tail = new_List._tail;
        this->_size = new_List._size;
    }
    cout << "List Inverted.\n";
    return;
}

int Linkedlist::KthNodeFromEnd(long int target_Node_FromEnd)
{
    if (target_Node_FromEnd <= 0)
        throw invalid_argument("Error\n           Reverse Node Index Start From 1!");
    else if (target_Node_FromEnd == _size)
        return _head->_data;
    else if (target_Node_FromEnd == 1)
        return _tail->_data;
    else
    {
        const long int best_Distance = target_Node_FromEnd - 1;
        unsigned long int current_Distance = 0;

        Node *node_ptr1 = _head;
        Node *node_ptr2 = _head;

        while (node_ptr1 != _tail)
        {
            node_ptr1 = node_ptr1->_next;
            if (current_Distance != best_Distance)
                current_Distance++;
            else
                node_ptr2 = node_ptr2->_next;
        }
        return node_ptr2->_data;
    }
}

int Linkedlist::middleNode()
{
    // //! With Using {size} Variable
    // if (_size == 0)
    //     cerr << "Your Linked List Is Empty!";
    // else if (_size < 3)
    //     return _head->_data;
    // else {
    //     unsigned int middle_Index = _size / 2;
    //     Node *current_Node = _head;
    //     for (size_t i = 1; i < middle_Index; i++)
    //         current_Node = current_Node->_next;
    //     return current_Node->_data; }

    //* Without Using {size} Variable
    if (_head == _tail)
        cerr << "Your Linked List Is Empty!";
    else
    {
        Node *fast_Node = _head;
        Node *slow_Node = _head;

        bool should_SlowNode_Move = false;
        while (fast_Node != _tail)
        {
            if (should_SlowNode_Move)
            {
                fast_Node = fast_Node->_next;
                slow_Node = slow_Node->_next;
                should_SlowNode_Move = false;
            }
            else
            {
                fast_Node = fast_Node->_next;
                should_SlowNode_Move = true;
            }
        }
        return slow_Node->_data;
    }
}
