#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution{
    private:
        int ans = 0;
        int calution(int var){
            int temp1 = 0;

            while (var!=0)
            {
                // check overflow 
                // INT_MAX = +2147483647
                // INT_MIN = -2147483648
                if(abs(temp1) > 214748364){
                    temp1 = 0;
                    return temp1;
                }
                /*  example:
                    var = 1234, temp1 = 0
                    var = 123,  temp1 = 4
                    var = 12,   temp1 = 43
                    var = 1,    temp1 = 432
                    var = 0,    temp1 = 4321

                    temp1的新值 = temp1的舊值*10 + 原數var%10當各位數
                    更新var的值
                */
                temp1 = temp1 * 10 + var % 10;
                var = var / 10;
                cout<<"temp1= "<<temp1<<" x= "<<var<<endl;
            }
            return temp1;
        }
    public:

        int reverse(int x){
            ans = calution(x);
            return ans;
        }
};
int main(){
    Solution test1;
    cout<<test1.reverse(1234)<<endl;
    cout<<test1.reverse(-2147483412)<<endl;
    cout<<test1.reverse(1534236469)<<endl;

    system("pause");
    return 0;
}
