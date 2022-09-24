#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int num = 0;
        int z = 0;

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<nums.size(); k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                    
                        ans[z][0] = i;
                        ans[z][1] = j;
                        ans[z][2] = k;
                        z++;
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