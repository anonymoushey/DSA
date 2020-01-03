#include "Node.h"

Node :: Node(Data* data){
    this->_data = data;
    this->_right = NULL;
    this->_left = NULL;
}
void Node :: setRightNode(Node * right){
    this->_right = right;
}
void Node :: setLeftNode(Node * left){
    this->_left = left;
}
Node * Node :: getLeftNode(){
    return this->_left;
}Node * Node :: getRightNode(){
    return this->_right;
}

Data * Node :: getData(){
    return this->_data;
}


