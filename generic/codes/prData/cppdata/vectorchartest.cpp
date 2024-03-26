#include <iostream>
#include <vector>

#define SIZE 20

using namespace std;

void printVector(const vector<char>& vec)
{
    vector<char>::const_iterator iter = vec.begin();
    vector<char>::const_iterator eiter = vec.end();

    for ( ; iter != eiter; ++iter)
    {
        cout << *iter;
    }
}

void writeInBuffer(char* buff)
{
    for(int i = 0; i < SIZE; ++i)
        buff[i] = 'a' + i;
    buff[SIZE] = '\0';
}

int main()
{
    vector<char> charbuff;
    charbuff.resize(SIZE + 1);

    cout << "before : {";
    printVector(charbuff);
    cout <<  "}" << endl;
    writeInBuffer(&charbuff[0]);
    cout << "after : {";
    printVector(charbuff);
    cout <<  "}" << endl;

    return 0;
}