#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

int N, e1, e2, x1, x2, sol;
int a1[101], a2[101], t1[101], t2[101];
int dp[3][101], track[3][101];
std::vector<std::pair<int, int> > v;

bool compare(const std::pair<int, int> a, const std::pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    std::cin >> N;
    std::cin >> e1 >> e2;
    std::cin >> x1 >> x2;
    for (int i = 1; i <= N; i++) {
        std::cin >> a1[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> a2[i];
    }
    for (int i = 1; i < N; i++) {
        std::cin >> t1[i];
    }
    for (int i = 1; i < N; i++) {
        std::cin >> t2[i];
    }

    dp[1][1] = e1 + a1[1];
    dp[2][1] = e2 + a2[1];
    for (int i = 1; i < N; i++) {
        int tmp1 = dp[2][i] + t2[i];
        if (dp[1][i] > tmp1) {
            dp[1][i + 1] = tmp1 + a1[i + 1];
            track[1][i + 1] = 2;
        }
        else {
            dp[1][i + 1] = dp[1][i] + a1[i + 1];
            track[1][i + 1] = 1;
        }

        int tmp2 = dp[1][i] + t1[i];
        if (dp[2][i] > tmp2) {
            dp[2][i + 1] = tmp2 + a2[i + 1];
            track[2][i + 1] = 1;
        }
        else {
            dp[2][i + 1] = dp[2][i] + a2[i + 1];
            track[2][i + 1] = 2;
        }
    }

    int k = N;
    int idx;
    if (dp[1][N] + x1 > dp[2][N] + x2) {
        sol = dp[2][N] + x2;
        idx = 2;
    }
    else {
        sol = dp[1][N] + x1;
        idx = 1;
    }

    while (k != 0) {
        v.push_back(std::make_pair(idx, k));
        idx = track[idx][k];
        k--;
    }

    std::sort(v.begin(), v.end(), compare);

    std::cout << sol << "\n";
    int size = v.size();
    for (int i = 0; i < size; i++) {
        std::cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}