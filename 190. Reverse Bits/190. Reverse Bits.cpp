// reference https://www.cnblogs.com/grandyang/p/4321355.html

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
        // 把要翻转的数从右向左一位位的取出来
        uint32_t ans = 0;
        for(int i=0; i<32; i++) {
            if((n&1)==1){
                // 取出来的是1，将结果 res 左移一位并且加上1
                ans = (ans << 1) + 1;
            }else{
                // 取出来的是0，将结果 res 左移一位
                ans = ans << 1;
            }
            // 然后将n右移一位即可
            n = n >> 1;
        }
        return ans;
    }
};

int main(){
/*
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the 
unsigned integer 43261596, so return 964176192 which its binary representation 
is 00111001011110000010100101000000.
*/
    Solution solution;
    uint32_t n = 43261596;
    uint32_t getans;
    getans = solution.reverseBits(n);
    cout<<getans<<endl;
    return 0;
}