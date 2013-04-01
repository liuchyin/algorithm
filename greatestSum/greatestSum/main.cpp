//
//  main.cpp
//  greatestSum
//
//  Created by Cong on 13-3-14.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;

template<int N>
int greatSum(int (&array)[N]){
    int max = 0;
    int sum = 0;
    for(int i = 0; i != N; ++i){
        sum += array[i];
        if(sum > max){
            max = sum;
        }
        if(sum < 0)
            sum = 0;
    }
    return max;
}


int main(int argc, const char * argv[])
{
    int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
    cout<<greatSum(array)<<endl;
    return 0;
}

