#include <stdio.h>
#include <conio.h>


using namespace std;

int main()
{
	char buf;
	char space;
	char current;
	char name[100];
	char text[1000]; //� ������� ��� ���������� �� ����� � ����� ������������ realloc, �� � ���� ������ ��� �������
	int k = 0;
	while (text[k] != 'k')
	{
		scanf("%c", &current);
		if (((buf = !'!') || (buf = !'.')) && (current == ' '))
		{
			scanf("%c", &current);
			
			if ((current >= 'A') && (current <= 'Z'))
			{
				int i = 0;
				while (current != ' ')
				{

					scanf("%c", &name[i]);
					k++;
					i++;
				}
				for (i; i != 0; i--)
				{
					text[k] = name[i];
				}
			}
			buf = current;
			continue;
		}
		text[k] = current;
		k++;
		buf = current;
	}
	for (int i = 0; i < k; i++)
	{
		printf("%�", name[i]);
	}
	return 0;
}