#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        // 用i和k固定兩個數之後和3Sum同樣的邏輯
        for(int k=0; k<nums.size(); k++){
            if(nums[k]>target && nums[k]>=0) break;
            if(k>0 && nums[k]==nums[k-1]) continue; // 對k去重
            for(int i=k+1; i<nums.size(); i++){
                if(nums[k]+nums[i]>target && nums[k]+nums[i]>=0) break;
                if(i>k+1 && nums[i]==nums[i-1]) continue; // 對i去重

                int left = i+1; int right = nums.size()-1;
                while(left<right){
                    if(nums[k]+nums[i]+nums[left]+nums[right]>target) right--;
                    else if((long)nums[k]+nums[i]+nums[left]+nums[right]<target) left++;
                    else{
                        result.push_back({nums[k],nums[i],nums[left],nums[right]});

                        //對left和right去重
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                        left++;
                        right++;
                    }
                }
            }
        }return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> ans;
    ans = solution.fourSum(nums,0);
    for(auto i : ans){
        for(auto value : i){
            cout<<value<<" ";
        }cout<<endl;
    }
    return 0;
}