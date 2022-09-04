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
        
        if(s.length()<=1){
            return s.length();
        }

        // 用 hash map 來建立字母有無出現過
        //unordered_map<int,int> ump;
        int ans = 0;

        for(int i=0; i<s.length(); i++){
            int j = i;
            vector<int> ump(128); 
            // 必須要進行設定在128內 因為 ASCII 表格最多用到 0~127 的編碼
            // 如果沒有預先設定的話 時間複雜度會是在 O(N^2) -> O(N*128)
            // And it can avoid TLE 
            while(j<s.length() && !ump[s[j]]){
                // if j still < s.length() and map can not find char s[j]
                // put new s[j] into hash map that present char s[j] are in
                ump[s[j++]]++;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};  
 */