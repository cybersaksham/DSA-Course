#include <iostream>
#include "Map.h"
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // Manual Implementation
    Map<int> map1;

    // Inserting
    for (int i = 0; i < 10; i++)
    {
        char s = '0' + i;
        string key = "abc";
        key += s;
        map1.insert(key, i + 1);
        cout << map1.getLoadFactor() << endl;
    }

    cout << map1.size() << endl;
    cout << map1.remove("abc2") << endl;
    cout << map1.remove("abc5") << endl;
    cout << map1.size() << endl;

    // Searching
    for (int i = 0; i < 10; i++)
    {
        char s = '0' + i;
        string key = "abc";
        key += s;
        cout << key << ": " << map1.getValue(key) << endl;
    }

    // Inbuilt Map
    map<int, int> map2;
    unordered_map<int, int> map3;

    pair<int, int> p(2, 3);
    map2.insert(p);
    map2[5] = 4;

    cout << map2.at(2) << " " << map2[5] << endl;
    cout << map2.count(5) << endl;
    map2.erase(5);
    // cout << map2.at(5) << endl;
    cout << map2[5] << endl;

    map2[10] = 12;
    map2[15] = 11;

    map<int, int>::iterator it;
    it = map2.begin();
    while (it != map2.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}