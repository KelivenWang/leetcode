#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        string substring = "";
        if(s.length()<=1){
            substring = s;
            return substring;
        }

        for(int left=0; left<s.length(); left++){
            int right = left;
            vector<int> mpforsubstring(27);

            while(right<s.length() && !mpforsubstring[s[right]-97]){

                mpforsubstring[s[right]-97] = 1;
                substring += s[right];
                right++;
            }

            substring += s[right];
            return substring;
        }

        return substring;
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
    string s = "babad";
    Solution solution;

    cout<<solution.longestPalindrome(s)<<endl;
    return 0;
}