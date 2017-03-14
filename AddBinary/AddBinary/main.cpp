//
//  main.cpp
//  AddBinary
//
//  Created by Wenzhen Zhu on 3/13/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <bitset>

using namespace std;
const size_t size = sizeof(unsigned long) * CHAR_BIT;
typedef std::bitset<size> my_bitset;


class Solution {
public:
    int convertToDecimal(string n){
        size_t len = n.size();
        int result = 0;
        for(int i = 0; i < len; i++){
            int temp;
            if(n[i] == '1'){
                temp = 1;
            }else{
                temp = 0;
            }
            result += temp * pow(2,(len - i - 1));
        }
        return result;
    }
    
    long binary(int n){
        long bin = 0;
        int remainder, i = 1;
        
        while(n!=0){
            remainder = n % 2;
            n /= 2;
            bin += remainder * i;
            i *= 10;
        }
        return bin;
    }
    
    string numToBits(int number){
        if(number == 0){
            return "0";
        }
        string temp;
        
        int n = (number > 0) ? number : - number;
        while(n > 0){
            temp = string((n & 1)? "1" : "0") + temp;
            n = n / 2;
        }
        if (number < 0)
            temp = "-" + temp;
        
        return temp;
    }
    

    string addBinary(string a, string b) {
        string result;
        int numA = convertToDecimal(a);
        int numB = convertToDecimal(b);
        
        int res = numA + numB;
        // cout << res << endl;
        
        return numToBits(res);
    }
    
    int digitNum (int n){
        int digit = 0;
        while(n!=0){
            n/=2;
            digit++;
        }
        return digit;
    }
    
    

};

int main(){
    Solution sol;
    cout << sol.addBinary("1110110101", "1110111011") << endl;
    return 0;
}
