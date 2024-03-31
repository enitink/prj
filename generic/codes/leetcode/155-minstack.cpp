#include <iostream>
#include <stack>

using namespace std;

typedef struct _dataVal
{
    int val;
    int min;
}dataVal;

class MinStack {
    stack<dataVal> minstack;
public:
    MinStack() {
    }
    void push(int val) {
        if (minstack.empty())
        {
            dataVal d;
            d.min = d.val = val;
            minstack.push(d);
        }
        else
        {
            dataVal d = minstack.top();
            d.min = (d.min > val) ? val : d.min;
            d.val = val;
            minstack.push(d);
        }
    }
    void pop() {
        minstack.pop();
    }    
    int top() {
        return minstack.top().val;
    }
    int getMin() {
        return minstack.top().min;
    }
};

int main()
{
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << obj.getMin() << endl; // return -3
    obj.pop();
    cout << obj.top() << endl;    // return 0
    cout << obj.getMin() << endl; // return -2
    return 0;
}