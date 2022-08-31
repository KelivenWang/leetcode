/*
205. Isomorphic Strings
https://leetcode.com/problems/isomorphic-strings/
reference
https://blog.csdn.net/qjh5606/article/details/81453618
*/

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // cause problem tell us "s and t consist of any valid ascii character.", so consider two array to map each character
        // each index(0~255) for Array m1 & m2 were mapped corresponding ascii table character.
        int m1[256] = {0}, m2[256] = {0};
        int n = s.size();

        for(int i=0; i<n; i++){
            if(m1[s[i]] != m2[t[i]]){
                // 如果對應過的次數不相同則 false
                return false;
            }
            // stringS's letter corresponding m1 table one times than i+1 代表對應過一次
            // stringT's letter corresponding m2 table one times than i+1 代表隊應過一次
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        return true;
    }
};

int main()
{
    string
    s1 = "egg",
    t1 = "add",
    s2 = "foo",
    t2 = "bar";

    bool flag = false;
    Solution solution;
    flag = solution.isIsomorphic(s1,t1);
    cout<<flag<<endl;

    flag = solution.isIsomorphic(s2,t2);
    cout<<flag;

    return 0;
}
