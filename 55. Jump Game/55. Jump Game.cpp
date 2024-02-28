#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int i=0; i<nums.size(); i++){
            if(i>reach){
                return false;
            }
            int current = i+nums[i];
            reach = max(reach,current);
        }return reach >= nums.size()-1;

    }
};

int main(){
    Solution solution;
    bool getAns;
    vector<int> nums = {0};
    getAns = solution.canJump(nums);
    cout<<getAns<<endl<<endl;
    return 0;
}

// reference https://blog.csdn.net/fuxuemingzhu/article/details/83504437