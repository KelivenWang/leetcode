#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int lengthS = s.size();
        int ans = 0;
        map<char, int> romanInt{
                    {'I', 1}, {'V', 5}, 
                    {'X', 10}, {'L', 50},
                    {'C', 100}, {'D', 500},
                    {'M', 1000}};

        for(int i=0; i<lengthS; i++){
            // normal state
            // Roman numerals are usually written largest to smallest from left to right
            ans = ans + romanInt[s[i]]; 
            
            // case by smallest to larget(reverse) from left to right
            // e.g. "IX", 1 + 10 – 2 * 1 = 9 instead of 1 + 10 = 11
            // subtract
            if( (i>0) && (romanInt[s[i]]>romanInt[s[i-1]]) ){
                ans = ans - 2 * romanInt[s[i-1]];
            }
        }
        return ans;
    }
};

int main(){
    string s = "III";
    string s2 = "LVIII";
    string s3 = "MCMXCIV";
    Solution solution;
    int getans = 0;

    cout<<endl;
    getans = solution.romanToInt(s);
    cout<<getans<<endl;
    getans = 0;

    getans = solution.romanToInt(s2);
    cout<<getans<<endl;
    getans = 0;

    getans = solution.romanToInt(s3);
    cout<<getans<<endl;
    return 0;
}