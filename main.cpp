#include<stdio.h>
#include<time.h>
#include"sort.h"
#include <string.h>  
#include <time.h>  
#include<windows.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
 int main()
{
//插入排序
  double time[6][4];       
  for (int i = 0; i < 6; i++)
	  for (int j = 0; j < 4;j++)
		  time[i][j] = 0;
  int size1 = 10, size2 = 50, size3 = 20, size4 = 10;
  int* array = (int *)calloc(size1, sizeof(int));
  getRandArray(array, size1);
  clock_t begin;
  clock_t end;
  begin = clock();
  InsertSort(array, size1);
  end = clock();
  time[0][0] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size2, sizeof(int));
  getRandArray(array, size2);
  begin = clock();
  InsertSort(array, size2);
  end = clock();
  time[0][1] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size3, sizeof(int));
  getRandArray(array, size3);
  begin = clock();
  InsertSort(array, size3);
  end = clock();
  time[0][2] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size4, sizeof(int));
  getRandArray(array, size4);
  begin = clock();
  for (int i = 1; i <= 100000; i++)
  {
	  InsertSort(array, size4);
	  getRandArray(array, size4);
  }
  end = clock();
  free(array);
  time[0][3] = ((end - begin) / 1000.0);
  printf("%lf  %lf  %lf  %lf\n", time[0][0], time[0][1], time[0][2], time[0][3]);
  //**********************************************************************************************
  //归并排序
  array = (int *)calloc(size1, sizeof(int));
  getRandArray(array, size1);
  begin = clock();
  MergeSort(array, 0, size1 - 1);
  end = clock();
  time[1][0] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size2, sizeof(int));
  getRandArray(array, size2);
  begin = clock();
  MergeSort(array, 0, size2 - 1);
  end = clock();
  time[1][1] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size3, sizeof(int));
  getRandArray(array, size3);
  begin = clock();
  MergeSort(array, 0, size3 - 1);
  end = clock();
  time[1][2] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size4, sizeof(int));
  getRandArray(array, size4);
  begin = clock();
  for (int i = 1; i <= 100000; i++)
  {
	  MergeSort(array, 0, size4 - 1);
	  getRandArray(array, size4);
  }
  end = clock();
  free(array);
  time[1][3] = ((end - begin) / 1000.0);
  printf("%lf  %lf  %lf  %lf\n", time[1][0], time[1][1], time[1][2], time[1][3]);
  //*******************************************************************
  //快排递归版
  array = (int *)calloc(size1, sizeof(int));
  getRandArray(array, size1);
  begin = clock();
  QSort_Recursion(array, 0, size1 - 1);
  end = clock();
  time[2][0] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size2, sizeof(int));
  getRandArray(array, size2);
  begin = clock();
  QSort_Recursion(array, 0, size2 - 1);
  end = clock();
  time[2][1] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size3, sizeof(int));
  getRandArray(array, size3);
  begin = clock();
  QSort_Recursion(array, 0, size3 - 1);
  end = clock();
  time[2][2] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size4, sizeof(int));
  getRandArray(array, size4);
  begin = clock();
  for (int i = 1; i <= 1; i++)
  {
	  QSort_Recursion(array, 0, size4- 1);
	  getRandArray(array, size4);
  }
  end = clock();
  free(array);
  time[2][3] = ((end - begin) / 1000.0);
  printf("%lf  %lf  %lf  %lf\n", time[2][0], time[2][1], time[2][2], time[2][3]);
  //*******************************************************************
  //快排非递归版
  array = (int *)calloc(size1, sizeof(int));
  getRandArray(array, size1);
  begin = clock();
  QSort(array, 0, size1 - 1);
  end = clock();
  time[3][0] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size2, sizeof(int));
  getRandArray(array, size2);
  begin = clock();
  QSort(array, 0, size2 - 1);
  end = clock();
  time[3][1] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size3, sizeof(int));
  getRandArray(array, size3);
  begin = clock();
  QSort(array, 0, size3 - 1);
  end = clock();
  time[3][2] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size4, sizeof(int));
  getRandArray(array, size4);
  begin = clock();
  for (int i = 1; i <= 100000; i++)
  {
	  QSort(array, 0, size4 - 1);
	  getRandArray(array, size4);
  }
  end = clock();
  free(array);
  time[3][3] = ((end - begin) / 1000.0);
  printf("%lf  %lf  %lf  %lf\n", time[3][0], time[3][1], time[3][2], time[3][3]);
  //***************************************************************
  //计数排序 
  array = (int *)calloc(size1, sizeof(int));
  getRandArray(array, size1);
  begin = clock();
  CountSort(array, size1);
  end = clock();
  time[4][0] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size2, sizeof(int));
  getRandArray(array, size2);
  begin = clock();
  CountSort(array, size2);
  end = clock();
  time[4][1] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size3, sizeof(int));
  getRandArray(array, size3);
  begin = clock();
  CountSort(array, size3);
  end = clock();
  time[4][2] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size4, sizeof(int));
  getRandArray(array, size4);
  begin = clock();
  for (int i = 1; i <= 100000; i++)
  {
	  CountSort(array, size4);
	  getRandArray(array, size4);
  }
  end = clock();
  free(array);
  time[4][3] = ((end - begin) / 1000.0);
  printf("%lf  %lf  %lf  %lf\n", time[4][0], time[4][1], time[4][2], time[4][3]);
  //*****************************************************************
  //基数计数排序
  array = (int *)calloc(size1, sizeof(int));
  getRandArray(array, size1);
  begin = clock();
  RadixCountSort(array, size1);
  end = clock();
  time[5][0] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size2, sizeof(int));
  getRandArray(array, size2);
  begin = clock();
  RadixCountSort(array, size2);
  end = clock();
  time[5][1] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size3, sizeof(int));
  getRandArray(array, size3);
  begin = clock();
  RadixCountSort(array, size3);
  end = clock();
  time[5][2] = ((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size4, sizeof(int));
  getRandArray(array, size4);
  begin = clock();
  for (int i = 1; i <= 100000; i++)
  {
	  RadixCountSort(array, size4);
	  getRandArray(array, size4);
  }
  end = clock();
  free(array);
  time[5][3] = ((end - begin) / 1000.0);
  printf("%lf  %lf  %lf  %lf\n", time[5][0], time[5][1], time[5][2], time[5][3]);
  Sleep(5000);

}