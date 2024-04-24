#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 暴力解法
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> result;
//         for(int i=0; i<nums.size(); i++){
//             for(int j=0; j<nums.size(); j++){
//                 if(i!=j){
//                     if((nums[i]+nums[j]) == target){
//                         result.push_back(i);
//                         result.push_back(j);
//                         return result;
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };

// https://medium.com/@chingyu.tung/leetcode-%E6%B6%88%E5%8C%96%E9%81%93-two-sum-%E8%A7%A3%E9%A1%8C%E7%AD%86%E8%A8%98-28f07b6dbf2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> discovered; // <key,value>
        vector<int> result;

        for(int i=0; i<nums.size(); i++){
            int numFind = target - nums[i];
            if(discovered.find(numFind)==discovered.end()){
                // 如果找到了則返回指向該元素的迭代器，否則返回 end()
                // 沒找到 把目前的數值放到已經查找過的 map 中
                discovered[nums[i]] = i;
            }else{
                result.push_back(discovered[numFind]);
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
};

int main(){
    // nums = [2,11,7,15], target = 9
    // ream = [7,-2,2,-6]
    Solution solution;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans;
    
    ans = solution.twoSum(nums,target);

    return 0;
}