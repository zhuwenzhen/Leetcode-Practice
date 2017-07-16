//
//  main.cpp
//  IsomorphicStrings
//
//  Created by Wenzhen Zhu on 6/1/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t){
        char map_s[128] = {0};
        char map_t[128] = {0};
        
        for(int i = 0; i < s.size(); i++){
            map_s[s[i]] = i + 1;
            map_t[t[i]] = i + 1;
        }
        for(int i = 0; i < s.size(); i++){
            cout << "(" << s[i] << ", " << map_s[s[i]] << "), ";
        }
        cout << endl;
        
        for(int i = 0; i < t.size(); i++){
            cout << "(" << t[i] << ", " << map_t[t[i]] << "), ";
        }
        cout << endl;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution soln;
    
    soln.isIsomorphic("foo", "add");
    
    return 0;
}
