//
//  main.cpp
//  WordBreakII
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
    bool contains(string s, vector<string> wordDict){
        for (auto word: wordDict){
            if(word.compare(s)) {
                return true;
            }
        }
        return false;
    }
    
    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        unordered_map<string, vector<string>> hash;
        
        if(hash.count(s)) return hash[s];
        
        for (auto word: wordDict){
            if(word == s) {
                result.push_back(s);
            }
        }
        
        for(int i = 0; i < s.size(); ++i){
            string word = s.substr(i);
            // cout << word << " ";
            
            if(contains(word, wordDict)){
                string rem = s.substr(0,i);
                cout << rem << " ";
                vector<string> prev = combine(word, wordBreak(rem, wordDict));
                result.insert(result.end(), result.begin(), prev.end());
            }
        }
        hash[s] = result;
        cout << endl;
        return result;
    }
};


int main(int argc, const char * argv[]) {
    
    string s = "catsanddog";
    
    vector<string> dictionary = {"cat", "cats", "and", "sand", "dog"};
    
    Solution soln;
    soln.wordBreak(s, dictionary);
    
    
    
    return 0;
}
