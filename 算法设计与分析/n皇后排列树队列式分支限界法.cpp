#include<bits/stdc++.h>
using namespace std;
struct node{
	char ceng;//��ǰ�������ceng�� 
	char a[15];//��Լ�ռ���һ���ֽڵ�char���� 
	bool istrue(){//�жϵ�ǰ����õĻʺ��ǲ��Ǻ�֮ǰ�Ĳ�ͬб�� 
		for(int i=1;i<ceng;i++){
			if(abs(ceng-i) == abs(a[ceng]-a[i])) return false;
		}
		return true;
	}
};
queue<node> q;
int main(){
	int n;
	cin>>n;
	node x;
	for(int i=1;i<=n;i++)
		x.a[i] = i;//��ʼ������ 
	x.ceng = 1;
	q.push(x);
	while(q.size()){
		node t = q.front();
		q.pop();
		if(t.ceng == n){
			if(!t.istrue()) continue;//�����n������������ԵĻ��ͼ����� 
			for(int i=1;i<=n;i++) cout<<(int)t.a[i]<<" ";
			cout<<endl;
			break;
		}
		for(int i=t.ceng;i<=n;i++){
			swap(t.a[i],t.a[t.ceng]);
			if(t.istrue()){//��֦��������ǰ����Ѿ�ѡ�������ͬб�� 
				t.ceng ++;//���û���⣬ת����һ�� 
				q.push(t);
				t.ceng --;
			}
			swap(t.a[i],t.a[t.ceng]);//�ָ��ֳ����Ա�ѭ������һ��ʹ�� 
		}
	}
	return 0;
}
