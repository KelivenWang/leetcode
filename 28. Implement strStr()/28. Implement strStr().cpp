#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    const int length_haystack = haystack.length();
    const int length_needle = needle.length();

    for(int i = 0; i<=length_haystack-length_needle; i++){
        // 如果要字串長度-子字串長度小於子字串長度，那就不可能會有子字串存在
        int j = 0;
        while (j<length_needle && haystack[i+j]==needle[j]){
            // i=piovt index 如果字符不一樣則字串piovt要在往下一個index
            j++;
        }
        if(j==length_needle){
            return i;
        }
    }
    return -1;
  }
};

int main(){
    string haystack1 = "hello";
    string needle1 = "ll";
    string haystack2 = "mississippi";
    string needle2 = "issip";
    Solution solution;

    cout<<solution.strStr(haystack1,needle1)<<endl;
    cout<<solution.strStr(haystack2,needle2)<<endl;
    return 0;
}

/*
        for(int i=0; i<length_haystack; i++){
            // cout<<string(haystack.begin()+i, haystack.begin()+i+length_needle)<<endl;
            if(string(haystack.begin()+i, haystack.begin()+i+length_needle) == needle){
                return i;
            }
        }   
        return -1;
        */