//
//  main.cpp
//  VerifySquenceOfBST
//
//  Created by Cong on 13-3-10.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;



//template <int N>
bool VerifySquenceOfBST(int* array, int n){
    
    if(n == 1)
        return true;
    int root = array[n - 1];
    int first = 0;
    while(array[first] < root)
        first++;
    for (int i = first; i <= n - 2; ++i) {
        if(array[i] < root)
            return false;
    }
    bool left = true, right = true;
    if(first > 0)
        left = VerifySquenceOfBST(array, first);
    if(n - 1 - first > 0)
        right = VerifySquenceOfBST(array + first + 1, n - 1 - first);
    return  left && right;
}

int main(int argc, const char * argv[])
{

    
    int BST[] = {7, 6, 9, 11, 10, 8};
    if(VerifySquenceOfBST(BST, 6))
        cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}

