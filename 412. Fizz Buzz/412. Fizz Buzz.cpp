#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=0; i<n; i++){
            int n1 = i+1;

            if(n1%3==0 && n1%5==0){
                ans.push_back("FizzBuzz");
            }else if(n1%3==0 && n1%5!=0){
                ans.push_back("Fizz");
            }else if(n1%3!=0 && n1%5==0){
                ans.push_back("Buzz");
            }else{
                // n1%3!=0 && n1%5!=0
                ans.push_back(to_string(n1));
            }
        }
        return ans;
    }
};

int main(){
/* 
Input: n = 3
Output: ["1","2","Fizz"]
*/
    int n = 5;
    Solution solution;
    vector<string> getans;
    getans = solution.fizzBuzz(n);

    for(int i=0; i<getans.size(); i++){
        cout<<getans[i]<<" ";
    }cout<<endl;
    return 0;
}