//
//  main.cpp
//  CloneComplexList
//
//  Created by Cong on 13-3-11.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
struct Node{
    int data;
    Node* pNext;
    Node* pSibling;
    Node() : pNext(NULL), pSibling(NULL){}
};


Node* buildComplexList(int n){
    Node* pHead = NULL;
    pHead = new Node();
    pHead->data = 1;
    Node* iter = pHead;
    for(int i = 1; i != n; i++){
        Node* newN = new Node();
        newN->data = i + 1;
        iter->pNext = newN;
        iter = iter->pNext;
    }
    //iter = pHead;
    for(iter = pHead; iter != NULL; iter = iter->pNext){
        int shift = rand() % (n - 1) + 1;
        Node* ptr = iter;
        for(int j = 0; j != shift; ++j){
            if(ptr->pNext == NULL){
                ptr = ptr->pNext;
                ptr = NULL;
                break;
            }
        }
        iter->pSibling = ptr;
    }
    return pHead;
}

Node* clone(Node* _pHead){
    if(_pHead == NULL){
        cout<<"invalid input"<<endl;
        return NULL;
    }
    map<Node*, Node*> nodeToNode;
    
    Node* newHead = new Node();
    
    newHead->data = _pHead->data;
    
    nodeToNode[_pHead] = newHead;
    Node* p = newHead;
    if(_pHead != NULL){
        for(Node* ptr = _pHead->pNext; ptr != NULL; ptr = ptr->pNext){
            Node* temp = new Node();
            temp->data = ptr->data;
            nodeToNode[ptr] = temp;
            p->pNext = temp;
            p = p->pNext;
        }
    }
    Node* ptr1 = _pHead;
    Node* ptr2 = newHead;
    for(;ptr1 != NULL;ptr1 = ptr1->pNext, ptr2 = ptr2->pNext){
        if(ptr1->pSibling != NULL){
            ptr2->pSibling = nodeToNode[ptr1];
        }
    }
    return newHead;
}


Node* clone2(Node* _pHead){
    
    for(Node* ptr = _pHead; ptr != NULL; ptr = ptr->pNext){
        Node* next = ptr->pNext;
        Node* newN = new Node();
        newN->data = ptr->data;
        ptr->pNext = newN;
        
        ptr = ptr->pNext;
        ptr->pNext = next;
    }
    
    for(Node* ptr = _pHead; ptr != NULL; ptr = ptr->pNext->pNext){
        Node* next = ptr->pNext;
        if(ptr->pSibling != NULL){
            next->pSibling = ptr->pSibling->pNext;
        }
    }
    
    Node* newHead = _pHead->pNext;
    for(Node* ptr = _pHead; ptr != NULL; ptr = ptr->pNext){
        if(ptr->pNext->pNext != NULL){
            Node* next = ptr->pNext;
            ptr->pNext = next->pNext;
            next->pNext = next->pNext->pNext;
        }else{
            ptr->pNext = NULL;
        }
    }
    return newHead;
}

int main(int argc, const char * argv[])
{
    Node* pHead = buildComplexList(8);
    Node* pNewHead = clone(pHead);
    return 0;
}

