#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//MAXΪ��������
#define  MAX 5
//STUNUMΪÿ�������ɱ�����ѧ������
#define  STUNUM 20

typedef struct competition
{
    char    competitionName[30];          // ��������
    int     maxAge;                       // ����ѧ����������
    int     count;                        // ����ѧ��������
    char    *studentName[STUNUM];             // ��������ѧ����������Ϊָ������
}Competition, *CompetitionPtr;

//����1��������������Ϣ�洢�ڲ���pComָ��������У�����comCountΪ��ǰ�����ľ������
void createCompetition(CompetitionPtr pCom, int comCount);

//ѧ������
void studentRegistration(CompetitionPtr pCom, int comCount);

//���Ҿ����Ƿ���ڡ�����comNoΪ�������
int findCompetition(CompetitionPtr pCom, int comNo);

// ���ݾ�����Ų���ĳ��������Ϣ
void competitionInfo(CompetitionPtr pCom);

//��ʾ���о����ľ�����ź;�������
void displayAll(CompetitionPtr pCom);

int main()
{
    Competition compet[MAX] = { {"",0,0,NULL} };

    int count = 0, op;
    while (1) {
        setbuf(stdin, NULL);//������뻺����
        printf("\n������ʾ��1-����������2-ѧ��������3-���ľ�����Ϣ��0-�˳�ϵͳ\n");
        printf("�����������");
        scanf("%d", &op);
        getchar();
        switch (op) {
        case 1:
            if (count < MAX)
            {
                createCompetition(compet, count); //ÿ�δ���1������
                count++;
            }
            else
                printf("���������Ѿ��������ޣ��޷����´�����\n");
            break;
        case 2:
            studentRegistration(compet, count);
            break;
        case 3:
            competitionInfo(compet);
            break;
        default:
            printf("ϵͳ�˳�\n");
            exit(0);
        }
    }
    return 0;
}

void createCompetition(CompetitionPtr pCom, int comCount)
{
	printf("�����뾺�������Ϣ\n�������ƣ�");
	gets(pCom[comCount].competitionName);
	printf("�������Ƶ�������䣺");
	scanf("%d", &pCom[comCount].maxAge);
	printf("\"%s\"���������ɹ�\n", pCom[comCount].competitionName);
	return;
}
void studentRegistration(CompetitionPtr pCom, int comCount)
{
//	char ch[40];
	int count1, age;
	printf("���о�����Ϣ���£�\n");
	displayAll(pCom);
	printf("\n������ѧ�����������Ϣ\n");
	printf("�������������ţ�");
	scanf("%d", &count1);
	getchar();
	if (count1 > comCount)
		printf("�þ���������");
	else{ 
		printf("���䣺");
		scanf("%d", &age);
		//getchar();
		if(age > pCom[count1].maxAge)
			printf("�����μ�%sʧ�ܣ����䲻����Ҫ��", pCom[count1].competitionName);
		else{
			printf("ѧ��������");
			gets(pCom[count1].studentName[pCom[count1].count]);
//			for (int i = 0; i < 40; i++){
//				*(pCom[count1].studentName[pCom[count1].count] + i) = ch[i];
//			}
			pCom[count1].count += 1;
			printf("%s�����μӾ���\"%s\"�ɹ�\n",pCom[count1].studentName[pCom[count1].count] , pCom[count1].competitionName);
		}
	}
	return;
}

void displayAll(CompetitionPtr pCom)
{
	for(int i = 0; i < MAX; i++){
		if(pCom[i].maxAge != 0){
			printf("������ţ�%-6d�������ƣ�%s\n", i, pCom[i].competitionName);
		}
	}
	return;
}

void competitionInfo(CompetitionPtr pCom)
{
	int num;
	printf("���о�����Ϣ���£�\n");
	displayAll(pCom);
	printf("\n��������ľ��������Ϣ\n�����뾺����ţ�");
	scanf("%d", &num);
	getchar();
	printf("��������Ϊ��%s\n���Ƶ�������䣺%d\n����ѧ��������%d\n����ѧ��������",pCom[num].competitionName,
		pCom[num].maxAge, pCom[num].count);
	for (int i = 0; i < pCom[num].count; i++){
		printf("%s", pCom[num].studentName[i]);
	}
	printf("\n");
	return;
}
