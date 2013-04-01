//
//  main.cpp
//  minK
//
//  Created by Cong on 13-3-14.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


int partition(int* array, int start, int end){
    int index = rand() % (start - end + 1) + start;
    swap(array[end], array[index]);
    int small = -1;
    for(index = start; index != end; ++index){
        if(array[index] < array[end]){
            ++small;
            if(small != index)
                swap(array[small], array[index]);
        }
    }
    ++small;
    swap(array[small], array[end]);
    return small;
}

template<int N>
void minK(int (&array)[N], int K){
    if(N < K){
        cout<<"invalid input"<<endl;
        return;
    }
    int start = 0;
    int end = N - 1;
    int p;
    while(true){
        p = partition(array, start, end);
        if(p == K - 1)
            break;
        else if(p < K - 1)
            start = p + 1;
        else end = p - 1;
    }
    copy(array, array + K, ostream_iterator<int>(cout, " "));
    cout<<endl;
}

template<int N>
void minK1(int (&array)[N], int K){
    vector<int> heap(K + 1);
    int pos = 0;
    while(pos < K){
        heap[pos] = array[pos];
        pos++;
    }
    make_heap(heap.begin(), heap.end() - 1);
    while(pos != N){
        heap[K] = array[pos];
        push_heap(heap.begin(), heap.end());
        pop_heap(heap.begin(), heap.end());
        pos++;
    }
    copy(heap.begin(), heap.end() - 1, ostream_iterator<int>(cout, " "));
    cout<<endl;
}


int main(int argc, const char * argv[])
{
    int array[] = {1, 3, 5, 8, 9, 4, 2, 9, 2, 5, 4, 8, 7};
    //partition(array, 0, 12);
    minK(array, 4);
    minK1(array, 4);
    //copy(array, array + 13, ostream_iterator<int>(cout, " "));
    return 0;
}

