#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>//�����ļ���д
#include <cstdlib>
using namespace std;
 
const int MAXN=10000;
const int p=23;
const string NULLKEY="NULLKEY";//����չؼ���ֵ
const string DELKEY="DELKEY";//���屻ɾ�ؼ���ֵ
string x[MAXN];//����ʱ�ĺ����
int hashlen=0;//��ϣ����
ifstream infile("read.txt",ios::in);
 
typedef struct
{
    string departure;//���վ
    string terminal;//�յ�վ
    string schedule;//����
    string start;//���ʱ��
    string arrival;//����ʱ��
    string type;//����
    double price;//Ʊ��
} Info;//˵����Ϣ����
 
typedef struct
{
    string number;//�����
    Info data;//˵����Ϣ
    int cnt;//̽�����
} Hash;//��ϣ������
Hash ha[MAXN];//����һ����ϣ��
 
int Work();//����ѡ���
int GetNum(string k);//ȡ��������е���ֵ����
int Search(string key);//�ڹ�ϣ���в��Һ����
int Delete(string str);//ɾ��ָ���ĺ�����Ϣ
void Insert1(string key);//�Զ����뺽����Ϣ
void Insert2(string key);//�ֶ����뺽����Ϣ
void Create1();//�ļ��Զ���ȡ
void Create2();//�����ֶ�����
void Number(string key);//��ѯ�����
void Departure(string key);//��ѯ���վ
void Terminal(string key);//��ѯ����վ
void Start(string key);//��ѯ���ʱ��
void Arrival(string key);//��ѯ����ʱ��
void FileOutput(int adr);//������Ϣ�����ļ�
void Output(int adr);//������Ϣ����Ļ����ʾ
void Input(int adr);//�ֶ����뺽����Ϣ
 
/*
*�������ƣ�Work
*����������������Ϣ��ѯ�ͼ���ϵͳ��ѡ���ܲ˵�
*�����������
*�����������
*����ֵ����
*����˵������
*/
int Work()
{
    while(1)
    {
        cout<<endl;//����ʽ
        cout<<"\t"<<"\t"<<"\t"<<"*********��ӭʹ�ú�����Ϣ��ѯ�ͼ���ϵͳ*********"<<endl;
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"�ٶ�������"<<"\t"<<"��ɾ������"<<"\n";
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"�ۺ����"<<"\t"<<"�����վ"<<"\n";
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"�ݵ���վ"<<"\t"<<"�����ʱ��"<<"\n";
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"�ߵ���ʱ��"<<"\t"<<"���˳�ϵͳ"<<"\n";
        cout<<"\t"<<"\t"<<"\t"<<"************************************************"<<endl;
        cout<<endl;
        cout<<"��ѡ��Ҫʹ�õĹ���(���):";
        int t;//���
        string temp;//�����
        cin>>t;
        switch (t)
        {
        case 1://�ٶ�������
        {
            cout<<"��ѡ���ȡ��ʽ(1:�Զ���ȡ/2:�ֶ�¼��):";
            int choose;//ѡ���ȡ��ʽ
            cin>>choose;
            if(choose==1)
                Create1();//1:�Զ���ȡ
            else if(choose==2)
                Create2();//2:�ֶ�¼��
            else
                cout<<"��Ŵ������֤���������룡"<<endl;
            cout<<"��Ϣ¼��ɹ���"<<endl;
            break;
        }
        case 2://��ɾ������
        {
            cout<<"������Ҫɾ���ĺ���ż���������Ϣ:";
            string str;
            cin>>str;
            Delete(str);
            cout<<"ɾ���ɹ���"<<endl;
            break;
        }
        case 3://�ۺ����
        {
            cout<<"�����뺽���:";
            cin>>temp;
            Number(temp);
            break;
            break;
        }
        case 4://�����վ
        {
            cout<<"���������վ:";
            cin>>temp;
            Departure(temp);
            break;
        }
        case 5://�ݵ���վ
        {
            cout<<"�������յ�վ:";
            cin>>temp;
            Terminal(temp);
            break;
        }
        case 6://�����ʱ��
        {
            cout<<"���������ʱ��:";
            cin>>temp;
            Start(temp);
            break;
        }
        case 7://�ߵ���ʱ��
        {
            cout<<"�����뵽��ʱ��:";
            cin>>temp;
            Arrival(temp);
            break;
        }
        case 8://���˳�ϵͳ
        {
            cout<<"���������������ϣ�����ļ��鿴�����"<<endl;
            return 0;
            break;
        }
        default://�������Ų���1~8֮��ķ�Χ��
        {
            cout<<"��Ŵ������֤���������룡"<<endl;
            break;
        }
        }
    }
    return 0;
}
 
