#include "../header.hpp"

using namespace ba;

/* Class Node */
Node::Node(data_type data, char charactere, Node *left, Node *right)
{
    this->data = data;
    this->charactere = charactere;
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

void Node::setCharactere(char charactere)
{
    this->charactere = charactere;
}
char Node::getCharactere()
{
    return charactere;
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
