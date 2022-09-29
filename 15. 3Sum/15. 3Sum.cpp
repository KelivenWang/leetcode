#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp; // 暫存某個正確數組解
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<nums.size(); k++){

                    if(nums[i]+nums[j]+nums[k]==0){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        ans.push_back(temp);
                        temp.clear();
                    }
                }
            }
        }

        return ans;
    }
};

int main(){

    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution solution;
    vector<vector<int>> getans;

    getans = solution.threeSum(nums);
    for(int i=0; i<getans.size(); i++){
        for(int j=0; j<getans.size(); j++){
            cout<<getans[i][j]<<" ";
        }
    }cout<<endl;
    return 0;
}