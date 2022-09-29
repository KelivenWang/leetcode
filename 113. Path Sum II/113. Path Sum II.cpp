// reference https://www.itdaan.com/tw/b8a3c74b7904e07d8950f9333b68d456
// reference https://www.youtube.com/watch?v=zrN2dxtQ0f0
// reference https://ithelp.ithome.com.tw/articles/10240282
// 題目的意思是指從 root 到 葉子節點的總和有沒有等於目標總和
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(root==nullptr){
            return {};
        }
        
        dfs(root,targetSum,0,ans,temp);
        return ans;
    }
private:
    void dfs(TreeNode *root, int targetSum, int curSum, vector<vector<int>> &ans, vector<int> temp){
        
        int curNum = root->val;
        temp.push_back(curNum);
        
        curSum += curNum;
        
        if(root->left==nullptr && root->right==nullptr){
            if(targetSum==curSum){
                // 總和 == 目標總和，把目前暫存合法的數組 push 到 ans
                // 並清空數組
                ans.push_back(temp);
                temp.clear();
                return;
            }
        }
        
        // 沒到葉子前繼續往下 dfs 找             
        if(root->left){

            dfs(root->left, targetSum, curSum, ans, temp);
        }
        if(root->right){
            
            dfs(root->right, targetSum, curSum, ans, temp);
        }
    }
};

int main(){
    TreeNode five(5);
    TreeNode four(4);
    TreeNode eight(8);
    TreeNode oneone(11);
    TreeNode onethree(13);
    TreeNode four2(4);
    TreeNode seven(7);
    TreeNode two(2);
    TreeNode five2(5);
    TreeNode one(1);
    
    TreeNode * head;
    head = &five;

    five.left = &four;
    five.right = &eight;

    four.left = &oneone;
    four.right = nullptr;

    oneone.left = &seven;
    seven.left = nullptr;
    seven.right = nullptr;
    oneone.right = &two;
    two.left = nullptr;
    two.right = nullptr;

    eight.left = &onethree;
    onethree.left = nullptr;
    onethree.right = nullptr;
    eight.right = &four2;

    four2.left = &five2;
    five2.left = nullptr;
    five2.right = nullptr;
    four2.right = &one;
    one.left = nullptr;
    one.right = nullptr;

    Solution solution;
    vector<vector<int>> getans;
    int targetSum = 22;
    getans = solution.pathSum(head,targetSum);

    for(int i=0; i<getans.size(); i++){
        for(int j=0; j<getans.size(); j++){
            cout<<getans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}


/*
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(NULL == root) return res;
        vector<int> temp;
        int preSum = 0;
        Lv(root, sum, preSum, temp, res);
        return res;
    }
    
void Lv(TreeNode* root,int sum, int& preSum, vector<int>& temp, vector<vector<int>>& res) {
    if(NULL == root) return;
    //進入節點就push
    preSum += root->val;
    temp.push_back(root->val);
    
    if(!root->left && !root->right)
    {
        if(sum == preSum)
        {
            res.push_back(temp);//路徑找到，copy到二維數組中
        }
        preSum -= root->val;
        temp.pop_back();
        return;
    }
    
    Lv(root->left, sum, preSum, temp, res);
    Lv(root->right, sum, preSum, temp, res);
    //離開節點就pop
    preSum -= root->val;
    temp.pop_back();
    }
};
*/