#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int lengthStrs = strs.size();
        string ans = "";
        
        if(strs.empty()){
            // testdata is empty
            return "";
        }

        int min = strs[0].size();
        for(int i=0; i<lengthStrs; i++){
            // find smallest string lengths
            int strs_i = strs[i].size();
            if(strs_i<min){
                min = strs_i;
            }
        }
        int smallLengthStrs = min;

        for(int i=0; i<smallLengthStrs; i++){
            // i.g. strs[0] = "flower"
            // i.g. strs[0][1] = "f"
            // check column index if same that is substr, different than return ans
            for(int j=0; j<lengthStrs-1; j++){
                if(strs[j][i] != strs[j+1][i]){
                    // strs[0][0] is first words firt char
                    // strs[1][0] is second words first char
                    return ans;
                }
            }
            ans = ans + strs[0][i];
        }
        return ans;
    }
};

int main(){
    vector<string> strs = {"flower","flow","flight"};
    string getans;
    Solution solution;

    getans = solution.longestCommonPrefix(strs);
    cout<<getans<<endl;
    return 0;
}