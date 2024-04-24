#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> nums, int target){
    int left = 0;
    int right = nums.size() - 1 ;
    while(left<=right){
        int mid = (left+right) / 2 ;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            left = mid + 1;
        }else{
            // nums[mid]>target
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums1 = {1,2,3};
    for(int i=0; i<nums1.size(); i++){
        cout<<nums1[i]<<endl;
    }
    return 0;
}