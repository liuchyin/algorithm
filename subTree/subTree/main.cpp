//
//  main.cpp
//  subTree
//
//  Created by Cong on 13-3-6.
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

bool checkNode(Node* pNode1, Node* pNode2){
    if(pNode2 == NULL)
        return true;
    if(pNode1 == NULL)
        return false;
    if(pNode1->data == pNode2->data){
        return checkNode(pNode1->left, pNode2->left) && checkNode(pNode1->right, pNode2->right);
    }else
        return false;
}

bool subTree(Node* pRoot1, Node* pRoot2){
    bool result = false;



    if(pRoot1 != NULL && pRoot2 != NULL){
        if(pRoot1->data == pRoot2->data){
            result = checkNode(pRoot1->left, pRoot2->left) && checkNode(pRoot1->right, pRoot2->right);
        }
        if(!result){
            result = subTree(pRoot1->left, pRoot2) || subTree(pRoot1->right, pRoot2);
        }
    }
    return result;
}

int main(int argc, const char * argv[])
{
    int array1[] = {5, 3, 4, 2, 7, 8, 6};
    int array2[] = {5, 4};
    Node* pRoot1 = buildTree(array1);
    Node* pRoot2 = buildTree(array2);
    print(pRoot1);
    print(pRoot2);
    if(subTree(pRoot1, pRoot2))
        cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    
    return 0;
}

