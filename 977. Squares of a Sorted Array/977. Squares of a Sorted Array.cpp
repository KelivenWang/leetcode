#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        int front = 0, end = nums.size() - 1, resultIndex = nums.size() - 1;

        for(;front<=end;){
            if((nums[front]*nums[front]) < (nums[end]*nums[end])){
                result[resultIndex] = nums[end]*nums[end];
                resultIndex--;
                end--;
            }else{
                result[resultIndex] = nums[front]*nums[front];
                resultIndex--;
                front++;
            }
        }return result;
    }
};