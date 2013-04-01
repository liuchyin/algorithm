//
//  main.cpp
//  printMinNumber
//
//  Created by Cong on 13-3-14.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

bool cmp(string& str1, string& str2){
    int ptr1 = 0;
    int ptr2 = 0;
    while(str1[ptr1] != 0 || str2[ptr2] != 0){//str1[ptr1] != 0 && str2[ptr2] != 0){
        if(str1[ptr1] != 0 && str2[ptr2] != 0){
            if(str1[ptr1] < str2[ptr2])
                return true;
            else if(str1[ptr1] > str2[ptr2])
                return false;
            else{
                ptr1++;
                ptr2++;
            }
        }
        if(str1[ptr1] == 0){
            if(str1[ptr1 - 1] < str2[ptr2]){
                return true;
            }else if(str1[ptr1 - 1] > str2[ptr2])
                return false;
            else
                ptr2++;
        }
        if(str2[ptr2] == 0){
            if(str2[ptr2 - 1] < str1[ptr1])
                return false;
            else if(str2[ptr2 - 1] > str1[ptr1])
                return true;
            else
                ptr1++;
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    string nums[] =  {"3", "33", "321"};
    
    sort(nums, nums + 3, cmp);
    copy(nums, nums + 3, ostream_iterator<string>(cout, ""));
    return 0;
}

