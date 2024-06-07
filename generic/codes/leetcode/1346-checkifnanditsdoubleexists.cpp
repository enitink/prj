class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> dset;
        for(auto& a : arr) {
            if (dset.find(a*2) != dset.end())
                return true;
            if ((!(a % 2)) && (dset.find(a/2) != dset.end()))
                return true;
            dset.insert(a);
        }
        return false;
    }
};