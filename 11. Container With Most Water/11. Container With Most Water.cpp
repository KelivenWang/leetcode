// https://leetcode.com/problems/container-with-most-water/
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size()-1;
        int area = 0;

        while(left<right){
            if(height[left]<height[right]){
                area = height[left] * abs(left-right);
                left++;
            }else{
                // height[right] <= height[left]
                area = height[right] * abs(left-right);
                right--;
            }

            if(area>maxArea){
                maxArea = area;
            }
        }
        return maxArea;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution solution;

    cout<<solution.maxArea(height)<<endl;
    system("pause");
    return 0;
}