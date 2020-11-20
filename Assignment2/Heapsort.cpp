//2019048095_±è¼ö¿¬_ITE2039
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>

int N, K;

std::vector<int> v;

int main() {
    std::cin >> N >> K;

    v.reserve(N);

    for (int i = 0; i < N; i++) {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::make_heap(v.begin(), v.end());

    for (int i = 0; i < K; i++) {
        std::pop_heap(v.begin(), v.end());
        std::cout << v.back() << " ";
        v.pop_back();
    }

    std::cout << "\n";

    for (int i = 0; i < N - K; i++) {
        std::cout << v[i] << " ";
    }
}