/*
leetcode 1480. Running Sum of 1d Array
https://leetcode.com/problems/running-sum-of-1d-array/
*/

#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

class Solution {
private:
    vector<int> ans;
    int sum = 0;
    bool flag = false;
public:
    vector<int> runningSum(vector<int>& nums) {
        cout<<nums.size()<<endl;

        for(int i=0; i<nums.size(); i++){
            if(flag == true){
                flag = false;
                break;
            }

            for(int j=0; j<=j+1; j++){
                if(j==nums.size()){
                    flag = true;
                    break;
                }
                sum = sum + nums[j];
                ans.push_back(sum);
            }
        }
        return ans;
    }

};


int main(){
	Solution solution;
	vector<int> getans;
	vector<int> nums = {1,2,3,4};

	getans = solution.runningSum(nums);
	cout<<typeid(getans).name()<<endl;

	for(int i=0; i<getans.size(); i++){
        cout<<getans[i]<<" ";
	}
	cout<<endl;



	return 0;
}
