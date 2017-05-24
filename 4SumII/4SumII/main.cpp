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
    void printMap(unordered_map<int, int> map){
        for(pair<int, int> element: map){
            cout <<"(" << element.first<< ", " << element.second << "), ";
        }
        cout << endl;
    }
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map <int, int> m; // <sum, count>
        
        // fill the map
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                ++m[A[i] + B[j]]; // question: how (2,0) appears?
            }
        }
        printMap(m);
        cout <<"map's size: " << m.size() << endl;
        
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                int target = -1 * (C[i] + D[j]);
                cout << target << endl;
                res += m[target];
                
            }
        }
        printMap(m);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    
    Solution s;
    int res = s.fourSumCount(A, B, C, D);
    cout << res << endl;
    return 0;
}
