#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> sum(n+1,0);
        sum[0] = sum[1] = 1;
        // sum[2] = 2;
        // i don't know why i can't do it
        for(int i=2; i<=n; i++){
            sum[i] = sum[i-1] + sum[i-2];
        }
        return sum[n];
    }
};

int main(){
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    Solution solution;
    int getans;

    getans = solution.climbStairs(n1);
    cout<<getans<<endl;

    getans = solution.climbStairs(n2);
    cout<<getans<<endl;

    getans = solution.climbStairs(n3);
    cout<<getans<<endl;
    return 0;
}