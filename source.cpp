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
void MinHeap::swap(size_t a, size_t b)
{
    // echanger deux valeur

    data_type temp = array[a]->getData();

    array[a]->setData(array[b]->getData());
    array[b]->setData(temp);
}
MinHeap::MinHeap(size_t max_size)
{
    this->array = new Node *[max_size];
    this->max_size = max_size;
    this->size = 0;

    for (size_t i = 0; i < max_size; i++) // intialiser tout le tableau avec null
        array[i] = nullptr;
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

void MinHeap::HeapfiyUp()
{
    if (isEmpty())
        return;

    size_t i = size - 1; // commencer du bas et remonte

    while (i > 0 && array[i]->getData() < array[getParent(i)]->getData())
    {
        swap(i, getParent(i));
        i = getParent(i); // changer l'indece
    }
}
void MinHeap::HeapfiyDown()
{
}
void MinHeap::insert(data_type data)
{
    Node *temp = new Node(data);

    if (size < max_size)
    {
        array[size] = temp;
        ++size;

        if (size > 1) // si la taille superieure a 1 faire un heapfiy up pour assurer l'ordre du tas
            HeapfiyUp();
    }
    else
        throw ERROR_HEAP_OVERFLOW;
}
data_type MinHeap::extract()
{
    if (size == 0)
        throw ERROR_HEAP_EMPTY;

    data_type temp = array[0]->getData();

    delete array[0]; // liberer la memoire du node racine

    if (size > 1) // si la taille du tas supperieur a 1, echanger le derniere element avec la racine
        array[0] = array[size - 1];

    array[size - 1] = nullptr;
    --size;

    if (size > 1) // si la taille superieure a 1 faire un heapfiy down pour assurer l'ordre du tas
        HeapfiyDown();
}

bool MinHeap::isEmpty()
{
    return (size == 0);
}

/* End MinHeap */