//
//  main.cpp
//  moreThanHalf
//
//  Created by Cong on 13-3-14.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;

int partition(int * array, int start, int end){
    if(array == NULL || start < 0){
        cout<<"invalid input"<<endl;
        return 0;
    }
    int index = rand() % (end - start + 1) + start;
    //cout<<array[index]<<endl;
    swap(array[end], array[index]);
    int small = start - 1;
    for(index = start; index != end; ++index){
        if(array[index] < array[end]){
            small++;
            if(small != index)
                swap(array[small], array[index]);
        }
    }
    ++small;
    swap(array[end], array[small]);
    return small;
}

template<int N>
int moreThanHalf(int (&array)[N]){
    int number = -1;
    int time = 0;
    for(int i = 0; i != N; ++i){
        if(array[i] != number){
            if(time == 0){
                number = array[i];
                time++;
            }else{
                --time;
                if(time == 0)
                    number = -1;
            }
        }else{
            time++;
        }
    }
    return number;
}


template<int N>
int moreThanHalf1(int (&array)[N]){
    int p = 0;
    int start = 0;
    int end = N - 1;
    while(true){
        p = partition(array, start, end);
        if(p == N / 2)
            break;
        else{
            if(p > N / 2)
                end = p - 1;
            else
                start = p + 1;
        }
    }
    return array[p];
}

int main(int argc, const char * argv[])
{
    
    int array[] = {2, 3, 5, 2, 2, 2, 5, 2, 1, 5, 2, 3, 2, 2, 5};
    cout<<moreThanHalf1(array)<<endl;
    
    
    return 0;
}

