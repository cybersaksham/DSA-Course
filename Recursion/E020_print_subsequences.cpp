// Print all subsequences of an string recursively

#include <bits/stdc++.h>
using namespace std;

void subsequences(string in, string out = "")
{
    if(in.size() == 0)
    {
        cout << out << endl;
        return;
    }
    subsequences(in.substr(1), out);
    subsequences(in.substr(1), out + in[0]);
}

int main()
{
    string s;
    cin >> s;

    subsequences(s);

    return 0;
}