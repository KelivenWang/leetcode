#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int j = 0;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]!=val){
        //         nums[j++] = nums[i];
        //     }
        // }
        // return j;
        int numsSize = nums.size();
        auto index = nums.begin(); //return first element of list
        for(int i=0; i<numsSize;){
            if(nums[i]==val){
                nums.erase(index+i);
                numsSize--;
            }else{
                i++;
            }
        }
        return numsSize;
    }
};

int main(){
    int remove = 2;
    vector<int> list = {4,2,2,3};
    Solution solution;
    cout<<solution.removeElement(list,remove)<<endl;

    return 0;
}