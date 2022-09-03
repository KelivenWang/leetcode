// reference https://ithelp.ithome.com.tw/articles/10262343?sc=iThelpR

#include<iostream>
#include<stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        
        while(n>0){
            if(n&1){
                // 和 1 做 AND 運匴
                /*
                1 & 1 = 1
                1 & 0 = 0 
                 */
                ans++;
            }
            // 做完一個bit運算後右移一個bit相當於除以2!!
            n= n >> 1;
        }
        return ans;
    }
};

int main(){
/*
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits. 
 */
    Solution solutino;
    uint32_t n = 00000000000000000000000000001011;

    cout<<solutino.hammingWeight(n)<<endl;

    return 0;
}