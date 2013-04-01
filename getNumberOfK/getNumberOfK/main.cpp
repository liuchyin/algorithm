//
//  main.cpp
//  getNumberOfK
//
//  Created by Cong on 13-3-16.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>

using namespace std;


template<int N>
int firstK(int (&array)[N], int K){
    int start = 0;
    int end = N - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(array[mid] == K){
            if(array[mid - 1] < K)
                return mid;
            else{
                end = mid - 1;
            }
        }else if(array[mid] < K){
            start = mid + 1;
        }else
            end = mid - 1;
    }
    //if(start > end)
    return -1;
}
template<int N>
int lastK(int (&array)[N], int K){
    int start = 0;
    int end = N - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(array[mid] == K){
            if(array[mid + 1] > K)
                return mid;
            else{
                start = mid + 1;
            }
        }else if(array[mid] < K){
            start = mid + 1;
        }else
            end = mid - 1;
    }
    //if(start > end)
    return -1;
}

int main(int argc, const char * argv[])
{
    int array[] = {1, 2, 3, 3, 3, 3, 4, 5};
    int first = firstK(array, 3);
    int last = lastK(array, 3);
    int number = last - first + 1;
    return 0;
}

