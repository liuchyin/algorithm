//
//  main.cpp
//  PopOrder
//
//  Created by Cong on 13-3-9.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
using namespace std;


template <int N>
bool isPopOrder(int (&pop)[N]){
    for(int i = 0; i != N; ++i){
        for(int j = i + 1; j != N; j++){
            if(pop[j] < pop[i]){
                for(int k = j; k != N; k++){
                    if(pop[k] > pop[j] && pop[k] < pop[i])
                        return false;
                }
            }
        }
    }
    return true;
}
template<int N>
bool isPopOrder2(int (&pop)[N]){
    stack<int> s;
    int count1 = 1;
    int count2 = 0;

    while(count2 != N){
        if(s.empty()){
            s.push(count1);
            count1++;
        }
        if(s.top() < pop[count2]){
            s.push(count1);
            count1++;
        }else if(s.top() == pop[count2]){
            count2++;
            s.pop();
        }else{
            return false;
        }
        
    }
    return true;
}

int main(int argc, const char * argv[])
{
    
    int pop[] = {1, 2, 3, 4, 5};
    do{
        bool res1 = isPopOrder(pop);
        bool res2 = isPopOrder2(pop);
        if(res1 != res2){
            copy(pop, pop + 5, ostream_iterator<int>(cout, " "));
            cout<<endl;
            cout<<res1<<" "<<res2<<endl;
        }
    }while(next_permutation(pop, pop + 5));
    return 0;
}

