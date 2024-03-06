#include <bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int left, int right)
{
    int shiftBits = 0;
    while (left != right)
    {
        left >>= 1;
        right >>= 1;
        ++shiftBits;
    }

    return left << shiftBits;
}

int main()
{
    int start = 1;
    int end = 2147483647;

    int ans = rangeBitwiseAnd(start, end);
    cout << ans << "\n";

    return 0;
}