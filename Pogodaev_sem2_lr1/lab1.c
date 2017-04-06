#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

int funccmp( const void *x1, const void *x2){ //������� ��������� ���� ��-���
return (*(int*)x1 - *(int*)x2);
}

int comp (const int *a, const int *b)//���������� ��� qsort
{
return *a - *b;
}



int main() {
  int i;
  int timeBeg1, timeBeg2, timeEnd1, timeEnd2;
  int key=0;//���� ��� ��������� ������
  int* arr=(int*)malloc(sizeof(int)*N);
  for (i=0;i<N;i++)//���������� ������� �������
    {
     scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int),(int(*)(const void *,const void *))comp); //���������� ������� ����� �������� ������� ����������
    timeBeg1 = clock(); //����� ������ ������
    int *ptrItem=(int*) bsearch( &key, arr, 100, sizeof(int), funccmp);
    timeEnd1 = clock(); //����� ����� ������

    if (ptrItem==NULL) {  //����� ���������� ��������� ������
    printf("doesn't exist\n");}
    else {
      printf("exists\n");}

    printf("%d\n",timeEnd1-timeBeg1);//����� ������� ��������� ������

    int l = 0; //����� 0 ���������
    timeBeg2 = clock();
    for (i=0;i<N;i++)
    {
        if (arr[i]==key)
        {
            l=1;
        }
    }
    timeEnd2 = clock();

    if (l==1)//����� ���������� ������ ���������
    {
        printf("exists\n");
    }
    else
    {
        printf("doesn't exists\n");
    }
    printf("%d\n",timeEnd2-timeBeg2);//����� ������� ������ ���������
free(arr);
  return 0;
}
