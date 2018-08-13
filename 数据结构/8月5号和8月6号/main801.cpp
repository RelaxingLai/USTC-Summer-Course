#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct BTNode{
	int key;
	BTNode *lchild,*rchild;
};
void insertBST(BTNode *&root,int x)
{
	if(root==NULL)
	{
		root=new BTNode;
		root->key=x;
		root->lchild=root->rchild=NULL;
		return;
	}
	else if(root->key>x)
		insertBST(root->lchild,x);
	else if(root->key<x)
		insertBST(root->rchild,x);
}
void searchBST(BTNode *root,int x)
{
	if(root==NULL)
	{
		cout<<"�Ҳ�������"<<endl;
		return;
	}
	if(root->key==x)
	{
		cout<<"�ҵ�����"<<endl;
		return;
	}
	if(root->key>x)
		searchBST(root->lchild,x);
	else if(root->key<x)
		searchBST(root->rchild,x);
}
void deleteNode(BTNode *&root,int x)
{
	if(root==NULL)
    {
        cout<<"�ö�������û��Ҫɾ����ֵ��"<<x<<endl;
        return;
    }
    if(root->key==x)
    {
        if(root->lchild==NULL&&root->rchild==NULL)
        {
            free(root);
            cout<<"ɾ���ɹ�"<<endl;
        }
        else if(root->lchild!=NULL)
        {
            BTNode *temp=root->lchild;
            while(temp->rchild!=NULL)
                temp=temp->rchild;
            root->key=temp->key;
            deleteNode(root->lchild,temp->key);
        }
        else
        {
            BTNode *temp=root->rchild;
            while(temp->lchild!=NULL)
                temp=temp->lchild;
            root->key=temp->key;
            deleteNode(root->rchild,temp->key);
        }
    }
    else if(root->key>x)
        deleteNode(root->lchild,x);
    else
        deleteNode(root->rchild,x);
}
int main()
{
	BTNode *root=NULL;
	int n,num,searchnum,deletenum;
	cout<<"�����뽨������������ֵ����:"<<endl;
	cin>>n;
	cout<<"��������������ֵ:"<<endl;
	for(int i=0;i<n;i++)
    {
        cin>>num;
        cout<<"��"<<i+1<<"������ɹ�"<<endl;
        insertBST(root,num);
        cout<<"��"<<i+1<<"�β���ɹ�"<<endl;
    }
    cout<<"���������������ɹ�"<<endl;
	cout<<"������Ҫ���ҵ�����ֵ:"<<endl;
	cin>>searchnum;
    searchBST(root,searchnum);
	cout<<"������Ҫɾ��������ֵ:"<<endl;
	cin>>deletenum;
	deleteNode(root,deletenum);
	return 0;
}

