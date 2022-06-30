#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;
int count;

class Student
{
public:
	void Addstudent();
	void showscore();
	void Revise();
	int rnumber()
	{
		return number;
	}
	int rscore()
	{
		return total_score;
	}
	void rrank(int newrank)
	{
		rank = newrank;
	}
	void sum()
	{
		total_score = Chinese + Math + English + C_Language;
	}
	void show()
	{
		cout << number << setw(6) << name << setw(6) << Chinese << setw(7) << Math << setw(6) << English << setw(6) << C_Language << setw(6) << total_score << setw(7) << rank << endl;
	}
private:
	int number;
	string name;
	int Chinese;
	int Math; 
	int English;
	int C_Language;

	int total_score;
	int rank;
};

Student stu[100]; 

void Student::Revise()
{
	int subject;
	int new_score;
	cout << "������Ҫ�޸ĵĿ�Ŀ������µĳɼ�(1.���ģ�2.��ѧ��3.Ӣ�4.C����)��" << endl;
	cin >> subject;
	cin >> new_score;
	switch (subject)
	{
	case 1:
		Chinese = new_score; 
		break;
	case 2:
		Math = new_score;
		break;
	case 3:
		English = new_score;
		break;
	case 4:
		C_Language = new_score;
		break;
	}
}

void Student::Addstudent()
{
	int i =::count;
	cout << "������ѧ���ɼ���Ϣ��ѧ�� ���� ���� ��ѧ Ӣ�� C���Գɼ���" << endl;
	cin >> stu[i].number >> stu[i].name >> stu[i].Chinese >> stu[i].Math >> stu[i].English >> stu[i].C_Language;
	stu[i].sum();
	::count++;
}

void Student::showscore()
{
	cout << "������Ϣ���£�" << endl;
	cout << "ѧ�ţ�     " << number << endl;
	cout << "������     " << name << endl;
	cout << "���ĳɼ��� " << Chinese << endl;
	cout << "��ѧ�ɼ��� " << Math << endl;
	cout << "Ӣ��ɼ��� " << English << endl;
	cout << "C���Գɼ���" << C_Language << endl;
	cout << "�ܳɼ���   " << total_score << endl;
	cout << "������     " << rank << endl;
}

void BubbleSort()
{
	int left=0, right=::count-1, shift=1, i=0;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			if (stu[i].rscore() < stu[i + 1].rscore())
			{
				Student temp;
				temp = stu[i];
				stu[i] = stu[i + 1];
				stu[i + 1] = temp;
				shift = i;
			}
		}
		right = shift;
		for (i = right - 1; i >= left; i--)
		{
			if (stu[i].rscore() < stu[i + 1].rscore())
			{
				Student temp;
				temp = stu[i];
				stu[i] = stu[i + 1];
				stu[i + 1] = temp;
				shift = i + 1;
			}
		}
		left = shift;
	}
	for (i = 0; i < ::count; i++)
	{
		stu[i].rrank(i + 1);
	}
}

void QuickSort(int low,int high)
{
	if (low < high)
	{
		int i = low;
		int j = high;
		Student key = stu[i];
		while (i < j)
		{
			while (i < j && stu[j].rscore() <= key.rscore())
			{
				j--;
			}
			if (i < j)
			{
				stu[i] = stu[j];
			}
			while (i < j && stu[i].rscore() > key.rscore())
			{
				i++;
			}
			if (i < j)
			{
				stu[j] = stu[i];
			}
		}
		stu[i] = key;
		QuickSort(low, i-1);
		QuickSort(i+1, high);
	}
}

void group_sort(int ipos, int istep)
{
	Student itmp;
	int j;
	for (int i = ipos + istep; i < ::count; i++)
	{
		itmp = stu[i];
		for (j = i - istep; j >= 0; j -= istep)
		{
			if (stu[j].rscore() >= itmp.rscore())
			{
				break;
			}
			stu[j + istep] = stu[j];
		}
		stu[j + istep] = itmp;
	}
}
void ShellInsertSort()
{
	int istep = ::count / 2;
	while (istep > 0)
	{
		for (int i = 0; i < istep; i++)
		{
			group_sort(i, istep);
		}
		istep /= 2;
	}
	for (int i = 0; i < ::count; i++)
	{
		stu[i].rrank(i + 1);
	}
}

