 /*
    make window(i,j) with unique char
    1. use a hash table to sotre the last index of each char
    2. keep track the valid starting point 
        a.when there is a match update the starting point to the current one

    i = max(i,m[s[j]] + 1) len = j - i + 1;
*/
// reference https://www.youtube.com/watch?v=LupZFfCCbAU
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
        vector<int> mp(128,-1);

        for(int i=0,j=0; j<s.length(); j++){
            i = max(i, mp[s[j]]+1);
            ans = max(ans, j-i+1);
            mp[s[j]] = j;
        }
        return ans;
    }
}; 

int main(){
/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. 
 */

    Solution solution;
    string s = "abcabc bb";
    string ss = "  ";

    cout<<solution.lengthOfLongestSubstring(s)<<endl;
    system("pause");
    return 0;
}

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            
            int j = i; // j 向右移動檢查每一個新的字元
            vector<int> ump(128); // 每一次重新建立一個 ACSII hash map 儲存出現過的字元 

            while(j<s.length() && !ump[s[j]]){
                // 如果右指標向還是小於字串長度 而且 在ASCII hash map 中還沒出現過這個字元
                // 就把目前字元存入進去
                ump[s[j]]++;
                j++;
            }
            // 發現重複後把目前子字元長度和以前最常的長度相比看誰最長
            ans = max(ans, j-i);
        }
        return ans;
    }
};   
 */