#include <stdio.h>
#include <string.h>

typedef struct Data_character
{
	char character[1000];
	int frequency;
}Creat;
void Print(int N_repeated,Creat *ArrayFrequency)
{
	int i;
	for (i = 0;i < N_repeated;i++)
	{
		printf("%c %d\n",ArrayFrequency[i].character[i],ArrayFrequency[i].frequency);
	}
}
int  Comparison(int index,int i,int j,int count,int size,char string[],Creat ArrayFrequency[])
{
    if (i == size || index == size)
    {
        return j;
    }
    else
    {
        if (string[i] == string[index])
        {
            count++;
            ++i;
        }
        if (string[i] != string[index])
        {
        ArrayFrequency[j].character[j] = string[index];
        ArrayFrequency[j].frequency = count;
        ++j;
        count = 0;
        index = i;
        }
    }
     Comparison(index,i,j,count,size,string,ArrayFrequency);
}
void Bubble_sort(int i,int size,char *string)
{
if (i < size - 1)
{
if (string[i] > string[i + 1])
{
char aux            = string[i];
string[i]           = string[i + 1];
string[i + 1]       = aux;
}
Bubble_sort(++i,size,string);
}
else if (size > 1)
{
Bubble_sort(0,size - 1,string);
}
}
int main() 
{
    Creat ArrayFrequency[255];
	char string[255];
    int size,N_repeated;
    scanf("%[^\n]",string);
    size = strlen(string);
	Bubble_sort(0,size,string);
    N_repeated = Comparison(0,0,0,0,size,string,ArrayFrequency);
	Print(N_repeated,ArrayFrequency);
}
