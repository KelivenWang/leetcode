// reference https://hackmd.io/@brad84622/SJSQF1cxw
#include<iostream>
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
    bool subtreeISmirror(TreeNode * t1, TreeNode * t2){
        if((t1==nullptr) && (t2==nullptr)){
            // only have root
            return true;
        }
        else if((t1==nullptr) || (t2==nullptr)){
            // one left or right subnode didn't have value
            return false;
        }
        else{
            // left and right subnode all have value need to distingue
            return ((t1->val==t2->val) && (subtreeISmirror(t1->left,t2->right)) && (subtreeISmirror(t1->right,t2->left)));
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            // root is null
            return true;
        }
        else{
            return subtreeISmirror(root->left,root->right);
        }
    }
};

int main(){
    Solution solution;
    TreeNode one(1);
    TreeNode two(2);
    return 0;

}