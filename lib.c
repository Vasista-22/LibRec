/* phase1 of stock taking.
   compare computer generated list of accession numbers with the withdrawn
   list and remove duplicates from the computer generated list and then
   compare accession list and withdrawn list and remove from accession list
*/

#include<stdio.h>

main()
{
 FILE *f1,*f2,*f3;
 
 int i,j,flag;
 char ch;

 f1=fopen("comp_list.txt","r");
 f2=fopen("withdrawn.txt","r");

 f3=fopen("new.txt","w");

 system("clear");

 while(fscanf(f1,"%d",&i)!=EOF)
  {
     while(1)
      {
       fscanf(f1,"%c",&ch);

       if((int)ch == 10)
        break;
      }

      fseek(f1,-1,SEEK_CUR);
      flag=1;
      rewind(f2);   

      while(fscanf(f2,"%d",&j)!=EOF)
       {   
         while(1)
          {
           fscanf(f2,"%c",&ch);

           if((int)ch == 10)
            break;
          }

          fseek(f2,-1,SEEK_CUR);
         
          if(i==j)
           {
            flag=0;
            break;
           }
       }

        if(flag==1)
         fprintf(f3,"%d\n",i);
  }

 fclose(f1);
 fclose(f2);
 fclose(f3);

 remove("comp_list.txt");
 rename("new.txt","comp_list.txt");

 f1=fopen("accession.txt","r");
 f2=fopen("withdrawn.txt","r");

 f3=fopen("new.txt","w");

 system("clear");

 while(fscanf(f1,"%d",&i)!=EOF)
  {
     while(1)
      {
       fscanf(f1,"%c",&ch);

       if((int)ch == 10)
        break;
      }

      fseek(f1,-1,SEEK_CUR);
      flag=1;
      rewind(f2);

      while(fscanf(f2,"%d",&j)!=EOF)
       {
         while(1)
          {
           fscanf(f2,"%c",&ch);

           if((int)ch == 10)
            break;
          }

          fseek(f2,-1,SEEK_CUR);

          if(i==j)
           {
            flag=0;
            break;
           }
       }

        if(flag==1)
         fprintf(f3,"%d\n",i);
  }

 fclose(f1);
 fclose(f2);
 fclose(f3);

 remove("accession.txt");
 rename("new.txt","accession.txt");

}
      

