#include<stdio.h>
#include<stdlib.h>
int compar(void*pa,void*pb)
{
	int a= *((int*)pa);
	int b= *((int*)pb);
	int ret = 0;
	if(a<b)
		ret =-1;
		else if (a>b)
				ret =1;
	return ret;

}
int main(void)
{
	int myarr[]= {2,23,298,110.1190,38,400,20,2};
	size_t L= sizeof(myarr)/sizeof(int);
printf("unsorted array is\n");
	for(int i=0;i<L;i++)
		printf(" %d\t",myarr[i]);
	qsort((void*)myarr,L,sizeof(int),compar);
	printf("\n");
	printf("sorted array is\n");
	for(int j=0; j<L; j++)
		printf(" %d \t", myarr[j]);

	return 0;



}
