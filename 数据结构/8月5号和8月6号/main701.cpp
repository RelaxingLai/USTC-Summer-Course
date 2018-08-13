#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
#define MAXBIT 1000        //�������������󳤶�
typedef struct HNode{
   char ch;//���ڴ�Ÿýڵ��ַ�
   int weight,parent,lchild,rchild;
}HNode;                //�����������
typedef struct HCode{
   int weight;
   int bit[MAXBIT];
   int start;
}HCode;                //��������������
void HuffTree(HNode Huff[],int n){//���ɹ�������
   FILE *fp;
   char d;
   int i,j,w,m1,m2,x1,x2;
   for(i=0;i<2*n-1;i++)                  //�����ʼ��
   {
      Huff[i].ch=' ';
      Huff[i].weight=0;
      Huff[i].parent=-1;
      Huff[i].lchild=-1;
      Huff[i].rchild=-1;
   }
   printf("����%d���ַ�������Ȩֵ: \n",n);//��������
   getchar();
   for(i=0;i<n;i++){
       printf("�������%d���ַ�:",i+1);
       scanf("%c",&d);
       getchar();
       Huff[i].ch=d;
       printf("�������%d���ַ���Ȩֵ:",i+1);
       scanf("%d",&w);
       getchar();
       Huff[i].weight=w;
   }
   for(i=0;i<n-1;i++){//����������������ɸ�����n-1����֧���
       m1=m2=32767;
       x1=x2=0;
       for(j=0;j<n+i;j++){//ѡȡ��С�ʹ�С����Ȩֵ��㲢���������x1��x2
          if(Huff[j].parent==-1&&Huff[j].weight<m1){
             m2=m1;
             x2=x1;
             m1=Huff[j].weight;
             x1=j;
          }
          else
             if(Huff[j].parent==-1&&Huff[j].weight<m2){
                m2=Huff[j].weight;
                x2=j;
             }
       }
       //���ҳ������������ϲ�Ϊһ���µ�����
      Huff[x1].parent=n+i;
      Huff[x2].parent=n+i;
      Huff[n+i].weight=Huff[x1].weight+Huff[x2].weight;
      Huff[n+i].lchild=x1;
      Huff[n+i].rchild=x2;
   }
   printf("���������б�:\n");
   printf("\n_________________________________________________________|\n");
   printf("zifu | Huff| weight |    lchild  |     rchild|    parent | \n");
   for(i=0;i<2*n-1;i++){//�����������������Huff����Ϣ
       printf("_____|_____|________|____________|___________|___________|\n");
       printf("%4c |%4d | %5d  | %10d |%10d |%10d |\n",Huff[i].ch, i, Huff[i].weight,
       Huff[i].lchild,Huff[i].rchild, Huff[i].parent);
   }
     printf("_________________________________________________________|\n");
     if((fp=fopen("d:\\hfmtree.txt","w"))==NULL)//����hfmtree�ļ�
        printf("cannot open the file of hfmtree\n");
     else{
        fprintf(fp,"zifu Huff weight     lchild      rchild     parent \n");
        for(i=0;i<2*n-1;i++){
            fprintf(fp,"%3c %3d %5d %10d %10d %10d \n",Huff[i].ch,i, Huff[i].weight,
            Huff[i].lchild,Huff[i].rchild, Huff[i].parent);
        }
        fclose(fp);
     }
}
void HuffmanCode(HNode Huff[],int n){//���ɹ���������
   FILE *fw;
   HCode HuffCode[MAXSIZE/2],cd;        
// MAXSIZE/2ΪҶ����������
   int i,j,c,p;
   for(i=0;i<n;i++){//��ÿ��Ҷ���Ĺ���������
      HuffCode[i].weight=Huff[i].weight;
      cd.start=MAXBIT-1;
      c=i;
      p=Huff[c].parent;
      while(p!=-1){
         if(Huff[p].lchild==c)
            cd.bit[cd.start]=0;
         else
            cd.bit[cd.start]=1;
         cd.start--;
         c=p;
         p=Huff[c].parent;
      }
      for(j=cd.start+1;j<MAXBIT;j++)//�����Ҷ����ַ��Ĺ���������
          HuffCode[i].bit[j]=cd.bit[j];
      HuffCode[i].start=cd.start;//����ñ���������bit�е���ʼλ��
   }
   printf("��ĸ��������������:\n");
   printf("-----|--------|--------|-------|\n");
   printf("zifu |HuffCode| weight |   bit |\n");       //�������HuffCode���й���Ϣ
   printf("-----|--------|--------|-------|\n");
   for(i=0;i<n;i++){//�����Ҷ����Ӧ�Ĺ���������   
       printf("%4c |%5d   |%4d    |     ",Huff[i].ch,i,HuffCode[i].weight);
       for(j=HuffCode[i].start+1;j<MAXBIT;j++)
           printf("%d |",HuffCode[i].bit[j]);
       printf("\n");
       printf("-----|--------|--------|-------|\n");
   }
   if((fw=fopen("d:\\CodeFile.txt","w"))==NULL)//����codeFile�ļ�
     printf("cannot open the file of CodeFile\n");
   else{
        fprintf(fw,"zifu HuffCode weight    bit \n");
        for(i=0;i<n;i++){
           fprintf(fw,"%4c%5d%8d     ",Huff[i].ch,i,HuffCode[i].weight);
           for(j=HuffCode[i].start+1;j<MAXBIT;j++)
              fprintf(fw,"%d",HuffCode[i].bit[j]);
           fprintf(fw,"\n");
        }
    }
    fclose(fw);
}
void decode(HNode Huff[],int n){//���ζ�����ģ����ݹ�����������
    FILE *fs;
    int i,j=0;
    char b[MAXSIZE];
    i=2*n-2;             //�Ӹ���㿪ʼ��������
    printf("��������ģ����������롿\n");
    getchar();
    printf("���뷢�͵ı���(��'2'Ϊ������־)��\n");
    gets(b);
    printf("�������ַ�Ϊ:\n");
    while(b[j]!='2'){
       if(b[j]=='0')
           i=Huff[i].lchild;   //��������
       else
           i=Huff[i].rchild;   //�����Һ���
       if(Huff[i].lchild==-1){//tree[i]��Ҷ���
          printf("%c",Huff[i].ch);
          i=2*n-2;      //�ص������
       }
      j++;
   }
    printf("\n");
    if(Huff[i].lchild!=-1&&b[j]!='2')//���Ķ��꣬����δ��Ҷ�ӽ��
         printf("\nERROR\n");  //��������д�
    else{
        if((fs=fopen("d:\\textFile.txt","w"))==NULL)//����textFile�ļ�
            printf("cannot open the textFile.txt of CodeFile\n");
        else{
            fprintf(fs,"�������ַ�Ϊ");
        while(b[j]!='2'){
            if(b[j]=='0')
              i=Huff[i].lchild;   //��������
            else
              i=Huff[i].rchild;   //�����Һ���
            if(Huff[i].lchild==-1){//tree[i]��Ҷ���
              fprintf(fs,"%c",Huff[i].ch);
              i=2*n-2;      //�ص������
           }
           j++;
         }
       }
    }
}
void menu(){
    printf("�˵�����\n");
    printf("1-------������������\n" );
    printf("2-------���й������\n");
    printf("3-------���й�������\n");
    printf("0-------�����˳�\n");
}
int main(){
    HNode Huff[MAXSIZE];
    int n,sel;
    printf("                            �������������������롪��\n");
    printf("Input numbers of leaf :\n");    //nΪҶ������
    scanf("%d",&n);
    do{
        menu();
        printf("����������ѡ��:\n");
        scanf("%d",&sel);
        switch(sel){
            case 1:
            HuffTree(Huff,n);//������������
            break;
            case 2:
            HuffmanCode(Huff,n);  //���ɹ���������
            break;
            case 3:
            decode(Huff,n);//��������
            break;
        }
    }while(sel!=0);
    return 0;
}

