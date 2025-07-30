#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SparseTable {
public:
    int size, maxLog;
    vector<vector<int>> table;
    vector<int> logVal;

    SparseTable() {}
    SparseTable(const vector<int> &deltaArr) 
    {
        size = deltaArr.size();
        maxLog = 32 - __builtin_clz(size);
        table.assign(maxLog, vector<int>(size));
        logVal.assign(size + 1, 0);
        for (int i = 2; i <= size; ++i)
            logVal[i] = logVal[i >> 1] + 1;
        
        table[0] = deltaArr;
        for (int k = 1; k < maxLog; ++k) 
        {
            for (int i = 0; i + (1 << k) <= size; ++i) 
            {
                table[k][i] = max(
                    table[k - 1][i],
                    table[k - 1][i + (1 << (k - 1))]
                );
            }
        }
    }

    int getMax(int l, int r) const 
    {
        int k = logVal[r - l + 1];
        return max(
            table[k][l],
            table[k][r - (1 << k) + 1]
        );
    }
};

int main() 
{
    int numTests;
    cin >> numTests;
    while (numTests--) 
    {
        int strLen, parts;
        cin >> strLen >> parts;
        string binStr;
        cin >> binStr;
        vector<int> prefixZero(strLen + 1, 0), prefixOne(strLen + 1, 0);
        for (int i = 1; i <= strLen; ++i) 
        {
            prefixZero[i] = prefixZero[i - 1] + (binStr[i - 1] == '0');
            prefixOne[i]  = prefixOne[i - 1]  + (binStr[i - 1] == '1');
        }
        vector<int> deltaArr(strLen + 1);
        for (int t = 0; t <= strLen; ++t) 
        {
            deltaArr[t] = prefixZero[t] - prefixOne[t];
        }
        SparseTable rmq(deltaArr);
        auto computeLIS = [&](int left, int right) 
        {
            int onesMinusZeros = prefixOne[right] - prefixZero[left - 1];
            int bestDelta = rmq.getMax(left - 1, right);
            return onesMinusZeros + bestDelta;
        };

        auto canSplit = [&](int targetScore) 
        {
            int segmentCount = 0;
            int startIdx = 1;
            while (startIdx <= strLen && segmentCount < parts) 
            {
                int lo = startIdx, hi = strLen, pos = strLen + 1;
                while (lo <= hi) 
                {
                    int mid = (lo + hi) >> 1;
                    if (computeLIS(startIdx, mid) >= targetScore) 
                    {
                        pos = mid;
                        hi = mid - 1;
                    } 
                    else 
                    {
                        lo = mid + 1;
                    }
                }
                if (pos == strLen + 1) break;
                ++segmentCount;
                startIdx = pos + 1;
            }
            return segmentCount >= parts;
        };

        int left = 0, right = strLen, maxScore = 0;
        while (left <= right) 
        {
            int midScore = (left + right) >> 1;
            if (canSplit(midScore)) 
            {
                maxScore = midScore;
                left = midScore + 1;
            } 
            else 
            {
                right = midScore - 1;
            }
        }

        cout << maxScore << "\n";
    }
    return 0;
}
