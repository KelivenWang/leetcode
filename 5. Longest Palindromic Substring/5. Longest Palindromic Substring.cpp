#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        if(s==""){
            return "";
        }

        vector<vector<int> > dp(s.size(),vector<int>(s.size(),0));
        int head = 0;
        int trail = 0;
        int max = 0;
        // 初始化 dp 
        for(int i=0; i<s.size(); i++){
            dp[i][i] = 1; // 字串長度 = 1
            if((i+1)<s.size() && s[i]==s[i+1]){
                // 長度為 2 的子字串
                dp[i][i+1] = 1;
            }
        }

        for(int i=2; i<s.size(); i++){
            // i 是第幾個從左上到右下的對角線 i = 0 表示主對角線
            for(int j=0; j<s.size()-i; j++){
                // j 是第幾行
                if(dp[j+1][j+i-1]==1 && s[j]==s[j+i]){
                    dp[j][j+i] = 1;
                }
            }
        }

        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(dp[i][j]){
                    if(j-i>max){
                        head = i;
                        trail = j;
                        max = j-i;
                    }
                }
            }
        }
        return s.substr(head,trail+1-head);
        
    }
};

int main(){
/* 
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

想法 :  給定左子針 右子針
        右子針代表目前檢查的字母
        如果左不等於右 -> 目前字母加入到 substring 中
        如果最左邊字母等於最右邊字母 -> return 答案
 */
    string s = "abdca";
    Solution solution;

    cout<<solution.longestPalindrome(s)<<endl;
    return 0;
}