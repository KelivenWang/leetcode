// reference https://www.youtube.com/watch?v=PCb1Ca_j6OU
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs("",ans,0,0,n);
        return ans;
    }

private:
    void dfs(string curString, vector<string> &ans, int left, int right, int n){
        if(right==n){
            // 右括號填滿
            ans.push_back(curString);
        }

        if(left<n){
            // 左括號還沒填滿，往下 DFS 去增加一個左括號
            // 直到往下到跟 n 一樣後 才會開始檢查右括號
            dfs(curString+"(",ans,left+1,right,n);
        }
        
        if(left>right){
            // 左括號結束==n 後開始補齊缺少的右括號
            dfs(curString+")",ans,left,right+1,n);
        }
    }
};

int main(){
/* 
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
 */
    int n = 3;
    Solution solution;
    vector<string> getans;

    getans = solution.generateParenthesis(n);
    for(int i=0; i<getans.size(); i++){
        cout<<getans[i]<<" ";
    }cout<<endl;
    return 0;
}