/*
*�������ƣ�GetNum
*����������ȡ������ŵ���ֵ����
*���������k-�����
*�����������
*����ֵ��getnum-���غ�����
*����˵������
*/
int GetNum(string k)
{
    int getnum=0,temp=1000;
    getnum=(int(k[0])*10000000+int(k[1])*100000);
    for(int i=2; k[i]!='\0'; ++i)//�Ե���ʾ���չ�˾�����Ƶ�ǰ������д��ĸ
    {
        getnum+=(int(k[i]-'0')*temp);
        temp/=10;
    }
    return getnum;//���غ�����
}
 
/*
*�������ƣ�Search
*�����������ڹ�ϣ���в��Һ����
*���������key-�����
*�����������
*����ֵ��0/-1-��ʾ��/����ҳɹ�
*����˵������
*/
int Search(string key)
{
    int i=0,adr;
    int k=GetNum(key);
    adr=k%p;
    while(ha[adr].number!=NULLKEY&&ha[adr].number!=key)
    {
        ++i;
        adr=(adr+1)%MAXN;//��������̽�鷨����һ����ַ
    }
    if(ha[adr].number==key)
        return adr;//���ҳɹ�
    else
        return -1;//����ʧ��
}
 
/*
*�������ƣ�Delete
*�����������ڹ�ϣ����ɾ��ָ���ĺ�����Ϣ
*���������key-�����
*���������hashlen-��ϣ��Ԫ�ظ���,ha[adr].number-����Ƿ�ɾ��
*����ֵ��0/-1-��ʾ��/����ҳɹ�
*����˵������
*/
int Delete(string key)
{
    int adr;
    adr=Search(key);//�ڹ�ϣ�����ҵ��ùؼ���
    if(adr!=-1)
    {
        ha[adr].number=DELKEY;
        --hashlen;//��ϣ��Ԫ�ظ�����һ
        return 1;
    }
    else//�ڹ�ϣ����δ�ҵ��ùؼ���
        return 0;
}
 
/*
*�������ƣ�Insert1
*�����������ڹ�ϣ�����Զ����뺽����Ϣ
*���������key-�����
*���������hashlen-��ϣ��Ԫ�ظ���,ha[adr].number-�ؼ���,ha[adr].cnt-̽�����
*����ֵ����
*����˵������
*/
void Insert1(string key)
{
    int i,adr;
    int k=GetNum(key);//ȡ����ֵ����
    adr=k%p;
    if(ha[adr].number==NULLKEY||ha[adr].number==DELKEY)
    {
        ha[adr].number=key;//ֱ�ӷ����ϣ����
        ha[adr].cnt=1;
        infile>>ha[adr].data.departure>>ha[adr].data.terminal>>ha[adr].data.schedule;
        infile>>ha[adr].data.start>>ha[adr].data.arrival>>ha[adr].data.type>>ha[adr].data.price;
    }
    else//������ͻʱ��������̽�鷨�����ͻ
    {
        i=1;//Ԫ��iΪ����ʱ������ͻ�Ĵ���
        while(ha[adr].number!=NULLKEY&&ha[adr].number!=DELKEY)
        {
            adr=(adr+1)%p;
            ++i;
        }
        ha[adr].number=key;
        ha[adr].cnt=i;
        infile>>ha[adr].data.departure>>ha[adr].data.terminal>>ha[adr].data.schedule;
        infile>>ha[adr].data.start>>ha[adr].data.arrival>>ha[adr].data.type>>ha[adr].data.price;
    }
    ++hashlen;//��ϣ���Ԫ�ظ�����һ
}
 
