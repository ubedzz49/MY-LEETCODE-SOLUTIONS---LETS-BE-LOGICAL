#include <unordered_set>
#include <utility>
namespace std {
    template <>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
}
class Solution {
public:
    void dirch(char& c, int com) {
        if (c == 'n') {
            if (com == -1) {
                c = 'e';
            } else {
                c = 'w';
            }
            return;
        }
        if (c == 'w') {
            if (com == -1) {
                c = 'n';
            } else {
                c = 's';
            }
            return;
        }
        if (c == 's') {
            if (com == -1) {
                c = 'w';
            } else {
                c = 'e';
            }
            return;
        }
        if (c == 'e') {
            if (com == -1) {
                c = 's';
            } else {
                c = 'n';
            }
            return;
            ;
        }
    }

    void nxtstp(char c, int& i, int& j, bool& b, unordered_set<pair<int,int>>& mpp) {
        int m = i;
        int n = j;
        if (c == 'n') {
            j++;
        }
        if (c == 's') {
            j--;
        }
        if (c == 'w') {
            i--;
        }
        if (c == 'e') {
            i++;
        }
        if (mpp.find(make_pair(i,j))!=mpp.end()) {
            i = m;
            j = n;
            b = false;
            return;
        }
    }

    int robotSim(vector<int>& com, vector<vector<int>>& obs) {
        unordered_set < pair<int,int> > mpp;
        for (int i = 0; i < obs.size(); i++) {
            mpp.insert(make_pair(obs[i][0],obs[i][1]));
        }
        int i = 0;
        int j = 0;
        int ans = 0;
        char c = 'n';
        bool b = true;
        for (int k = 0; k < com.size(); k++) {
            if (com[k] == -1) {
                dirch(c, -1);
                b = true;
                continue;
            }
            if (com[k] == -2) {
                dirch(c, -2);
                b = true;
                continue;
            }
            for (int g = 0; g < com[k]; g++) {
                if (b == true) {
                    nxtstp(c, i, j, b, mpp);
                    if (i * i + j * j > ans) {
                        ans = i * i + j * j;
                    }
                }else{
                    continue;
                }
            }
        }
        return ans;
    }
};