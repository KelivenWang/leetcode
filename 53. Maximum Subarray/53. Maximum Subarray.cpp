#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 卡達內演算法用來找最大子數組
        int numsLen = nums.size();
        int ans = INT_MIN;
        int currentSum = nums[0];

        if(numsLen==1){
            return nums[0];
        }

        for(int i=1; i<numsLen; i++){
            // 計算加入新數字後的數組和新數字中的大小
            currentSum = max(currentSum+nums[i],nums[i]);

            // 更新後的結果和目前最大值相比比大小
            ans = max(ans,currentSum);
        }
        return ans;
    }
};

int main(){

    Solution solution;
    vector<int> test = {-2,-3,-1,-5};
    int ans = solution.maxSubArray(test);
    cout<<ans<<endl;
    return 0;
}