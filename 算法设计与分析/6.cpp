#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
constexpr auto MAX = 200;
typedef int Grade;
typedef struct linknode
{
 int number;  //ѧ�� 
 char name[20];   //���� 	
 Grade chinese,math,english,physical,chemical,biological,total;//�������� ����Ӣ�ﻯ�� 
 struct linknode  *next;
}LinkList;

typedef struct linkgrade
{
 int number;  //ѧ�� 
 char name[20];   //���� 	
	//�������� ����Ӣ�ﻯ�� 
 Grade chinese,math,english,physical,chemical,biological,threetotal,total;
 int threetotalrank,totalrank;
}LinkGrade;


void ShowAllGrade(LinkList *head);
void ShowOneGrade(LinkList *head);
void InsertOneGrade(LinkList *head); 
void oneshow(LinkList *head);
void FindInNumber(LinkList *head,int number);
void FindInName(LinkList *head,char *name);
void Save(LinkList *head);
void twoshow(LinkList *head);
void UpdateGrade(LinkList *head,int UpdateNumber);
void DeleteGrade(LinkList *head,int DeleteNumber);
void SortGrade(LinkList *head,int sort);
void back(LinkList *head);

//��ʼ������ 
LinkList *InitList()
{
	LinkList *head;
	head = (LinkList*)malloc(sizeof(LinkList));
	head->next = NULL;
	return head; 
}

//ѡ�񷵻� 
void back(LinkList *head)
{   int ok;
	printf("\n                                      ��0�������˵���\n");
 
 for(int i=1;i<=100;i++)
 {
 
  	scanf("%d",&ok);
	if(ok==0)
    {
  		system("cls");
		oneshow(head); 
	}
	else
	{
		printf("                                      ����������ѡ��\n"); 
		
	}
  }
}

//��������DAO(��ѧ��)
void Insert(LinkList *head , int number ,char *name, Grade chinese, Grade math, Grade english, Grade physical, Grade chemical, Grade biological)
{
	LinkList *p,*s;
	p=head;
	while(p->next != NULL && p->next->number<number)
	{
		p=p->next;
	}
	if(p!=NULL)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->number=number;
        strcpy(s->name,name);
        s->chinese=chinese;
        s->math=math;
        s->english=english;
        s->physical=physical;
        s->chemical=chemical;
        s->biological=biological;
        s->next=p->next;
        p->next=s;
        printf("                                      ����ɹ���");
    }
    else
        printf("                                      ����ʧ�ܣ�");
    Save(head);
}

//��������Controller(��ѧ��)
void InsertOneGrade(LinkList *head)
{
	int ok;
	int number;  //ѧ�� 
    char name[20];   //���� 	
	//����Ӣ�ﻯ�� 
    Grade chinese,math,english,physical,chemical,biological;
	
    printf("                                      ������ѧ��������\n");
    scanf("%s",name);
   	printf("                                      ������ѧ��ѧ�ţ�\n");
	scanf("%d",&number);		
	printf("                                      ���������ĳɼ���\n");
	scanf("%d",&chinese); 
    if(chinese<0 || chinese>150)
    {
	printf("                                      �������������ĳɼ���0~150�֣���\n");
	scanf("%d",&chinese); 
    } 
	printf("                                      ��������ѧ�ɼ���\n");
	scanf("%d",&math); 
    if(math<0 || math>150)
    {
	printf("                                      ������������ѧ�ɼ���0~150�֣���\n");
	scanf("%d",&math); 
    } 
	printf("                                      ������Ӣ��ɼ���\n");
	scanf("%d",&english); 
    if(english<0 || english>150)
    {
	printf("                                      ����������Ӣ��ɼ���0~150�֣���\n");
	scanf("%d",&english); 
    } 
	printf("                                      ����������ɼ���\n");
	scanf("%d",&physical); 
    if(physical<0 || physical>100)
    {
	printf("                                      ��������������ɼ���0~100�֣���\n");
	scanf("%d",&physical); 
    } 
	printf("                                      �����뻯ѧ�ɼ���\n");
	scanf("%d",&chemical); 
    if(chemical<0 || chemical>100)
    {
	printf("                                      ���������뻯ѧ�ɼ���0~100�֣���\n");
	scanf("%d",&chemical); 
    } 
	printf("                                      ����������ɼ���\n");
	scanf("%d",&biological); 
    if(biological<0 || biological>100)
    {
	printf("                                      ��������������ɼ���0~100�֣���\n");
	scanf("%d",&biological); 
    } 
	Insert(head,number,name,chinese,math,english,physical,chemical,biological); 
    back(head);   
}

