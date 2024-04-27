#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 用unorder_map存nums1+nums2數值的數量 <nums1+nums2的值,這個數值的數量>
        // 檢查此unorder_map的數值key和nums3+nums4的數值相加是否等於0
        // 等於0的話把此數量全部加起來就是nums1+nums2+nums3+nums4=0的數量
        unordered_map<int, int> umap;
        for(auto i : nums1){
            for(auto j : nums2){
                umap[i+j]+=1;
            }
        }
        int count = 0;
        for(auto i : nums3){
            for(auto j : nums4){
                if(umap.find(0-(i+j))!=umap.end()){
                    // 因為key要相同所以必須要給負號
                    // 找到四個相加會等於0的數值
                    count += umap[0-(i+j)];
                }
            }
        }return count;
    }
};

int main(){
    Solution solution;
    vector<int> n1 = {1,2};
    vector<int> n2 = {-2,-1};
    vector<int> n3 = {-1,2};
    vector<int> n4 = {0,2};
    int ans;
    ans = solution.fourSumCount(n1,n2,n3,n4);
    cout<<ans<<endl;
    return 0;
}