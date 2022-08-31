#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int val = 0;
        map<int,int> mp;
        
        for(int i=0; i<nums.size(); i++){
            auto item = mp.find(nums[i]);
            if(item!=mp.end()){
                mp[nums[i]] = 2;
            }else{
                mp[nums[i]] = 1;
            }
        }
        
        for(auto i=mp.begin(); i!=mp.end(); i++){
            if(i->second==2){
                return true;
            }
        }
        return false;
    }
};

int main(){
    vector<int> nums = {1,5,-2,-4,0};
    Solution solution;
    cout<<solution.containsDuplicate(nums)<<endl;
    return 0;
}