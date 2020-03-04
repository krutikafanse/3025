#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct person_s
{
char lastname[30];
char firstname[30];
char city[30];
};
typedef struct person_s person_t ;
person_t dbasepeople[100];
int compar(void *pa, void *pb)
{
return strcmp(((person_t *)pa)->lastname, ((person_t *)pb)->lastname);
}
int main(void)
{

FILE *fp;
fp= fopen("names.txt","r");
if(fp==NULL){
printf("file doesn't exist");
return 1;}
else
printf("file exists");
char str1[30], str2[30],str3[30];
int ctr=0;
while(fscanf(fp," %s %s %s", str1,str2,str3)!=EOF)
{
strcpy(dbasepeople[ctr].firstname,str1);
strcpy(dbasepeople[ctr].lastname,str2);
strcpy(dbasepeople[ctr].city,str3);
++ctr;
}
printf("unsorted list \n");
for(int j=0;j<ctr;j++)
printf("%s %s %s\n",dbasepeople[j].firstname,dbasepeople[j].lastname,dbasepeople[j].city);
qsort(dbasepeople,ctr,sizeof(person_t),compar);
printf("sorted list \n");
for(int j=0; j<ctr;j++)
printf("%s %s %s\n",dbasepeople[j].firstname,dbasepeople[j].lastname,dbasepeople[j].city);
fclose(fp);
return 0;
}
