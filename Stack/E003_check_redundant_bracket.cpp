/*
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkRedundant(string const &s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            char c = st.top();
            if (c == '(')
                return true;
            st.pop();
            if (st.top() == '(')
                return true;
            if (c == ')')
            {
                while (st.top() != '(')
                    st.pop();
                st.pop();
                if (st.top() == '(')
                    return true;
            }
        }
        st.push(s[i]);
    }

    return false;
}

int main()
{
    string s;
    getline(cin, s);

    cout << checkRedundant(s) << endl;

    return 0;
}