#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void lr(struct student stu[],int n);  //成绩录入
void xs(struct student stu[],int n);  //成绩显示
void px(struct student stu[],int n);  //成绩排序
void tj(struct student stu[],int n);  //成绩统计
void tc(struct student stu[],int n);   //退出系统

struct student
{
    char num[11];
    char name[16];
    int banji;
    float score[4];
    float total;
    float aver;
}stu[11];

int main()
{
    int xz,n;
    printf("输入学生数：");
    scanf("%d",&n);
    while(1)
    {
        printf("***学生成绩管理系统***\n");
        printf("======================\n");
        printf("   1.学生成绩录入 \n");
        printf("   2.学生成绩显示 \n");
        printf("   3.学生成绩排序 \n");
        printf("   4.学生成绩统计 \n");
        printf("   0.结束程序     \n");
        printf("=======================\n");
        printf("choose 1,2,3,4,0:  \n");
        scanf("%d",&xz);
        switch(xz)
        {
            case 1: lr(stu,n); break;
            case 2: xs(stu,n); break;
            case 3: px(stu,n); break;
            case 4: tj(stu,n); break;
            case 0:            break;
            default: printf("enter data error!\n");
        }
         if(xz==0) break;
    }
    return 0;
}

//*1.学生成绩录入程序(xxlr.c)*//
void lr(struct student stu[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("输入班级 学号 姓名:\n");
        scanf("%d%s%s",&stu[i].banji,stu[i].num,stu[i].name);
        printf("\n数学成绩,语文成绩,C语言成绩,计算机实验成绩\n");
        scanf("%f%f%f%f",&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        stu[i].total=stu[i].score[0]+stu[i].score[1]+stu[i].score[2]+stu[i].score[3];
        stu[i].aver=stu[i].total/4;
    }
}

//*2.学生成绩显示程序(xxxs.c)*//
void xs(struct student stu[], int n)
 {
    int i;
    printf("\n学生信息:班级 学号 姓名 数学成绩 语文成绩 C语言成绩  计算机实验成绩  总成绩 平均成绩\n");
    for(i=0;i<n;i++)
      printf("\n%d,%s,%s,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f\n",stu[i].banji,stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].total,stu[i].aver);
      printf("\n");
 }

//*3.学生成绩排序程序(xxpx.c)*//
void px(struct student stu[], int n)
{
    int i,j;
    int m;
    struct student t;
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        if(m==stu[i].banji)
     {

      for(i=0;i<n-1;i++)    //第i个学生
     {
         for(j=i+1;j<n;j++)  //第i+1个学生
        if(stu[j].total>stu[i].total)
        {
             t=stu[j];
             stu[j]=stu[i];
             stu[i]=t;
        }
     }
     }
    }
      printf("the sorted numbers:\n");
       for(i=0;i<n;i++)
            {
                if(m==stu[i].banji)
                {

                 printf("\n 学生信息:班级 学号 姓名 数学成绩 语文成绩 C语言成绩  计算机实验成绩  总成绩 平均成绩\n");
                 printf("\n%d,%s,%s,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f\n",stu[i].banji,stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].total,stu[i].aver);
            }
            }
}
//*6.学生成绩统计程序(xxtj.c)*//
void tj(struct student stu[], int n)
{
	int i, j, k;
	int m,geshu = 0;
	float max, min, sum, aver_cour[4];
	scanf("%d", &m);
	for (j = 0; j<4; j++)
	{
		max = 0;
		k = 0;
		for (i = 0; i<n; i++)
			if (m == stu[i].banji)
			{
				if (stu[i].score[j] > max)
				{
					max = stu[i].score[j];
					k = i;
				}
			}
		printf("第%d门课程,\n成绩最高的学生的信息 班级%d 学号%s 姓名%s 数学%.1f 语文%.1f 英语%.1f 政治%.1f 总成绩%.1f 平均成绩%.1f\n", j + 1, m, stu[k].num, stu[k].name, stu[k].score[0], stu[k].score[1], stu[k].score[2], stu[k].score[3], stu[k].total, stu[k].aver);
	}
	for (j = 0; j<4; j++)
	{
		min = 200;
		k = 0;
		for (i = 0; i<n; i++)
			if (m == stu[i].banji)
			{
				if (stu[i].score[j] < min)
				{
					min = stu[i].score[j];
					k = i;
				}
			}
		printf("第%d门课程,\n成绩最低的学生的信息 班级%d 学号%s 姓名%s 数学%.1f 语文%.1f 英语%.1f 政治%.1f 总成绩%.1f 平均成绩%.1f\n", j + 1, m, stu[k].num, stu[k].name, stu[k].score[0], stu[k].score[1], stu[k].score[2], stu[k].score[3], stu[k].total, stu[k].aver);
	}
	for (j = 0; j<4; j++)
	{
		sum = 0,geshu = 0;
		for (i = 0; i<n; i++)
			if (m == stu[i].banji)
			{
				sum = sum + stu[i].score[j];
				geshu++;
			}
		aver_cour[j] = sum / geshu;
		printf("第%d门课,课程的平均成绩为%.1f\n", j + 1, aver_cour[j]);
	}
	for (j = 0; j<4; j++)
	{
		k = 0;       //k表示超过某门课平均成绩的人数
		for (i = 0; i<n; i++)
		if (m == stu[i].banji)
		{
			if (stu[i].score[j]>aver_cour[j])
				k++;
		}
		printf("第%d门课有%d个同学超过平均分\n", j + 1, k);
	}
}
