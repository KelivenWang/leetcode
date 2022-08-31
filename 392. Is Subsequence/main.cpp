/*
392. Is Subsequence
https://leetcode.com/problems/is-subsequence/

reference
https://just4once.gitbooks.io/leetcode-notes/content/leetcode/binary-search/392-is-subsequence.html
https://clay-atlas.com/blog/2022/03/02/leetcode-392-is-subsequence/
*/

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <map>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lengthS = s.length();
        int lengthT = t.length();
        int indexS = 0;

		if(lengthS == 0){
            return true;
		}

		for(int indexT=0; indexT<lengthT; ++indexT){
            if(s[indexS] == t[indexT]){
                ++indexS;
            }

            if(indexS == lengthS){
                return true;
            }
		}
        return false;
    }
};

int main()
{
    string
    s1 = "abc",
    t1 = "ahbgdc",
    s2 = "axc",
    t2 = "ahbgdc";

    bool flag = false;
    Solution solution;
    flag = solution.isSubsequence(s1,t1);
    cout<<flag<<endl;

    flag = solution.isSubsequence(s2,t2);
    cout<<flag;

    return 0;
}
