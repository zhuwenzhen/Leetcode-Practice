//
//  main.cpp
//  SingleNumber
//
//  Created by Wenzhen Zhu on 3/16/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i+=2){
            cout << nums[i] << " " << nums[i+1] << endl;
            if(nums[i] != nums[i+1]) {
                cout << nums[i] << " " << nums[i+1] << endl;
                return nums[i];
            }
        }
        return 0;
    }
};
int main(int argc, const char * argv[]) {
    Solution soln;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    soln.singleNumber(nums);
    
    return 0;
}
