//2019048095_±è¼ö¿¬_ITE2039
#include<iostream>
#include<algorithm>
#include<vector>

int out[30001];
std::vector<int> v;

int main() {
    int N;
    int tmp;
    bool flag = false;
    
    std::cin >> N;
    std::cin >> tmp;
    v.push_back(tmp);

    for (int i = 0; i < N - 1; i++) {
        flag = false;
        std::cin >> tmp;
        
        std::vector<int>::iterator it = v.begin();
        while (tmp < *it) {
            it++;
            if (it == v.end()) {
                v.push_back(tmp);
                flag = true;
                break;
            }
        }

        if (!flag) {
            v.insert(it, tmp);
        }

    }

    for (std::vector<int>::iterator i = v.begin(); i != v.end(); i++) {
        std::cout << *i << "\n";
    }


    return 0;
}