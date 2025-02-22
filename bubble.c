#include<stdio.h>
int bubblesort(float* salaries,int size);
int sortInsertion(float* salaries, int size);
void printSalaries(float* salaries, int size);
int main() {
	float salaries[] = {20.0f, 10.0f, 15.0f, 12.0f, 13.0f};
	int salariiesCount = 5;
	printf("Before Sort:\n");
	printSalaries(salaries, salariiesCount);
	sortInsertion(salaries, salariiesCount);
	printf("After Sort:\n");
	printSalaries(salaries, salariiesCount);
	return 0;
}
void printSalaries(float* salaries, int size) {
	for(int I = 0; I < size; I++) {
		printf("%.2f ", salaries[I]);
	}
	printf("\n");
}
void swap(float* first,float*second)
{
	float temp=(*first);
	(*first)=(*second);
	(*second)=temp;
}
int bubblesort(float* salaries,int size);
{
    int isswapped;
    do {
        isswapped=0;
        for(int=0;i<(size-1);i++)
        {
            if(salaries[i]>salaries[i+1])
            {
                swap(&salareies[i],&salaries[i+1]);
                isswapped=1;
            }
        }
        size--;
        while(isswapped);
}
}   //something is wrong run again
