//
//  main.cpp
//  MinStack
//
//  Created by Wenzhen Zhu on 5/22/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MinStack{
private:
    stack<int> s1;
    stack<int> s2;
    
public:
    MinStack(){
        
    }
    
    void push(int x){
        s1.push(x);
        if(s2.empty() || x <= getMin()){
            s2.push(x);
        }
    }
    
    void pop() {
        if(s1.top() == getMin()){
            s2.pop();
        }else{
            s1.pop();
            
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

int main(int argc, const char * argv[]) {
    MinStack obj;
    obj.push(4);
    obj.push(6);
    obj.push(1);
    obj.push(20);
    obj.push(5);
    
    
    int topNum = obj.top();
    cout << topNum << endl;
    int min = obj.getMin();
    cout << min << endl;
    
    return 0;
}
