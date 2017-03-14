//
//  main.cpp
//  GroupAnagrams
//
//  Created by Wenzhen Zhu on 3/14/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    void printMap(unordered_map<string, multiset<string>> map){
        for(pair<string, multiset<string>> element: map){
            for(multiset<string>:: const_iterator it(element.second.begin()), end(element.second.end());
                it != end; ++it){
                cout << element.first << " " << *it << endl;
            }
        }
        cout << endl;
    }
    
    void printVector(vector<string> vec){
        for(auto e: vec){
            cout << e << " ";
        }
        cout << endl;
    }
    void printVectorOfVector(vector<vector<string>> vec){
        for(auto e: vec){
            printVector(e);
        }
        cout << endl;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> map;
        vector<vector<string>> res;
        
        for(string s: strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            map[temp].insert(s);
        }
        
        for(auto e: map){
            vector<string> anagram(e.second.begin(), e.second.end());
            
            res.push_back(anagram);
        }
        //printMap(map);
        // printVectorOfVector(res);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<string> test = {"eat", "tea", "tan", "ate", "nat", "bat"};
    s.groupAnagrams(test);
    
    return 0;
}
