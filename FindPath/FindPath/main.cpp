//
//  main.cpp
//  FindPath
//
//  Created by Cong on 13-3-10.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <vector>
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

vector<int> stack;
int sum = 0;
bool Find = false;
void FindPath(Node* pRoot, int k){
    stack.push_back(pRoot->data);
    sum += pRoot->data;
    if(sum == k){
        Find = true;
        for(int i = 0; i != stack.size(); i++)
            cout<<stack[i]<<" ";
        cout<<endl;
    }
    if(sum < k && pRoot->left != NULL)
        FindPath(pRoot->left, k);
    if(sum < k && pRoot->right != NULL)
        FindPath(pRoot->right, k);
    stack.pop_back();
}



int main(int argc, const char * argv[])
{
    int array[] = {5, 3, 7, 2, 4, 6, 8};
    Node* pRoot = buildTree(array);
    //print(pRoot);
    
    FindPath(pRoot, 11);
    if(!Find)
        cout<<"no valid path is found!"<<endl;
    return 0;
}

