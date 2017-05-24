//
//  main.cpp
//  SimplifyPath
//
//  Created by Wenzhen Zhu on 3/21/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    void printVector(vector<string> vec){
        for(auto e: vec){
            cout << e << " ";
        }
        cout << endl;
    }
    
    void split(string s, char delim, vector<string>& nodes) {
        string temp;
        stringstream ss(s);
        while(getline(ss, temp, delim)) {
            nodes.push_back(temp);
        }
    }
    
    string simplifyPath(string path) {
        stack<string> st;
        vector<string> nodes;
        string result;
        split(path, '/', nodes);
        printVector(nodes);
        for(auto node : nodes) {
            //empty or only '.' path no change
            if(node == "" || node == ".")  continue;
            //go back to the upper directory
            if(node == ".." && !st.empty())  st.pop();
            //push back the current directory
            else if(node != "..")  st.push(node);
        }
        for(auto it : st) result += "/" + it;
        return result.empty() ? "/" : result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.simplifyPath("/a/./b/../../c/");
    return 0;
}
