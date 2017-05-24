//
//  main.cpp
//  ProductOfArrayExceptSelf
//
//  Created by Wenzhen Zhu on 3/18/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    void printVectorInt(vector<int> nums){
        for (auto elem: nums){
            cout << elem << " ";
        }
        cout << endl;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productList;
        int product2 = 1;
        for(unsigned int i = 0; i < nums.size(); i++){
            product2 = product2 * nums[i];
            productList.push_back(product2);
            for(unsigned int j = i + 1; j < nums.size(); j++){
                int product1 = nums[i]*nums[j];
                productList.push_back(product1);
            }
        }
        sort(productList.begin(), productList.end());
        sort(nums.begin(), nums.end());
        
        for(unsigned int i = 0; i < nums.size(); i++){
            productList.erase(remove(productList.begin(), productList.end(), nums[i]));
        }

        // delete duplicates
        productList.erase(unique(productList.begin(), productList.end()), productList.end());

        return productList;
    }
};

class Solution2{
public:
    void printVectorInt(vector<int> nums){
        for (auto elem: nums){
            cout << elem << " ";
        }
        cout << endl;
    }
    vector<int> productExceptSelf(vector<int>& nums){
        vector<int> products;
        for(unsigned int i = 0; i < nums.size(); i++){
            int prod = 1;
            for(unsigned int j = 0; j < nums.size(); j++){
                if(j != i){
                    prod = prod * nums[j];
                }
            }
            products.push_back(prod);
        }
        return products;
    }
};

class Solution{
public:
    void printVectorInt(vector<int> nums){
        for (auto elem: nums){
            cout << elem << " ";
        }
        cout << endl;
    }
    vector<int> productExceptSelf(vector<int> &nums){
        int N = (int)nums.size();
        vector<int> res(N,1);
        
        for(int i=0; i<N; i++){
            if (i==0)   res[i] = 1;
            else res[i] = res[i-1]*nums[i-1];
        }
        
        int r_prod = 1;
        for(int i=N-1; i>=0; i--){
            res[i] *= r_prod;
            r_prod *= nums[i];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test = {1,2,3,4};
    vector<int> result;
    Solution s;
    result = s.productExceptSelf(test);
    s.printVectorInt(result);
    return 0;
}
