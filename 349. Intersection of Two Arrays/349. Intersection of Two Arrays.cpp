#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> hashTable(1000,0);
        vector<int> result;
        for(int i=0; i<nums1.size(); i++){
            hashTable[nums1[i]] = 1;
        }
        for(int i=0; i<nums2.size(); i++){
            if(hashTable[nums2[i]]){
                result.push_back(nums2[i]);
                hashTable[nums2[i]] = 0; // result
            }
        }return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> ans;
    ans = solution.intersection(nums1,nums2);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}