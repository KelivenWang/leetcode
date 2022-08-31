
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<vector<int> > groupThePeople(vector<int>& groupSizes) {

        vector<int> buffer_gropupSize;
        int x;
        for(int i=0; i<groupSizes.size(); i++){
            buffer_gropupSize[i] = groupSizes[i];
        }

        for(int i=0; i<buffer_gropupSize.size(); i++){
            for(int j=0; j<buffer_gropupSize.size(); j++){
             if(buffer_gropupSize[j]>buffer_gropupSize[i]){
                    x = buffer_gropupSize[i];
                    buffer_gropupSize[i] = buffer_gropupSize[j];
                    buffer_gropupSize[j] = x;
                }
            }
        }
        for(int i=0; i<buffer_gropupSize.size(); i++){
            cout<<buffer_gropupSize[i]<<endl;
        }
        system("pause");

    }
};

int main(){
    Solution ans;
    vector<vector<int> > getans;
    vector<vector<int> > pattern = {{3,3,3,3,3,1,3}};

    getans = ans.groupThePeople(pattern);

    //getans = ans;
    for(int i=0; i<getans.size(); i++){
        for(int j=0; j<getans.size(); j++){
            cout<<getans[i][j]<<" "<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    system("pause");

}
