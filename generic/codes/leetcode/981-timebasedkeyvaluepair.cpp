#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _TimeValue {
    string value;
    int timestamp;
} TimeValue;

class TimeMap {
    map<string, vector<TimeValue> > timeMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (timeMap.find(key) == timeMap.end()) 
            timeMap[key] = vector<TimeValue>();

            timeMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<TimeValue>& values = timeMap[key];
        vector<TimeValue>::iterator it = upper_bound(values.begin(), values.end(), timestamp, [](int timestamp, TimeValue& tv) {
            return timestamp < tv.timestamp;
        });
        if (it == values.begin()) {
            return "";
        } else {
            return (--it)->value;
        }
    }
};

int main() {
    TimeMap* obj = new TimeMap();
    obj->set("foo", "bar", 1);
    cout << obj->get("foo", 1) << endl;
    cout << obj->get("foo", 3) << endl;
    obj->set("foo", "bar2", 4);
    cout << obj->get("foo", 4) << endl;
    cout << obj->get("foo", 5) << endl;
    return 0;
}