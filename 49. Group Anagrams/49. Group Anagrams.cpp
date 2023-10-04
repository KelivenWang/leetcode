#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strscopy = strs; // copy input string
        vector<vector<string>> strsort; // construct a two dim vector
        map<string,vector<string>> mapstr; // construct a map 
        int strsLength = strs.size();

        for(int i=0; i<strsLength; i++){
            sort(strscopy[i].begin(), strscopy[i].end()); // sort every letter for every strscopy elements
            mapstr[strscopy[i]].push_back(strs[i]); // put it in the map
        }

        for(auto iter=mapstr.begin(); iter!=mapstr.end(); iter++){
            strsort.push_back(iter->second);
        }

        return strsort;
    }

};

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution solution;
    vector<vector<string>> getans;

    getans = solution.groupAnagrams(strs);
    for(int i=0; i<getans.size(); i++){
        for(int j=0; j<getans[i].size(); j++){
            cout<<getans[i][j]<<" ";
        }cout<<endl;
    }
    system("pause");
    return 0;
}

/*
step1. 先建立一個 map key=原始字串, value=字串被排序後的string>
step2. 
*/