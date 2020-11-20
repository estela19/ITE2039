#include<iostream>
#include<algorithm>

int m[101][101], s[101][101], p[101];
int N;

void print(int i, int j);

int main() {
    std::cin >> N;
    for (int i = 0; i <= N; i++) {
        std::cin >> p[i];
    }

    for (int i = 1; i <= N; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= N; l++) {
        for (int i = 1; i <= N - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = 200000000;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    std::cout << m[1][N] << "\n";
    print(1, N);
}

void print(int i, int j) {
    if (i == j) {
        std::cout << i << " ";
    }
    else {
        std::cout << "( ";
        print(i, s[i][j]);
        print(s[i][j] + 1, j);
        std::cout << ") ";
    }
}