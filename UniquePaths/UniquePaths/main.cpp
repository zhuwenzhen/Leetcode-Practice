//
//  main.cpp
//  UniquePaths
//
//  Created by Wenzhen Zhu on 3/29/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 function choose(n, k)
 if k == 0 return 1
 return (n * choose(n - 1, k - 1)) / k
 */

class Solution {
public:
    unsigned long long int factorial(unsigned int n) {
        if (n == 0){
            return 1;
        }
        return n * factorial(n - 1);
    }
    
    int choose(int n, int k){
        if (k == 0) {
            return 1;
        } else if (k > n/2){
            return choose(n, n - k);
        }
        return n * choose(n - 1, k - 1)/k;
    }
    
    int f(int n, int k){
        return (int) factorial(n)/(factorial(n-k)*factorial(k));
    }
    int uniquePaths(int m, int n) {
    
        return f(m+n-2, n-1);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    cout << s.uniquePaths(10, 9) << endl;
    return 0;
}
