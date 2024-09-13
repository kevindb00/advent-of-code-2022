#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIG_SIZE 14

int main()
{
      int i,j,k=0;
      int count=0;
      int part_a_answer=0;
      int part_b_answer=0;
      char buf[4096];
      char buf_saved_1;
      char buf_saved_2;
      char buf_saved_3;
      char buf_saved_4;
      
            
    printf("Advent 2022 - Day xx\n\n");

    // Read in the initial dataset 
    FILE *pFile;
    pFile = fopen ("input_full.txt", "r");
    if (pFile == NULL)
    {
      printf ("error opening file");
      return 0;
    }

    while (fgets(buf, sizeof(buf),pFile) != NULL)
    //while (fscanf(pFile,"%d ", &input_calories) != EOF)
    {
        int size=strlen(buf);
        printf("size=%d\n",size);
        printf("%s\n",buf);
        count++;

        buf_saved_1=buf[0];
        buf_saved_2= buf[1];
        buf_saved_3= buf[2];
        buf_saved_4= buf[3];

/*
        int sig_found = 0;
        for (i=3;i<size;i++)
        {
          if ( (buf[i] != buf_saved_1) && (buf[i] != buf_saved_2) && (buf[i] != buf_saved_3) &&
               (buf[i-1] != buf_saved_2) && (buf[i-1] != buf_saved_1) &&
                (buf[i-2] != buf_saved_1) )
          { 
            printf("Found the unique entry at ending position: %d\n", i+1);
            part_a_answer = i+1;
            break;
          }
        
        buf_saved_1= buf_saved_2;
        buf_saved_2= buf_saved_3;
        buf_saved_3= buf_saved_4;
        buf_saved_4= buf[i+1];
          

       }
*/


        for (i=(SIG_SIZE-1);i<size;i++)
        {
          int sig_found = 1;
          for(j=1;j<SIG_SIZE;j++)
          {
              for(k=0;k<SIG_SIZE-j;k++)
              {
                  int tmp1=i-j+1;
                  int tmp2=i-j-k;
                  if( buf[i-j+1] == buf[i-j-k])
                  {
                    sig_found = 0;
                    break;
                  }
              } 
          } 
          
          if ( sig_found == 1 )
          { 
            printf("Found the unique entry at ending position: %d\n", i+1);
            part_a_answer = i+1;
            break;
          }
        
    

       }
        

       
    }

   
    // ========================================================
    // FINAL ANSWERS
    // ========================================================
    //part_a_answer = 0;
    //part_b_answer = 0;
    printf("\nAnswer to part A is =:%d\n",part_a_answer);
    printf("\nAnswer to part B is =:%d\n",part_b_answer);
    return 0;

}
