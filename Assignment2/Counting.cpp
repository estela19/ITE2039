// 2019048095_±è¼ö¿¬_ITE2039
#include<iostream>
#include<algorithm>

int N, M, K;
int key[100001];
int query[100000][2];

int main() {
    std::cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        std::cin >> query[i][0] >> query[i][1];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> key[i];
    }

    std::sort(key, key + N);

    for (int i = 0; i < K; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (query[i][0] <= key[j] && key[j] <= query[i][1]) {
                cnt++;
            }
        }
        std::cout << cnt << "\n";
    }
}
