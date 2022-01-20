#include<stdio.h> 
int num[1000];
int* input_n_int_Array(int n)
{
	getchar();
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	return num;
}

void find_two_largest(int p[], int n, int *large, int *second_large)
{
	int temp;
	for (int j = 0; j < n; j++){
		for (int i = 1; i < n; i++){
			if (p[i] >= p[i - 1]){
				temp = p[i];
				p[i] = p[i - 1];
				p[i - 1] = temp;
			}
		}
	}
	*large = p[0];
	*second_large = p[1];
}

void free(int p[])
{
	return;
}
//StudybarCommentBegin
int main(void)
{
    int *p = NULL;
    int n,i,large,second_large;
    scanf("%d",&n);
    p = input_n_int_Array(n);
    find_two_largest(p, n, &large, &second_large);
    free(p);

    printf("%d %d\n",large,second_large);
    return 0;
}
//StudybarCommentEnd
