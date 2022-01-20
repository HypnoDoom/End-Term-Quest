#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <Windows.h>
#define DEAL 50	/*�������״���*/

int size = 0;
struct Date
{
	int da_year;  //��
	int da_mon;  //��
	int da_day;  //��
};
struct Time
{
	int ti_hour;   //Сʱ
	int ti_min;   //����
	int ti_sec;    //��
};
struct deal
{
	Date dt;						/*ÿ�ʽ��׵�����*/
	Time ti;						/*ÿ�ʽ��׵�ʱ��*/
	double earning;						/*ÿ�ʽ��׵�������*/
	double payout;						/*ÿ�ʽ��׵�֧�����*/
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
FINANCE person[DEAL] = { 0 };    //����û�ÿ�ʵĽ�����Ϣ

void getdate(Date *pd);//��ʵ�֣�������ʾ����ȡϵͳ���ڣ�����pd��ָ��Date�ṹ����
void gettime(Time *pt);// ��ʵ�֣�������ʾ����ȡϵͳʱ�䣬����pt��ָ��Time�ṹ����
void GetDateTime(FINANCE *per); //����getdate��gettime��������ȡ��ʱ�����ڴ���per��ָ�Ľṹ�������
void Menu() //��ʾϵͳ�˵�
{
	printf("1.Input one deal\n");
	printf("2.Print all the balance\n");
	printf("3.Printf one year balance\n");
	printf("4.Exit to dos\n");
	return;
}
char bioskey() //�����û�����Ĳ˵�����
{
	char ch;
	ch = getchar();
	return ch;
}
void InputOneDeal(FINANCE *per) //ִ�в˵�����1������һ�ʽ��ף�����ṹ��per��ָ�Ľṹ������С�
//ע�⵱����Ϊ������ʱ�����earning�У�����Ϊ������ʱ�����payout�С�
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
float Balance(FINANCE *per)  //�����˻������˻�person�����е�����������֧��֮�
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
void OneYearBalance(FINANCE *per, int year) //��ӡĳһ��Ľ�����Ϣͳ��
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
void PrintBalance(FINANCE *per) //ִ�в˵�����2����ӡ������ݵ����н�����Ϣ
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
void PrintOneYear(FINANCE *per)	//ִ�в˵�����3����ӡĳһ������н�����Ϣ��
//�������꽻����ϸ������OneYearBalance�����������ͳ��
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
		fflush(stdin);   //��ջ�����
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

//��ȡϵͳ���ڣ�����pd��ָ��Date�ṹ����
void getdate(Date *pd)
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	pd->da_day = st.wDay;
	pd->da_mon = st.wMonth;
	pd->da_year = st.wYear;
}
//��ȡϵͳʱ�䣬����pt��ָ��Time�ṹ����
void gettime(Time *pt)
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	pt->ti_hour = st.wHour;
	pt->ti_min = st.wMinute;
	pt->ti_sec = st.wSecond;

}