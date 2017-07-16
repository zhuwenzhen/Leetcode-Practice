//
//  main.cpp
//  SerializeAndDeserializeBinaryTree
//
//  Created by Wenzhen Zhu on 6/15/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

// Serialize and Deserialize Binary Tree

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right (NULL) {}
};

class Codec {
public:
    
    vector<vector<int> > levelOrderTraversal(TreeNode *root) {
        vector<vector<int> >  result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur_vec;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t==NULL) {
                result.push_back(cur_vec);
                cur_vec.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                cur_vec.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return result;
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;
        
        while(!stack.empty() || pCurrent)
        {
            if(pCurrent)
            {
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else
            {
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }
    void printVectorInt(vector<int> vec){
        for(auto e: vec){
            cout << e << " ";
        }
        cout << endl;
    }
    
    // Encodes a tree to a single string.
    string serialize1(TreeNode* root) {
//        vector<int> inorderTraversalResult = inorderTraversal(root);
        vector<vector<int>> levelOrderTraversalResult = levelOrderTraversal(root);
        string str = "";
        for(vector<int> e: levelOrderTraversalResult){
            for(int elem: e){
                str += to_string(elem) + " ";
            }
        }
        str.pop_back();
        
        return str;
    }
    
    
    string serialize(TreeNode* root){
        ostringstream out;
        serialize(root, out);
        string res = out.str();
        res.pop_back();
        return res;
    }
    
    TreeNode * deserialize(string is) {
        istringstream inputStream(is);
        auto pair = readValue(inputStream);
        if (pair.first == false) {
            return NULL;
        } else {
            TreeNode * root = new TreeNode(pair.second);
            deserialize(root, inputStream);
            return root;
        }
    }
private:
    void serialize(TreeNode * root, ostringstream& os){
        
        if(root){
            os << root->val << " ";
            serialize(root->left, os);
            serialize(root->right, os);
        } else{
            os << "n ";
        }
    }
    
    // Decodes your encoded data to tree.
    
    pair<bool, int> readValue(istringstream & input) {
        string valueString;
        input >> valueString;
        if (valueString == "n") {
            return make_pair(false, 0);
        } else {
            return make_pair(true, stoi(valueString));
        }
    }
    
    void deserialize (TreeNode * root, istringstream& input) {
        auto leftPair = readValue(input);
        if (leftPair.first == true) {
            root->left = new TreeNode(leftPair.second);
            deserialize(root->left, input);
        }
        
        auto rightPair = readValue(input);
        if (rightPair.first == true) {
            root->right = new TreeNode(rightPair.second);
            deserialize(root->right, input);
        }
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    // make a tree
    /*
      1
     / \
    2   3
       / \
      4   5
     */
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = NULL;
    node1->right = NULL;
    
    node2->left = node3;
    node2->right = node4;
    
    Codec c;
    string serialRes = c.serialize1(root);
    cout << serialRes << endl;
    
    string serial = c.serialize(root);
    cout << serial << endl;
    
    string test = "1 2 n n 3 4 n n 5 n n";
    TreeNode * res = c.deserialize(test);
    
//    vector<int> traversal = c.inorderTraversal(root);
//    c.printVectorInt(traversal);
    return 0;
}
