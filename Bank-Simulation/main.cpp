#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5
#define TRUE 1
#define FALSE 0


typedef struct{
	int id;
	int arrival_time;
	int service_time;
}element;

typedef struct{
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;

}QueueType;

QueueType q;

int wait_num1 = 0;
int wait_num2 = 0;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q)
{

	q->front = 0;
	q->rear = 0;

}
	
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

int is_full(QueueType *q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("ť�� ���� á���ϴ�.\n");
	else
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
}

element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("ť�� ����ֽ��ϴ�.\n");
	else
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}


void main(){

	int minutes = 10;
	int total_wait = 0;
	int total_customers = 0;
	int empoyee = 2;
	int j;

	QueueType queue;
	init_queue(&queue);
	element customer[2] = { 0, 0, 0, 0, 0, 0 };
	int num1 = 0;
	int num2 = 0;
	srand(time(NULL));

	for (int clock = 0; clock < minutes; clock++)
	{
		printf("����ð�=%d\n", clock);
		if ((rand() % 10 < 3))
		{
			
				if (wait_num1 <= wait_num2)
				{

					customer[0].id = total_customers++;
					customer[0].arrival_time = clock;
					customer[0].service_time = (int)(rand() % 10 + 1);
					enqueue(&queue, customer[0]);


					printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n", customer[0].id, customer[0].arrival_time, customer[0].service_time);
					printf("1��â������ ��%d�� %d�п� ����ó���� �����մϴ�.���ð��� 0���̾����ϴ�.\n", customer[0].id, customer[0].arrival_time);
				
					




					wait_num1++;
					

					if (customer[0].service_time-clock == 0)
					{
						wait_num1--;
					}

					if (wait_num1 != 0)
					{
						printf("1��â������ ��%d�� ����ó�����Դϴ�.\n", customer[0].id);


					}


					if (wait_num2 != 0)
					{
						printf("2��â������ ��%d�� ����ó�����Դϴ�.\n", customer[1].id);


					}



				}

				else
				{
					customer[1].id = total_customers++;
					customer[1].arrival_time = clock;
					customer[1].service_time = (int)(rand() % 10 + 1);

					enqueue(&queue, customer[1]);

					printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n", customer[1].id, customer[1].arrival_time, customer[1].service_time);
					printf("1��â������ ��%d�� %d�п� ����ó���� �����մϴ�.���ð��� 0���̾����ϴ�.\n", customer[0].id, customer[0].arrival_time);
				

					
					wait_num2++;
					


					if (customer[1].service_time-clock == 0)
					{
						wait_num2--;
					}


					if (wait_num1 != 0)
					{
						printf("1��â������ ��%d�� ����ó�����Դϴ�.\n", customer[0].id);


					}
					
					if (wait_num2 != 0)
					{
						printf("2��â������ ��%d�� ����ó�����Դϴ�.\n", customer[1].id);


					}


				}

				if (!is_empty(&queue))
				{


					if (customer[0].service_time - clock == 0)
					{
						customer[0] = dequeue(&queue);
						num1 = clock - customer[0].arrival_time;
						total_wait += num1;
						printf("1��â������ ��%d�� %d�п� ����ó���� �����մϴ�.���ð��� %d���̾����ϴ�.\n", customer[0].id, customer[0].arrival_time, num1);

					}

					if (customer[1].service_time - clock == 0)
					{
						
						customer[1] = dequeue(&queue);
						num2 = clock - customer[1].arrival_time;
						total_wait += num2;
						printf("2��â������ ��%d�� %d�п� ����ó���� �����մϴ�.���ð��� %d���̾����ϴ�.\n", customer[1].id, customer[1].arrival_time, num2);
					}

				}

			}
		
	
	
	}


		

		
	printf("�Ѵ��ð� %d\n", total_wait);


	}


	
	
