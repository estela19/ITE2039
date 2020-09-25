//2019048095_±è¼ö¿¬_ITE2039
#include<iostream>
#include<algorithm>

int N;
int arr[100001];
int sol[100001];

void Sort(int start, int end);
void Merge(int start, int mid, int end);

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    Sort(0, N - 1);

    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << "\n";
    }

    return 0;
}


void Sort(int start, int end){
    if (start == end) {
        return;
    }

    int mid = (start + end) / 2;
    Sort(start, mid);
    Sort(mid + 1, end);
    Merge(start, mid, end);
}

void Merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;
    int flag = 0;

    while (k <= end) {
        if (flag == 1) {
            sol[k++] = arr[j++];
        }

        else if (flag == 2) {
            sol[k++] = arr[i++];
        }

        else {
            if (arr[i] > arr[j]) {
                sol[k++] = arr[i++];

                if (i > mid) {
                    flag = 1;
                }
            }

            else {
                sol[k++] = arr[j++];

                if (j > end) {
                    flag = 2;
                }
            }
        }
    }

    for (int l = start; l <= end; l++) {
        arr[l] = sol[l];
    }
    
}