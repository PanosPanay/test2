#include <iostream>
#include <vector>
using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int len = heights.size();
    vector<vector<vector<bool>>> dp(len, vector<vector<bool>>(bricks + 1, vector<bool>(ladders + 1, true)));
    for(int i = 1; i < len; ++i)
    {
        for(int b = 0; b <= bricks; ++b)
        {
            for(int l = 0; l <= ladders; ++l)
            {
                if(heights[i] <= heights[i - 1])
                    dp[i][b][l] = dp[i - 1][b][l];
                else
                {
                    bool candidate1 = false;
                    bool candidate2 = false;
                    int heightDiff = heights[i] - heights[i - 1];
                    if(b - heightDiff >= 0)
                        candidate1 = dp[i - 1][b - heightDiff][l];
                    if(l - 1 >= 0)
                        candidate2 = dp[i - 1][b][l - 1];
                    dp[i][b][l] = candidate1 || candidate2;
                }
                cout << "dp[" << i << "][" << b << "][" << l << "] = " << dp[i][b][l] << endl;
            }
        }
        if(dp[i][bricks][ladders] == false)
            return i - 1;
    }
    return len - 1;
}

int main()
{
    vector<int> heights = {4,2,7,6,9,14,12};
    int bricks = 5;
    int ladders = 1;
    cout << furthestBuilding(heights, bricks, ladders) << endl;
    return 0;
}