//�鿴����ѧ���ɼ�DAO (��ѧ��)
void FindInNumber(LinkList *head,int number)
{

	int ok;
	LinkList *p;
	p=head->next;
	while(p!=NULL && p->number!=number)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
 	    printf("\n-----------------------------------------------------------------------------------------------------");
	    printf("\n|      ѧ��     ����     ����     ��ѧ     Ӣ��     ����     ��ѧ     ����     С����     �ܷ�      |");
        printf("\n|      %-9d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |",p->number,p->name,p->chinese,p->math,p->english,p->physical,p->chemical,p->biological,p->chinese+p->math+p->english,p->chinese+p->math+p->english+p->physical+p->chemical+p->biological);
		printf("\n|---------------------------------------------------------------------------------------------------|\n");
	}
		else
	{
		printf("\n                                      Sorry���Ҳ�����ѧ��~\n"); 
		ShowOneGrade(head);
	}
    back(head);
} 

//�鿴����ѧ���ɼ�DAO(������)
void FindInName(LinkList *head, char *name)
{
	int ok;
    LinkList *p;
	p=head->next;
	while(p!=NULL && strcmp(p->name,name)!=0)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
		printf("\n-----------------------------------------------------------------------------------------------------");
	    printf("\n|      ѧ��     ����     ����     ��ѧ     Ӣ��     ����     ��ѧ     ����     С����     �ܷ�      |");
        printf("\n|      %-9d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |",p->number,p->name,p->chinese,p->math,p->english,p->physical,p->chemical,p->biological,p->chinese+p->math+p->english,p->chinese+p->math+p->english+p->physical+p->chemical+p->biological);
		printf("\n|---------------------------------------------------------------------------------------------------|\n");
	}
	else
	{
		printf("\n                                      Sorry���Ҳ�����ѧ��~\n"); 
		ShowOneGrade(head);
	}
   back(head);
}

//�鿴����ѧ���ɼ�Controller
void ShowOneGrade(LinkList *head)
{
	int choose;
	int number;
	char name[20];
	printf("                                      ��ѡ����ҷ�ʽ��\n");
	printf("                                      1����ѧ�Ų���\n");
	printf("                                      2������������\n"); 
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
	        printf("                                      ������ѧ�ţ�\n");
	        scanf("%d",&number);
	        system("cls");
			FindInNumber(head,number);
			break;
		case 2:
			printf("                                      ������������\n");
			scanf("%s",name); 
			system("cls");
			FindInName(head,name);
			break;
	}
	
} 
 
 
//�༭ѧ���ɼ�
void UpdateGrade(LinkList *head,int UpdateNumber)
{
    LinkList *p;
	p=head->next;
	while(p!=NULL && p->number!=UpdateNumber)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
	    printf("\n-----------------------------------------------------------------------------------------------------");
	    printf("\n|      ѧ��     ����     ����     ��ѧ     Ӣ��     ����     ��ѧ     ����     С����     �ܷ�      |");
        printf("\n|      %-9d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |",p->number,p->name,p->chinese,p->math,p->english,p->physical,p->chemical,p->biological,p->chinese+p->math+p->english,p->chinese+p->math+p->english+p->physical+p->chemical+p->biological);
		printf("\n|---------------------------------------------------------------------------------------------------|\n");
	    printf("\n                                      ��������º�ĸ��Ƴɼ���\n");
	    printf("                                      (�����ʽ�����ģ���ѧ��Ӣ�������ѧ������)\n");
	    scanf("%d,%d,%d,%d,%d,%d",&p->chinese,&p->math,&p->english,&p->physical,&p->chemical,&p->biological);
	    printf("                                      ���³ɹ���\n"); 
	    Save(head);
	    back(head);
	} 
	else
	{
		printf("                                      ����ʧ�ܣ��Ҳ�����ѧ����");
		back(head);
	 } 
} 

