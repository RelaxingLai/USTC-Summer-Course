#include <WinSock2.h>//��windows������һ��ʹ��WinSock2ͷ�ļ��еĺ�������������ͨ��
#include <stdio.h>
#include <string.h>
#pragma comment(lib, "ws2_32.lib")
int main() {
    printf("���ǿͻ����˳���\n");
    WSADATA wsaData;//WSADATA�������������洢��WSAStartup�������ú󷵻ص�Windows Sockets���ݡ�
    char buff[1024];//���ͻ�����
    char recvBuf[1024];//���ջ�����
    memset(buff, 0, sizeof(buff));//��ʼ��������ֵΪ0
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKADDR_IN addrSrv;//����һ��SOCKADDR_IN���ͱ���addsrv,��ʾ�������˵��׽���������
    addrSrv.sin_family = AF_INET;//��ַ�帳ֵ��AF_INET��ʾIPv4
    addrSrv.sin_port = htons(8000);//�˿ںŸ�ֵ��1024���ϵĶ˿ں�
    addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//ip��ַ��ֵ��INADDR_ANY��ʾ���뱾��ip��ַ
    SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);//�����ͻ������׽���
    connect(sockClient, (struct sockaddr *) &addrSrv, sizeof(addrSrv));
    printf("�ͻ����������ӷ�������\n");
    while(1){
        memset(recvBuf, 0, sizeof(recvBuf));
        printf("���շ������˷�������Ϣ��\n");
        recv(sockClient, recvBuf, sizeof(recvBuf), 0);//��������
        printf("%s\n", recvBuf);//��ӡ���յ�����
        printf("������Ҫ���͸��������˵���Ϣ(�ַ�������������1024���ַ����س�ֹͣ����,�����һ���ַ�Ϊ#ʱ�رտͻ�����\n");//��������
        gets(buff);
        fflush(stdin);
        int temp=strlen(buff);
        if(buff[temp-1]=='#')
            break;
        send(sockClient, buff, sizeof(buff), 0);
        printf("���͸��������˵���Ϣ�������\n");
        printf("�����յ�����Ϣ��Сд��ĸ�ĳɴ�д��ĸ��������д�����Ϣ������������\n");
        int length=strlen(recvBuf);
        memset(buff, 0, sizeof(buff));
        for(int i=0;i<length;i++){
            buff[i]=recvBuf[i];
            if(recvBuf[i]>=97&&recvBuf[i]<=122)
                buff[i]-=32;
        }
        send(sockClient, buff, sizeof(buff), 0);
        printf("��д�����Ϣ�������\n");
        memset(recvBuf, 0, sizeof(recvBuf));
        printf("���յ��������˷����ĸ�д�����Ϣ��\n");
        recv(sockClient, recvBuf, sizeof(recvBuf), 0);
        printf("%s\n", recvBuf);//��ӡ���յ�����
    }
    printf("�ر��׽���\n");
    closesocket(sockClient);//�رտͻ����׽���
    WSACleanup();//�����ɹ�����ֵΪ0�����򷵻�ֵΪSOCKET_ERROR������ͨ������WSAGetLastError��ȡ������롣
    system("pause");//system("pause")���Ǵӳ�������á�pause������.
    return 0;
}
