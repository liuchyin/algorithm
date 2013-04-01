//
//  main.cpp
//  InversePairs
//
//  Created by Cong on 13-3-16.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <iterator>
using namespace std;


int merge(int array[], int start1, int end1, int start2, int end2){
    int count = 0;
    int length1 = end1 - start1 + 1;
    int length2 = end2 - start2 + 1;
    int* temp = new int[length1 + length2];
    int ptr1 = end1;
    int ptr2 = end2;
    int ptr = length1 + length2 - 1;
    while(ptr >= 0){
        if(length1 == 0){
            temp[ptr] = array[ptr2];
            ptr2--;
            ptr--;
            continue;
        }
        if(length2 == 0){
            temp[ptr] = array[ptr1];
            ptr1--;
            ptr--;
            continue;
        }
        if(array[ptr1] > array[ptr2]){
            count += length2;
            temp[ptr] = array[ptr1];
            --ptr1;
            --ptr;
            --length1;
        }else{
            temp[ptr] = array[ptr2];
            --ptr2;
            --ptr;
            --length2;
        }
    }
    
    for(int i = 0; i != end2 - start1 + 1; ++i){
        array[start1 + i] = temp[i];
    }
    delete temp;
    return count;
}

template<int N>
int InversePairs(int (&array)[N]){
    int step = 1;
    int count = 0;
    while(true){
        for(int i = 0; i < N; i += step * 2){
            if(i + step < N){
                int end1 = i + step - 1;
                int start2 = i + step;
                int end2 = i + step * 2 - 1;
                if(end2 >= N)
                    end2 = N - 1;
                count += merge(array, i, end1, start2, end2);
            }
        }
        if(step * 2 > N)
            break;
        else step *= 2;
    }
    return count;
}


int main(int argc, const char * argv[])
{
    
    int array[] = {7, 5, 6};
    cout<<InversePairs(array)<<endl;
    //cout<<merge(array, 0, 1, 2, 3)<<endl;
    copy(array, array + 3, ostream_iterator<int>(cout, " "));
    return 0;
}

