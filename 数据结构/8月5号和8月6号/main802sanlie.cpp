#include<iostream>
#include<cstdio>
using namespace std;
void Hashsort(int table[],int x,int p)
{
    int no=x%p;
    while(table[no]!=0)
        no=(no+1)%15;
    table[no]=x;
    return;
}
int Hashsearch(int table[],int x,int p)
{
    int no=x%p;
    int count=0;
    while(table[no]!=x&&count<15)
    {
        no=(no+1)%15;
        count++;
    }
    if(count<15)
        return no;
    else
    {
        cout<<"�����޸�ֵ"<<endl;
        return 0;
    }
}
int main()
{
    int Table[15]={0};
    int n,num;
    int p=11;
    int weizhi;
    cout<<"���������ݸ�����"<<endl;
    cin>>n;
    cout<<"������������ݣ��Կո���:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        Hashsort(Table,num,p);
    }
    cout<<"��ϣ���ұ��ѽ���"<<endl;
    cout<<"������ϣ�����ҵ�����ֵ:"<<endl;
    cin>>num;
    weizhi=Hashsearch(Table,num,p);
    cout<<"���������±�"<<weizhi<<"��"<<endl;
    return 0;
}
