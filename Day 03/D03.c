#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
      int i,j,k=0;
      int count=0;
      int elf_count=0;
      int part_a_answer=0;
      int part_b_answer=0;
      char buf[255];
      char buf_1[255];
      int buf_1_count=0;
      char buf_2[255];
      int buf_2_count=0;
      char buf_3[255];
      int buf_3_count=0;
      int RS_length=0;
      int RS_comp_length=0;
      char comp1[40];
      char comp2[40];
      int total_priority_a=0;
      int total_priority_b=0;
      int priority=0;
      char *ptr;
      char dup[2];
            
    printf("Advent 2022 - Day 03\n\n");

    // Read in the initial dataset 
    FILE *pFile;
    pFile = fopen ("input_full.txt", "r");
    if (pFile == NULL)
    {
      printf ("error opening file");
      return 0;
    }

    //while (fgets(buf, sizeof(buf),pFile) != NULL)
    while (fscanf(pFile,"%s", &buf) != EOF)
    {
        count++;
        RS_length = strlen(buf);
        dup[0]=' ';
        dup[1]=' ';
        //printf("RS #%d is %d items total\n",count,RS_length);
        RS_comp_length = RS_length / 2;

        for (i=0;i<RS_length;i++)
        {
            if (elf_count == 0)
            {
              buf_1[i] = buf[i];
              buf_1_count = RS_length;
            } else if (elf_count ==1)
            {
              buf_2[i] = buf[i];
              buf_2_count = RS_length;
            } else
            {
              buf_3[i] = buf[i];
              buf_3_count = RS_length;
            } 
            
        }
        
        for (i=0;i<RS_comp_length;i++)
        {
            comp1[i] = buf[i];
            comp2[i] = buf[i+RS_comp_length];
        }

        for (i=0;i<RS_comp_length;i++)
        {
          for (j=0;j<RS_comp_length; j++)
          {
              if ( (comp1[i] == comp2[j]) && (comp1[i] != dup[0]) )
              { 
                //printf("Row %d\t found <%c> in both parts.\t Priority=%d\n", count, comp1[i], priority);
                //printf("DEBUG: ASCII value =%d\n",comp1[i]);
                dup[0] = comp1[i];
                if ((int)comp1[i] < 97)
                {
                  priority = (int)comp1[i] - 38;
                  total_priority_a = total_priority_a + (int)comp1[i] - 38;
                }
                else
                {
                  priority = (int)comp1[i] - 96;
                  total_priority_a = total_priority_a + (int)comp1[i] - 96;
                }
                printf("Row %d\t - Length = %d. Found <%c> in both parts.\t Priority=%d\n",  count, RS_length, comp1[i], priority);
                i=99;
                break; 
              }
              else
              {
                if ( (i==(RS_comp_length-1)) && ( j == (RS_comp_length-1) ) ) 
                {
                  //printf(" ERROR - not found\n");
                }
              }
          }
        }


        // Process part 2 of the problem.
       if (elf_count == 2)
       {
            for (i=0;i<buf_1_count;i++)
            {
              for (j=0;j<buf_2_count; j++)
              {
                  if (buf_1[i] == buf_2[j])
                  {
                      for (k=0;k< buf_3_count;k++)
                      {
                          if ( (buf_1[i] == buf_3[k]) &&  (comp1[i] != dup[1]) )
                          {
                              dup[1] = buf_1[i];
                              if ((int)buf_1[i] < 97)
                                {
                                  priority = (int)buf_1[i] - 38;
                                  total_priority_b = total_priority_b + (int)buf_1[i] - 38;
                                }
                                else
                                {
                                  priority = (int)buf_1[i] - 96;
                                  total_priority_b = total_priority_b + (int)buf_1[i] - 96;
                                }
                                printf("P2:  Row %d\t -Found <%c> in both parts.\t Priority=%d\n",  count, buf_1[i], priority);
                                i=99;
                                k=99;
                                 break; 
                          }
                      }
                  }

              }
            }
       } 

                
        elf_count++;
        if (elf_count ==3)
        {
          elf_count = 0;
        }

    }

   
    // ========================================================
    // FINAL ANSWERS
    // ========================================================
    part_a_answer = total_priority_a;
    part_b_answer = total_priority_b;
    printf("\nAnswer to part A is =:%d\n",part_a_answer);
    printf("\nAnswer to part B is =:%d\n",part_b_answer);
    return 0;

}