/*
*�������ƣ�Insert2
*�����������ڹ�ϣ�������ļ��ֶ����뺽����Ϣ
*���������key-�����
*���������hashlen-��ϣ��Ԫ�ظ���,ha[adr].number-�ؼ���,ha[adr].cnt-̽�����
*����ֵ����
*����˵������
*/
void Insert2(string key)
{
    int i,adr;
    int k=GetNum(key);
    adr=k%p;
    if(ha[adr].number==NULLKEY||ha[adr].number==DELKEY)
    {
        ha[adr].number=key;
        ha[adr].cnt=1;
        Input(adr);//�ֶ�����ʣ����Ϣ
    }
    else
    {
        i=1;
        while(ha[adr].number!=NULLKEY&&ha[adr].number!=DELKEY)
        {
            adr=(adr+1)%p;
            ++i;
        }
        ha[adr].number=key;
        ha[adr].cnt=i;
        Input(adr);//�ֶ�����ʣ����Ϣ
    }
    ++hashlen;
}
 
/*
*�������ƣ�Create1
*�����������ڹ�ϣ�����Զ����뺽��ؼ�����Ϣ
*���������key-�����
*���������ha[adr].number-�ؼ���ȫ����ʼ��ΪNULLKEY,ha[adr].cnt-̽�����ȫ����ʼ��Ϊ0
*����ֵ����
*����˵������
*/
void Create1()
{
    int i;
    for(i=0; i<MAXN; ++i)//��ʼ��
    {
        ha[i].number=NULLKEY;
        ha[i].cnt=0;
    }
    cout<<"������Ϣ��ȡ�С����Ժ�"<<endl;//��ʾ��Ϣ
    for(i=0;; ++i)
    {
        if(!infile)//�����ļ��򿪲����Ƿ�ɹ�
        {
            cerr<<"open error!"<<endl;
            exit(1); //�򿪲��ɹ�������ʾ���˳�
        }
        infile>>x[i];//���ļ��ж�ȡ
        string s=x[i];
        if(s=="00")
            break;//����00ʱ������ȡ
        else
            Insert1(x[i]);//���ؼ��ֲ����ϣ��
    }
    infile.close();//�������һ��Ҫ�ر��ļ�
}
 
/*
*�������ƣ�Create2
*�����������ڹ�ϣ�����ֶ����뺽��ؼ�����Ϣ
*���������key-�����
*���������ha[adr].number-�ؼ���ȫ����ʼ��ΪNULLKEY,ha[adr].cnt-̽�����ȫ����ʼ��Ϊ0
*����ֵ����
*����˵������
*/
void Create2()
{
    int i;
    for(i=0; i<MAXN; ++i)
    {
        ha[i].number=NULLKEY;
        ha[i].cnt=0;
    }
    cout<<"�����뺽����Ϣ(����00ʱ¼�����)"<<endl;
    for(i=0;; ++i)
    {
        cin>>x[i];//�Ӽ����ֶ�����ؼ���
        string s=x[i];
        if(s=="00") break;
        else Insert2(x[i]);
    }
}
 
