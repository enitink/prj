#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef struct _FrequencyData {
    int frequency;
    int time;
}FrequencyData;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        char taskcount[26] = {0};
        for (auto task : tasks)
            taskcount[task - 'A']++;

        priority_queue<int> pq;
        queue<FrequencyData> empq;

        for (int i=0; i<26; ++i)
            if (taskcount[i] > 0)
                pq.push(taskcount[i]);

        int result = 0;
        while (!pq.empty() || !empq.empty()) {
            ++result;
            int fd = 0;
            if (!pq.empty()) {
                fd = pq.top() - 1;
                pq.pop();
                if (fd > 0){
                    empq.push({fd, result+n});
                }
            }
            if ((!empq.empty()) && (empq.front().time <= result)) {
                fd = empq.front().frequency;
                empq.pop();
                pq.push(fd);
            }
        }
        return result;
    }
};

int main()
{
    Solution sln;

    {
        vector<char> tasks = {'A','A','A','B','B','B'};
        cout << sln.leastInterval(tasks, 2) << endl;
    }
    {
        vector<char> tasks = {'A','C','A','B','D','B'};
        cout << sln.leastInterval(tasks, 1) << endl;
    }
    {
        vector<char> tasks = {'A','A','A','B','B','B'};
        cout << sln.leastInterval(tasks, 3) << endl;
    }
    {
        vector<char> tasks = {'A','A','A','B','B','B'};
        cout << sln.leastInterval(tasks, 0) << endl;
    }
    {
        vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
        cout << sln.leastInterval(tasks, 2) << endl;
    }
    {
        vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
        cout << sln.leastInterval(tasks, 0) << endl;
    }
    {
        vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
        cout << sln.leastInterval(tasks, 1) << endl;
    }
    return 0;
}