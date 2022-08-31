#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;



 /// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
 public :
    TreeNode * constructMaximumBinaryTree(vector< int >& nums) {
         if (nums.empty()) return NULL;

         int mx = INT_MIN, mx_idx = 0 ;

         for ( int i = 0 ; i < nums.size(); ++ i) {
             if (mx < nums[i]) {
                mx = nums[i];
                mx_idx = i;
            }
        }

        TreeNode *node = new TreeNode(mx);

        vector < int > leftArr = vector< int >(nums.begin(), nums.begin() + mx_idx);
        vector < int > rightArr = vector< int >(nums.begin() + mx_idx + 1 , nums.end());

        node ->left = constructMaximumBinaryTree(leftArr);
        node ->right = constructMaximumBinaryTree(rightArr);

        return node;
    }
};
int main(){
    vector<int> patern = {3,2,1,6,0,5};
    Solution test1;
    int s;

    test1.constructMaximumBinaryTree(patern);
}
