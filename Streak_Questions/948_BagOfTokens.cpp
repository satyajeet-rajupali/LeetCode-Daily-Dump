#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int> &tokens, int power)
{

    int i = 0;
    int j = tokens.size() - 1;
    int score = 0;
    int ans = 0;

    sort(tokens.begin(), tokens.end());

    while (i <= j && (power >= tokens[i] || score))
    {
        while (i <= j && power >= tokens[i])
        {
            power -= tokens[i];
            i++;
            score++;
        }

        ans = max(ans, score);

        if (i <= j && score)
        {
            power += tokens[j];
            j--;
            score--;
        }
    }

    return ans;
}

int main()
{
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;
    int ans = bagOfTokensScore(tokens, power);
    cout << ans << "\n";
    return 0;
}