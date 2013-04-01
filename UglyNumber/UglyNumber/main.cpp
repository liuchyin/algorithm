//
//  main.cpp
//  UglyNumber
//
//  Created by Cong on 13-3-15.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;

int getUglyNumber(int N){
    int* numbers = new int[N];
    numbers[0] = 1;
    int T2 = 0;
    int T3 = 0;
    int T5 = 0;
    int ptr = 1;
    while(ptr != N){
        int min2 = numbers[T2] * 2;
        int min3 = numbers[T3] * 3;
        int min5 = numbers[T5] * 5;
        while(min2 <= numbers[ptr - 1]){
            ++T2;
            min2 = numbers[T2] * 2;
        }
        while(min3 <= numbers[ptr - 1]){
            ++T3;
            min3 = numbers[T3] * 3;
        }
        while(min5 <= numbers[ptr - 1]){
            ++T5;
            min5 = numbers[T5] * 5;
        }
        
        int temp = min2 < min3 ? min2 : min3;
        numbers[ptr] = temp < min5 ? temp : min5;
        ptr++;
    }
    int result = numbers[N - 1];
    delete numbers;
    return result;
}


int main(int argc, const char * argv[])
{
    
    cout<<getUglyNumber(1500)<<endl;
    
    return 0;
}

