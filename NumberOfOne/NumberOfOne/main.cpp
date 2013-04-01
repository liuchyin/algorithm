//
//  main.cpp
//  NumberOfOne
//
//  Created by Cong on 13-3-14.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;

int getLength(char* str){
    int length = 0;
    while(str[length] != 0){
        if(str[length] >= '0' && str[length] <= '9')
            length++;
    }
    return length;
}

int PowerBase10(int n){
    int result = 1;
    while(n--)
        result *= 10;
    return result;
}

int numberOfOne(char* number, int length){


    int first = number[0] - '0';
    if(length == 1){
        if(first == 1)
            return 1;
        else return 0;
    }
    int numberOfFirstDigit = 0;
    if(first == 1)
        numberOfFirstDigit = atoi(number + 1) + 1;
    else if(first > 1){
        numberOfFirstDigit = PowerBase10(length - 1);
    }
    int numberOfOtherDight = first * (length - 1) * PowerBase10(length - 2);
    
    return numberOfFirstDigit + numberOfOtherDight + numberOfOne(number + 1, length - 1);
}

int main(int argc, const char * argv[])
{
    char number[100];

    cin>>number;
    
    int length = getLength(number);
    cout<<numberOfOne(number, length);
    
    return 0;
}

