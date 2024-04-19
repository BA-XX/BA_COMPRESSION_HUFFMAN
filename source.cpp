#include "header.hpp"

using namespace ba;

/* Class Node */
Node::Node(data_type data, Node *left, Node *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

void Node::setData(data_type data)
{
    this->data = data;
}
data_type Node::getData()
{
    return data;
}

void Node::setLeft(Node *left)
{
    this->left = left;
}
Node *Node::getLeft()
{
    return left;
}

void Node::setRight(Node *right)
{
    this->right = right;
}
Node *Node::getRight()
{
    return right;
}
/* End Node*/

/* Class MinHeap */
MinHeap::MinHeap(size_t max_size)
{
    this->array = new Node *[max_size];
    this->max_size = max_size;
    this->size = 0;
}
MinHeap::~MinHeap()
{
    for (size_t i = 0; i < size; i++) // liberer la memoire de chaque node
        delete array[i];

    delete[] array;
}
size_t MinHeap::getParent(size_t i)
{
    return (i - 1) / 2;
}
size_t MinHeap::getLeftChild(size_t i)
{
    return 2 * i + 1;
}
size_t MinHeap::getRightChild(size_t i)
{
    return 2 * i + 2;
}

void MinHeap::exchange(size_t a, size_t b) // echanger deux valeurs en fournissant les index
{
    data_type temp = array[a]->getData();

    array[a]->setData(array[b]->getData());
    array[b]->setData(temp);
}
void MinHeap::HeapfiyUp()
{
}
void MinHeap::insert(data_type data)
{
    Node *temp = new Node(data);

    if (size < max_size)
    {
        array[size] = temp;
        ++size;

        if (size > 1)
            HeapfiyUp();
    }
    else
        throw ERROR_HEAP_OVERFLOW;
}
/* End MinHeap */