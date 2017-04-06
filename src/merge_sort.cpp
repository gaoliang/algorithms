//
// Created by gaoliang on 2017/4/6.
//

#include <iostream>
#include <SortableList.h>

void SortableList::MergeSort(int left, int right) {

    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
}

void SortableList::Merge(int left, int mid, int right) {
    int *temp = new int[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while ((i <= mid) && (j <= right))
        if (l[i] <= l[j]) temp[k++] = l[i++];
        else temp[k++] = l[j++];
    while (i <= mid) temp[k++] = l[i++];
    while (j <= right) temp[k++] = l[j++];
    for (i = 0, k = left; k <= right;) l[k++] = temp[i++];
}

void SortableList::MergeSort() {
    MergeSort(0, n - 1);
}

int main() {
    SortableList list(10);
    list.Input();
    std::cout << "before sort, the array is :" << std::endl;
    list.Output();
    list.MergeSort();
    std::cout << "after sort, the array is :" << std::endl;
    list.Output();
}