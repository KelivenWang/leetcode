#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<int> hash(26,0); // 紀錄字母出現的頻率

        for(int i=0; i<words[0].size(); i++){
            hash[words[0][i]-'a']+=1;
        }

        //vector<int> hashOtherStr(26,0);
        int hashOtherStr[26] = {0};  // 統計除了第一個字符串，其他的字符串的字母出現的頻率
        for(int i=1; i<words.size(); i++){
            memset(hashOtherStr, 0, 26*sizeof(int));
            for(int j=0; j<words[i].size(); j++){
                hashOtherStr[words[i][j]-'a']+=1;
            }
            
            // 然后hash 和 hashOtherStr 取最小值，这是本题关键所在，此时取最小值，就是 一个字符在所有字符串里出现的最小次数了。
            // 更新hash，保證hash裡統計26個字符在所有字符串裡出現的最小次數
            for(int k=0; k<26; k++){
                hash[k] = min(hash[k],hashOtherStr[k]);
            }
        }

        // 把hash統計的字串次數轉換成輸出的形式
        for(int i=0; i<26; i++){
            while(hash[i]!=0){
                string s(1,i+'a'); // char->string
                result.push_back(s);
                hash[i]--;
            }
        }
        return result;
    }
};

int main(){
    vector<string> input = {"bella","label","roller"};
    Solution solution;
    vector<string> getinput;
    getinput = solution.commonChars(input);
    
    for(int i=0; i<getinput.size(); i++){
        cout<<getinput[i]<<endl;
    }
    return 0;
}