/*
*�������ƣ�Number
*�����������ڹ�ϣ���в�ѯ�����
*���������key-�����
*���������ha[adr].number-�����,ha[adr].data.departure-���վ,ha[adr].data.terminal-����վ,ha[adr].data.schedule-����,
ha[adr].data.start-���ʱ��,ha[adr].data.arrival-����ʱ��,ha[adr].data.type-����,ha[adr].data.price-Ʊ��
*����ֵ����
*����˵������
*/
void Number(string key)
{
    int i=0,adr;
    int k=GetNum(key);
    adr=k%p;
    while(ha[adr].number!=NULLKEY&&ha[adr].number!=key)//��ϣ����
    {
        ++i;
        adr=(adr+1)%MAXN;
    }
    if(ha[adr].number==key&&ha[adr].number!=DELKEY)
    {
        Output(adr);//����Ļ����ʾ
        FileOutput(adr);//�����ļ�
    }
    else
        cout<<"�Բ��𣬲��޴˺��࣡"<<endl;
}
 
/*
*�������ƣ�Departure
*�����������ڹ�ϣ���в�ѯ���վ
*���������key-���վ
*���������ha[adr].number-�����,ha[adr].data.departure-���վ,ha[adr].data.terminal-����վ,ha[adr].data.schedule-����,
ha[adr].data.start-���ʱ��,ha[adr].data.arrival-����ʱ��,ha[adr].data.type-����,ha[adr].data.price-Ʊ��
*����ֵ����
*����˵������
*/
void Departure(string key)//���վ
{
    int i,flag=0;
    for(i=0; i<MAXN; ++i)//˳�����
    {
        if(flag) break;
        else if(ha[i].data.departure==key)
        {
            Output(i);
            FileOutput(i);
            flag=1;//����Ƿ��ѯ�������Ϣ
        }
    }
    if(!flag)
        cout<<"�Բ��𣬲��޴˺��࣡"<<endl;
}
 
/*
*�������ƣ�Terminal
*�����������ڹ�ϣ���в�ѯ�յ�վ
*���������key-�յ�վ
*���������ha[adr].number-�����,ha[adr].data.departure-���վ,ha[adr].data.terminal-����վ,ha[adr].data.schedule-����,
ha[adr].data.start-���ʱ��,ha[adr].data.arrival-����ʱ��,ha[adr].data.type-����,ha[adr].data.price-Ʊ��
*����ֵ����
*����˵������
*/
void Terminal(string key)//�յ�վ
{
    int i,flag=0;
    for(i=0; i<MAXN; ++i)
    {
        if(flag)
            break;
        else if(ha[i].data.terminal==key)
        {
            Output(i);
            FileOutput(i);
            flag=1;
        }
    }
    if(!flag)
        cout<<"�Բ��𣬲��޴˺��࣡"<<endl;
}
 
/*
*�������ƣ�Start
*�����������ڹ�ϣ���в�ѯ���ʱ��
*���������key-���ʱ��
*���������ha[adr].number-�����,ha[adr].data.departure-���վ,ha[adr].data.terminal-����վ,ha[adr].data.schedule-����,
ha[adr].data.start-���ʱ��,ha[adr].data.arrival-����ʱ��,ha[adr].data.type-����,ha[adr].data.price-Ʊ��
*����ֵ����
*����˵������
*/
void Start(string key)
{
    int i,flag=0;
    for(i=0; i<MAXN; ++i)
    {
        if(flag) break;
        else if(ha[i].data.start==key)
        {
            Output(i);
            FileOutput(i);
            flag=1;
        }
    }
    if(!flag)
        cout<<"�Բ��𣬲��޴˺��࣡"<<endl;
}
 
/*
*�������ƣ�Arrival
*�����������ڹ�ϣ���в�ѯ����ʱ��
*���������key-����ʱ��
*���������ha[adr].number-�����,ha[adr].data.departure-���վ,ha[adr].data.terminal-����վ,ha[adr].data.schedule-����,
ha[adr].data.start-���ʱ��,ha[adr].data.arrival-����ʱ��,ha[adr].data.type-����,ha[adr].data.price-Ʊ��
*����ֵ����
*����˵������
*/
void Arrival(string key)
{
    int i,flag=0;
    for(i=0; i<MAXN; ++i)
    {
        if(flag) break;
        else if(ha[i].data.arrival==key)
        {
            Output(i);
            FileOutput(i);
            flag=1;
        }
    }
    if(!flag)
        cout<<"�Բ��𣬲��޴˺��࣡"<<endl;
}
 
