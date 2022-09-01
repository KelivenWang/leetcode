#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        // n = 27 = 3*3*3
        for(int i=0; ; i++){
            if(pow(3,i)==n){
                return true;
            }
            if(pow(3,i)>n){
                return false;
            }
        }
        return -1;
    }
};

int main(){
    int n = 0;
    Solution solution;
    cout<<solution.isPowerOfThree(n)<<endl;
    return 0;
}

/*
另外一種解法 比較好 fmod(x,y) // x=分子 y=分母
class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;
    }
};
*/