//
//  main.cpp
//  RomanToInteger
//
//  Created by Wenzhen Zhu on 5/25/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T =
            {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D' ,500}, {'M', 1000}};
        
        int sum = T[s.back()];
        for(int i = s.length() - 2; i >= 0; --i){
            if(T[s[i]] < T[s[i+1]]){
                sum -= T[s[i]];
            } else {
                sum += T[s[i]];
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string str = "XIV";
    Solution s;
    cout << s.romanToInt(str) << endl;
    return 0;
}