void Down(int i,int n)
{
	int child = 2 * i + 1;
	Student key = stu[i];
	while (child < n)
	{
		if (child + 1 < n && stu[child].rscore() > stu[child + 1].rscore())
		{
			child++;
		}
		if (key.rscore() > stu[child].rscore())
		{
			Student temp;
			temp = stu[i];
			stu[i] = stu[child];
			stu[child] = temp;
			i = child;
		}
		else
		{
			break;
		}
		child = child * 2 + 1;
	}
}

void BuildHeap()
{
	for (int i = ::count / 2 - 1; i >= 0; i--)
	{
		Down(i,::count);
	}
}

void HeapAdjust()
{
	BuildHeap();
	for (int i = ::count - 1; i > 0; i--)
	{
		Student temp;
		temp = stu[0];
		stu[0] = stu[i];
		stu[i] = temp;
		Down(0, i);
	}
	for (int i = 0; i < ::count; i++)
	{
		stu[i].rrank(i + 1);
	}
}

void menu()
{
	while (1)
	{
		cout << "   ***ѧ���ɼ�����ϵͳ***" << endl;
		cout << "      1.ѧ����Ϣ¼��  " << endl;
		cout << "      2.ѧ����Ϣ��ѯ  " << endl;
		cout << "      3.ѧ����Ϣ�޸�  " << endl;
		cout << "      4.ѧ���ɼ�����  " << endl;
		cout << "      5.ѧ���ɼ����  " << endl;
		cout << "      0.��������      " << endl;

		int i;
		cin >> i;
		switch (i)
		{
		case 1:
			system("cls"); stu[::count].Addstudent(); break;
		case 2:
			system("cls");
			cout << "������Ҫ��ѯѧ����ѧ�ţ�" << endl;
			int no;
			cin >> no;
			for (int i = 0; i < ::count; i++)
			{
				if (stu[i].rnumber() == no)
				{
					stu[i].showscore();
					break;
				}
			}
			break;
		case 3:
			system("cls");
			cout << "������Ҫ�޸�ѧ����ѧ�ţ�" << endl;
			no=0;
			cin >> no;
			for (int i = 0; i < ::count; i++)
			{
				if (stu[i].rnumber() == no)
				{
					stu[i].Revise();
					stu[i].sum();
					break;
				}
			}
			break;
		case 4:
			system("cls");
			cout << "��ѡ������ʽ��1.˫��ð������ 2.�������� 3.ϣ������ 4.������" << endl;
			cin >> i;
			switch (i)
			{
			case 1:
				BubbleSort();
				break;
			case 2:
				QuickSort(0, ::count - 1);
				for (i = 0; i < ::count; i++)
				{
					stu[i].rrank(i + 1);
				}
				break;
			case 3:
				ShellInsertSort();
				break;
			case 4:
				HeapAdjust();
				break;
			}
			break;
		case 5:
			system("cls");
			cout << "ѧ��   ����   ����  ��ѧ  Ӣ��  C���� �ܷ�  ����" << endl;
			for (int i = 0; i < ::count; i++)
			{
				stu[i].show();
			}
			break;
		case 0:
			cout << "ллʹ�ã���ӭ�´ι��� " << endl;
			system("pause");
			exit(0);

		default: cout << "�������" << endl;
			break;
		}
	}
}

int main()
{
	menu();

	return 0;
}
/*
2020201 ���±� 149 148 130 100
2020202 ��Ӿ�� 148 134 120 98
2020203 ���� 100 30 100 68
2020204 ������ 140 139 148 99
2020205 ������ 97 23 98 60
2020206 ��˼�� 101 36 110 71
2020207 �ܲ� 69 76 39 10
2020208 ���� 120 78 69 73
*/