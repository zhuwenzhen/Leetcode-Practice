//
//  main.cpp
//  Amazon_FindEven
//
//  Created by Wenzhen Zhu on 6/15/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.

/*
 Given an array with repeated integers, find all the numbers repeated even times
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> FindEven(vector<int> array){
        unordered_map<int, int> map;
        
        for(int num : array){
            map[num] += 1;
        }
        printMap(map);
        
        vector<int> result;
        
        
        for(auto e: map){
            if(e.second % 2 == 0){
                result.push_back(e.first);
            }
        }
        return result;
    }
    
    void printMap(unordered_map <int, int> map){
        for(auto e: map){
            cout << e.first << " " << e.second << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    vector<int> arr = {1,2,2,3,4,4,5,6,6,6,6};
    
    vector<int> res = s.FindEven(arr);
    
    for(auto elem : res){
        cout << elem << " ";
    }
    cout << endl;
    
    
    return 0;
}
