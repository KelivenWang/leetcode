#include <bits/stdc++.h>
using namespace std;

int main()
{
    //empty 2Dvector initialized
    vector<vector<int> > two_D_vector;

    //below is an empty 1D vector
    vector<int> one_D_vector(5, 2);

    //pushing back the above 1D vector to the 
    //empty 2D vector each time
    for (int i = 0; i < 5; i++) {
        two_D_vector.push_back(one_D_vector);
    }

    //printing the 2D vector
    cout << "printing the 2D vector\n";
    for (auto it : two_D_vector) {
        //it is now an 1D vector
        for (auto ij : it) {
            cout << ij << " ";
        }
        cout << endl;
    }

    return 0;
}