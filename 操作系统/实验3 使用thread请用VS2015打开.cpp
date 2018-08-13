#include <iostream>
#include <cstdlib>
#include <thread>
#include <time.h>
#include <windows.h>
#define M 10
#define MAX 20
int mutex = 1;
int EMPTY = M;
int FULL = 0;
int a[M+1] = { 0 };
using namespace std;
void consumer(int *n1) {
	if (*n1 > MAX) {
		cout << "���д����Ѵﵽ������ƣ������߽��̽���\n" << endl;
		return;
	}
	if (FULL == 0) {
		printf("�޲�Ʒ�����ѣ��������������ʱ��\n");
		srand((unsigned)time(NULL));
		Sleep(rand()%3000);
		return consumer(n1);
	}
	while (FULL>0&&EMPTY<M) {
		if (mutex == 1) {
			mutex = 0;
			int i = 1;
			while (a[i] != 0 )
				i++;
			printf("�����ߴ�ӡ����a�е�%d�ŵ����ݣ����Ϊ%d,�����¹���\n", i - 1, a[i - 1]);
			a[i - 1] = { 0 };
			FULL -= 1;
			EMPTY += 1;
			printf("�����߽�������һ�Σ�����һ����Ʒ��EMPTY��ĿǰΪ%d��FULL��ĿǰΪ%d������������a�е�%d������\n", EMPTY, FULL,i-1);
			mutex = 1;
			*n1++;
			srand((unsigned)time(NULL));
			Sleep(rand() % 3000);
			return consumer(n1);
		}
		else {
			printf("����������������ռ�ã��������������ʱ��\n");
			srand((unsigned)time(NULL));
			Sleep(rand() % 3000);
			return consumer(n1);
		}
	}
	return;
}
void producer(int *n2) {
	if (*n2 > MAX) {
		cout << "���д����Ѵﵽ������ƣ������߽��̽���\n" << endl;
		return;
	}
	if (FULL == M) {
		printf("��Ʒ�����������������������ʱ��\n");
		srand((unsigned)time(NULL));
		Sleep(rand() % 3000);
		return producer(n2);
	}
	while (EMPTY>0&&FULL<M) {
		if (mutex == 1) {
			mutex = 0;
			EMPTY -= 1;
			FULL += 1;
			int i = 1;
			while (a[i] != 0)
				i++;
			a[i] = i;
			printf("��������a�е�%d��д������%d\n", i, a[i]);
			printf("�����߽�������һ�Σ�����һ����Ʒ��EMPTY��ĿǰΪ%d��FULL��ĿǰΪ%d,������a��%d��д������\n", EMPTY, FULL,i);
			mutex = 1;
			*n2++;
			srand((unsigned)time(NULL));
			Sleep(rand() % 3000);
			return producer(n2);
		}
		else {
			printf("����������������ռ�ã��������������ʱ��\n");
			srand((unsigned)time(NULL));
			Sleep(rand() % 3000);
			return producer(n2);
		}
	}
	return;
}
int main() {
	cout << "��������ʼ����\n" << endl;
	int count1 = 0, count2 = 0;
	int *c1 = &count1, *c2 = &count2;
	thread CONSUMER(consumer,c1);
	thread PRODUCER(producer,c2);
	PRODUCER.join();
	CONSUMER.join();
	cout << "���������н���\n" << endl;
	return 0;
}