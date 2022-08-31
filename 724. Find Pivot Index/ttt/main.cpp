/*
724. Find Pivot Index
https://leetcode.com/problems/find-pivot-index/
*/

#include <iostream>
#include <vector>
#include <typeinfo>
#include <numeric>

using namespace std;

class Solution{
public:
    int pivotIndex(vector<int>& nums){
        int sum = 0;
        int left = 0;
        int right = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        right = sum;

        for(int pivot=0; pivot<nums.size(); pivot++){
            right = right - nums[pivot];
            if(left == right){
                return pivot;
            }
            left = left + nums[pivot];
        }
        return -1;
    }

    int pivotIndex_myTLE(vector<int>& nums){

        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        int range = nums.size();
        int index = nums.size();
        int pivot = 0;
        int sumleft = 0;
        int sumright = 0;

        while(pivot<range){
            sumleft = sumright = 0;
            for(int i=0; i<pivot; i++){
                sumleft = sumleft + nums[i];
            }


            for(int i=index-1; i>pivot; i--){
                sumright = sumright + nums[i];
            }

            if(sumleft == sumright){
                return pivot;
            }
            pivot++;
        }

        return -1;
    }
};

int main(){

    vector<int> data1 = {1,7,3,6,5,6};
    vector<int> data2 = {1,2,3};
    vector<int> data3 = {2,1,-1};
    int getans;

    Solution solution;
    getans = solution.pivotIndex(data1);
    cout<<getans<<endl;

    //getans = solution.pivotIndex(data2);
    //cout<<getans<<endl;

    //getans = solution.pivotIndex(data3);
    //cout<<getans<<endl;
    return 0;
}
