#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int oven(vector<int>& times, int total_times) {

    int times_size = times.size();
    
    vector<vector<bool>> dp(times_size + 1, vector<bool>(total_times / 2 + 1, false));
    dp[0][0] = true;
    
    for (int i = 1; i <= times_size; i++) {
        for (int j = total_times / 2; j >= times[i - 1]; j--) {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - times[i - 1]];
        }
    }
    e
    for (int j = total_times / 2; j >= 0; j--) {
        if (dp[times_size][j]) {
            return total_times - 2 * j;
        }
    }
    return total_times;
}

int main() {
    int n_pizzas;
    while (cin >> n_pizzas) {
        vector<int> times(n_pizzas);
        int total_times = 0;
        for (int i = 0; i < n_pizzas; i++) {
            cin >> times[i];
            total_times += times[i];
        }
        sort(times.begin(), times.end());
        cout << oven(times,total_times) << endl;
    }
    return 0;
}
