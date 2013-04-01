//
//  main.cpp
//  ConvertBinarySearchTree
//
//  Created by Cong on 13-3-12.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
};

bool insert(Node* &root, int n){
    if(root == NULL){
        root = new Node();
        root->data = n;
        return true;
    }
    Node* ptr = root;
    while(ptr != NULL){
        if(ptr->data > n){
            if(ptr->left != NULL)
                ptr = ptr->left;
            else{
                ptr->left = new Node();
                ptr->left->data = n;
                return true;
            }
        }
        else if(ptr->data < n){
            if(ptr->right != NULL)
                ptr = ptr->right;
            else{
                ptr->right = new Node();
                ptr->right->data = n;
                return true;
            }
        }
        else return false;
    }
    return true;
}

template<int N>
Node* buildTree(int (&array)[N]){
    Node* root = NULL;
    for(int i = 0; i != N; ++i)
        insert(root, array[i]);
    return root;
}

typedef pair<Node*, int> p;

void print(Node* root){
    queue<pair<Node*, int>*> BFS;
    BFS.push(new p(root, 0));
    int height = 0;
    while(!BFS.empty()){
        Node* n = BFS.front()->first;
        int h = BFS.front()->second;
        if(h > height){
            cout<<endl;
            height = h;
        }
        if(n->left != NULL)
            BFS.push(new p(n->left, h + 1));
        if(n->right != NULL)
            BFS.push(new p(n->right, h + 1));
        cout<<n->data<<" ";
        BFS.pop();
    }
    cout<<endl;
}
Node* convertMax(Node* node);
Node* convertMin(Node* node);

Node* convertMax(Node* node){
    if(node->right != NULL){
        Node* temp = convertMin(node->right);
        node->right = temp;
        temp->left = node;
    }
    if(node->left != NULL){
        Node* temp = convertMax(node->left);
        node->left = temp;
        temp->right = node;
    }
    
    Node* ptr = node;
    while(ptr->right != NULL)
        ptr = ptr->right;
    return ptr;
    
}

Node* convertMin(Node* node){
    if(node->right != NULL){
        Node* temp = convertMin(node->right);
        node->right = temp;
        temp->left = node;
    }
    if(node->left != NULL){
        Node* temp = convertMax(node->left);
        node->left = temp;
        temp->right = node;
    }
    
    Node* ptr = node;
    while(ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}



Node* convert(Node* pRoot){
    if(pRoot == NULL){
        cout<<"invalid input"<<endl;
        return NULL;
    }
    if(pRoot->left != NULL){
        Node* temp = convertMax(pRoot->left);
        pRoot->left = temp;
        temp->right = pRoot;
    }
    if(pRoot->right != NULL){
        Node* temp = convertMin(pRoot->right);
        pRoot->right = temp;
        temp->left = pRoot;
    }
    Node* ptr = pRoot;
    while(ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

int main(int argc, const char * argv[])
{
    int array[] = {5, 3, 7, 2, 4, 8, 6};
    Node* pRoot = buildTree(array);
    
    Node* pHead = convert(pRoot);
    for(Node* ptr = pHead; ptr != NULL; ptr = ptr->right)
        cout<<ptr->data<<endl;
    return 0;
}

