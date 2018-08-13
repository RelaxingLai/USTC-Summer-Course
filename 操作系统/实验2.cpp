/*
���̵����㷨����������������ȵĵ����㷨�������ȷ����㷨��ÿ��������һ�����̿���
�飨PCB����ʾ�����̿��ƿ���԰���������Ϣ����������������������ʱ�䡢��Ҫ����ʱ�䡢
����CPUʱ�䡢����״̬�ȵȡ����̵�����������Ҫ������ʱ�����������Ϊ��ָ����Ҳ������
����������������̵ĵ���ʱ��Ϊ���������ʱ�䡣
���̵�����ʱ����ʱ��ƬΪ��λ���м��㡣
ÿ�����̵�״̬�����Ǿ��� W��Wait ��������R��Run���������F��Finish ������״̬֮һ��
�������̻��CPU��ֻ������һ��ʱ��Ƭ������ռ��CPUʱ���1����ʾ��
�������һ��ʱ��Ƭ�󣬽��̵���ռ��CPUʱ���Ѵﵽ����Ҫ������ʱ�䣬�����ý��̣�
�������һ��ʱ��Ƭ����̵���ռ��CPUʱ�仹δ������Ҫ������ʱ�䣬Ҳ���ǽ��̻���Ҫ
�������У���ʱӦ�����̵���������1��������һ������Ȼ���������������еȴ�CPU��
ÿ����һ�ε��ȳ��򶼴�ӡһ�����н��̡��������С��Լ��������̵�PCB���Ա���м�顣
�ظ����Ϲ��̣�ֱ����Ҫ���̶����Ϊֹ��
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef struct PCB{ 
	char state;
	int id;	
	int super;
	int arrivetime;
	int runtime;
	struct PCB *next;
}PCB;
void insertjincheng(PCB *root,PCB *q){
	PCB *temp=root;
	if(temp->next==NULL)
	{
		temp->next=q;
		return;
	}
	while(temp->next!=NULL&&temp->arrivetime<q->arrivetime)
		temp=temp->next;
	while(temp->super>q->super&&temp->next!=NULL)
		temp=temp->next;
	q->next=temp->next;
	temp->next=q;
	return;		
} 
void yunxing(PCB *&root){
	PCB *temp=root;
	if(temp->next==NULL)
	{
		printf("���н������н���\n");
		return;
	}
	temp=temp->next;
	printf("��������%d�Ž���\n",temp->id);
	temp->super-=1;
	temp->runtime-=1;
	printf("%d�Ž���ʱ��Ƭ����\n",temp->id);
	if(temp->runtime==0){
		temp->state='R';
		printf("���Ϊ%d�Ľ������н���,����״̬Ϊ%c\n",temp->id,temp->state);
		root->next=temp->next;
		free(temp);
	}
	else{
		root->next=temp->next;
		insertjincheng(root,temp);
	}
	return;
}
int main(){	
	PCB *root=(PCB*)malloc(sizeof(PCB));
	root->next=NULL;
	int num;
	printf("�����������������\n");
	scanf("%d",&num);
	printf("������������̵���Ϣ��\n");
	for(int i=0;i<num;i++){
		PCB *q=(PCB*)malloc(sizeof(PCB));
		PCB *p=root;
		q->state='W';
		q->next=NULL;
		printf("\n��������̱�š����̳�ʼ���ȼ������̵���ʱ�䡢��������ʱ�䣬�Կո�����\n");
		cin>>q->id>>q->super>>q->arrivetime>>q->runtime;
		printf("����%d�Ž�����Ϣ�ɹ�\n",q->id);
		insertjincheng(root,q);
		printf("����%d�Ž��̵����������гɹ�\n",q->id);
	}
	printf("�������\n");
	while(root->next!=NULL){
		yunxing(root);
		printf("����������һ��\n");
	} 	
	return 0;
}
	
	
	
