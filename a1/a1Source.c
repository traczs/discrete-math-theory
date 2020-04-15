//binary subset sum calculator
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int n;
int k;
int m;
int num1s = 0;
int counter = 0;
void listBinary(int t, int BinaryArr[]);
FILE *f;



int main(int argc, char* argv[])
{
    printf("Please input length (n): ");
    scanf("%d", &n);
    printf("Please input number of 1s (k):");
    scanf("%d", &k);
    printf("PLease input sum of subset  (m):");
    scanf("%d", &m);
    //printf("You entered: %d\n", n);
	
	f = fopen("output.txt", "a");
	int BinaryArr[n];
	listBinary(0, BinaryArr);
	printf("Total count = %d\n", counter);
	return 0;
}

void listBinary(int t, int BinaryArr[])
{
	//if num1s is above the number of 1s youre looking for 
	if(num1s > k)
		return;
	//if number of 0s is too much
	if(t-num1s > n-k)
		return;
	if(t>=n)
	{
		int count = 0;
		for(int i = 0; i<n; i++)
		{
			if(BinaryArr[i]==1)
			{
				count = count+i+1;
			}
		}
		
		if(count==m)
		{
			//print (bn1..bn)
			for(int i = 0; i< n; i++)
			{
				fprintf(f,"%d",BinaryArr[i]);
			}
			fprintf(f,"\n");
			counter++;
		}
		
	}
	else
	{
		BinaryArr[t] =  0;
		listBinary(t+1, BinaryArr);
		BinaryArr[t] = 1;
		num1s++;
		listBinary(t+1, BinaryArr);
		num1s--;
	}
}
	
