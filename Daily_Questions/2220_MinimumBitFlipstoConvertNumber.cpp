#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{
    int bits = start ^ goal;
    int count = 0;

    while (bits != 0)
    {
        int rmsb = bits & -bits;
        bits = bits - rmsb;
        count++;
    }

    return count;
}

int main()
{
    int start = 10;
    int goal = 7;
    int ans = minBitFlips(start, goal);

    cout << ans << "\n";
    return 0;
}