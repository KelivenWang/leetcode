#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // map(key,value)
        map<int,int> cont;
        int max = 0;
        int index = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(cont.find(nums[i])->second){
                cont[nums[i]] = cont[nums[i]] + 1;
            }else{
                cont[nums[i]] = 1;
            }
        }
        
        for(auto itor=cont.begin(); itor!=cont.end(); itor++){
            if(itor->second>max){
                max = itor->second;
                index = itor->first;
            }
        }
        return index;
    }
};

int main(){
    Solution solution;
    vector<int> num{-1,1,1,1,2,1};
    int getans;
    getans = solution.majorityElement(num);
    cout<<getans<<endl;
    return 0;
}