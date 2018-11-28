
#include<stdio.h>
#include<time.h>

main()
{
 FILE *f1;

 int i=1,n,j;

 system("clear");

 printf("how many numbers? : ");
 scanf("%d",&n);

 /*f1=fopen("comp_list.txt","w");
 
 while(i<=n)
  {
   fprintf(f1,"%d\n",i);
   i++;
  }

 fclose(f1);

 f1=fopen("withdrawn.txt","w");

 i=2;
 while(i<=n)
  {
   fprintf(f1,"%d\n",i);
   i+=2;
  }

 fclose(f1);
*/
 f1=fopen("accession.txt","w");

 i=1;

 while(i<=40521)
  {
   fprintf(f1,"%d\n",i);
   i++;
  }

 fclose(f1);

 /*f1=fopen("physical.txt","w");

 i=1;

 while(i<=2*n)
  {
   j=random()%10;
 
   fprintf(f1,"%d\n",j);
   i++;
  }

 fclose(f1);
*/

} 
