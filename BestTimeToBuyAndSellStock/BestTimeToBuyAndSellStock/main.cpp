//
//  main.cpp
//  BestTimeToBuyAndSellStock
//
//  Created by Wenzhen Zhu on 3/16/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//


#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> price){
        int maxProfit = 0;
        int minPrice = 10e6;
        
        for(unsigned int i = 0; i < price.size(); i++){
            minPrice = min(price[i], minPrice);
            maxProfit = max(price[i] - minPrice, maxProfit);
            
        }
        return maxProfit;
    }
    
};

int main(){
    vector<int> price = {7, 1, 5, 3, 6, 4};
    
    Solution soln;
    cout << soln.maxProfit(price) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
