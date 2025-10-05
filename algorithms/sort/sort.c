#include "sort.h"

// Static functions

static void swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

static int partition(int* nums, int left, int right, int pivot) {
    int i = left;
    int j = left;
    while (i < right) {
        if (nums[i] < pivot) {
            if (i > j) {
                swap(nums, i, j);
            }
            j++;
        }
        i++;
    }
    swap(nums, right, j);
    return j;
}

static void quick_sort_rec(int* nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = nums[right];
    int idx = partition(nums, left, right, pivot);
    quick_sort_rec(nums, left, idx - 1);
    quick_sort_rec(nums, idx + 1, right);
}

static void merge(int* nums, int* tmp_nums, int left, int mid, int right) {
    int idx_l = left;
    int idx_r = mid;
    while (idx_l < mid && idx_r < right) {
        
    }
}

static void merge_sort_rec(int* nums, int* tmp_nums, int left, int right) {
    if ((right - left) < 2) {
        return;
    }
    int mid = (left + right) / 2;
    merge_sort_rec(nums, tmp_nums, left, mid);
    merge_sort_rec(nums, tmp_nums, mid + 1, right);
    merge(nums, tmp_nums, left, mid, right);
}

// Public functions

void bubble_sort(int* nums, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums, j, j + 1);
            }
        }
    }
}

void insertion_sort(int* nums, int len) {
    for (int i = 1; i < len; i++) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void selection_sort(int* nums, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        swap(nums, i, min);
    }
}

void quick_sort(int* nums, int len) {
    quick_sort_rec(nums, 0, len - 1);
}

void merge_sort(int* nums, int len) {
    int tmp_nums[len];
    merge_sort_rec(nums, tmp_nums, 0, len - 1);
}