//ɾ��ѧ���ɼ�
void DeleteGrade(LinkList *head,int DeleteNumber)
{
	LinkList *p,*s;
	p=head;
	while(p->next!=NULL && p->next->number != DeleteNumber)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
		s=p->next;
		p->next=s->next;
		free(s);
		printf("                                      ɾ���ɹ���\n");
	    Save(head);
		back(head);
	
	}
     else
    {
          printf("                                      ɾ��ʧ��,�Ҳ�����ѧ����\n");
	      back(head);
    }
} 


//�ɼ�����
void SortGrade(LinkList *head,int sort)
{
	int ok;
	system("cls");
	LinkGrade aasort[MAX];
	LinkList *p;
	p=head->next;
    int i=1;
    int k,j;
	if(sort==1)
    {
    	while(p)
    	{
    		strcpy(aasort[i].name,p->name);
    		aasort[i].number=p->number;
    		aasort[i].chinese=p->chinese;
    		aasort[i].math=p->math;
    		aasort[i].english=p->english;
    		aasort[i].physical=p->physical;
    		aasort[i].chemical=p->chemical;
    		aasort[i].biological=p->biological;
    		aasort[i].threetotal=p->chinese+p->math+p->english;
    		aasort[i].total=p->chinese+p->math+p->english+p->physical+p->chemical+p->biological;
    		i++;
    		p=p->next;
		}
		for(k=2;k<i;k++)
		{
                strcpy(aasort[0].name,aasort[k].name);
				aasort[0].number=aasort[k].number;
				aasort[0].chinese=aasort[k].chinese;
				aasort[0].math=aasort[k].math;
				aasort[0].english=aasort[k].english;
				aasort[0].physical=aasort[k].physical;
				aasort[0].chemical=aasort[k].chemical;
				aasort[0].biological=aasort[k].biological;
				aasort[0].threetotal=aasort[k].threetotal;
				aasort[0].total=aasort[k].total;
			j=k-1;
			while(aasort[0].threetotal>aasort[j].threetotal)
			{
				strcpy(aasort[j+1].name,aasort[j].name);
				aasort[j+1].number=aasort[j].number;
				aasort[j+1].chinese=aasort[j].chinese;
				aasort[j+1].math=aasort[j].math;
				aasort[j+1].english=aasort[j].english;
				aasort[j+1].physical=aasort[j].physical;
				aasort[j+1].chemical=aasort[j].chemical;
				aasort[j+1].biological=aasort[j].biological;
				aasort[j+1].threetotal=aasort[j].threetotal;
				aasort[j+1].total=aasort[j].total;
				j=j-1;
			}
                strcpy(aasort[j+1].name,aasort[0].name);
				aasort[j+1].number=aasort[0].number;
				aasort[j+1].chinese=aasort[0].chinese;
				aasort[j+1].math=aasort[0].math;
				aasort[j+1].english=aasort[0].english;
				aasort[j+1].physical=aasort[0].physical;
				aasort[j+1].chemical=aasort[0].chemical;
				aasort[j+1].biological=aasort[0].biological;
				aasort[j+1].threetotal=aasort[0].threetotal;
				aasort[j+1].total=aasort[0].total;
			    aasort[k-1].threetotalrank=k-1;
				aasort[k].threetotalrank=k;
		}
		printf("\n\n\n                                      �Ѱ�С���Ƴɼ�������ϣ�\n");
     	printf("\n----------------------------------------------------------------------------------------------------------------");
	    printf("\n|     С��������   ѧ��     ����     ����     ��ѧ     Ӣ��    ����     ��ѧ     ����     С����     �ܷ�      |\n");
    	printf("\n----------------------------------------------------------------------------------------------------------------");
	    for(int t=1;t<i;t++)
	    {
	    	printf("\n|      %-12d%-8d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |\n",aasort[t].threetotalrank,aasort[t].number,aasort[t].name,aasort[t].chinese,aasort[t].math,aasort[t].english,aasort[t].physical,aasort[t].chemical,aasort[t].biological,aasort[t].threetotal,aasort[t].total);
		    printf("\n----------------------------------------------------------------------------------------------------------------");
		}
		back(head);
}
		
	else
	{
		while(p)
    	{
    		strcpy(aasort[i].name,p->name);
    		aasort[i].number=p->number;
    		aasort[i].chinese=p->chinese;
    		aasort[i].math=p->math;
    		aasort[i].english=p->english;
    		aasort[i].physical=p->physical;
    		aasort[i].chemical=p->chemical;
    		aasort[i].biological=p->biological;
    		aasort[i].threetotal=p->chinese+p->math+p->english;
    		aasort[i].total=p->chinese+p->math+p->english+p->physical+p->chemical+p->biological;
    		i++;
    		p=p->next;
		}
		for(k=2;k<i;k++)
		{
                strcpy(aasort[0].name,aasort[k].name);
				aasort[0].number=aasort[k].number;
				aasort[0].chinese=aasort[k].chinese;
				aasort[0].math=aasort[k].math;
				aasort[0].english=aasort[k].english;
				aasort[0].physical=aasort[k].physical;
				aasort[0].chemical=aasort[k].chemical;
				aasort[0].biological=aasort[k].biological;
				aasort[0].threetotal=aasort[k].threetotal;
				aasort[0].total=aasort[k].total;
			j=k-1;
			while(aasort[0].total>aasort[j].total)
			{
				strcpy(aasort[j+1].name,aasort[j].name);
				aasort[j+1].number=aasort[j].number;
				aasort[j+1].chinese=aasort[j].chinese;
				aasort[j+1].math=aasort[j].math;
				aasort[j+1].english=aasort[j].english;
				aasort[j+1].physical=aasort[j].physical;
				aasort[j+1].chemical=aasort[j].chemical;
				aasort[j+1].biological=aasort[j].biological;
				aasort[j+1].threetotal=aasort[j].threetotal;
				aasort[j+1].total=aasort[j].total;
				j=j-1;
			}
                strcpy(aasort[j+1].name,aasort[0].name);
				aasort[j+1].number=aasort[0].number;
				aasort[j+1].chinese=aasort[0].chinese;
				aasort[j+1].math=aasort[0].math;
				aasort[j+1].english=aasort[0].english;
				aasort[j+1].physical=aasort[0].physical;
				aasort[j+1].chemical=aasort[0].chemical;
				aasort[j+1].biological=aasort[0].biological;
				aasort[j+1].threetotal=aasort[0].threetotal;
				aasort[j+1].total=aasort[0].total;
			    aasort[k-1].totalrank=k-1;
				aasort[k].totalrank=k;
		}
		printf("\n\n\n                                      �Ѱ��ܳɼ�������ϣ�\n");
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	    printf("\n|     ������      ѧ��     ����     ����     ��ѧ     Ӣ��     ����     ��ѧ     ����     С����     �ܷ�      |\n");
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	    for(int t=1;t<i;t++)
	    {
	    	printf("\n|      %-12d%-8d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |\n",aasort[t].totalrank,aasort[t].number,aasort[t].name,aasort[t].chinese,aasort[t].math,aasort[t].english,aasort[t].physical,aasort[t].chemical,aasort[t].biological,aasort[t].threetotal,aasort[t].total);
		    printf("\n----------------------------------------------------------------------------------------------------------------");
		}
	 back(head);
	}
} 


