//
//  main.cpp
//  SlidingWindowMaximum
//
//  Created by Wenzhen Zhu on 6/16/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        
        if(nums.size() == 0){
            return ans;
        }
        for (int i=0; i<nums.size()-k+1; i++) {
            vector<int> temp;
            
            for(int j = 0; j < k; j++){
                //cout << nums[i+j] << " ";
                temp.push_back(nums[i+j]);
            }
           // cout << endl;
            
            auto it = max_element(begin(temp), end(temp));
            //cout << *it << endl;
            
            ans.push_back(*it);
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
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    Solution s;
    vector<int> res = s.maxSlidingWindow(nums, 3);
    printVectorInt(res);
}

