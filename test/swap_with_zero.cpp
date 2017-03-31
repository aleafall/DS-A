//
// Created by aleafall on 17-3-3.
//


#include <iostream>

using namespace std;
/**
 * 交换数组里n和0的位置
 * array: 存储[0-n)的数组
 * len: 数组长度
 * n: 数组里要和0交换的数
 */
extern void swap_with_zero(int* array, int len, int n);

class Solution {
public:
	/**
	 * 调用方法swap_with_zero来对array进行排序
	 */
	void sort(int* array, int len) {
		if (!array || len <= 0) {
			return;
		}
		int *pos = new int[len];
		for (int i = 0; i < len; ++i) {
			pos[array[i]] = i;
		}
		int k = 0;
		while (array[0] || k == 0) {
			if (array[0] == 0) {
				for (k++; k < len; ++k) {
					if (array[k] != k) {
						pos[0] = k;
						pos[array[k]] = 0;
						swap(array[0], array[k]);
						break;
					}
				}
			}
			if (array[0]) {
				swap_with_zero(array, len, array[pos[0]]);
				swap(pos[0], pos[pos[0]]);
			}
		}
		delete[] pos;
	}
};