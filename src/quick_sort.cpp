//
// Created by gaoliang on 2017/4/6.
//

#include <iostream>
#include <SortableList.h>
#include <sys/time.h>


int SortableList::Partition(int left, int right) {
    int i = left, j = right + 1;
    do {
        do i++; while (l[i] < l[left]);
        do j--; while (l[j] > l[left]);
        if (i < j) Swap(i, j);
    } while (i < j);
    Swap(left, j);
    return j;
}

void SortableList::QuickSort() {
    QuickSort(0, n);
}

void SortableList::QuickSort(int left, int right) {
    if (left < right) {
        int j = Partition(left, right);
        QuickSort(left, j - 1);
        QuickSort(j + 1, right);
    }
}

void SortableList::Swap(int i, int j) {
    int c = l[i];
    l[i] = l[j];
    l[j] = c;
}


int main() {
    struct timeval start, end;
    
    SortableList list(10);
    list.Input();
    std::cout << "before sort, the array is :" << std::endl;
    list.Output();
    list.AddSentinel();
    gettimeofday(&start, NULL);
    list.QuickSort();
    gettimeofday(&end, NULL);
    int timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("time: %d us\n", timeuse);
    std::cout << "after sort, the array is :" << std::endl;
    list.Output();
}