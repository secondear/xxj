#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void lr(struct student stu[],int n);  //�ɼ�¼��
void xs(struct student stu[],int n);  //�ɼ���ʾ
void px(struct student stu[],int n);  //�ɼ�����
void tj(struct student stu[],int n);  //�ɼ�ͳ��
void tc(struct student stu[],int n);   //�˳�ϵͳ

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
    printf("����ѧ������");
    scanf("%d",&n);
    while(1)
    {
        printf("***ѧ���ɼ�����ϵͳ***\n");
        printf("======================\n");
        printf("   1.ѧ���ɼ�¼�� \n");
        printf("   2.ѧ���ɼ���ʾ \n");
        printf("   3.ѧ���ɼ����� \n");
        printf("   4.ѧ���ɼ�ͳ�� \n");
        printf("   0.��������     \n");
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

//*1.ѧ���ɼ�¼�����(xxlr.c)*//
void lr(struct student stu[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("����༶ ѧ�� ����:\n");
        scanf("%d%s%s",&stu[i].banji,stu[i].num,stu[i].name);
        printf("\n��ѧ�ɼ�,���ĳɼ�,C���Գɼ�,�����ʵ��ɼ�\n");
        scanf("%f%f%f%f",&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        stu[i].total=stu[i].score[0]+stu[i].score[1]+stu[i].score[2]+stu[i].score[3];
        stu[i].aver=stu[i].total/4;
    }
}

//*2.ѧ���ɼ���ʾ����(xxxs.c)*//
void xs(struct student stu[], int n)
 {
    int i;
    printf("\nѧ����Ϣ:�༶ ѧ�� ���� ��ѧ�ɼ� ���ĳɼ� C���Գɼ�  �����ʵ��ɼ�  �ܳɼ� ƽ���ɼ�\n");
    for(i=0;i<n;i++)
      printf("\n%d,%s,%s,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f\n",stu[i].banji,stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].total,stu[i].aver);
      printf("\n");
 }

//*3.ѧ���ɼ��������(xxpx.c)*//
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

      for(i=0;i<n-1;i++)    //��i��ѧ��
     {
         for(j=i+1;j<n;j++)  //��i+1��ѧ��
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

                 printf("\n ѧ����Ϣ:�༶ ѧ�� ���� ��ѧ�ɼ� ���ĳɼ� C���Գɼ�  �����ʵ��ɼ�  �ܳɼ� ƽ���ɼ�\n");
                 printf("\n%d,%s,%s,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f\n",stu[i].banji,stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].total,stu[i].aver);
            }
            }
}
//*6.ѧ���ɼ�ͳ�Ƴ���(xxtj.c)*//
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
		printf("��%d�ſγ�,\n�ɼ���ߵ�ѧ������Ϣ �༶%d ѧ��%s ����%s ��ѧ%.1f ����%.1f Ӣ��%.1f ����%.1f �ܳɼ�%.1f ƽ���ɼ�%.1f\n", j + 1, m, stu[k].num, stu[k].name, stu[k].score[0], stu[k].score[1], stu[k].score[2], stu[k].score[3], stu[k].total, stu[k].aver);
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
		printf("��%d�ſγ�,\n�ɼ���͵�ѧ������Ϣ �༶%d ѧ��%s ����%s ��ѧ%.1f ����%.1f Ӣ��%.1f ����%.1f �ܳɼ�%.1f ƽ���ɼ�%.1f\n", j + 1, m, stu[k].num, stu[k].name, stu[k].score[0], stu[k].score[1], stu[k].score[2], stu[k].score[3], stu[k].total, stu[k].aver);
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
		printf("��%d�ſ�,�γ̵�ƽ���ɼ�Ϊ%.1f\n", j + 1, aver_cour[j]);
	}
	for (j = 0; j<4; j++)
	{
		k = 0;       //k��ʾ����ĳ�ſ�ƽ���ɼ�������
		for (i = 0; i<n; i++)
		if (m == stu[i].banji)
		{
			if (stu[i].score[j]>aver_cour[j])
				k++;
		}
		printf("��%d�ſ���%d��ͬѧ����ƽ����\n", j + 1, k);
	}
}
