// reference https://hackmd.io/@Ji0m0/B1dUOaRjN/https%3A%2F%2Fhackmd.io%2F%40Ji0m0%2FHyAgG6bU_
// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/
#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
  void traversal(TreeNode * node, vector<int> &res){
    if (node){

        traversal(node->left, res);
        res.push_back(node->val);
        traversal(node->right, res);
    }
  }
  vector<int> inorderTraversal(TreeNode* root) {

    vector<int> res;
    traversal(root, res);
    return res;
  }
};

int main(){
    // inorder left middle right !!
    vector<int> root = {1,2,3,4};
    vector<int> getans;
    Solution solution;

    TreeNode * trail;
    TreeNode * head;
    head = new TreeNode;
    head = trail;

    for(int i=0; i<root.size(); i++){
        TreeNode * newnode;
        newnode = new TreeNode;

        newnode->val = root[i];
        trail->right = newnode;
        trail = newnode;
    }
    
    getans = solution.inorderTraversal(head);
    TreeNode * ptr;
    for(int i=0; i<getans.size(); i++){
      cout<<getans[i]<<" ";
    }
    cout<<endl;

    
    cout<<endl;
    return 0;
}