//
//  main.cpp
//  AddDigits
//
//  Created by Wenzhen Zhu on 3/14/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int result = 0;
        
        bool oneDigit = false;
        int val = num;
        while(!oneDigit){
            while(val / 10 != 0){
                cout << val % 10 << " ";
                result += val % 10;
                val = val / 10;
                
            }
            cout << val << " " << endl;
            result += val;
            cout << "R = " << result << endl;
            
            if(result / 10 == 0){
                oneDigit = true;
            } else {
                val = result;
                result = 0;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    int digits = s.addDigits(25891);
    cout << digits << endl;
    return 0;
}
