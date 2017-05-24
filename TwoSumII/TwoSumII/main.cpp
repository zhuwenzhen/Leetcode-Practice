//
//  main.cpp
//  TwoSumII
//
//  Created by Wenzhen Zhu on 3/15/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void printVectorInt(vector<int> nums){
        for (auto elem: nums){
            cout << elem << " ";
        }
        cout << endl;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        cout << "target = " << target << endl;
        for(int i = 0; i < numbers.size(); i++){
            if(hash.find(target - numbers[i]) != hash.end()){                
                result.push_back(hash[target - numbers[i]]+1);
                result.push_back(i+1);
                printVectorInt(result);
                
            }
            hash[numbers[i]] = i;
            
        }

        printMap(hash);
        
        return result;
    }
    
    void printMap(unordered_map<int, int> map){
        for(pair<int, int> element: map){
            cout <<"(" << element.first<< ", " << element.second << "), ";
        }
        cout << endl;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> numbers = {2, 7, 11, 15, 1, 8};
    int target = 9;
    Solution s;
    s.twoSum(numbers, target);
    return 0;
}
