#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    int find(int i) {
        if (path[i] == i) return i;
        path[i] = find(path[i]);
        return path[i];
    }
    void merge(int a, int b) {
        int root1 = find(a);
        int root2 = find(b);
        path[root1] = root2;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int count = 0;
        int length = source.size();
        path.resize(length);
        for (int i = 0; i < length; i++) {
            path[i] = i;
        }
        for (auto& set : allowedSwaps) {
            merge(set[0], set[1]);
        }
        unordered_map<int, map<int, int>> temp;
        for (int i = 0; i < length; i++) {
            int root = find(i);
            temp[root][source[i]]++;
        }
        for (int i = 0; i < length; i++) {
            int root = find(i);
            if (temp[root][target[i]] == 0) {
                count++;
            } else {
                temp[root][target[i]]--;
            }
        }
        return count;
    }
};