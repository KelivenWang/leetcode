// reference notice!!! 
// https://www.wongwonggoods.com/cplusplus/leetcode-cpp-88/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 從最後面開始檢查大小，大的放入nums1中
        int index1 = m-1, index2 = n-1, lastIndex = m+n-1;
        while(index1>=0 && index2>=0){
            if(nums1[index1]<nums2[index2]){
                nums1[lastIndex] = nums2[index2];
                index2--;
                lastIndex--;
            }else{
                nums1[lastIndex] = nums1[index1];
                index1--;
                lastIndex--;
            }
        }
        while(index2>=0){
            // 代表 nums2 內部還有數值沒有檢查到但是 nums1 已經檢查完了，所以直接把剩下的複製過去
            nums1[lastIndex] = nums2[index2];
            index2--;
            lastIndex--;
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

    vector<int> nums5 = {-50,-48,-47,-47,-46,-44,-43,-43,-41,-39,-38,-37,-37,-37,-33,-33,-32,-31,-29,-29,-27,-26,-26,-26,-25,-25,-24,-24,-23,-22,-22,-22,-18,-17,-17,-14,-14,-11,-11,-11,-6,-5,-5,-5,-5,-4,-1,0,2,2,2,2,5,6,7,7,9,10,13,13,14,14,18,21,21,21,22,24,24,24,25,26,26,29,29,29,30,30,31,31,32,33,34,34,34,35,38,40,41,42,43,44,44,46,46,47,47,48,49,49};
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
