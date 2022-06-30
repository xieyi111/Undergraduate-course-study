#include<iostream>

using namespace std;

#define MAX 50

int table[MAX][MAX];

void fillTable(int x, int y, int step)
{
	if (step == 1)
		return;
	step /= 2;
	fillTable(x, y, step);    //��д���ϵı��
	fillTable(x + step, y, step);    //��д���µı��
	for (int i = 0; i < step; i++)
		for (int j = 0; j < step; j++) 
		{
			table[x + step + i][y + step + j] = table[x + i][y + j];  //���ϱ��������±�
			table[x + i][y + step + j] = table[x + step + i][y + j];  //���±��������ϱ�
		}
}

int main()
{
	int n;   //����

	cout << "�����������ѡ������:" << endl;
	cin >> n;

	for (int i = 1; i <= n; i++)//��ʼ����һ��
		table[i][1] = i;

	fillTable(1, 1, n);//�ݹ����б��

	//��ӡ
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++)
			cout << table[i][j] << "  ";
		cout << endl;
	}

	system("pause");
	return 0;
}