/*
*�������ƣ�FileOutput
*����������������Ϣ�����ļ�
*�����������ϣ���е�λ��
*���������ha[adr].number-�����,ha[adr].data.departure-���վ,ha[adr].data.terminal-����վ,ha[adr].data.schedule-����,
ha[adr].data.start-���ʱ��,ha[adr].data.arrival-����ʱ��,ha[adr].data.type-����,ha[adr].data.price-Ʊ��
*����ֵ����
*����˵������
*/
void FileOutput(int adr)
{
    ofstream outfile("search.dat",ios::app);//׷�ӷ�ʽд���ļ�
    if(!outfile)//�����ļ��򿪲����Ƿ�ɹ�
    {
        cerr<<"open error!"<<endl;
        exit(1);//�򿪲��ɹ�������ʾ���˳�
    }
    outfile<<"�����"<<"\t"<<"���վ"<<"\t"<<"����վ"<<"\t"<<"����"<<"\t"<<"\t"<<"���ʱ��"<<"\t";
    outfile<<"����ʱ��"<<"\t"<<"����"<<"\t"<<"Ʊ��"<<"\n";
    outfile<<ha[adr].number<<"\t"<<ha[adr].data.departure<<"\t"<<ha[adr].data.terminal<<"\t"<<ha[adr].data.schedule<<"\t"<<"\t";
    outfile<<ha[adr].data.start<<"\t"<<"\t"<<ha[adr].data.arrival<<"\t"<<"\t"<<ha[adr].data.type<<"\t"<<ha[adr].data.price<<"\n";
    outfile.close();//�ر��ļ��������˱���رգ�����ᶪʧ����
}
 
/*
*�������ƣ�Output
*����������������Ϣ����Ļ����ʾ
*�����������ϣ���е�λ��
*���������ha[adr].number-�����,ha[adr].data.departure-���վ,ha[adr].data.terminal-����վ,ha[adr].data.schedule-����,
ha[adr].data.start-���ʱ��,ha[adr].data.arrival-����ʱ��,ha[adr].data.type-����,ha[adr].data.price-Ʊ��
*����ֵ����
*����˵������
*/
void Output(int adr)
{
    cout<<"�����"<<"\t"<<"���վ"<<"\t"<<"����վ"<<"\t"<<"����"<<"\t"<<"\t"<<"���ʱ��"<<"\t";
    cout<<"����ʱ��"<<"\t"<<"����"<<"\t"<<"Ʊ��"<<"\n";
    cout<<ha[adr].number<<"\t"<<ha[adr].data.departure<<"\t"<<ha[adr].data.terminal<<"\t"<<ha[adr].data.schedule<<"\t"<<"\t";
    cout<<ha[adr].data.start<<"\t"<<"\t"<<ha[adr].data.arrival<<"\t"<<"\t"<<ha[adr].data.type<<"\t"<<ha[adr].data.price<<"\n";
}
 
/*
*�������ƣ�Input
*�����������ֶ����뺽����Ϣ
*�����������ϣ���е�λ��
*���������ha[adr].number-�����,ha[adr].data.departure-���վ,ha[adr].data.terminal-����վ,ha[adr].data.schedule-����,
ha[adr].data.start-���ʱ��,ha[adr].data.arrival-����ʱ��,ha[adr].data.type-����,ha[adr].data.price-Ʊ��
*����ֵ����
*����˵������
*/
void Input(int adr)
{
    cin>>ha[adr].data.departure>>ha[adr].data.terminal>>ha[adr].data.schedule;
    cin>>ha[adr].data.start>>ha[adr].data.arrival>>ha[adr].data.type>>ha[adr].data.price;
}
 
int main()
{
    Work();
    return 0;
}
