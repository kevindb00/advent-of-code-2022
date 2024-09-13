#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
      int i,j,k=0;
      int tot_contained =0;
      int tot_overlap=0;
      int count=0;
      int part_a_answer=0;
      int part_b_answer=0;
      char buf[255];
      char tmp;
      char* elf_1;
      char* elf_2;
      char* E1L, E1H; 
      char* E2L, E2H;
      int elf_1L=0;
      int elf_1H=0;
      int elf_2L=0;
      int elf_2H=0;
            
    printf("Advent 2022 - Day 04\n\n");

    // Read in the initial dataset 
    FILE *pFile;
    pFile = fopen ("input_full.txt", "r");
    if (pFile == NULL)
    {
      printf ("error opening file");
      return 0;
    }

    //while (fgets(buf, sizeof(buf),pFile) != NULL)
    while (fscanf(pFile,"%d-%d,%d-%d", &elf_1L, &elf_1H, &elf_2L, &elf_2H) != EOF)
    {

      printf("%d %d %d %d\n",elf_1L, elf_1H, elf_2L, elf_2H);
      /*
      printf("%s\n",buf);
      elf_1 = strtok(buf, ",");
      elf_2 = strtok(NULL, " \n\r");
      printf("Elf_1:\t%s\n",elf_1);
      printf("Elf_2:\t%s\n",elf_2);
      E1L = strtok(elf_1, "-");
      E2L = strtok(elf_2, "-");
      printf("\t\t--> E1L=%s\tE2L=%s\n",E1L,E2L);
      int tmp_E1L = atoi(E1L);
      int sum = atoi(E1L) + atoi(E2L);
      printf("sum=%d\n",sum);
      */

     if ( ( ( elf_1L <= elf_2L) && (elf_1H >= elf_2H) ) || ( ( elf_2L <= elf_1L) && (elf_2H >= elf_1H) ) )
     { 
      printf("Row:%d Completely covered\n", count+1);
      tot_contained++;
      tot_overlap++;
     } else if ( (( elf_1L <= elf_2L) && ( elf_2L <= elf_1H)) || (( elf_2L <= elf_1L) && ( elf_1L <= elf_2H)) )
     {
            printf("Row:%d Partially covered\n",count+1);
            tot_overlap ++;
     }


       
        count++;
        
    }

   
    // ========================================================
    // FINAL ANSWERS
    // ========================================================
    part_a_answer = tot_contained;
    part_b_answer = tot_overlap;
    printf("\nAnswer to part A is =:%d\n",part_a_answer);
    printf("\nAnswer to part B is =:%d\n",part_b_answer);
    return 0;

}
