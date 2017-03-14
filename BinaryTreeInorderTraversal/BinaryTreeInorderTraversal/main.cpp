//
//  main.cpp
//  BinaryTreeInorderTraversal
//
//  Created by Wenzhen Zhu on 3/14/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#include <stack>

using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    
    void printVectorInt(vector<int> vec){
        for(auto e: vec){
            cout << e << " ";
        }
        cout << endl;
    }
    // recursion
    void inorder(TreeNode * node, vector<int> &result){
        if(!node) return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }
    
    vector<int> inorderTraversalR(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
    
    // iterative - use stack
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> nodes;
        stack<TreeNode *> toVisit;
        
        TreeNode* currentNode = root;
        while(currentNode || toVisit.empty()){
            if(currentNode){
                toVisit.push(currentNode);
                currentNode = currentNode -> left;
            } else {
                currentNode = toVisit.top();
                toVisit.pop();
                nodes.push_back(currentNode -> val);
                currentNode = currentNode -> right;
            }
        }
        return nodes;
    }
  
    
};

int main(int argc, const char * argv[]) {
    // Tree Init
    
    Solution s;
    TreeNode t = TreeNode(1);
    // vector<int> res = s.inorderTraversalR(*t);
    // s.printVectorInt(res);
}
