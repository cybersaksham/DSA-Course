/*
For a given a string expression containing brackets, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.

Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.

You need to return a boolean value indicating whether the expression is balanced or not.
Note:
The input expression will not contain spaces in between.

Input Format:
The first and the only line of input contains a string expression without any spaces in between.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<char> st;

    string s;
    getline(cin, s);

    int flag = 1;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            if (st.top() == '(')
                st.pop();
            else
            {
                flag = 0;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (st.top() == '[')
                st.pop();
            else
            {
                flag = 0;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (st.top() == '{')
                st.pop();
            else
            {
                flag = 0;
                break;
            }
        }
    }

    cout << (flag && st.empty()) << endl;

    return 0;
}