//����ϼ�
void Category(LinkList *head)
{
	int i=1,j=1,k=1;
	LinkList *p;
	LinkGrade aasort[MAX],bbsort[MAX],ccsort[MAX];
	p=head->next;
	int a,b,c,d,e,f;
	printf("                                      ����������׼:\n");
	printf("                                      A�������䣺750��~~?��\n");
	scanf("%d",&a);
	printf("                                      C�������䣺?��~~0��\n");
	scanf("%d",&b);
	while(p)
	{
		if(p->chinese+p->math+p->english+p->physical+p->chemical+p->biological>a) 
		{
            strcpy(aasort[i].name,p->name);
    		aasort[i].number=p->number;
    		aasort[i].chinese=p->chinese;
    		aasort[i].math=p->math;
    		aasort[i].english=p->english;
    		aasort[i].physical=p->physical;
    		aasort[i].chemical=p->chemical;
    		aasort[i].biological=p->biological;
    		aasort[i].threetotal=p->chinese+p->math+p->english;
    		aasort[i].total=p->chinese+p->math+p->english+p->physical+p->chemical+p->biological;
    		i++;
		   p=p->next;
		}
		else if(p->chinese+p->math+p->english+p->physical+p->chemical+p->biological>b)
		{
			 strcpy(bbsort[j].name,p->name);
    		bbsort[j].number=p->number;
    		bbsort[j].chinese=p->chinese;
    		bbsort[j].math=p->math;
    		bbsort[j].english=p->english;
    		bbsort[j].physical=p->physical;
    		bbsort[j].chemical=p->chemical;
    		bbsort[j].biological=p->biological;
    		bbsort[j].threetotal=p->chinese+p->math+p->english;
    		bbsort[j].total=p->chinese+p->math+p->english+p->physical+p->chemical+p->biological;
    		j++;
		   p=p->next;
		}
		else
		{
			 strcpy(ccsort[k].name,p->name);
    		ccsort[k].number=p->number;
    		ccsort[k].chinese=p->chinese;
    		ccsort[k].math=p->math;
    		ccsort[k].english=p->english;
    		ccsort[k].physical=p->physical;
    		ccsort[k].chemical=p->chemical;
    		ccsort[k].biological=p->biological;
    		ccsort[k].threetotal=p->chinese+p->math+p->english;
    		ccsort[k].total=p->chinese+p->math+p->english+p->physical+p->chemical+p->biological;
    		k++;
		   p=p->next;
		}
		
	}
	    system("cls");
	    printf("\n\n\n                                      A����(750~%d)���£���ѧ������\n",a);
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	    printf("\n|      ѧ��     ����     ����     ��ѧ     Ӣ��     ����     ��ѧ     ����     С����     �ܷ�      |\n");
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	     for(int t=1;t<i;t++)
	    {
	    	printf("\n|      %-8d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |\n",aasort[t].number,aasort[t].name,aasort[t].chinese,aasort[t].math,aasort[t].english,aasort[t].physical,aasort[t].chemical,aasort[t].biological,aasort[t].threetotal,aasort[t].total);
		    printf("\n----------------------------------------------------------------------------------------------------------------");
		}
		printf("\n\n\n                                      B����(%d~%d)���£���ѧ������\n",a,b);
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	    printf("\n|      ѧ��     ����     ����     ��ѧ     Ӣ��     ����     ��ѧ     ����     С����     �ܷ�      |\n");
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	     for(int t=1;t<j;t++)
	    {
	    	printf("\n|      %-8d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |\n",bbsort[t].number,bbsort[t].name,bbsort[t].chinese,bbsort[t].math,bbsort[t].english,bbsort[t].physical,bbsort[t].chemical,bbsort[t].biological,bbsort[t].threetotal,bbsort[t].total);
		    printf("\n----------------------------------------------------------------------------------------------------------------");
		}
		printf("\n\n\n                                      C����(%d~0)���£���ѧ������\n",b);
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	    printf("\n|      ѧ��     ����     ����     ��ѧ     Ӣ��     ����     ��ѧ     ����     С����     �ܷ�      |\n");
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	     for(int t=1;t<k;t++)
	    {
	    	printf("\n|      %-8d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |\n",ccsort[t].number,ccsort[t].name,ccsort[t].chinese,ccsort[t].math,ccsort[t].english,ccsort[t].physical,ccsort[t].chemical,ccsort[t].biological,ccsort[t].threetotal,ccsort[t].total);
		    printf("\n----------------------------------------------------------------------------------------------------------------");
		}
		 back(head);
} 

 
//������ʼ��ҳ��
void oneshow(LinkList *head)  
{
	int Delete;
	printf("\n\n\n\n\n");
	printf("\n                                               ��ӭ����ѧ���ɼ�����ϵͳ           \n");
	printf("\n                                      ============================================");
	printf("\n                                      |             ��ѡ���ܱ��               |");
	printf("\n                                      |         1���鿴����ѧ���ɼ�              |");
    printf("\n                                      |         2�����ҵ���ѧ���ɼ�              |");
    printf("\n                                      |         3�����뵥��ѧ���ɼ�              |");
    printf("\n                                      |         4��ɾ������ѧ���ɼ�              |");
    printf("\n                                      |         5��     �˳�                     |");
    printf("\n                                      ============================================\n");
	int choose;
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			system("cls");
			ShowAllGrade(head);
			break;
		case 2:
			system("cls");
			ShowOneGrade(head);
			break;
		case 3:
			system("cls");
			InsertOneGrade(head);
            break;
        case 4:
        	system("cls");
        	printf("\n                                      ��ѡ����Ҫɾ����ѧ��ѧ�ţ�(��0����)\n");
			scanf("%d",&Delete);
			if(Delete==0)
			{ 
			  system("cls");
			  oneshow(head);
	        } 
		    DeleteGrade(head,Delete);
		    break;
		case 5:
		    exit(0); 
        default:
	        system("cls");
        	printf("����������ѡ��\n");
			oneshow(head); 
	}
}

