#include <stdio.h>
#include <stdlib.h>
void reverse(int* nums, int left, int right) {
	while (left < right) {
		int tmp = nums[right];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	int tmp = K;
	int KNum = 0; 
	while (tmp) {
		KNum++;
		tmp /= 10;
	}
	int newArraySize = ASize > KNum ? ASize + 1 : KNum + 1;
	int* newArray = (int*)malloc(sizeof(int)*newArraySize);
	int i = 0;
	int idx = ASize - 1;
	int step = 0;
	while (idx >= 0 || K > 0) {
		//当前位的加法
		newArray[i] = step;
		if (idx >= 0) {
			newArray[i] += A[idx];
		}
		if (K > 0) {
			newArray[i] += K % 10;
		}
		//更新进位
		if (newArray[i] > 9) {
			newArray[i] = 10;
			step = 1;
		}
		else {
			step = 0;
		}
		//继续下一位的加法运算
		idx--;
		K /= 10;
		i++;
	}
	//判断最高位是否有进位
	if (step == 1) {
		newArray[i++] = 1;
	}
		reverse(newArray, 0, idx - 1);
		*returnSize = i;
		return newArray;
}

int main() {
	int A[] = { 1,2,3,4 };
	int k = 23;
	int returnSize[4] = { 0 };
	int ret = addToArrayForm(A, 4, 23,returnSize);
	for (int i = 0; i < 4; i++) {
		printf("%d", returnSize[i]);
	}
	system("pause");
	return 0; 
}