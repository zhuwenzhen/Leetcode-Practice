//
//  main.cpp
//  4Sum
//
//  Created by Wenzhen Zhu on 3/13/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        size_t n = nums.size();
        if(n < 4){
            return total;   // currently empty
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            int target3 = target - nums[i];
            
            for(int j = i + 1; j < n; j++) {
                int target2 = target3 - nums[j];
                int front = j + 1;
                int back = (int) n - 1;
                while (front < back){
                    int two_sum = nums[front] + nums[back];
                    if(two_sum < target2) front++;
                    else if (two_sum > target2) back--;
                    else{
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        total.push_back(quadruplet);
                        
                        // processing the duplicates of number 3
                        while(front < back && nums[front] == quadruplet[2]) ++front;
                        
                        // processing the duplicates of number 4
                        while(front < back && nums[back] == quadruplet[3]) --back;
                    }
                    cout << "----------------" << endl;
                    printVectorContent(total);
                }
                // processing the duplicates of number 2
                // while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            //while(i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return total;
    }
    
    void printVectorContent(vector<vector<int>> vec){
        for(unsigned int i = 0; i < vec.size(); i++){
            for(unsigned int j = 0; j < vec[i].size(); j++){
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution mySolution;
    
    vector<int> array = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = mySolution.fourSum(array, 0);
    cout << "================" << endl;
    mySolution.printVectorContent(res);
    return 0;
}
