#include<stdio.h>
#include<stdint.h>
#include<string>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans,temp1;
        vector<uint32_t> vt;

        while(n!=0){
            temp1 = n % 2;
            vt.push_back(temp1);
            n = n / 2;
        }
        for(int i=vt.size(); i<32; i++){
            vt.push_back(0);
        }
        for(int i=0; i<vt.size(); i++){
            ans = ans + vt[i] * pow(2,vt[i]);
        }
        return ans;
    }
};

int main(){
    Solution solution;
    uint32_t n = 00000010100101000001111010011100;
    uint32_t getans;
    getans = solution.reverseBits(n);
    cout<<getans<<endl;
    return 0;
}