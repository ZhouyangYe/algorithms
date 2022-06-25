#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        int length = intervals.size();

        if (length == 0) {
            result.push_back(newInterval);
            return result;
        }

        vector<int> mergedInterval(2, -1);

        if (newInterval[1] < intervals[0][0]) {
            result.push_back(newInterval);
            result.insert(result.end(), intervals.begin(), intervals.end());
            return result;
        }

        if (newInterval[0] > intervals[length - 1][1]) {
            result = intervals;
            result.push_back(newInterval);
            return result;
        }

        for (int i = 0; i < length; ++i) {
            vector<int>& temp = intervals[i];

            if (mergedInterval[0] == -1) {
                if (newInterval[0] >= temp[0] && newInterval[0] <= temp[1]) {
                    mergedInterval[0] = temp[0];
                }
                
                if (newInterval[0] < temp[0]) {
                    mergedInterval[0] = newInterval[0];
                }
            }

            if (mergedInterval[1] == -1) {
                if (newInterval[1] >= temp[0] && newInterval[1] <= temp[1]) {
                    mergedInterval[1] = temp[1];
                }
                
                if (newInterval[1] < temp[0]) {
                    mergedInterval[1] = newInterval[1];
                }
            }

            if (mergedInterval[0] == -1) {
                result.push_back(intervals[i]);
            }

            if (mergedInterval[0] != -1 && mergedInterval[1] != -1) {
                int offset = mergedInterval[1] < temp[0] ? i : i + 1;
                result.push_back(mergedInterval);
                if (offset >= length) break;
                result.insert(result.end(), intervals.begin() + offset, intervals.end());
                break;
            }
        }

        if (mergedInterval[1] == -1) {
            mergedInterval[1] = newInterval[1];
            result.push_back(mergedInterval);
        }

        return result;
    }
};
