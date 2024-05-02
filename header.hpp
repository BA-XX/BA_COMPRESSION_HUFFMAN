#pragma once

#include <string>

namespace ba // definier un nouvel espace de nom s'apple ba
{
    // typedef unsigned int size_t;
    typedef int data_type;
    typedef std::string string;

    const int ERROR_HEAP_EMPTY = 21;
    const int ERROR_HEAP_OVERFLOW = 22;
    const int ERROR_NULL_HUFFMAN_TREE = 40;
    const int ERROR_INPUT_IS_EMPTY = 41;

    class Node
    {
        data_type data;
        char charactere;
        Node *left;
        Node *right;

        string charCode;

    public:
        Node(data_type, char = '\0', Node * = nullptr, Node * = nullptr);

        void setData(data_type);
        data_type getData();

        void setCharactere(char);
        char getCharactere();

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

        size_t getParent(size_t);
        size_t getLeftChild(size_t);
        size_t getRightChild(size_t);

        void swap(size_t, size_t);
        void HeapfiyUp();
        void HeapfiyDown();

    public:
        MinHeap(size_t);
        ~MinHeap();

        void insert(Node *);
        Node *extract();
        size_t getSize();
        bool isEmpty();
    };

    /* Huffman result stucture pour retourner les results apres la compression */
    struct huffman_result_t
    {
        string encoded;
        string serializedHuffmanTree;
        string codes;
    };

    class BA_Huffman
    {

        string codes[128]; // global variable utilse pour savaugarder les resultas des codes generer
        string input;      // pour stocker l'entrer

        size_t *calculateCharsFrequency();

        Node *buildHuffmanTree();

        bool isLeaf(Node *root);

        string serialize(Node *root);

        void generateCodes(Node *root, string code = "");

        void clearHuffmanTree(Node *root); // parcour postfixe pour liberer la memoire

        void clearCodes(); // vider touts les codes generer

        string getCodes();

    public:
        BA_Huffman();

        void setInput(string input);
        string getInput();

        huffman_result_t compress();
    };

}