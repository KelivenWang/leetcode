#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdlib>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> temp; // 暫存某個正確數組解
//         sort(nums.begin(),nums.end());

//         for(int i=0; i<nums.size(); i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 for(int k=j+1; k<nums.size(); k++){

//                     if(nums[i]+nums[j]+nums[k]==0){
//                         temp.push_back(nums[i]);
//                         temp.push_back(nums[j]);
//                         temp.push_back(nums[k]);
//                         ans.push_back(temp);
//                         temp.clear();
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &nums){
        vector<vector<int>> result;
        // 利用雙指針法 有排序就可以利用
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) return result;
            if(i>0 && nums[i]==nums[i-1]) continue; // 去重a 和過去看過的數值看是否相同

            int left = i + 1; int right = nums.size() - 1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0) right--;
                else if(nums[i]+nums[left]+nums[right]<0) left++;
                else{
                    result.push_back({nums[i],nums[left],nums[right]});

                    // 最難的地方 去重b和c 看之後的數值是否相同
                    while(left<right && nums[right]==nums[right-1]) right--;
                    while(left<right && nums[left]==nums[left+1]) left++;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

int main(){

    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution solution;
    vector<vector<int>> getans;

    getans = solution.threeSum(nums);
    for(auto i : getans){
        for(auto value : i){
            cout<<value<<" ";
        }cout<<endl;
    }
    return 0;
}