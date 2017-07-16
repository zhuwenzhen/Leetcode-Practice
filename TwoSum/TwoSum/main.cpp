//
//  main.cpp
//  TwoSum
//
//  Created by Wenzhen Zhu on 7/15/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector <int> result;
        
        for(int i = 0; i < nums.size(); i++){
            int numToFind = target - nums[i];
            
            // if not find
            if(hash.find(numToFind) == hash.end()){
                hash[nums[i]] = i;
            }  else { // find
                result.push_back(hash[numToFind]);
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
    
    void printVectorInt(vector<int> nums){
        for (auto elem: nums){
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> res = s.twoSum(test, target);
    s.printVectorInt(res);
    return 0;
}
