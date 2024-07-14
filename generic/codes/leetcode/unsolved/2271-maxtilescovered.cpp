bool compare(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end(), compare);
        int max = 0;
        int i = 0;
        int len = tiles.size();
        for(; i<len-1; ++i) {
            int lmax = 0;
            while(1) {
                lmax += (tiles[i][1] - tiles[i][0] + 1);
                if (lma)
            }
        }
    }
};