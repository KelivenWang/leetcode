#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:    
    int removeDuplicates(vector<int>& nums) {
        int total=1, sortedpt=0, currentpt=1;
        if(nums.size()==1){
            return total;
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[currentpt]==nums[sortedpt]){
                currentpt++;
            }else{
                sortedpt++;
                nums[sortedpt]=nums[currentpt];
                currentpt++;
                total++;
            }
        }
        return total;
    }
};

int main(){
    Solution solution;
    vector<int> numslist = {0,0,1,1,1,2,2,3,3,4};
    cout<<solution.removeDuplicates(numslist)<<endl;
    return 0;
}

// reference https://medium.com/@urdreamliu/26-%E5%9C%96%E8%A7%A3-remove-duplicates-from-sorted-array-cbee5b2d4df8