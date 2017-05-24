//
//  main.cpp
//  UglyNumber
//
//  Created by Wenzhen Zhu on 3/14/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false;
        if(num == 1) return false;
        while(num % 2 == 0) num /= 2;
        while(num % 3 == 0) num /= 3;
        while(num % 5 == 0) num /= 5;
        return num == 1;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    s.isUgly(2434500);
    return 0;
}
