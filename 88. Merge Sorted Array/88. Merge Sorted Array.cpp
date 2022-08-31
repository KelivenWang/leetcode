// reference notice!!! 
// https://www.wongwonggoods.com/cplusplus/leetcode-cpp-88/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 && n > 0){
            if(nums1[m-1] >= nums2[n-1]){
                nums1[m+n-1] = nums1[m-1];
                m -= 1;
            }
            else{
                nums1[m+n-1] = nums2[n-1];
                n -= 1;
            }
        }
        while(n > 0){
            nums1[m+n-1] = nums2[n-1];
            n -= 1;
        }

        for(int i=0; i<nums1.size(); i++){
            cout<<nums1[i]<<" ";
        }
    }       
};

int main(){
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    int m1 = 0;
    int n1 = 1;

    vector<int> nums3 = {1,2,3,0,0,0};
    vector<int> nums4 = {2,5,6};
    int m2 = 3;
    int n2 = 3;

    vector<int> nums5 = {1};
    vector<int> nums6 = {};
    int m3 = 1;
    int n3 = 0;

    Solution solution;

    solution.merge(nums1,m1,nums2,n1);
    cout<<endl;
    solution.merge(nums5,m3,nums6,n3);
    cout<<endl;
    solution.merge(nums3,m2,nums4,n2);
    return 0;
}
