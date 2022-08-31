// reference https://www.cnblogs.com/yunmeng-shi/p/14977295.html

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return nullptr;
        }
        int min = nums.size() / 2;
        TreeNode * node;
        node = new TreeNode;
        node->val = nums[min];
    
        vector<int> leftTree(nums.begin(), nums.begin() + min);
        vector<int> rightTree(nums.begin()+1+min, nums.end());

        if (min != 0) 
            node->left = sortedArrayToBST(leftTree); 
        if (min != nums.size() - 1)
            node->right = sortedArrayToBST(rightTree);
        return node;
    }
};

int main(){
    Solution solution;
    vector<int> data = {-10,-3,0,5,9};

    // solution.sortedArrayToBST(data);

    TreeNode * ptr;
    TreeNode * getans;
    getans = solution.sortedArrayToBST(data);
    ptr = getans;

    while(ptr!=nullptr){
        cout<<getans->val<<" ";
        ptr = getans->left;
    }
    return 0;
}