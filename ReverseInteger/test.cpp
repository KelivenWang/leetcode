#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
        // handle overflow/underflow
            cout<<"x= "<<x<<endl;
            cout<<"abs(ret)= "<<abs(ret)<<endl;
            if (abs(ret) > 214748364) return 0;

            ret = ret * 10 + x % 10;
            x /= 10;

        }
        return ret;
    }
};

int main() {
    int ans = 0;
    int y =1;
    Solution test1;
    //cout<<test1.reverse(1534236469)<<endl;
    //cout<<test1.reverse(-2147483412)<<endl;
    cout<<test1.reverse(1234)<<endl;
    return 0;
}
//214748364
//1534236469
//-2147483412
