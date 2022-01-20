#include <stdio.h>
#include <string.h>
int calc(char a[], char b[], int *pos)
{
	int flag;
	int len1 = strlen(a);
	int len2 = strlen(b);
	char temp[40];
	for (int i = 0; i < len2 - len1 + 1; i++){
		strncpy(temp, b + i, len1);
		//puts(temp);
		//puts(a);
		temp[len1] = 0;
		int sum = 0;
		for (int j = 0; j < len1; j++){
			if (temp[j] == a[j]){
				sum += 1;
			}
			if (sum == len1){
				*pos = i + 1;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int n;
	char p1[40], p2[40];
	char a[40], b[40];
	gets(p1);
	gets(p2);
	if (strlen(p1) <= strlen(p2)){
		for(int i = 0; i < 40; i++){
			a[i] = p1[i];
			b[i] = p2[i];
		}
	}
	else{
		for(int i = 0; i < 40; i++){
			a[i] = p2[i];
			b[i] = p1[i];
		}
	}
	int pos = 0;
	//printf("%d,%d", strlen(a), strlen(b));
	//puts(a);
	//puts(b);
	n = calc(a, b, &pos);
	float rate = (float)strlen(a) / (float)strlen(b) * 100;
	if (n == 0 || rate < 60){
		printf("����A��B������\n");
	}
	else{
		if (strlen(p1) <= strlen(p2)){
			printf("B�е�%d��Ԫ������%lu��Ԫ����Aƥ�䣬��ƥ����%.2f%%������A��B����\n", pos,
				pos + strlen(a) - 1, rate);
		}
		else{
			printf("A�е�%d��Ԫ������%lu��Ԫ����Bƥ�䣬��ƥ����%.2f%%������A��B����\n", pos,
				pos + strlen(a) - 1, rate);
		}
	}
	return 0;
}
