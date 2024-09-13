#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
      int i,j,k=0;
      int count=0;
      int part_a_answer=0;
      int part_b_answer=0;
      char buf[255];
            
    printf("Advent 2022 - Day xx\n\n");

    // Read in the initial dataset 
    FILE *pFile;
    pFile = fopen ("input.txt", "r");
    if (pFile == NULL)
    {
      printf ("error opening file");
      return 0;
    }

    while (fgets(buf, sizeof(buf),pFile) != NULL)
    //while (fscanf(pFile,"%d ", &input_calories) != EOF)
    {
        
        count++;
        
    }

   
    // ========================================================
    // FINAL ANSWERS
    // ========================================================
    part_a_answer = 0;
    part_b_answer = 0;
    printf("\nAnswer to part A is =:%d\n",part_a_answer);
    printf("\nAnswer to part B is =:%d\n",part_b_answer);
    return 0;

}
