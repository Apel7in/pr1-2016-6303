#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) 
{
     return *(int*)a - *(int*)b;
 }

 int main() {
    int i, j;
    int N=1000;
    int arr1[N], arr2[N];
    //��� ������� arr1  ����� ������������ �����  bubble sort, ��� arr2 - ������� qsort
    double timebsort, timeqsort;
    //�������� ��� ������ double  ����� ������� ����� � ����� ������ 
    for(i = 0 ; i < N; i++) 
    { 
        scanf("%d", &arr1[i]);
    }
    //��������� �������� ������� arr1
     for(i = 0 ; i < N; i++) 
    { 
        arr2[i]=arr1[i];
    }
    //�������� ������ arr1 � ������� arr2
    
    timebsort = clock();
    //���������� � ���������� timebsort ����� �� ������ ���������� 
    for(i = 0 ; i < N - 1; i++) 
    { 
       // ���������� ��� �������� ��������.
       for(j = 0 ; j <N - i - 1 ; j++) 
       {  
           if(arr1[j] > arr1[j+1]) 
           {           
              // ���� ��� ���� � ������������ �������, �� ������ �� �������. 
              int tmp = arr1[j];
              arr1[j] = arr1[j+1] ;
              arr1[j+1] = tmp; 
           }
        }
    }
     timebsort = (clock()-timebsort)/CLOCKS_PER_SEC;
     //�������� �� �������� ������� ����� �� time1, ��������� ��� � �������
     //�LOCKS_PER_SEC - ��������� ������� ������������ ���������� ������ ������������� ������� � �������
     
     timeqsort = clock();
     //���������� ������� ����� � ���������� timeqsort
      qsort(arr2, N, sizeof(int), cmp ); // �������� ������� ����������
       timeqsort = (clock()-timeqsort)/CLOCKS_PER_SEC;
       //�������� �� �������� ������� ����� �� timeqsort, ��������� ��� � �������
    for(i = 0 ; i < N; i++) 
    { 
    	//������� ��������������� ������
        printf("%d ", arr2[i]);
    }
         printf("\n%.5f seconds\n", timebsort);
         printf("%.5f seconds\n", timeqsort);
     
 }