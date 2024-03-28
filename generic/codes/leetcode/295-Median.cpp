#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxheap.push(num);
        int cont = true;
        while(cont)
        {
            cont = false;
            if (((int)maxheap.size() - (int)minheap.size()) > 1)
            {
                //remove top from maxheap & put into min heap.
                int el = maxheap.top();
                maxheap.pop();
                minheap.push(el);
                cont = true;
            }
            else if (((int)minheap.size() - (int)maxheap.size()) > 1)
            {
                // remove top from min heap & put into max heap.
                int el = minheap.top();
                minheap.pop();
                maxheap.push(el);
                cont = true;
            }

            if ( !maxheap.empty() && !minheap.empty())
            {
                if (maxheap.top() > minheap.top())
                {
                    // remove top from max heap and move it to min heap.
                    int el = maxheap.top();
                    maxheap.pop();
                    minheap.push(el);
                    cont = true;
                }
            }
        }
    }
    
    double findMedian() {
        if (minheap.size() == maxheap.size())
        {    
            return (minheap.top() + maxheap.top()) / 2.0;
        }
        else if (minheap.size() > maxheap.size())
        {
            return minheap.top();
        }
        else
            return maxheap.top();
    }
private:
    priority_queue <int, vector<int>, greater<int> > minheap; 
    priority_queue <int> maxheap;
};

int main()
{
    MedianFinder mf;
    //["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
    //[[], [1], [2], [], [3], []]

    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum((3));
    cout << mf.findMedian() << endl;

    return 0;
}
