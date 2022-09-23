// reference https://www.youtube.com/watch?v=fLy8t33M1qQ&t=1s
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }

        vector<string> ans;
        unordered_map<int,string> mp;
        mp[0] = " ";
        mp[1] = "";
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi"; 
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        string cur;
        dfs(digits,mp,0,cur,ans);
        return ans;
    }

    void dfs(string &Digits, unordered_map<int,string> &mp, int len, string &cur, vector<string> &ans){
        if(len==Digits.length()){
            ans.push_back(cur);
            return;
        }

        for(const char c : mp[Digits[len]-'0']){
            cur.push_back(c);
            dfs(Digits,mp,len+1,cur,ans);
            cur.pop_back();
        }
    }
};

int main(){
    string digits = "2";
    Solution solution;
    vector<string> getans;

    getans = solution.letterCombinations(digits);
    for(int i=0; i<getans.size(); i++){
        cout<<getans[i]<<" ";
    }cout<<endl;
    system("pause");
    return 0;
}