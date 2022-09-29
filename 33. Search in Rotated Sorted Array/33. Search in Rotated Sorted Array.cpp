// reference https://walkccc.me/LeetCode/problems/0033/
// reference https://www.youtube.com/watch?v=vaGN5Cjlrfk
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分法
        int left = 0;
        int right = nums.size()-1;

        while(left<=right){

            int mid = (left + right) / 2;
            if(nums[mid]==target){
                return mid;
            }
            
            if(nums[mid]>=nums[left]){
                // nums[mid] 位在 nums[left....mid]
                if(nums[left]<=target && target<=nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                // nums[mid] 位在 nums[mid....right]
                if(nums[mid]<=target && target<=nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    Solution solution;

    cout<<solution.search(nums,target)<<endl;
    return 0;
}

/* 
int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
 */