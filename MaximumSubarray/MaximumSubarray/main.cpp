//
//  main.cpp
//  MaximumSubarray
//
//  Created by Wenzhen Zhu on 3/16/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>

using namespace std;
#include <math.h>
#include <vector>
class Solution {
    
public:
    // DP: lookup[i] = max(A[i], A[i] + lookup[i - 1])
    int maxSubArray(vector<int>& nums) {
        // base
        if(nums.size() == 0){
            return INT_MIN;
        }
        
        int pre = nums[0];
        int maxSum = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            //cout << nums[i] << endl;
            cout << "pre = " << pre << endl;
            pre = max(nums[i], nums[i] + pre);
            cout << "nums[i] = " << nums[i] << " updated pre = " << pre << endl;
            maxSum = max(maxSum, pre);
            cout << maxSum << endl;
        }
        return maxSum;
    }
};

int main(int argc, const char * argv[]) {
    Solution soln;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    soln.maxSubArray(nums);
    return 0;
}
