#include <iostream>
#include "../include/Array.hpp"
using namespace std;

Array::Array(int length = 0)
{
    _elementsCount = 0;
    _length = length;
    _array = new int[length];
}

void Array::insert(int newElement)
{
    if (this->_elementsCount == this->_length)
    {
        Array newArray(this->_length * 2);
        for (size_t i = 0; i < this->_elementsCount; i++)
        {
            newArray._array[i] = this->_array[i];
        }
        newArray._array[this->_elementsCount++] = newElement;

        this->_array = newArray._array;
        this->_length = newArray._length;
        newArray._elementsCount = this->_elementsCount;
    }
    else
    {
        _array[_elementsCount++] = newElement;
    }

    return;
}

void Array::removeAt(int index)
{
    if (index < 0 or index >= _elementsCount)
    {
        cerr << "Invalid Index For Remove...!\n";
        return;
    }

    for (size_t i = index; i < _length; i++)
    {
        if (i == _length - 1)
        {
            _array[i] = NULL;
            break;
        }
        _array[i] = _array[i + 1];
    }
    _elementsCount--;
    return;
}

int Array::indexOf(int targetItem)
{
    for (size_t i = 0; i < _elementsCount; i++)
        if (_array[i] == targetItem)
            return i;

    return -1;
}

void Array::print()
{
    cout << "[";
    for (size_t i = 0; i < _elementsCount; i++)
    {
        cout << _array[i];
        if (i == _elementsCount - 1)
            break;
        cout << ", ";
    }
    cout << "]" << endl;
    return;
}

int Array::max()
{
    // O(n)
    int max = _array[0];

    for (size_t i = 1; i < _elementsCount; i++)
        if (_array[i] > max)
            max = _array[i];

    return max;
}

Array Array::intersect(Array gotArr)
{
    Array intersectArr(_elementsCount);

    for (size_t i = 0; i < this->_elementsCount; i++)
        if (gotArr.indexOf(_array[i]) >= 0)
            intersectArr.insert(_array[i]);

    return intersectArr;
}

void Array::reverse()
{
    int middle = _elementsCount % 2 == 0 ? (_elementsCount / 2) - 1 : _elementsCount / 2;

    int temp;
    for (size_t i = 0; i <= middle; i++)
    {
        temp = _array[i];
        _array[i] = _array[_elementsCount - 1 - i];
        _array[_elementsCount - 1 - i] = temp;
    }
    print();
    return;
}

void Array::insertAt(int newElement, int targetIndex)
{
    if (targetIndex < 0 or targetIndex > _elementsCount)
    {
        cerr << "Invalid Index For Remove...!\n";
        return;
    }

    if (this->_elementsCount == this->_length)
    {
        Array newArray(this->_length * 2);
        for (size_t i = 0; i <= this->_elementsCount; i++)
        {
            if (i == targetIndex)
                newArray._array[i] = newElement;
            else if (i > targetIndex)
                newArray._array[i] = this->_array[i - 1];
            else
                newArray._array[i] = this->_array[i];
        }
        newArray._array[this->_elementsCount++] = newElement;

        this->_array = newArray._array;
        this->_length = newArray._length;
    }
    else
    {
        for (int i = _elementsCount - 1; i >= targetIndex; i--)
            _array[i + 1] = _array[i];

        _array[targetIndex] = newElement;
        _elementsCount++;
    }

    return;
}
