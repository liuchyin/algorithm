//
//  main.cpp
//  FindNumberWithSum
//
//  Created by Cong on 13-3-16.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;

template<int N>
void FindNumberWithSum(int (&array)[N], int sum){
    int start = 0;
    int end = N - 1;
    while(start < end){
        int _sum = array[start] + array[end];
        if(_sum > sum)
            --end;
        else if(_sum < sum)
            ++start;
        else{
            cout<<array[start]<<" "<<array[end]<<endl;
            return;
        }
    }
    cout<<"cant find valid pair of numbers"<<endl;
}

void print(int a, int b){
    for(int i = a; i <= b; ++i)
        cout<<i<<" ";
    cout<<endl;
}

void FindContinuousSequence(int sum){
    if(sum < 3){
        cout<<"invalid input"<<endl;
        return;
    }
    int start = 1;
    int end = 2;
    int middle = (sum + 1) / 2;
    int _sum = 3;
    while(start < middle){
        if(_sum == sum){
            print(start, end);
            _sum -= start;
            ++start;
        }else if(_sum < sum){
            ++end;
            _sum += end;
        }else{
            _sum -= start;
            ++start;
        }
    }
}

int main(int argc, const char * argv[])
{
    int array[] = {1, 2, 4, 7, 11, 15};
    //FindNumberWithSum(array, 14);
    FindContinuousSequence(15);
    return 0;
}

