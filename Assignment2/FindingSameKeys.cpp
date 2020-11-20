//2019048095_±è¼ö¿¬_ITE2039
#include<iostream>
#include<algorithm>
#include<math.h>

int N, M;
int cnt;
int a[100001];
int b[100001];

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < M; i++) {
        std::cin >> b[i];
    }

    std::sort(a, a + N);
    std::sort(b, b + M);

    a[N] = b[M] = INFINITY;

    int i = 0;
    int j = 0;

    while (i < N || j < M) {
        if (a[i] < b[j]) {
            i++;
        }

        else if (a[i] > b[j]) {
            j++;
        }

        else if (a[i] == b[j]) {
            cnt++;
            i++;
            j++;
        }
    }

    std::cout << cnt;
}