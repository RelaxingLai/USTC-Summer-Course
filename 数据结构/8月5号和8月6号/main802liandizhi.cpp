#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXSIZE 15
using namespace std;
typedef struct HNode{
    int data;
    struct HNode *next;
}HNode;
void Init(HNode *HashLink[])
{
    int i;
    for(i=0;i<MAXSIZE;i++)
    {
	    HashLink[i]=(HNode*)malloc(sizeof(HNode));
		HashLink[i]->next=NULL;
	}
}
void InsertHash(HNode *HashLink[],int key,int p)
{
    int k;
    HNode *q,*s;
    k=key%p;
    q=HashLink[k];
    s=new HNode;
    s->data=key;
	s->next=NULL;
    if(HashLink[k]->next==NULL)
    {
        HashLink[k]->next=s;
        cout<<"��λ�ò����׸�ֵ�ɹ�"<<endl;
    }
    else
    {
        while(q->next!=NULL)
            q=q->next;
        q->next=s;
        cout<<"���뵥����ɹ�"<<endl;
    }
    return;
}
int FindHash(HNode *HashLink[],int key,int p)
{
    int k;
    HNode *q;
    k=key%p;
    q=HashLink[k];
    if(q->next==NULL)
        cout<<"�ù�ϣ�����޸���"<<endl;
    else
    {
        q=q->next;
		while(q!=NULL)
        {
            if(q->data==key)
            {
                cout<<"�����ڹ�ϣ���У�λ��Ϊ:"<<endl;
                return k;
            }
            else
                q=q->next;
        }
    }
    return 0;
}
int main()
{
    HNode *HashLink[MAXSIZE];
    int n,num,k;
    int p=11;
    Init(HashLink);
    cout<<"��ʼ���ɹ�"<<endl; 
    cout<<"���������ݸ�����"<<endl;
    cin>>n;
    cout<<"������������ݣ��Կո�����"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        InsertHash(HashLink,num,p);
    }
    cout<<"������������ҵ�����"<<endl;
    cin>>num;
    k=FindHash(HashLink,num,p);
    if(k!=0)
        cout<<k<<endl;
    return 0;
}

