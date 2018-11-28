/* phase2 of stocktaking
   compare the computer generated list with the accession register
   add accession numbers to the computer generated list if necessary
   make a separate file of accession numbers missing from comp_list
   This file is called in_accession_not_in_comp.txt
*/

#include<stdio.h>
#include<stdlib.h>

int digits(int n)
{
 int i=0;

 if(n==0)
  return 1;

 while(n!=0)
  {
   n/=10;
   i++;
  }

 return i;
}

/////////////////////////////////////////////////////

main()
{
 FILE *f1,*f2,*f3,*f4;
 int i,j,k,flag,n,b,num=0,*a;
 char ch;

 f1=fopen("comp_list.txt","r+");
 f2=fopen("accession.txt","r");
 f4=fopen("in_accession_not_in_comp.txt","w");
 f3=fopen("new.txt","w+");

 while(fscanf(f2,"%d",&i)!=EOF)
  {
    while(1)
     {
      fscanf(f2,"%c",&ch);

      if((int)ch == 10)
       break;
     }

     fseek(f2,-1,SEEK_CUR);

    flag=1;

   rewind(f1);

   while(fscanf(f1,"%d",&j)!=EOF)
    {     
     if(i==j)
      {
       flag=0;
       break;
      }
    }

    if(flag==1)
     {
      fseek(f1,0,SEEK_END);     
      fprintf(f1,"%d\n",i);
      fprintf(f4,"%d\n",i);
     }
  }
 
 rewind(f1);

 while(fscanf(f1,"%d",&i)!=EOF)
  {
   num++;
  }

 rewind(f1);
 a=calloc(num,sizeof(int));
 num=0;

 while(fscanf(f1,"%d",&i)!=EOF)
  {
   a[num]=i;
   num++;
  }

 for(i=0;i<num;i++)
  {
   b=a[i]; 
   k=i;

   for(j=i+1;j<num;j++)
    {
     if(b>a[j])
      {
       b=a[j];
       k=j;
      }
    }

   a[k]=a[i];
   a[i]=b;
  }
   
 for(i=0;i<num;i++)
  {
   fprintf(f3,"%d\n",a[i]);
  }

 fclose(f1);
 fclose(f2);
 fclose(f3);
 fclose(f4);

 remove("comp_list.txt");
 rename("new.txt","comp_list.txt");

}  
