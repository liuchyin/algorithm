//
//  main.cpp
//  LastRemaining
//
//  Created by Cong on 13-3-17.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void buildList(Node* &pHead, int n){
    pHead = new Node();
    pHead->data = 0;
    Node* ptr = pHead;
    for(int i = 1; i != n; ++i){
        Node* temp = new Node();
        temp->data = i;
        ptr->next = temp;
        ptr = ptr->next;
    }
    ptr->next = pHead;
}

void deleteNode(Node* &pHead, int m){
    Node* ptr = pHead;
    while(ptr->next != ptr){
        for(int i = 0; i != m - 1; ++i)
            ptr = ptr->next;
        ptr->data = ptr->next->data;
        Node* temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
    cout<<ptr->data<<endl;
}

int main(int argc, const char * argv[])
{
    Node* phead = NULL;
    buildList(phead, 5);
    deleteNode(phead, 3);
    
    
    return 0;
}

