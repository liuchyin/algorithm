//
//  main.cpp
//  numberAppearOnce
//
//  Created by Cong on 13-3-16.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;


template <int N>
void numberAppearOnce(int (&array)[N]){
    int ORresult = 0;
    for(int i = 0; i != N; ++i)
        ORresult ^= array[i];
    int t = 0;
    while(!(ORresult & 1)){
        t++;
        ORresult = ORresult>>1;
    }
    
    int num1 = 0;
    int num2 = 0;
    for(int i = 0; i != N; ++i){
        if((array[i] >> t) & 1)
            num1 ^= array[i];
        else num2 ^= array[i];
    }
    
    cout<<num1<<" "<<num2<<endl;
}


int main(int argc, const char * argv[])
{
    int array[] = {2, 4, 3, 6, 3, 2, 5, 5};
    numberAppearOnce(array);
    
    return 0;
}

