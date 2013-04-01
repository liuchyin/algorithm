//
//  main.cpp
//  printProbability
//
//  Created by Cong on 13-3-16.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <iterator>

using namespace std;
const int max_value = 6;

void printProbability(int n){
    int *times1 = new int[n * max_value];
    int *times2 = new int[n * max_value];
    for(int i = 0; i != n * max_value; ++i){
        if(i < max_value)
            times1[i] = 1;
        else times1[i] = 0;
        
        times2[i] = 0;

    }
    //times2[2] = 0;
    //copy(times2, times2 + n * max_value, ostream_iterator<int>(cout, " "));
    for(int i = 1; i < n; ++i){
        for(int j = i; j != max_value * (i + 1); ++j){
            //cout<<j<<endl;
            times2[j] = 0;
            int pos = j - 1;
            int count = 0;
            while(count < max_value && pos >= 0){
                times2[j] += times1[pos];
                count++;
                pos--;
            }
        }

        for(int j = i; j != max_value * (i + 1); ++j)
            times1[j] = times2[j];
    }
    
    copy(times1, times1 + n * max_value, ostream_iterator<int>(cout, " "));
    
}


int main(int argc, const char * argv[])
{
    printProbability(1);
    
    return 0;
}

