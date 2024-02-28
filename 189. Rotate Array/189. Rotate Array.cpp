#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int numsLen = nums.size();
        int steps = k % numsLen;
        int prept = 0, lastpt = numsLen - steps;
        vector<int> ans;

        for(int i=lastpt; i<numsLen; i++){
            ans.push_back(nums[i]);
        }

        for(int i=prept; i<lastpt; i++){
            ans.push_back(nums[i]);
        }

        nums = ans;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    solution.rotate(nums,k);
    cout<<endl;
    return 0;
}

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int numsLen = nums.size();
//         int steps = k % numsLen;

//         int tempNum = nums[numsLen-1];
//         for(int i=1; i<=steps; i++){
//             for(int j=numsLen-1; j>0; j--){
//                 nums[j] = nums[j-1];
//             }
//             nums[0] = tempNum;
//             tempNum = nums[numsLen-1];
//         }

//         for(int i=0; i<numsLen; i++){
//             cout<<nums[i]<<" ";
//         }cout<<endl;
//     }
// };