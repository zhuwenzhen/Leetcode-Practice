//
//  main.cpp
//  ClimbingStairs
//
//  Created by Wenzhen Zhu on 3/16/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>

#include <iostream>

using namespace std;

class Solution{
public:
    int climbStairs(int n){
        // 1: 1
        // 2: 1, 1; 2;
        // 3: 1, 1, 1; 2, 1; 1, 2
        // 4: 1, 1, 1, 1; 2, 1, 1; 1, 2, 1; 1, 1, 2; 2, 2
        
        // 1: 1
        // 2: 2;
        // 3: 3;
        // 4: 5;
        // 5: 8;
        
        // f[n]:= f[n-1] + f[n-2]
        
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int f1 = 2;
        int f2 = 1;
        int fn = 0;
        for(int i = 3; i <= n; i++){
            fn = f1 + f2;
            f2 = f1;
            f1 = fn;
        }
        return fn;
    }
};

int main (){
    Solution sol;
    cout << sol.climbStairs(6) << endl;
    return 0;
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
