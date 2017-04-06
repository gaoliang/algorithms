//
// Created by gaoliang on 2017/4/6.
//

#ifndef ALGORITHMS_SORTABLELIST_H
#define ALGORITHMS_SORTABLELIST_H

#endif //ALGORITHMS_SORTABLELIST_H

#include <iostream>


class SortableList {
public:
    SortableList(int mSize) {
        maxSize = mSize;
        l = new int[maxSize + 1];
        n = 0;
    }

    ~SortableList() {
        delete[]l;
    }

    void Input() {
        std::cout << "input the number of the array" << std::endl;
        std::cin >> n;
        std::cout << "input your numbers, one number per line." << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> l[i];
        }
    }

    void Output() {
        for (int i = 0; i < n; i++) {
            std::cout << l[i] << ",";
        }
        std::cout << std::endl;
    }

    void MergeSort();

    void QuickSort();

    void AddSentinel() {
        l[n] = INF;
    }

private:
    int *l;
    int maxSize;
    int n;
    const int INF = 2147483647; //定义一个极大值∞

    void MergeSort(int left, int right);

    void Merge(int left, int mid, int right);

    void Swap(int i, int j);

    void QuickSort(int left, int right);

    int Partition(int left, int right);
};