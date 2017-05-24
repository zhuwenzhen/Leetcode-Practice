//
//  main.cpp
//  4SumII
//
//  Created by Wenzhen Zhu on 3/14/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /*void printMap(unordered_map<int, int> map){
        for(pair<int, int> element: map){
            cout <<"(" << element.first<< ", " << element.second << "), ";
        }
        cout << endl;
    }*/
    vector<vector<int>> fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<vector<int>> res;
        unordered_map <int, vector<vector<int>>> m;
        // fill the map
        for(int i = 0; i < A.size(); i++) {
            for(int j = i+1; j < B.size(); j++) {
                m[A[i] + B[j]].push_back(vector<int>({i, j}));
            }
        }
        
        cout <<"map's size: " << m.size() << endl;
        
        for(int i = 0; i < C.size(); i++){
            for(int j = i+1; j < D.size(); j++){
                int target = -1 * (C[i] + D[j]);
                cout << target << endl;
                for (auto k = m[target].begin(); k != m[target].end(); k++) {
                    if ((*k)[1] < i) {
                        res.push_back(vector<int>({A[(*k)[0]], B[(*k)[1]], C[i], D[j]}));
                    }
                }
            }
        }
        //printMap(m);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  S = {1,0,-1,0,-2,2};
    
    Solution s;
    vector<vector<int>> res = s.fourSumCount(S, S, S, S);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
