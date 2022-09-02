#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        // make two map table
        map<int,int> mp1;
        map<int,int> mp2;

        for(int i=0; i<nums1.size(); i++){
            // 用map建立各自的hash table
            auto item = mp1.find(nums1[i]);
            if(item==mp1.end()){
                // 第一次出現mp1設 1
                mp1[nums1[i]] = 1;
            }else{
                // 再次出現在mp1 則+1
                mp1[item->first] += 1;

            }
        }

        for(int i=0; i<nums2.size(); i++){
            auto iter = mp2.find(nums2[i]);
            if(iter==mp2.end()){
                mp2[nums2[i]] = 1;
            }else{
                mp2[iter->first] += 1;
            }
        }

        vector<int> ans;
        for(auto iter=mp1.begin(); iter!=mp1.end(); iter++){
            for(auto jter=mp2.begin(); jter!=mp2.end(); jter++){
                // 檢查兩個map table中有哪些 key 是相同的
                if(iter->first==jter->first && iter->second>0 && jter->second>0){
                    int min = 0;
                    if(iter->second<jter->second){
                        min = iter->second;
                    }else{
                        min = jter->second;
                    }
                    
                    for(int i=0; i<min; i++){
                        ans.push_back(iter->first);
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
 /* 
    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2,2]
 */

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    Solution solution;
    vector<int> getans;

    getans = solution.intersect(nums1,nums2);
    for(auto iter=getans.begin(); iter!=getans.end(); iter++){
        cout<<*iter<<" ";
    }cout<<endl;

    return 0;
}

/*
another best solution 
reference https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/82269/Short-Python-C%2B%2B

vector<int> intersect(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
    return a;
}

vector<int> intersect(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> ctr;
    for (int i : a)
        ctr[i]++;
    vector<int> out;
    for (int i : b)
        if (ctr[i]-- > 0)
            out.push_back(i);
    return out;
}
 */