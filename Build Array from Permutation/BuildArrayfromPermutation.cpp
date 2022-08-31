#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        vector<int> ret;
        vector<int> buildArray(vector<int>& nums){
            // ans[i] = nums[nums[i]]
            for(int i=0; i<nums.size(); i++){
                ret.push_back(nums[nums[i]]);
            }
            return ret;
        }
};

int main(){
    Solution test1;
    vector<int> testArray({5,0,1,2,3,4});
    vector<int> ans;

    ans = test1.buildArray(testArray);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}