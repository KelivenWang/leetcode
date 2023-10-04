#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // similar as 53.Maximum Subarray
        int numsLen = nums.size();
        int maxans = nums[0];
        vector<int> minNum(numsLen,0);
        vector<int> maxNum(numsLen,0);
        
        // init NP
        minNum[0] = nums[0];
        maxNum[0] = nums[0];

        if(numsLen==1){
            return nums[0];
        }

        for(int i=1; i<numsLen; i++){
            minNum[i] = min(min(minNum[i-1]*nums[i],maxNum[i-1]*nums[i]),nums[i]);
            maxNum[i] = max(max(minNum[i-1]*nums[i],maxNum[i-1]*nums[i]),nums[i]);
            maxans = max(maxans,maxNum[i]);
        }
        return maxans; 
    }
};

int main(){
    vector<int> arr = {-2,3,-4};
    Solution solution;
    int res = solution.maxProduct(arr);
    cout<<res<<endl;
    return 0;
}

/*class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // similar as 53.Maximum Subarray
        int numsLen = nums.size();
        int currentSum = nums[0];
        int maxans = currentSum;
        int temp = 0;

        if(numsLen==1){
            return nums[0];
        }

        for(int i=0; i<numsLen; i++){
            temp = nums[i];
            maxans = max(maxans,temp);
            for(int j=i+1; j<numsLen; j++){
                temp = temp * nums[j];
                maxans = max(maxans,temp);
            }
        }
        return maxans;
    }
};*/