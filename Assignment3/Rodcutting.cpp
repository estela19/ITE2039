#include<iostream>
#include<algorithm>
#include<vector>

int N;
int inp[100];
int dp[100];
int track[100];

int main() {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> inp[i];
    }

    dp[1] = inp[1];
    track[1] = 1;

    for (int i = 2; i <= N; i++) {
        int tmp = -1;
        for (int j = 1; j <= i/2; j++) {
            tmp = dp[j] + dp[i - j];
            if (tmp > dp[i]) {
                dp[i] = tmp;
                track[i] = j;
            }
        }
        if (dp[i] < inp[i]) {
            dp[i] = inp[i];
            track[i] = i;
        }
    }

    std::cout << dp[N] << "\n";

    int k = N;
    std::vector<int> v;
    while (k != 0) {
        v.push_back(track[k]);
        k -= track[k];
    }
    std::sort(v.begin(), v.end());

    int size = v.size();
    for (int i = 0; i < size; i++) {
        std::cout << v[i] << " ";
    }
}
