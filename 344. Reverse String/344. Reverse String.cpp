#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        // need to include algorithm
        reverse(s.begin(),s.end());
        for(auto iter=s.begin(); iter!=s.end(); iter++){
            cout<<*iter<<" ";
        }cout<<endl;
    }
};

int main(){
    Solution solution;
    vector<char> s = {'h','e','l','l','o'};
    solution.reverseString(s);
    cout<<endl;
    return 0;
}

/**
 * @brief best solution
class Solution {
public:
    string reverseString(string s) {
        // 建立兩個指針
        int i = 0, j = s.size() - 1;

        while(i < j){
            如果指針i<j的話，就把兩個值給交換
            swap(s[i++], s[j--]); 
        }
        
        return s;
    }
};
 * 
 */