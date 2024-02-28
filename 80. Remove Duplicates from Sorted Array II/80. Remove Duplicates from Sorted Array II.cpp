#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        
        int p = 2;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]!=nums[p-2]){
                nums[p]=nums[i];
                p++;
            }
        }
        return p;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    Solution solution;
    cout<<solution.removeDuplicates(nums)<<endl;
    return 0;
}

// reference https://www.jb51.net/article/217631.htm