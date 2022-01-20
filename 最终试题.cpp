#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <Windows.h>
#define DEAL 50	/*设计最大交易次数*/

int size = 0;
struct Date
{
	int da_year;  //年
	int da_mon;  //月
	int da_day;  //日
};
struct Time
{
	int ti_hour;   //小时
	int ti_min;   //分钟
	int ti_sec;    //秒
};
struct deal
{
	Date dt;						/*每笔交易的日期*/
	Time ti;						/*每笔交易的时间*/
	double earning;						/*每笔交易的收入额度*/
	double payout;						/*每笔交易的支出额度*/
};
struct memtime
{
	int y;
	int mon;
	int d;
	int h;
	int min;
	int s;
}mem[DEAL];
typedef struct deal FINANCE;
FINANCE person[DEAL] = { 0 };    //存放用户每笔的交易信息

void getdate(Date *pd);//已实现，如下所示。获取系统日期，存入pd所指的Date结构体中
void gettime(Time *pt);// 已实现，如下所示。获取系统时间，存入pt所指的Time结构体中
void GetDateTime(FINANCE *per); //调用getdate与gettime函数将获取的时间日期存入per所指的结构体变量中
void Menu() //显示系统菜单
{
	printf("1.Input one deal\n");
	printf("2.Print all the balance\n");
	printf("3.Printf one year balance\n");
	printf("4.Exit to dos\n");
	return;
}
char bioskey() //返回用户输入的菜单命令
{
	char ch;
	ch = getchar();
	return ch;
}
void InputOneDeal(FINANCE *per) //执行菜单命令1，输入一笔交易，存入结构体per所指的结构体变量中。
//注意当输入为整数的时候存入earning中，输入为负数的时候存入payout中。
{
	static int n = 0;
	Time pt;
	Date pd;
	getdate(&pd);
	gettime(&pt);
	mem[n].y = pd.da_year;
	mem[n].mon = pd.da_mon;
	mem[n].d = pd.da_day;
	mem[n].h = pt.ti_hour;
	mem[n].min = pt.ti_min;
	mem[n].s = pt.ti_sec;
	printf("Input one deal <+/->:\n");
	printf("%d/%d/%d  %d:%d:%d : ", pd.da_year, pd.da_mon, pd.da_day, pt.ti_hour,
		pt.ti_min, pt.ti_sec);
	static double num = 0;
	scanf("%lf", &num);
	if (num >= 0)
		person[n].earning = num;
	else
		person[n].payout = num;
	n += 1;
	size += 1;
	getchar();
	return;
}
float Balance(FINANCE *per)  //返回账户中余额。账户person数组中的所有收入与支出之差。
{
	float sum = 0;
	for (int i = 0; i < size; i++) {
		if (person[i].earning > 0)
			sum += person[i].earning;
		else
			sum += person[i].payout;
	}
	return sum;
}
void OneYearBalance(FINANCE *per, int year) //打印某一年的交易信息统计
{
	double total1 = 0, total2 = 0, total = 0;
	for (int i = 0; i < size; i++) {
		if (mem[i].y == year) {
			if (person[i].earning > 0) {
				total1 += person[i].earning;
				total += person[i].earning;
			}
			else {
				total2 += person[i].payout;
				total += person[i].payout;
			}
		}
	}
	printf("Param of %d\n", year);
	printf(" Sum of earning          Sum of payout              Balance\n");
	printf(" %14.2lf            %11.2lf      %15.2lf\n", total1, total2, total);
	return;
}
void PrintBalance(FINANCE *per) //执行菜单命令2，打印所有年份的所有交易信息
{
	printf("  Date       Time       Earning       Payout       Balance\n");
	printf("-----------------------------------------------------------\n");
	for (int i = 0; i < size; i++) {
		printf("%d/%d/%d  %d:%d:%d", mem[i].y, mem[i].mon, mem[i].d, mem[i].h,
			mem[i].min, mem[i].s);
		if (person[i].earning > 0)
			printf("%12.2lf\n", person[i].earning);
		else
			printf("%25.2lf\n", person[i].payout);
	}
	printf("-----------------------------------------------------------\n");
	printf("                                                    %.2f\n", Balance(person));
	return;
}
void PrintOneYear(FINANCE *per)	//执行菜单命令3，打印某一年的所有交易信息，
//包括该年交易明细及调用OneYearBalance函数输出交易统计
{
	int year1;
	printf("Please input one year: ");
	scanf("%d", &year1);
	printf("  Date       Time       Earning       Payout\n");
	printf("-------------------------------------------------\n");
	for (int i = 0; i < size; i++) {
		if (mem[i].y == year1) {
			printf("%d/%d/%d  %d:%d:%d", mem[i].y, mem[i].mon, mem[i].d, mem[i].h,
				mem[i].min, mem[i].s);
			if (person[i].earning > 0)
				printf("%12.2lf\n", person[i].earning);
			else
				printf("%25.2lf\n", person[i].payout);
		}
	}
	printf("-------------------------------------------------\n");
	getchar();
	OneYearBalance(person, year1);
	return;
}


int main()
{
	char key;
	int i;

	i = 0;

	while (1)
	{
		Menu();
		key = bioskey();
		fflush(stdin);   //清空缓冲区
		switch (key)
		{
		case '1':  InputOneDeal(person + i);
			i++;
			break;
		case '2':  PrintBalance(person);
			break;
		case '3':  PrintOneYear(person);
			break;
		case '4':  exit(0);
		default:  break;
		}
	}
}

//获取系统日期，存入pd所指的Date结构体中
void getdate(Date *pd)
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	pd->da_day = st.wDay;
	pd->da_mon = st.wMonth;
	pd->da_year = st.wYear;
}
//获取系统时间，存入pt所指的Time结构体中
void gettime(Time *pt)
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	pt->ti_hour = st.wHour;
	pt->ti_min = st.wMinute;
	pt->ti_sec = st.wSecond;

}