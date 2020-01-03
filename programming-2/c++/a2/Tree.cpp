#include "Tree.h"
//#include "Data.h"
//#include "Node.h"
#include <vector>
#include<iostream>
void Tree::addInOrder(Node* d){
    inOrder.push_back(d);
}

void Tree::addInPreOrder(Node *d){
    preOrder.push_back(d);
}

void Tree::printPostOrder(Node * root){
    if (root == NULL)
        return ;
    printPostOrder(root->getLeftNode());
    printPostOrder(root->getRightNode());
    std :: cout << root->getData();
}

int Tree:: search(Data *d, int start, int end){
    for (int i = start ; i < end ; i++){
        if (this->inOrder.at(i)->getData()->getName() == d->getName()){
            return i ;
        }
    }
    return 0;
}

Node * Tree :: getFromPreOrder(int ind){
    return preOrder.at(ind);
}

Node * Tree :: buildTree(int start, int end){
    static int index = 0;
    if (start > end ) return NULL ;
    Node * n = new Node(preOrder[index++]->getData());
    if (start == end){
        return n ;
    }
    int helper = search(n->getData(), start,end);
    n->setLeftNode(buildTree(start,helper-1));
    n->setRightNode(buildTree(helper+1,end));
    return n;

}
