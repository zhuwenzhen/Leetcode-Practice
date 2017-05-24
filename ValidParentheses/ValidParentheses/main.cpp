//
//  main.cpp
//  ValidParentheses
//
//  Created by Wenzhen Zhu on 5/23/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        
        for(char &c: s){
            switch (c) {
                case '(':
                    parentheses.push(c);
                    break;
                case '{':
                    parentheses.push(c);
                    break;
                case '[':
                    parentheses.push(c);
                    break;
                case ')':
                    if(parentheses.empty() || parentheses.top()!= '(')
                        return false;
                    else
                        parentheses.pop();
                    break;
                case '}':
                    if(parentheses.empty() || parentheses.top()!= '{'){
                        return false;
                    }
                    else{
                        parentheses.pop();
                    }
                    break;
                case ']':
                    if(parentheses.empty() || parentheses.top()!= '['){
                        return false;
                    } else {
                        parentheses.pop();
                    }
                    break;
                default:
                    ;
            }
        }
        return parentheses.empty();
        
    }
};

int main(int argc, const char * argv[]) {
    string s = "((([[{dkfajdlkfja]])))";
    Solution sol;
    cout << sol.isValid(s) << endl;
    
    return 0;
}
