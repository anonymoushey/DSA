#include "Node.h"
#include <vector>
class Tree{
    private  :
        std::vector <Node*> preOrder;
        std::vector <Node*> inOrder;
        Node * root;
    public :

        void addInPreOrder(Node* d);
        void addInOrder(Node* d);
        Node* getFromPreOrder(int ind);
        void printPostOrder(Node *root);
        Node* buildTree(int start, int end);
        int search(Data* d, int start, int end);

};