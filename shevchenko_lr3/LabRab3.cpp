#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // ���������� ��� ����������� ������� ������� ��������



int main()
{
	int outcounter, arrcounter = 4, stringcounter1 = 0, stringcounter2 = 0; // ������������� ����������
	char* arr;
	char buf;
	arr = (char*)malloc(arrcounter * sizeof(char)); // ������������ ������
	do {
		buf = getchar();
		if ((arr[k - 4] == '.') || (arr[k - 4] == ';')) {
			if (buf == ' ') { continue; }
		}												  // ����������� ����������� ������� �� stdin � �������� ����������
		if ((buf == '.') || (buf == ';') || (buf == '?')) // 17 - 35 ������: ������ ������� � �������� ����������
		{												  // ����� ���� �������� �� �������������� �������� ������
			stringcounter1++;							  // ���-�� ���������� �������� (����������) ����� ����������������� ������� ������
		}												  // ���� ������ ������������� ���� ���������, ���������� ���������� ������� �� ������ �������
		if ((buf == '\t') || (buf == '\n')) { continue; } // ����� ���������� �������� � ������ ������� �� �������� ���������� (buf)
		if (buf == '?') {								  // ���� ����������� ��� ���������� ���������������� �����
			while (arrcounter >= 4) {
				if ((arr[arrcounter - 4] == '.') || (arr[arrcounter - 4] == ';')) { break; }
				arrcounter--;
			} continue;
		}
		arrcounter++;
		arr = (char*)realloc(arr, arrcounter * sizeof(char));
		arr[arrcounter - 4] = buf;
	} while (buf != '!');
	for (outcounter = 1; outcounter < arrcounter - 21; outcounter++)
	{
		printf("%c", arr[outcounter]);								// ����� ������� �� stdout
		if ((arr[outcounter] == '.') || (arr[outcounter] == ';')) {	// ������������ �������� �������� ������ � ����� ��������
			printf("\n");
			stringcounter2++;										// ������� ����� ����� �������������� ������
		}
	}
	setlocale(LC_ALL, "rus");										// ����������� �������� ����� � �������� ������� ��������
	printf("���������� ����������� �� %d � ���������� ����������� ����� %d\n", stringcounter1, stringcounter2);
	return 0;
}

