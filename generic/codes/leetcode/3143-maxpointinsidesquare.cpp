// didn't solve

class Point {
public:
    Point(): x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    Point(Point& ob) : x(ob.x), y(ob.y) {}
    int x;
    int y;
};

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        map<char, Point> mymap;
        int len = s.length();
        int i = 0;
        int minside = INT_MAX;
        for(;i<len;++i){
            map<char, Point>::iterator itr = mymap.find(s[i]);
            if (itr != mymap.end()) {
                Point p(itr->second.x, itr->second.y);
                int pd = abs(p.x) > abs(p.y) ? abs(p.x) : abs(p.y);
                Point l(points[i][0], points[i][1]);
                int ld = abs(l.x) > abs(l.y) ? abs(l.x) : abs(l.y);
                //cout << ld << " : " << pd << endl;
                if (ld > pd) {
                    ld = pd;
                } else {
                    mymap[s[i]] = l;
                    ld = pd - 1;
                }
                if (minside > ld)
                    minside = ld;
            } else {
                Point l(points[i][0], points[i][1]);
                mymap[s[i]] = l;
            }
        }
        map<char, Point>::iterator itr = mymap.begin();
        map<char, Point>::iterator eitr = mymap.end();
        int result = 0;
        for (; itr != eitr; ++itr) {
            //cout << endl << itr->first << " : " << itr->second.x << "," << itr->second.y << " : " << minside;
            Point p(itr->second.x, itr->second.y);
            int pd = abs(p.x) > abs(p.y) ? abs(p.x) : abs(p.y);
            if (pd <= minside)
                ++result;
        }
        
        return result;
    }
};