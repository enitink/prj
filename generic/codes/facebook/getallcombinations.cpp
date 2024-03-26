#include <iostream>
#include <list>
#include <string>

using namespace::std;

string allowed1 = "PAB";
string allowed2 = "BAP";

typedef struct _nextAllowedChar
{
    _nextAllowedChar() : nextPosition(-1) {}

    string flowstr;
    int nextPosition;
} nextAllowedChar;

void getAllCombinations(string s,
                     int st,
                      string ins,
                       list<string>& result,
                        int lastValidPosition,
                         nextAllowedChar nxtA,
                         int X,
                         int Y)
{
    if (s.size() == ins.size())
    {
        if ((lastValidPosition != -1) && (nxtA.nextPosition == 3))
        {
            result.push_back(ins);
        }
        return;
    }

    if (s[st] == '.')
    {
        getAllCombinations(s, st+1, ins + '.', result, lastValidPosition, nxtA, X, Y);
    }
    else
    {
        getAllCombinations(s, st+1, ins + '.', result, lastValidPosition, nxtA, X, Y);
        if (nxtA.nextPosition == -1)
        {
            if (s[st] == 'A')
                return;
            if (s[st] == 'P')
            {
                nxtA.flowstr = allowed1;
            }
            else
            {
                nxtA.flowstr = allowed2;
            }
            nxtA.nextPosition = 1;
        }
        else if (s[st] != nxtA.flowstr[nxtA.nextPosition])
        {
            return;
        }
        else
        {
            nxtA.nextPosition++;
        }
        if ((lastValidPosition != -1) && 
            (((st - lastValidPosition < X)) ||
            ((st - lastValidPosition) > Y)))
            return;

        getAllCombinations(s, st+1, ins + s[st], result, st, nxtA, X, Y);
    }
}

int main()
{
    list<string> result;
    nextAllowedChar nxtA;
    getAllCombinations(".PBAAP.B", 0, "", result, -1, nxtA, 1, 3);

    list<string>::iterator it = result.begin();
    list<string>::iterator eit = result.end();

    cout << endl;
    for( ; it != eit;  ++it)
    {
        cout << *it << endl;
    }

    return 0;
}