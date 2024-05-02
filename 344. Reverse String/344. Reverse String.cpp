// reference https://iq.opengenus.org/reverse-vector-in-cpp-stl/#:~:text=C%2B%2B%20vectors%20support%20reverse%20iterators%20vector%3A%3Arbegin%20%28%29%20and,just%20in%20front%20of%20the%20first%20first%20element.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// class Solution {
// public:
//     void reverseString(vector<char>& s) {

//         // need to include algorithm
//         reverse(s.begin(),s.end());
//         for(auto iter=s.begin(); iter!=s.end(); iter++){
//             cout<<*iter<<" ";
//         }cout<<endl;
//     }
// };

class Solution{
public:
    void reverseString(vector<char>& s){
        int left = 0; int right = s.size()-1;
        for(int i=0; i<s.size()/2; i++){
            swap(s[left],s[right]);
            left++;
            right--;
        }
        for(auto i : s){
            cout<<i<<" ";
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