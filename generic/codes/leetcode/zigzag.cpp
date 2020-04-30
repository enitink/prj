#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string sarray[numRows];
        int len = s.length(), i=0,j;
        for( ; i<len; )
        {
            j = 0;
            while(j<numRows && i< len)
            {
                sarray[j++].push_back(s[i++]);
            }
            j-=2;
            while(j>0  && i< len)
            {
                sarray[j--].push_back(s[i++]);
            }
        }
        string result;
        for(i=0;i<numRows;++i)
        {
            result += sarray[i];
        }
        return result;
    }
};

int main()
{
    Solution ob;
    string s("PAYPALISHIRING");
    cout << endl << ob.convert(s, 10);

    return 0;
}