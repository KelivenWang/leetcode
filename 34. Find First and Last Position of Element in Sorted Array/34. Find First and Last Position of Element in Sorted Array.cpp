// reference https://blog.csdn.net/fuxuemingzhu/article/details/83273084
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // 二分法 變形重點題型 
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1,-1};
        }

        int left = leftIndex(nums,target);
        int right = rightIndex(nums,target);
        
        if(left==right){
            return  {-1,-1};
        }
        return {left,right-1};
    }

private:
    int leftIndex(vector<int> &nums, int target){
        int right = nums.size();
        int left = 0;

        while(left<right){
            // 這樣子右邊指標會往左移動
            int mid = (left + right-1) / 2;
            
            if(nums[mid]>=target){
                // 中間值 > 目標值 更新 右指標
                // 中間值 = 目標值 更新 右指標
                // 因為這樣可以讓他繼續往左邊去檢查有沒有可能解答
                // 找出最左邊解
                right = mid;
            }else{
                // 中間值 < 目標值 更新 左指標
                left = mid + 1;
            }
        }
        // 最後左指標指到的位置是最左邊解
        return left;
    }

    int rightIndex(vector<int> &nums, int target){
        int right = nums.size();
        int left = 0;

        while(left<right){
            int mid = (left + right-1) / 2;

            if(nums[mid]<=target){
                // 中間值 < 目標值 更新左指標
                // 中間值 = 目標值 更新左指標
                // 因為這樣可以讓他繼續往右邊檢查還有沒有可能解答
                // 找出最右解
                left = mid + 1;
            }else{
                // 中間值 > 目標值 更新 右指標
                right = mid;
            }
        }
        // 最後左指標指到的位置是最右邊解的下一個，所以要-1
        return left;
    }
};

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    Solution solution;
    int target = 8;
    vector<int> getans;

    getans = solution.searchRange(nums,target);
    for(int i=0; i<getans.size(); i++){
        cout<<getans[i]<<" ";
    }cout<<endl;
    return 0;
}
