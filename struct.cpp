#include <iostream>
using namespace std;

struct HeapNode{
    int key;
    HeapNode *leftChild;
    HeapNode *nextSibling;

    HeapNode() : leftChild(nullptr), nextSibling(nullptr){}

    HeapNode(int key_, HeapNode *leftChild_, HeapNode *nextSibling_) :
    key(key_), leftChild(leftChild_), nextSibling(nextSibling_){}

    void display(){
        cout << key << "-" << leftChild << "-" << nextSibling << endl;
    }
};

int main(){
    HeapNode h1 (5, nullptr, nullptr);
    HeapNode h2 (7, &h1, nullptr);

    h1.display();
    h2.display();

    
}