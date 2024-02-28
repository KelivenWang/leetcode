#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slowindex = 0, fastindex = 0;
        int minimal = INT32_MAX, sum = 0, subLen = 0;

        for(; fastindex<nums.size(); fastindex++){
            sum += nums[fastindex];
            while(sum>=target){
                subLen = fastindex - slowindex + 1;
                minimal = subLen<minimal ? subLen : minimal;
                sum -= nums[slowindex++];
            }
        }return minimal==INT32_MAX ? 0 : minimal;
    }
};