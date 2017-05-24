//
//  main.cpp
//  FindPeakElement-I
//
//  Created by Wenzhen Zhu on 3/25/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = (int)nums.size() - 1;
        
        if (end < 1){
            return 0;
        }
        
        int mid = (end + start) / 2;
        
        while(start < end){
            if(nums[mid] < nums[mid + 1]){
                start = mid + 1;
            } else if (nums[mid] > nums[mid+1]){
                end = mid;
            }
            mid = (end + start) / 2;
        }
        return start;
    }
};



int main(int argc, const char * argv[]) {
    vector<int> v = {1,2,3,1};
    Solution s;
    cout << s.findPeakElement(v) << endl;
    return 0;
}
