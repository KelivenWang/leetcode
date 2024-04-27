#include <iostream>  
#include <string>  
#include <vector>  
#include <set>  
#include <map>  
#include <unordered_map>  
using namespace std;  
int main()  
{  
    map<string, int>dict;  // <key,value>
    // 基本操作  
    // 1. Insert data  
    // 2. 判斷是否有資料  
    // 3. 查找  
    // 1. Insert data  
    dict.insert(pair<string, int>("cat", 2));  
    dict.insert(map<string, int>::value_type("banana", 3));  
    dict["apple"] = 10;  
    // 2. 判斷是否有資料  
    if (dict.empty())  
        cout << "dict is not empty" << endl;  
    else  
        cout << "dict size is : " << dict.size() << endl;  
    for (auto D : dict)  
    {  
        // 這邊Print的值(value)會按照字母順序(因為map是有序的)  因為按照 key 的大小去排列
        // 輸出順序為 :apple(10)->banana(3)->cat(2)  
        cout << D.first << "=>" << D.second << endl;  
    }  
    map<string, int>::iterator iter;  
    // 3. 查找, 返回一個迭代器指向鍵值為key的元素，如果沒找到就返回end()  因為 find 沒找到會回傳 map 的最後一個 key 的元素
    if ((iter = dict.find("banana")) != dict.end())   
    {  
        cout << "Find key[banana], value: " << iter->second;  
    }  
    else  
    {  
        cout << "Can't find the key[banana]" << endl;                    
    }  
    // unordered_map  
    /*  
        template < class Key,             // unordered_map::key_type  
        class T,                   // unordered_map::mapped_type  
        class Hash = hash<Key>,            // unordered_map::hasher  
        class Pred = equal_to<Key>,          // unordered_map::key_equal  
        class Alloc = allocator< pair<const Key,T> > // unordered_map::allocator_type  
        > class unordered_map;  
        Unordered Map  
        Unordered maps are associative containers that store elements   
        formed by the combination of a key value and a mapped value,   
        and which allows for fast retrieval of individual elements based on their keys.  
        In an unordered_map, the key value is generally used to uniquely identify the element,  
        while the mapped value is an object with the content associated to this key.  
        Types of key and mapped value may differ.  
        Internally, the elements in the unordered_map are not sorted in any particular   
        order with respect to either their key or mapped values, but organized into buckets  
        depending on their hash values to allow for fast access to individual  
        elements directly by their key values (with a constant average time complexity on average).  
        unordered_map containers are faster than map   
        containers to access individual elements by their key,   
        although they are generally less efficient for range iteration through  
        a subset of their elements.  
        Unordered maps implement the direct access operator   
        (operator[]) which allows for direct access of the mapped value   
        using its key value as argument.  
        Iterators in the container are at least forward iterators.  
    */  
    unordered_map<string, int>unordered_dict;  
    unordered_dict.insert(pair<string, int>("apple", 2));  
    unordered_dict.insert(unordered_map<string, int>::value_type("orange", 3));  
    unordered_dict["banana"] = 10;  
    if (unordered_dict.empty())  
    {  
        cout << "No elements" << endl;  
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    else  
    {  
        cout << "unorderd_dict size is : " << unordered_dict.size() << endl;   
    }  
    for (auto D : unordered_dict)  
    {  
        cout << D.first << "=>" << D.second << endl;  
    }  
    /*  
    *     output:  
    *               apple=>2  
    *               orange=>3  
    *               banana=>10  
    */  
}  