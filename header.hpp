#pragma once

namespace ba // definier un nouvel espace de nom s'apple ba
{
    typedef unsigned int size_t;
    typedef int data_type;

    const int ERROR_HEAP_OVERFLOW = 22;

    class Node
    {
        data_type data;
        Node *left;
        Node *right;

    public:
        Node(data_type, Node * = nullptr, Node * = nullptr);

        void setData(data_type);
        data_type getData();

        void setLeft(Node *);
        Node *getLeft();

        void setRight(Node *);
        Node *getRight();
    };

    class MinHeap
    {

        Node **array;    // tableau de pointeurs sur des nodes
        size_t max_size; // la taille maximume
        size_t size;     // la taille effective

    public:
        MinHeap(size_t);
        ~MinHeap();

        size_t getParent(size_t);
        size_t getLeftChild(size_t);
        size_t getRightChild(size_t);

        void exchange(size_t, size_t);
        void HeapfiyUp();
        void insert(data_type);
        data_type extract();
    };

}