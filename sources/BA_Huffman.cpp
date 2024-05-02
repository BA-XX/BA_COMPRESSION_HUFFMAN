#include "../header.hpp"

using namespace ba;

/* BA_Huffman*/

size_t *BA_Huffman::calculateCharsFrequency()
{
    size_t *temp = new size_t[128]();

    for (size_t i = 0; i < input.size(); i++)
        ++temp[input[i]];

    return temp;
}

Node *BA_Huffman::buildHuffmanTree()
{ // retourne la racine de l'arbre de Huffman
    /* Etape 1 : initialisation */

    size_t *charsFrequency = calculateCharsFrequency();

    MinHeap heap(128);

    for (size_t i = 0; i < 128; i++)
    {
        if (charsFrequency[i] > 0)
            heap.insert(new Node(charsFrequency[i], i));
    }

    Node *root = nullptr;

    /* La    principale*/
    while (!heap.isEmpty())
    {
        if (heap.getSize() == 1)
        { // s'il existe un seul noeud dans le tas
            root = heap.extract();
            break;
        }

        Node *node1 = heap.extract();
        Node *node2 = heap.extract();

        heap.insert(new Node(node1->getData() + node2->getData(), '\0', node1, node2));
    }

    return root;
}

bool BA_Huffman::isLeaf(Node *root)
{
    return (root->getLeft() == nullptr && root->getRight() == nullptr);
}

string BA_Huffman::serialize(Node *root)
{
    if (root == nullptr)
        return "()";

    return "(" + ((root->getCharactere() == '\0') ? "" : std::string(1, root->getCharactere())) + serialize(root->getLeft()) + serialize(root->getRight()) + ")";
}

void BA_Huffman::generateCodes(Node *root, string code)
{

    if (isLeaf(root))
        codes[root->getCharactere()] = code;
    else
    {
        generateCodes(root->getLeft(), code + "0");
        generateCodes(root->getRight(), code + "1");
    }
}
void BA_Huffman::clearHuffmanTree(Node *root) // parcour postfixe pour liberer la memoire
{
    if (root == nullptr)
        return;

    clearHuffmanTree(root->getLeft());
    clearHuffmanTree(root->getRight());

    delete root;
}

void BA_Huffman::clearCodes() // vider touts les codes generer
{
    for (size_t i = 0; i < 128; i++)
        codes[i].clear();
}

string BA_Huffman::getCodes()
{
    string tmp;
    for (size_t i = 0; i < 128; i++)
    {
        if (!codes[i].empty())
            tmp += "   " + std::string(1, i) + "(" + codes[i] + ")";
    }

    return tmp;
}

BA_Huffman::BA_Huffman()
{
}

void BA_Huffman::setInput(string input)
{
    this->input = input;
}
string BA_Huffman::getInput()
{
    return input;
}

huffman_result_t BA_Huffman::compress()
{
    if (input.empty())
        throw ERROR_INPUT_IS_EMPTY;

    huffman_result_t result;

    Node *root = buildHuffmanTree();

    if (root == nullptr)
        throw ERROR_NULL_HUFFMAN_TREE;

    clearCodes();        // S'assurer que tous les codes sont réinitialisés avant de générer de nouveaux
    generateCodes(root); // generer les codes

    for (size_t i = 0; i < input.size(); i++) // generer les bit de results
        result.encoded += codes[input[i]];

    result.serializedHuffmanTree = serialize(root); // serialiser l'arbre
    result.codes = getCodes();

    clearHuffmanTree(root); // liberer la memoire utilise par l'arbre de Huffman

    return result;
}

/* END BA_huffman*/