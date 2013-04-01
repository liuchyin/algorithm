//
//  main.cpp
//  quicksort
//
//  Created by Cong on 13-3-13.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <iterator>
using namespace std;


int partition(int * array, int start, int end){
    /*if(array == NULL || start < 0){
        cout<<"invalid input"<<endl;
        return 0;
    }*/
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


void qsort(int * array, int start, int end){
    if(array == NULL || start < 0 || end < 0){
        cout<<"invalid input"<<endl;
        return;
    }

   
    int p = partition(array, start, end);
    //copy(array, array + 10, ostream_iterator<int>(cout, " "));
    //cout<<endl;
    //cout<<array[p]<<endl;
    if(p > start + 1)
        qsort(array, start, p - 1);
    if(p < end - 1)
        qsort(array, p + 1, end);
}


int main(int argc, const char * argv[])
{
    int array[] = {2, 3, 5, 9, 33, 1, 24, 19, 7, 6};
    //partition(array, 0, 9);
    qsort(array, 0, 9);
    copy(array, array + 10, ostream_iterator<int>(cout, " "));
    

    return 0;
}

