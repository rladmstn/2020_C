#include <stdio.h>

int BSearch(int* arr, int len, int target)
{
	int first = 0; //탐색시작 인덱스
	int last = len - 1; // 탐색 마지막 인덱스
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;
		// mind 중앙인덱스
		if (target == arr[mid])
		{
			return mid;
			//찾은경우 인덱스 mid를 반환 (탐색완료)
		}
		else // 아니면 탐색대상 반으로 줄임
		{
			if (target > arr[mid])
			{
				first = mid + 1; // 타겟이 더 크면 first의 위치를 옮김
			}
			else
			{
				last = mid - 1; // 타겟이 더 작으면 last의 위치를 옮김
			}
		}

	}
	return -1; // 탐색실패 경우
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 }; // 인덱스
	int len = sizeof(arr) / sizeof(int);
	int index;

	index = BSearch(arr, len, 10); // 8을 찾아봄
	if (index == -1)
	{
		printf("탐색 실패\n");
	}
	else
	{
		printf("target의 인덱스 : %d\n", index);
	}
	return 0;
}
