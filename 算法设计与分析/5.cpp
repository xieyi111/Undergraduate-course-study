#include<iostream>
#include<cstdio>

using namespace std;
const int inf=0x3f3f3f3f;//Ԥ�����֮��ľ���Ϊ�����
string citys[10]= {"0","����","����","֣��","����","�ɶ�","����","�Ϻ�"};

void build(int e[][10],int n,int m)
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			e[i][j]=(i==j)?0:inf;
	cout << "�����������֮��ľ��룺" << endl;
	for(int i=1; i<=m; i++) 
	{
		int t1,t2,d;//λ��t1��λ��t2�ľ�����d
		cin>>t1>>t2>>d;
		e[t1][t2]=e[t2][t1]=d;//����ͼ
	}
}

void Floyd(int e[][10],int n)//��Դ���·,�������
{
	system("cls");
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				if(e[i][k]+e[k][j]<e[i][j])
					e[i][j]=e[i][k]+e[k][j];

	/**
	cout << "��������֮������·������:" << endl;
	for(int i=1; i<=n; i++)
		cout<<"\t"<<citys[i];
	cout<<endl;
	for(int i=1; i<=n; i++) 
	{
		cout<<citys[i];
		for(int j=1; j<=n; j++)
			printf("%8d",e[i][j]);
		cout<<endl;
	}
	**/

	cout << "��������֮������·��Ϊ:" << endl;
	for (int i = 1; i <= n; i++)
		for (int j = 6; j > i; j--)
		{
			cout << citys[i] << "->" << citys[j] << ": " << e[i][j] << endl;
		}
		

	system("pause");
}

void Dijkstra(int e[][10],int n)//̰��˼��
{
	int dis[10] = { 0 };//��ʼ����Դ�������dis,������1�Ŷ��㵽���������ĳ�ʼ·��
	int book[10] = { 0 }; //�����㵽�����������·  ��¼��ǰ����Ƿ��Ѿ��жϹ���
	for(int i=1; i<=n; i++)
		dis[i]=e[1][i];

	for(int i=2; i<=n; i++)
		book[i]=0;//δ֪���·����
	book[1]=1;

	//Dijkstra �㷨�������
	for(int i=1; i<=n-1; i++) 
	{
		int min=inf,t=0;
		for(int j=1; j<=n; j++)
			if(book[j]==0&&dis[j]<min) 
			{ //�ҳ�δ�жϽ���е�1�Ž�㣨��Դ���·��㣩������С���
				min=dis[j];
				t=j;
			}
		book[t]=1;//��ʱ��ѡ���ĸý����Ϊ���жϹ���
		for(int v=1; v<=n; v++) 
		{ //�ж�������������ǰѡ���Ľ�㣬�Ƿ�ʹ�õ�1�Ž��ľ�����
			if(e[t][v]<inf) 
			{
				if(dis[v]>dis[t]+e[t][v])
					dis[v]=dis[t]+e[t][v];//��¼������ǰѡ�����ʹ�õ�1�Ž�����·�����¾���
			}
		}
	}

	cout<<"������е�Դ���·��Ϊ:"<<endl;
	for(int i=2; i<=n; i++)
		cout<<citys[1]<<"->"<<citys[i]<<": "<<dis[i]<<endl;
}

void Inquiry(int e[][10],int n)
{
	int i;
	string t;
	cout<<"��������Ҫ��ѯ�ĳ�������";
	cin>>t;
	for(i=1; i<=n; i++) 
	{
		if(citys[i]==t)
			break;
	}
	if(i==n+1) 
	{
		cout<<endl<<"������в��ڽ�ͨ����ͼ��"<<endl;
		return ;
	}
	cout<<endl<<"�������"<<citys[i]<<"��Դ���·��Ϊ:"<<endl;
	for(int j=1; j<=n; j++) 
	{
		if(i==j) continue;
		cout<<citys[i]<<"->"<<citys[j]<<": "<<e[i][j]<<endl;
	}

}
void menu()
{
	int e[10][10];
	int n,m;//�������  �ߵĸ���
	cout << "��������и�����·��������" << endl;
	cin>>n>>m;
	build(e,n,m);
	Floyd(e,n);
	Dijkstra(e,n);
	while (1)
	{
		system("cls");
		Inquiry(e, n);
		system("pause");
	}
}

int main()
{
	menu();
	return 0;
}

/**
1 2 2553
1 3 692
1 4 704
2 3 511
3 4 349
2 5 812
3 6 1579
4 7 651
5 6 2368
6 7 1385
**/