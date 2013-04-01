//
//  main.cpp
//  reverseSentence
//
//  Created by Cong on 13-3-16.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;



void reverse(char str[], int start, int end){
    while(start < end){
        swap(str[start], str[end]);
        ++start;
        --end;
    }
}

template<int N>
void reverse(char (&str)[N]){

    reverse(str, 0, N - 2);
    
    for(int i = 0; i != N - 1; ++i){
        if(str[i] == ' ')
            continue;
        for(int j = i + 1; j != N - 1; ++j){
            if(str[j] == ' ' || j == N - 2){
                reverse(str, i, j - 1);
                i = j;
                break;
            }
        }
    }
    cout<<str<<endl;
}
template<int N>
void reverse(char (&str)[N], int pos){
    reverse(str, 0, pos - 1);
    reverse(str, pos, N - 2);
    reverse(str, 0, N - 2);
    cout<<str<<endl;
}

int main(int argc, const char * argv[])
{
    char str[] = "i am a student.";
    char str2[] = "abcde";
    reverse(str2, 2);
    //reverse(str);
    return 0;
}

