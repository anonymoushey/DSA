#include "Data.h"
class Node{
    private : 
        Node * _right;
        Node * _left;
        Data * _data;
    public :
        Node(Data* data);
        void setRightNode(Node * right);
        void setLeftNode(Node * left);
        Node * getLeftNode();
        Node * getRightNode();
        Data * getData();
        std::ostream& operator<<(std::ostream &out , Node *n);

        Node &operator - (){
            // -Node
        }
        Node operator +(const Node & n){
            //Node2+Node1;
        }
        friend std :: ostream & operator << (std::ostream &output, Node* n){
          //   cout <<  
            return cout;
        }
        friend std :: istream 
};