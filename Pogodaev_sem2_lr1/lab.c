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

int SoAnCo(int* arr1, int n, int key);

int main() {
  int i;
  int key=0;//���� ��� ��������� ������
  int* arr1 =(int*)malloc(sizeof(int)*N);
	for(i=0;i<N;++i)
	{
		scanf("%d",&arr1[i]);
	}
    SoAnCo(arr1,i,0);
//    free(arr1);

}

int SoAnCo(int* arr1, int n, int key){
    qsort(arr1, N,sizeof(int),( int(*) (const void *, const void*)) comp);//���������� �������
    int time1 = clock();//����� ������ ��������� ������
    int* ptr = (int*)bsearch(&key, arr1, N, sizeof(int), ( int(*) (const void *, const void*)) funccmp);
    int time2 = clock();//����� ���������� ��������� ������
    if (ptr==NULL) {  //����� ���������� ��������� ������
    printf("doesn't exist\n");}
    else {
      printf("exists\n");}
    printf("%d\n",time2-time1);//����� ������� �������� ��������� ������
    int i;
    int time3 = clock();//����� ������ ��������
    while (i<N)
    {
        if (arr1[i]==key)
        {
            i=N-1;
        }
        i++;
    }
    int time4 = clock();//����� ���������� ��������
    if (ptr==NULL) {  //����� ���������� ��������
    printf("doesn't exist\n");}
    else {printf("exists\n");}
    printf("%d\n",time4-time3);//����� ������� ��������
}

