#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        return pow(x,0.5);
    }
};

int main(){
    Solution solution;
    int getans;
    int input1 = 4;
    int input2 = 8;

    getans = solution.mySqrt(input1);
    cout<<getans<<endl;

    getans = solution.mySqrt(input2);
    cout<<getans<<endl;
    return 0;
}