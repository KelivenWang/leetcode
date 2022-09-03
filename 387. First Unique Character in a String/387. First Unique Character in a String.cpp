#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    
    int firstUniqChar(string s) {
        /*
            建立一個 map table 儲存字串中每個子母出現次數
            之後依序從第一個字母尋找哪個字母只出現一次 
         */
        int key = 0;
        int mp[26] = {0};
        for(int i=0; i<s.size(); i++){
            // ASCII 小寫編碼 a=97
            key = s[i] - 97;
            mp[key]++;
        }

        for(int i=0; i<s.size(); i++){
            key = s[i] - 97;
            if(mp[key] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main(){
/*
Input: s = "leetcode"
Output: 0 
 */    
    string s = "loveleetcode";
    Solution solution;

    cout<<solution.firstUniqChar(s)<<endl;
    return 0;
}