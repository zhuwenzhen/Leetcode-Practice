//
//  main.cpp
//  BinarySearchArray
//
//  Created by Wenzhen Zhu on 3/16/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

// find index of first occurrence in a sorted array, binary search

using namespace std;
class Solution{
public:
    int firstOccurrence(vector<int> &nums, int t){
        int index = 0;
        int min = 0;
        int max = (int) nums.size() - 1;
        int mid;
        while(min < max){
            mid = (min + max) / 2;
            //cout << mid << endl;
            if(nums[mid] == t){
                while(nums[mid] == t){
                    mid--;
                    cout << mid + 1 << endl;
                }
                index = mid+1;
                break;
            }
            else if(nums[mid] < t){
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return index;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {0,0,1, 1, 1, 1, 1,1,1,2,3,4,4,5,5,6, 7, 8};
    Solution soln;
    soln.firstOccurrence(nums, 1);
    return 0;
}
