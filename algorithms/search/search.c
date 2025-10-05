#include "search.h"

int linear_search(int target, int* nums, int len) {
    for (int i = 0; i < len; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int binary_search(int target, int* nums, int len) {
    int l = 0;
    int r = len - 1;
    while (l < r) {
        int m = (l + r) / 2 + 1;
        if (nums[m] < target) {
            l = m;
        }
        else if (nums[m] > target) {
            r = m;
        }
        else {
            return nums[m];
        }
    }
    return -1;
}