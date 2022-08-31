// reference
// https://zxi.mytechroad.com/blog/stack/leetcode-20-valid-parentheses/
// https://clay-atlas.com/blog/2021/01/22/leetcode-cn-20-valid-parentheses-solution/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> temp_st;
        char symbol = ' ';
        
        for(char symbol: s){
            // use stack STL 
            // Using a stack to track the existing open parentheses
            // if the current one is a close parenthesis but does not match the top of the stackreturn false
            // otherwise pop the stack. Check whether the stack is empty in the end.
            // Time complexity: O(n)
            // Space complexity: O(n)

            if((symbol=='(') || (symbol=='{') || (symbol=='[')){
                temp_st.push(symbol);
            }
            else if(temp_st.empty()){
                return false;
            }
            else if((symbol!=')') && (temp_st.top()=='(')){
                return false;
            }
            else if ((symbol!='}') && (temp_st.top()=='{')){
                return false;
            }
            else if((symbol!=']') && (temp_st.top()=='[')){
                return false;
            }
            else{
                temp_st.pop();
            }
        }
        if(temp_st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    string s1 = "()[]{}";
    string s2 = "()";
    string s3 = "(]";
    Solution solution;
    
    cout<<solution.isValid(s1)<<endl;
    cout<<solution.isValid(s2)<<endl;
    cout<<solution.isValid(s3)<<endl;
    return 0;
}