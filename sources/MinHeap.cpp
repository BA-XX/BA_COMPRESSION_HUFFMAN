#include "../header.hpp"

using namespace ba;

/* Class MinHeap */
void MinHeap::swap(size_t a, size_t b)
{
    // echanger deux valeur

    Node *temp = array[a];

    array[a] = array[b];
    array[b] = temp;
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
    size_t i = 0;

    while (i < size / 2)
    {
        size_t left = getLeftChild(i);
        size_t right = getRightChild(i);

        size_t min = i; // supposons que le min est le per

        if (left < size && array[i]->getData() > array[left]->getData())
            min = left;

        if (right < size && array[min]->getData() > array[right]->getData())
            min = right;

        if (min != i)
        {
            swap(i, min);
            i = min;
        }
        else
            break;
    }
}
void MinHeap::insert(Node *node)
{
    if (size < max_size)
    {
        array[size] = node;
        ++size;

        if (size > 1) // si la taille superieure a 1 faire un heapfiy up pour assurer l'ordre du tas
            HeapfiyUp();
    }
    else
        throw ERROR_HEAP_OVERFLOW;
}
Node *MinHeap::extract()
{
    if (size == 0)
        throw ERROR_HEAP_EMPTY;

    Node *temp = array[0];

    if (size > 1) // si la taille du tas supperieur a 1, echanger le derniere element avec la racine
        array[0] = array[size - 1];

    array[size - 1] = nullptr;
    --size;

    if (size > 1) // si la taille superieure a 1 faire un heapfiy down pour assurer l'ordre du tas
        HeapfiyDown();

    return temp;
}

size_t MinHeap::getSize()
{
    return size;
}
bool MinHeap::isEmpty()
{
    return (size == 0);
}

/* End MinHeap */
