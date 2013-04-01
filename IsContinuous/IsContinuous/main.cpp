//
//  main.cpp
//  IsContinuous
//
//  Created by Cong on 13-3-17.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;

bool isContinuous(int* array, int N){
    if(array == NULL || N < 1){
        return false;
    }
    
    sort(array, array + N);
    int numberOfZero = 0;
    while(array[numberOfZero] == 0)
        numberOfZero++;
    
    int start = numberOfZero;
    int end = start + 1;
    
    int count = 0;
    
    while(end != N){
        if(array[start] == array[end])
            return false;
        
        count += array[end] - array[start] - 1;
        ++start;
        ++end;
    }
    
    if(count <= numberOfZero)
        return true;
    return false;
    
}

int main(int argc, const char * argv[])
{
    int array[] = {6, 2, 3, 1, 0};

    if(isContinuous(array, 5))
        cout<<"yes"<<endl;
    else cout<<"false"<<endl;
    return 0;
}

