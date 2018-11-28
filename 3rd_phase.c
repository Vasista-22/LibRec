/*
   removes duplicates from physically written list.
   creates a file which has the accession numbers which are present in
   comp_list.txt but not present in accession.txt
   creates a file which has the accession numbers which are present in
   accession.txt but not present in comp_list.txt
*/
   
#include<stdio.h>
#include<stdlib.h>

main()
{
 FILE *f1,*f2,*f3,*f4;
 int i,j,num,*a,flag;
 char ch;

 f1=fopen("physical.txt","r");
 f3=fopen("new.txt","w");

 num=0;

 while(fscanf(f1,"%d",&i)!=EOF)
  {
   num++;
  }

 rewind(f1);
 a=calloc(num,sizeof(int));
 j=0;

 while(fscanf(f1,"%d",&i)!=EOF)
  {
   while(1)
    {
     fscanf(f1,"%c",&ch);

     if((int)ch == 10)
      break;
    }
 
   fseek(f1,-1,SEEK_CUR);

   a[j]=i;
   j++;
  }

 for(i=0;i<num;i++)
  {
   flag=1;
   for(j=i+1;j<num;j++)
    {
     if(a[i]==a[j])
      {
       flag=0;
       break;
      }
    }

   if(flag==1)
    fprintf(f3,"%d\n",a[i]);
  }     

 fclose(f1);
 fclose(f3);

 remove("physical.txt");
 rename("new.txt","physical.txt");

 f1=fopen("physical.txt","r");
 f2=fopen("comp_list.txt","r");
 f3=fopen("missing_from_physically_written_list.txt","w");
 f4=fopen("missing_from_comp_list.txt","w");
 
 while(fscanf(f2,"%d",&i)!=EOF)
  {
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
     fprintf(f3,"%d\n",i);
    }
  }

 rewind(f1);
 
 while(fscanf(f1,"%d",&i)!=EOF)
  {
    flag=1;
    rewind(f2);

   while(fscanf(f2,"%d",&j)!=EOF)
    {
     if(i==j)
      {
       flag=0;
       break;
      }
    }

   if(flag==1)
    {
     fprintf(f4,"%d\n",i);
    }
  }

 fclose(f1);
 fclose(f2);
 fclose(f3);

} 
