//
//  main.cpp
//  deepOfBinaryTree
//
//  Created by Cong on 13-3-16.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

typedef pair<bool, int> state;
state is_Balance(Node* pRoot){
    if(pRoot == NULL)
        return state(true, 0);
    state sta1 = is_Balance(pRoot->left);
    state sta2 = is_Balance(pRoot->right);
    state result(false, 0);
    if(sta1.first && sta2.first){
        int distance = sta1.second - sta2.second;
        if(distance <= 1 && distance >= -1){
            result.first = true;
            result.second = 1 + sta1.second > sta2.second ? sta1.second : sta2.second;
        }
    }
    return result;
}

int main(int argc, const char * argv[])
{
    
    
    return 0;
}

