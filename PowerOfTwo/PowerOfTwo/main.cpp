//
//  main.cpp
//  PowerOfTwo
//
//  Created by Wenzhen Zhu on 6/6/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }
        
        int oneBitCount = 0;
        
        for(int i = 0; i < 32; i++){
            if((n & 1) == 1){
                oneBitCount ++;
                
            }
            
            cout << n << endl;
            n = n >> 1;
            
        }
        return oneBitCount == 1;
    }
    
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.isPowerOfTwo(8);
    return 0;
}
