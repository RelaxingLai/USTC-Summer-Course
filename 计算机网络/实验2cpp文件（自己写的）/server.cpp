#include <WinSock2.h>//��windows������һ��ʹ��WinSock2ͷ�ļ��еĺ�������������ͨ��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma comment(lib, "ws2_32.lib")
int main() {
    printf("���Ƿ������˳���\n");
    WSADATA wsadata;//WSADATA�������������洢��WSAStartup�������ú󷵻ص�Windows Sockets���ݡ�
    int port=8000;//���÷������˿ں�
    char buff[1024];//���ͻ�����
    char recvBuf[1024];//���ջ�����
    printf("�������˿ں���Ϊ8000\n");
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);//�������ڼ������׽���
    SOCKADDR_IN addrSrv;//����һ��SOCKADDR_IN���ͱ���addsrv,��ʾ�������˵��׽���������
    addrSrv.sin_family = AF_INET;//��ַ�帳ֵ��AF_INET��ʾIPv4
    addrSrv.sin_port = htons(port); //�˿ںŸ�ֵ��1024���ϵĶ˿ں�
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//ip��ַ��ֵ��INADDR_ANY��ʾ���뱾��ip��ַ
    bind(sockSrv, (LPSOCKADDR) & addrSrv, sizeof(SOCKADDR_IN));
    listen(sockSrv, 10);
    printf("��������׼����ɣ���ʼ�ȴ��ͻ�����������\n");
    while(1){
        SOCKADDR_IN addrClient;//����һ��SOCKADDR_IN���ͱ���Client,��ʾ�ͻ����˵��׽���������
        int len = sizeof(SOCKADDR);//ȡ��SOCKADDR_IN�ṹ��ĳ���
        SOCKET sockConn = accept(sockSrv, (SOCKADDR * ) & addrClient, &len);//sockConn��������������׽���������
        printf("��ͻ��������ӳɹ������ӵĿͻ�����IPΪ:%s\n", inet_ntoa(addrClient.sin_addr));//��ӡ�ͻ���ip��ַ
        while (1) {//�ȴ��ͻ�������
            printf("������Ҫ���͸��ͻ����˵���Ϣ(�ַ�������������1024���ַ�,�س�ֹͣ����,�����һ���ַ�Ϊ#ʱ�ر���ͻ������ӣ�\n");//��ʼ��������
            gets(buff);
            fflush(stdin);
            int temp=strlen(buff);
            if(buff[temp-1]=='#')
                break;
            send(sockConn, buff, sizeof(buff), 0);
            printf("���͸��ͻ����˵���Ϣ�������\n");
            memset(recvBuf, 0, sizeof(recvBuf));//��ʼ�����շ������˵Ļ�����
            recv(sockConn, recvBuf, sizeof(recvBuf), 0);  //��������
            printf("���յ��ͻ����˷�������Ϣ��\n");//��ӡ���յ�������
            printf("%s\n",recvBuf);//��ӡ���յ�������
            printf("�����յ�����Ϣ��Сд��ĸ�ĳɴ�д��ĸ��������д�����Ϣ�����ͻ�����\n");
            int length=strlen(recvBuf);
            memset(buff, 0, sizeof(buff));
            for(int i=0;i<length;i++){
                buff[i]=recvBuf[i];
                if(recvBuf[i]>=97&&recvBuf[i]<=122)
                    buff[i]-=32;
            }
            send(sockConn, buff, sizeof(buff), 0);
            printf("��д�����Ϣ�������\n");
            memset(recvBuf, 0, sizeof(recvBuf));//��ʼ�����շ������˵Ļ�����
            printf("���յ��ͻ����˷����ĸ�д�����Ϣ��\n");//��ӡ���յ�������
            recv(sockConn, recvBuf, sizeof(recvBuf), 0);//��������
            printf("%s\n",recvBuf);//��ӡ���յ�������
        }
        printf("�ر��׽���\n");//��ӡ���յ�������
        closesocket(sockConn);// closesocket���������ر�һ��������ΪsockConn���׽���
        int flag;
        printf("�Ƿ������з������˳�������Y��N\n");
        scanf("%c",&flag);
        if(flag=='N')
            break;
    }
    closesocket(sockSrv);
    WSACleanup();//�����ɹ�����ֵΪ0�����򷵻�ֵΪSOCKET_ERROR������ͨ������WSAGetLastError��ȡ������롣
    system("pause");//system("pause")���Ǵӳ�������á�pause������.
    return 0;
}
