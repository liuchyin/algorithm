//
//  main.cpp
//  StackWithMin
//
//  Created by Cong on 13-3-8.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

template<class T,
    class Compare = less<T>>
class StackWithMin{
private:
    stack<T> s;
    stack<T> m;
    unsigned int count;
public:
    StackWithMin(): count(0){};
    void push(int n){
        if(empty()){
            s.push(n);
            m.push(n);
        }else{
            s.push(n);
            if(Compare()(n, m.top()))
                m.push(n);
        }
        count++;
    }
    bool pop(){
        if(empty()){
            cout<<"The stack is empty"<<endl;
            return false;
        }
        if(s.top() == m.top())
            m.pop();
        s.pop();
        count--;
        return true;
    }
    
    int top(){
        if(empty()){
            cout<<"The stack is empty"<<endl;
            return 0;
        }
        return s.top();
    }
    
    int min(){
        if(empty()){
            cout<<"The stack is empty"<<endl;
            return 0;
        }
        return m.top();
    }
    
    bool empty(){
        return count == 0;
    }
    unsigned int size(){
        return count;
    }
};




int main(int argc, const char * argv[])
{
    StackWithMin<int> s;
    s.push(5);
    s.push(2);
    s.push(3);
    s.push(1);
    cout<<s.min()<<endl;
    s.pop();
    cout<<s.min()<<endl;
    return 0;
}

