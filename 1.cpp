//StudybarCommentBegin
#include <stdio.h>
//函数LuckNumber用来判断一个数字x是否为幸运数字，如果是返回1，否则返回0.
int LuckyNumber(int x); 
//StudybarCommentEnd

int main()
{
	int n;
	int num[1000], total;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		if (LuckyNumber(i) == 1){
			sum += 1;
			num[total] = i;
			total += 1;
		}
	}
	if (sum != 0){
		for (int j = 0; j < total - 1; j++)
			printf("%d ", num[j]);
		printf("%d \n", num[total - 1]);
	}
	printf("Total：%d\n", sum);
	return 0;
}

int LuckyNumber(int x)
{
	int n = x;
	int y;
	if (x % 9 == 0)
		return 1;
	
	while (n != 0){
		y = n % 10;
		if (y == 9)
			return 1;
		n /= 10;
	}
	
	return 0;
}
