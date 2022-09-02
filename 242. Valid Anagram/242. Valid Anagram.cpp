#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size()!=t.size()){
            return false;
        }
        
        // 建立兩個字串的Hash table表格 並初始化為0
        vector<int> checkS(26,0);
        vector<int> checkT(26,0);
        for(int i=0; i<s.size(); i++){
            // 放置相對應的位置
            checkS[s[i]-'a']++;
        }

        for(int i=0; i<t.size(); i++){
            checkT[t[i]-'a']++;
        }

        for(int i=0; i<26; i++){
            if(checkS[i]!=checkT[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    string s = "rat";
    string t = "car";

    cout<<solution.isAnagram(s,t)<<endl;
    system("pause");
    return 0;
}