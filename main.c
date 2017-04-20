#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag = -1;

void push(char ** stack, char * element){   // �������� � ����
    flag++;
    strcpy(stack[flag],element);
}
void pop(char ** stack){ // ������� ��������� ������� �����
    flag--;
}
int size_s(){ // ���������� ������ �����
    return flag;
}
int empty_s(){ //     ���������� 0 ,���� ���� ����
    if (flag == -1){//���������� 1 ,���� ���� �� ����
        return 0;
    }
    else{
        return 1;
    }
}
int main()
{
    char c,tag[80];
    int i;
    /*��������� ������ ��� ����*/
    char **stack;
    stack = (char**)malloc(100 * sizeof(char*));
        for (i = 0; i<100; i++){
                stack[i] = (char*)malloc(80 * sizeof(char));
        }
     /**/
    while ((c = getchar()) != EOF ){

        if (c == '<') {
                        scanf("%79[^>]>",tag); //��������� ��� ����

                        if (strcmp(tag,"hr") && strcmp(tag,"br")){

                                if (tag[0] != '/'){ // ���� ��� - ������������� : ������� � ����
                                                    push(stack,tag);
                                                    }
            else{
                    if (empty_s() == 0){    // ���� ���� ����, �� ���� ������������  ��� �� ��� ������, �� �����
                                printf("wrong");
                                return 0;
                                    }
                                else{
                                        if (strcmp(stack[flag],tag+1) != 0){  // ���� �������������, �� ����� ����� ��� �������� ��������������
                                                    printf("wrong");
                                                    return 0;
                                                                        }
                                                                        else{   // ���� ���� ���������
                                                                            pop(stack);
                                                                            }
                                        }
                }
                                                                    }
                    }
                                        }
    if (empty_s() == 0){ // ���� ���� ����, �� �������� �������
        printf("correct");
    }
    else{
       printf("wrong");
    }
}