//����ѡ��ҳ��2
void twoshow(LinkList *head)
{
	int choose,sort;
	int UpdateNumber,DeleteNumber;
	printf("                                      �ɶԵ�ǰ�ɼ������д���\n");
	printf("                                      ѡ���ܱ�ţ�\n");
	printf("                                      0������������\n");
	printf("                                      1���༭�ɼ�\n");
	printf("                                      2��ɾ��ѧ��\n");
	printf("                                      3���ɼ�����\n");
	printf("                                      4������ϼ�\n");
 
    scanf("%d",&choose);
    switch(choose)
    {
    	case 1:
    		printf("                                      ��ѡ��Ҫ�༭��ѧ��ѧ�ţ�\n");
			scanf("%d",&UpdateNumber);
			UpdateGrade(head,UpdateNumber);
			break;
	    case 2:
	    	printf("                                      ��ѡ��Ҫɾ����ѧ��ѧ�ţ�\n");
	    	scanf("%d",&DeleteNumber);
	    	DeleteGrade(head,DeleteNumber);
	    	break;
    	case 3:
    		printf("                                      ��ѡ������ʽ��\n");
    		printf("                                      1����С���Ƴɼ�����\n");
    		printf("                                      2�����ܳɼ�����\n");
    		scanf("%d",&sort);
    		SortGrade(head,sort);
    		break; 
   		case 0:
   			system("cls");
   			oneshow(head);
   			break;
	    case 4:
	    	system("cls");
	    	Category(head);
	    	break;
	}
    
} 

