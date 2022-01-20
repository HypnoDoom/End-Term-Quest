#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//MAX为竞赛数量
#define  MAX 5
//STUNUM为每个竞赛可报名的学生数量
#define  STUNUM 20

typedef struct competition
{
    char    competitionName[30];          // 竞赛名称
    int     maxAge;                       // 报名学生年龄上限
    int     count;                        // 报名学生总人数
    char    *studentName[STUNUM];             // 各个报名学生的姓名，为指针数组
}Competition, *CompetitionPtr;

//创建1个竞赛，并将信息存储在参数pCom指向的数组中，参数comCount为当前创建的竞赛编号
void createCompetition(CompetitionPtr pCom, int comCount);

//学生报名
void studentRegistration(CompetitionPtr pCom, int comCount);

//查找竞赛是否存在。参数comNo为竞赛编号
int findCompetition(CompetitionPtr pCom, int comNo);

// 根据竞赛编号查阅某个竞赛信息
void competitionInfo(CompetitionPtr pCom);

//显示所有竞赛的竞赛编号和竞赛名称
void displayAll(CompetitionPtr pCom);

int main()
{
    Competition compet[MAX] = { {"",0,0,NULL} };

    int count = 0, op;
    while (1) {
        setbuf(stdin, NULL);//清空输入缓冲区
        printf("\n操作提示：1-创建竞赛；2-学生报名；3-查阅竞赛信息；0-退出系统\n");
        printf("请输入操作：");
        scanf("%d", &op);
        getchar();
        switch (op) {
        case 1:
            if (count < MAX)
            {
                createCompetition(compet, count); //每次创建1个竞赛
                count++;
            }
            else
                printf("竞赛数量已经超出上限，无法再新创建。\n");
            break;
        case 2:
            studentRegistration(compet, count);
            break;
        case 3:
            competitionInfo(compet);
            break;
        default:
            printf("系统退出\n");
            exit(0);
        }
    }
    return 0;
}

void createCompetition(CompetitionPtr pCom, int comCount)
{
	printf("请输入竞赛相关信息\n竞赛名称：");
	gets(pCom[comCount].competitionName);
	printf("报名限制的最大年龄：");
	scanf("%d", &pCom[comCount].maxAge);
	printf("\"%s\"竞赛创建成功\n", pCom[comCount].competitionName);
	return;
}
void studentRegistration(CompetitionPtr pCom, int comCount)
{
//	char ch[40];
	int count1, age;
	printf("现有竞赛信息如下：\n");
	displayAll(pCom);
	printf("\n请输入学生报名相关信息\n");
	printf("报名竞赛数组编号：");
	scanf("%d", &count1);
	getchar();
	if (count1 > comCount)
		printf("该竞赛不存在");
	else{ 
		printf("年龄：");
		scanf("%d", &age);
		//getchar();
		if(age > pCom[count1].maxAge)
			printf("报名参加%s失败，年龄不符合要求", pCom[count1].competitionName);
		else{
			printf("学生姓名：");
			gets(pCom[count1].studentName[pCom[count1].count]);
//			for (int i = 0; i < 40; i++){
//				*(pCom[count1].studentName[pCom[count1].count] + i) = ch[i];
//			}
			pCom[count1].count += 1;
			printf("%s报名参加竞赛\"%s\"成功\n",pCom[count1].studentName[pCom[count1].count] , pCom[count1].competitionName);
		}
	}
	return;
}

void displayAll(CompetitionPtr pCom)
{
	for(int i = 0; i < MAX; i++){
		if(pCom[i].maxAge != 0){
			printf("竞赛编号：%-6d竞赛名称：%s\n", i, pCom[i].competitionName);
		}
	}
	return;
}

void competitionInfo(CompetitionPtr pCom)
{
	int num;
	printf("现有竞赛信息如下：\n");
	displayAll(pCom);
	printf("\n请输入查阅竞赛相关信息\n请输入竞赛编号：");
	scanf("%d", &num);
	getchar();
	printf("竞赛名称为：%s\n限制的最大年龄：%d\n报名学生数量：%d\n报名学生姓名：",pCom[num].competitionName,
		pCom[num].maxAge, pCom[num].count);
	for (int i = 0; i < pCom[num].count; i++){
		printf("%s", pCom[num].studentName[i]);
	}
	printf("\n");
	return;
}
