#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
      int i,j,k=0;
      int elf_total=0;
      int elf_count=0;
      int max_total=0;
      int max_total_1=0;
      int max_total_2=0;
      int max_total_3=0;
      int part_a_answer=0;
      int part_b_answer=0;
      int input_calories=0;
      char buf[255];
            
    printf("Advent 2022 - Day 01\n\n");

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
        elf_count++;
        if(atoi(buf) == 0)
        {
            printf("Total for Elf # %d\t = %d\n",elf_count, elf_total);
            if (elf_total > max_total)
            {
                max_total = elf_total;
                printf(" New Leader\n\n");
            }
            if (elf_total > max_total_1)
            {
                max_total_3 = max_total_2;
                max_total_2 = max_total_1;
                max_total_1 = elf_total;
            } else if (elf_total> max_total_2)
            {
              max_total_3 = max_total_2;
              max_total_2 = elf_total;
            } else if (elf_total > max_total_3)
            {
                max_total_3 = elf_total;
            }
            elf_total=0;
        }
        else
        {
            elf_total = elf_total + atoi(buf);
        }
    }

    // sum up the last ELF
    elf_count++;
    printf("Total for Elf # %d\t = %d\n",elf_count, elf_total);
    if (elf_total > max_total)
    {
        max_total = elf_total;
        printf("** New Leader\n\n");
    }
    if (elf_total > max_total_1)
    {
        max_total_3 = max_total_2;
        max_total_2 = max_total_1;
        max_total_1 = elf_total;
    } else if (elf_total> max_total_2)
    {
        max_total_3 = max_total_2;
        max_total_2 = elf_total;
    } else if (elf_total > max_total_3)
    {
        max_total_3 = elf_total;
    }



    // ========================================================
    // FINAL ANSWERS
    // ========================================================
    part_a_answer = max_total;
    part_b_answer = max_total_1+max_total_2+max_total_3;
    printf("\nAnswer to part A is =:%d\n",part_a_answer);
    printf("\nAnswer to part B is =:%d\n",part_b_answer);
    return 0;
}