//�鿴����ѧ���ɼ�ҳ�� 
void ShowAllGrade(LinkList *head){
	int ok;
	LinkList *nn;
	nn=head->next;
    printf("\n\n                                      1������ǰ����\n");
    printf("                                      2���������˵�\n");
	printf("\n-----------------------------------------------------------------------------------------------------");
	printf("\n|      ѧ��     ����     ����     ��ѧ     Ӣ��     ����     ��ѧ     ����     С����     �ܷ�      |");
	printf("\n-----------------------------------------------------------------------------------------------------");
	while(nn!=NULL)
	{
		printf("\n|      %-9d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |",nn->number,nn->name,nn->chinese,nn->math,nn->english,nn->physical,nn->chemical,nn->biological,nn->chinese+nn->math+nn->english,nn->chinese+nn->math+nn->english+nn->physical+nn->chemical+nn->biological);
		printf("\n|---------------------------------------------------------------------------------------------------|\n");
		nn=nn->next;
    } 
    for(int i=1;i<=100;i++)
	{
	scanf("%d",&ok);
    if(ok==1)
       twoshow(head);
    else if(ok==2)
    {
    	system("cls");
    	oneshow(head);
	}
	else
	{
		printf("                                      ����������ѡ��\n");
	}
    }
    
}

//���ݴ���
void Save(LinkList *head){   
    FILE* fp;  
    LinkList *p;  
    int count=0;  
    fp=fopen("student.txt","wb");/*��ֻд��ʽ�򿪶������ļ�*/  
    p=head->next;  
    while(p)  
    {  
        if(fwrite(p,sizeof(LinkList),1,fp)==1)  
        {  
            p=p->next;  
            count++;  
        }  
        else break;  
    }  
    if(count>0)  
    {  
        printf("\n                                      ��ǰ����%d��ѧ����¼\n",count);  
         
    }  
    else  
        printf("                                      ���ļ�������ʧ��!!\n");  
    fclose(fp); //�رմ��ļ�  
}  


//������ 
int main()
{
	LinkList *r = InitList();
	LinkList *p,*head;
	head=r;
	FILE *fp; 
    fp=fopen("student.txt","ab+"); 
    while(!feof(fp))  
    {  
        p=(LinkList*)malloc(sizeof(LinkList));  
        if(fread(p,sizeof(LinkList),1,fp)==1) /*һ�δ��ļ��ж�ȡһ��ѧ���ɼ���¼*/  
        {  
            p->next=NULL;  
            r->next=p;  
            r=p;                            /*rָ�������һ��λ��*/  
        }  
    }  
    fclose(fp); /*�ر��ļ�*/  
	oneshow(head);
	return 0;
}



