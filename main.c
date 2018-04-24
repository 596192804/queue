#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
int main()
{
	AQueue Q;
	LQueue q;
	int data, l;
	void* k; k = &l;
	char  option='\0',choice='\0', selection='\0', c_data;
	float f_data;
	InitAQueue(&Q);
	InitLQueue(&q);
	printf("\t选择循环队列还是链式队列\n");
	printf("\t1.循环队列\n");
	printf("\t2.链式队列\n");
	do {
		option = getchar();
		if (option == '1')
		{
			for (int flag = 1; flag != 0;)
			{
				char ch; while ((ch = getchar()) != '\n' && ch != EOF);
				system("cls");
				printf("****************菜单****************\n");
				printf("\t1.初始化队列\n");
				printf("\t2.销毁队列\n");
				printf("\t3.检查队列是否已满\n");
				printf("\t4.检查队列是否为空\n");
				printf("\t5.查看队头元素\n");
				printf("\t6.确定队列长度\n");
				printf("\t7.入队操作\n");
				printf("\t8.出队操作\n");
				printf("\t9.清空队列\n");
				printf("\tt.遍历函数操作\n");
				printf("\t0:退出\n");
				printf("************************************\n");
				choice = getchar();
				system("cls");
				switch (choice)
				{
				case '1':
				{
					InitAQueue(&Q);
					printf("初始化成功\n");
					system("pause"); break;
				}
				case '2':
				{
					DestoryAQueue(&Q);
					printf("销毁成功\n");
					system("pause"); break;
				}
				case '3':
				{
					if (IsFullAQueue(&Q) == TRUE)
						printf("队列满\n");
					else
						printf("队列未满\n");
					system("pause"); break;
				}
				case '4':
				{
					if (IsEmptyAQueue(&Q) == TRUE)
						printf("队列空\n");
					else
						printf("队列未空\n");
					system("pause"); break;
				}

				case '5':
				{
					if (GetHeadAQueue(&Q,&k) == TRUE)
						APrint(&k);
					else
						printf("获取失败\n");
					system("pause"); break;
				}

				case '6':
				{
					printf("队列长度为:%d\n", LengthAQueue(&Q));
					system("pause"); break;
				}

				case '7':
				{
					char ch; while ((ch = getchar()) != '\n' && ch != EOF);//清空键盘缓存
					printf("输入要入列的数据的类型\n1.整形\n2.字符\n3.浮点型\n");
					selection = getchar();
					printf("输入要入列的数据:\n");
					switch (selection)
					{
					case '1':
					{
						char ch; while ((ch = getchar()) != '\n' && ch != EOF);
						scanf_s("%d", &data);
						
						if (EnAQueue(&Q, &data) == TRUE)
							printf("入队成功\n");
						else
							printf("入队失败\n");
						system("pause"); break;
					}
					case '2':
					{
						char ch; while ((ch = getchar()) != '\n' && ch != EOF);
						scanf_s("%c", &c_data);
						if (EnAQueue(&Q, &c_data) == TRUE)
							printf("入队成功\n");
						else
							printf("入队失败\n");
						system("pause"); break;
					}

					case '3':
					{
						char ch; while ((ch = getchar()) != '\n' && ch != EOF);
						scanf_s("%f", &f_data);
						if (EnAQueue(&Q, &f_data) == TRUE)
							printf("入队成功\n");
						else
							printf("入队失败\n");
						system("pause"); break;
					}
					default:break;
					}
					break;
				}
				case '8':
				{
					if (DeAQueue(&Q) == TRUE)
						printf("出队成功\n");
					else
						printf("出队失败\n");
					system("pause"); break;
				}
				case '9':
				{
					ClearAQueue(&Q); printf("成功");
					system("pause");
					break;
				}
				case 't':
				{
					if (TraverseAQueue(&Q, APrint) == TRUE)
						printf("遍历成功\n");
					else
						printf("遍历失败\n");
					system("pause");
					break;
				}
				case '0':flag = 0; system("pause"); break;
				default:printf("错误，请重输\n");
				}
			}
		}
		else if (option == '2')
			for (int flag = 1; flag != 0;)
			{
				system("cls");
				printf("****************MENU****************\n");
				printf("\t1.初始化队列\n");
				printf("\t2.销毁队列\n");
				printf("\t3.检查队列是否为空\n");
				printf("\t4.查看队头元素\n");
				printf("\t5.确定队列长度\n");
				printf("\t6.入队操作\n");
				printf("\t7.出队操作\n");
				printf("\t8.清空队列\n");
				printf("\t9.遍历函数操作\n");
				printf("************************************\n");
				printf("请输入你的选择\n");
				char ch; while ((ch = getchar()) != '\n' && ch != EOF);
				scanf_s("%c", &choice);
				system("cls");
				switch (choice)
				{
				case '1':
				{
					InitLQueue(&q);
					printf("初始化成功\n");
					break;
				}
				case '2':
				{
					DestoryLQueue(&q);
					printf("销毁成功\n");
					break;
				}
				case '3':
				{
					if (IsEmptyLQueue(&q) == TRUE)
						printf("队列空\n");
					else
						printf("队列未空\n");
					break;
				}
				case '4':
				{
					if (GetHeadLQueue(&q, &k) == TRUE)
						APrint(&k);
					else
						printf("获取失败\n");
					break;
				}
				case '5':
				{
					printf("队列长度为:%d\n", LengthLQueue(&q));
					break;
				}
				case '6':
				{
					printf("输入要输入的数据的类型\n1.整形\t2.字符\t3.浮点型\n");
					char ch; while ((ch = getchar()) != '\n' && ch != EOF);
					scanf_s("%c", &selection);
					printf("输入要输入的数据:\n");
					switch (selection)
					{
					case '1':
					{
						char ch; while ((ch = getchar()) != '\n' && ch != EOF);
						scanf_s("%d", &data);
						if (EnLQueue(&q, &data) == TRUE)
							printf("入队成功\n");
						else
							printf("入队失败\n");
						break;
					}
					case '2':
					{
						char ch; while ((ch = getchar()) != '\n' && ch != EOF);
						scanf_s("%c", &c_data);
						if (EnLQueue(&q, &c_data) == TRUE)
							printf("入队成功\n");
						else
							printf("入队失败\n");
						break;
					}
					case '3':
					{
						char ch; while ((ch = getchar()) != '\n' && ch != EOF);
						scanf_s("%f", &f_data);
						if (EnLQueue(&q, &f_data) == TRUE)
							printf("入队成功\n");
						else
							printf("入队失败\n");
						break;
					}
					}
					break;
				}
				case '7':
				{
					if (DeLQueue(&q) == TRUE)
						printf("出队成功\n");
					else
						printf("出队失败\n");
					break;
				}
				case '8':
				{
					ClearLQueue(&q); printf("成功");
					break;
				}
				case '9':
				{
					if (TraverseLQueue(&q, APrint) == TRUE)
						printf("遍历成功\n");
					else
						printf("遍历失败\n");
					break;
				}
				default:printf("错误，请重输\n");
				}
			}
		if (option != '1' && option != '2')
			printf("错误，请重输\n");
	} while (option != '1' &&option != '2');
	return 0;
}
