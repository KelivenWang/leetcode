#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty() || s.length()==1){
            return true;
        }
        int sLen = s.size();
        int frontpt = 0, backpt = sLen-1;
        while(frontpt<backpt){
            while(frontpt<backpt && !isalnum(s[frontpt])){
                frontpt++;
            }
            while(frontpt<backpt && !isalnum(s[backpt])){
                backpt--;
            }
            if(tolower(s[frontpt++])!=tolower(s[backpt--])){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s = "A man, a plan, a canal: Panama";
    Solution solution;
    cout<<solution.isPalindrome(s)<<endl;
    return 0;
}

// reference https://blog.csdn.net/weixin_41162823/article/details/80172379
// reference https://zxi.mytechroad.com/blog/two-pointers/leetcode-125-valid-palindrome/