//
//  main.cpp
//  NextGreaterElementI
//
//  Created by Wenzhen Zhu on 5/24/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int>& nums){
        stack<int> s;
        unordered_map <int, int> m;
        
        for(int n: nums){
            while(s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        
        vector<int> ans;
        for(int n : findNums){
            ans.push_back(m.count(n) ? m[n] : -1);
            
        }
        return ans;
    }
};

void printVectorInt(vector<int> nums){
    for (auto elem: nums){
        cout << elem << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    vector<int> num1 = {4, 1, 2};
    vector<int> num2 = {1, 3, 4, 2};
    Solution s;
    vector<int> res = s.nextGreaterElement(num1, num2);
    
    printVectorInt(res);
    
    
}
