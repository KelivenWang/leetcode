#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int len = nums.size() + 1;
        // 建立nums的hash 表
        vector<int> mp(len,0);
        for(int i=0; i<nums.size(); i++){
            // 放置正確的hash表的位置
            mp[nums[i]-0]++;
        }

        for(int i=0; i<len; i++){
            if(mp[i]==0){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    Solution solution;
    int getans = 0;
    getans = solution.missingNumber(nums);
    cout<<getans<<endl;
    return 0;
}