/*
* Copyright (c) 2022,Qingdao University
* All rights reserved.
* anuthor: Sun Xinbin
* Completion date: 2022.4.23
*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>

using namespace std;
int count=0;

class Flight{
public:
	friend void Info_file();//�ļ�����
	friend void Info_self();//����д�� 
	friend void Search();//��ѯ����
	friend void Show();//չʾȫ����Ϣ
	void Print();//��ӡ
private:
	string number;
	string Departure_Station;
	string Terminus;
	string Flight_schedule;
	int Departure_time;
	int Arrival_time;
	string Model;
	int Price;
};

Flight flight[100];

void Flight::Print()
{
	cout << number <<" " << Departure_Station << " " << Terminus << " " << Flight_schedule<<" " 
		<< Departure_time <<" " << Arrival_time << " " << Model << " " << Price<<endl;
}

void Info_file()
{
	fstream f;
	f.open("FlightInformation.txt", ios::in);
	if (!f)
	{
		cout << "�ļ���ʧ��" << endl;
	}
	while (f >> flight[::count].number >> flight[::count].Departure_Station >> flight[::count].Terminus
		>> flight[::count].Flight_schedule >> flight[::count].Departure_time >> flight[::count].Arrival_time>>flight[::count].Model
		>> flight[::count].Price)
		::count++;

	f.close();
	cout << "�ļ�����ɹ���" << endl;
}

void Info_self()
{
	Flight new_info;

		cout<<"�����뺽����Ϣ���������,���վ,�յ�վ,������,���ʱ��,����ʱ��,����,Ʊ�ۣ�"<<endl;
		cin>>new_info.number >> new_info.Departure_Station >> new_info.Terminus
		>> new_info.Flight_schedule >> new_info.Departure_time >> new_info.Arrival_time>>new_info.Model
		>> new_info.Price;
		flight[::count].number = new_info.number;
		flight[::count].Departure_Station = new_info.Departure_Station;
		flight[::count].Terminus = new_info.Terminus;
		flight[::count].Flight_schedule = new_info.Flight_schedule;
		flight[::count].Departure_time = new_info.Departure_time;
		flight[::count].Arrival_time = new_info.Arrival_time;
		flight[::count].Model = new_info.Model;
		flight[::count].Price = new_info.Price;
		
		ofstream outfile;
        outfile.open("FlightInformation.txt", ios::app);
        outfile<<"\n"<<new_info.number<<" "<< new_info.Departure_Station<<" "<< new_info.Terminus
		<<" "<< new_info.Flight_schedule <<" "<< new_info.Departure_time<<" "<< new_info.Arrival_time<<" "<<new_info.Model
		<<" "<< new_info.Price;
		::count++; 
}
//MA0011 �ൺ ���� ����� 1900 2130 K30 1700 

void Search()
{
	cout << "�������ѯ��Ϣ����1.�����2.���վ3.�յ�վ4.���ʱ��5.����ʱ�䣩" << endl;
	int i = 0;
	int flag = 1;
	string no;
	string station;
	string station1;
	cin >> i;
	switch (i)
	{
	case 1:
		system("cls");
		cout << "������Ҫ��ѯ�ĺ���ţ�" << endl;
		cin >> no;
		for (int i = 0; i < ::count; i++)
		{
			if (no == flight[i].number)
			{
				flight[i].Print();
				flag = 0;
			}
		}
		break;
	case 2:
		system("cls");
		cout << "������Ҫ��ѯ�����վ��" << endl;
		cin >> station;
		for (int i = 0; i < ::count; i++)
		{
			if (station == flight[i].Departure_Station)
			{
				flight[i].Print();
				flag = 0;
			}
		}
		break;
	case 3:
		system("cls");
		cout << "������Ҫ��ѯ���յ�վ��" << endl;
		cin >> station1;
		for (int i = 0; i < ::count; i++)
		{
			if (station1 == flight[i].Terminus)
			{
				flight[i].Print();
				flag = 0;
			}
		}
		
		break;
	case 4:
		system("cls");
		cout << "������Ҫ��ѯ�����ʱ�䣺" << endl;
		int time;
		cin >> time;
		for (int i = 0; i < ::count; i++)
		{
			if (time == flight[i].Departure_time)
			{
				flight[i].Print();
				flag = 0;
			}
		}
		break;
	case 5:
		system("cls");
		cout << "������Ҫ��ѯ�ĵ���ʱ�䣺" << endl;
		int time1;
		cin >> time1;
		for (int i = 0; i < ::count; i++)
		{
			if (time1 == flight[i].Arrival_time)
			{
				flight[i].Print();
				flag = 0;
			}
		}
		break;
	}
	if (flag)
		cout << "δ�鵽��غ�����Ϣ" << endl;
}

void Show()
{
	for (int i = 0; i < ::count; i++)
	{
		cout << flight[i].number << " " << flight[i].Departure_Station << " " << flight[i].Terminus
			<< " " << flight[i].Flight_schedule << " " << flight[i].Departure_time << " " << flight[i].Arrival_time << " " << flight[i].Model
			<< " " << flight[i].Price << endl;;
	}
}

void menu()
{
	while (1)
	{
		cout << "    ������Ϣ��ѯϵͳ" << endl;
		cout << "     1.��Ӻ�����Ϣ" << endl;
		cout << "     2.�ļ����뺽����Ϣ" << endl;
		cout << "     3.��ѯ������Ϣ" << endl;
		cout << "     4.չʾȫ��������Ϣ" << endl;
		cout << "     5.�˳�ϵͳ" << endl;
		int i;
		cin >> i;
		switch (i)
		{
		case 1:
			system("cls");
			Info_self();
			break;
		case 2:
			system("cls");
			Info_file();
			break;
		case 3:
			system("cls");
			Search();
			break;
		case 4:
			system("cls");
			Show();
			break;
		case 5:
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
