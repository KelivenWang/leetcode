#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    void reverseSt(string &st, int start, int end){
        for(int i=start, j=end; i<j; ){
            swap(st[i],st[j]);
            i++;
            j--;
        }
    }
    string reverseStr(string s, int k){
        for(int i=0; i<s.size(); i=i+(2*k)){
            // 每次取用2K的範圍移動
            if(i+k<=s.size()){
                // 還夠長(If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.)
                reverseSt(s,i,i+k-1);
                continue;
            }else{
                // 檢查剩下的長度有沒有小於k個(If there are fewer than k characters left, reverse all of them. )
                reverseSt(s,i,s.size()-1);
            }
        }return s;
    }
};

int main(){
    string s = "abcdefg";
    int k = 2;
    string getans;
    Solution solution;
    getans = solution.reverseStr(s,k);
    cout<<getans<<endl;
    return 0;
}