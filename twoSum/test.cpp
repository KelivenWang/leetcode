#include <iostream>
#include <map>

using namespace std;

int main(){
    // init null map that name is word_count
    map<string,int> word_count;
    // for key "aaa" to insert a new element and let value = 1
    // it will happen to do:
    // search key "aaa" in word_count, and didn't find it!!
    // a new key-value pair will be insert to word_count that it's key is "aaa", value will be value initialized 0
    word_count["aaa"] = 2;


    cout<<word_count["aaa"]<<endl;
    cout<<word_count["aaa"]++<<endl;
    cout<<word_count["aaa"]<<endl;
    return 0;
}