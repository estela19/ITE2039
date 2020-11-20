//2019048095_±è¼ö¿¬_ITE2039
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>

void sort_heap(std::vector<int>& v, int idx);
void swap(int* a, int* b);

std::vector<int> v;

int main() {
    v.reserve(100001);

    while (true) {
        int inp;
        scanf("%d", &inp);

        if (inp == 0) {
            printf("\n");
            int size = v.size();
            for (int i = 0; i < size; i++) {
                printf("%d ", v[i]);
            }
            break;
        }

        else if (inp == 1) {
            int num;
            scanf("%d", &num);
            v.push_back(num);
            std::push_heap(v.begin(), v.end());
        }

        else if (inp == 2) {
/*            
            std::pop_heap(v.begin(), v.end());
            printf("%d ", v.back());
            v.pop_back();
*/
///*
            printf("%d ", v.front());
            v[0] = v.back();
            v.pop_back();
            sort_heap(v, 0);
//*/
        }

        else if (inp == 3) {
            int num, idx;
            scanf("%d %d", &idx, &num);
            v[idx - 1] = num;
//            sort_heap(v, idx - 1);
            std::make_heap(v.begin(), v.end());
            int n = 1;
            /*
            v[idx - 1] = num;
            */
        }
    }

    return 0;
}

void sort_heap(std::vector<int>& v, int idx) {
    int pidx = (idx - 1) / 2;

    while (idx > 0) {
        if (v[pidx] < v[idx]) {
            swap(&v[pidx], &v[idx]);
            idx = pidx;
            pidx = (idx - 1) / 2;
        }
        else break;
    }

    int endidx = v.size();
    int lchild = (idx + 1) * 2 - 1;
    int rchild = (idx + 1) * 2;
    int maxidx;

    while (idx <= endidx - 1) {
        lchild = (idx + 1) * 2 - 1;
        rchild = (idx + 1) * 2;
        if (lchild >= endidx) {
            break;
        }

        else if (rchild >= endidx) {
            if (v[lchild] > v[idx]) {
                swap(&v[lchild], &v[idx]);
                idx = lchild;
            }
            else break;
        }
        else {
            if (v[lchild] > v[idx] && v[rchild] > v[idx]) {
                if (v[lchild] <= v[rchild]) {
                    swap(&v[rchild], &v[idx]);
                    idx = rchild;
                }
                else {
                    swap(&v[lchild], &v[idx]);
                    idx = lchild;
                }
            }
            else if (v[lchild] > v[idx]) {
                swap(&v[rchild], &v[idx]);
                idx = rchild;
            }
            else
                break;
        }
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}