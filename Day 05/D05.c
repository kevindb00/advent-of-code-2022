#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define INPUT_ROW 36
#define MAX_COLS 9
#define MAX_ITEMS_PER_STACK 8

int main()
{
      int i,j,k=0;
      int ins_move_count, ins_from, ins_to =0;
      int end_of_headers=0;
      int count=0;
      int col_count;
      int part_a_answer=0;
      int part_b_answer=0;
      char buf[255];
      int input_char;
      char tmp_ch[2] = {0};
      char input_stack[MAX_COLS][MAX_ITEMS_PER_STACK*MAX_COLS];
      int input_col_count[MAX_COLS];
            
    printf("Advent 2022 - Day 052\n\n");
    // initialize the input stack
    for(i=0;i<MAX_COLS;i++)
    {
      input_col_count[i] = 0;
       for (j=0;j<MAX_ITEMS_PER_STACK;j++)
      {
        input_stack[i][j] = ' ';
      }
    }

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
        // check for end of first section
         end_of_headers = 1;
         col_count=0;
         for(i=1;i<MAX_COLS*4;i+=4)
        {
            tmp_ch[0] = buf[i];
            
            // if value is non blank and an alpha then load up the stack
            if (isalpha(buf[i]) )
            {
              //printf("found a stack entry to process\n");
                input_stack[col_count][count] = buf[i];
                input_col_count[col_count]++;
            }
                        
            if (atoi(tmp_ch) != col_count+1)
            {
              end_of_headers = 0;
            }              
            
            col_count++;


        } 
        if (end_of_headers == 1)
        {
          break;
        }
        //printf("input char: %s \n", buf);
        count++;

        
    }  

    // fix up the stack
    int offset = ((MAX_COLS*MAX_ITEMS_PER_STACK)-1) - count +1;
    for(i=0;i<MAX_COLS;i++)
    {
       for (j=0;j< count;j++)
      {
        int tmp_fx_to = ((MAX_COLS*MAX_ITEMS_PER_STACK)-1) - offset +j;
        //input_stack[i][tmp_fx_to] = input_stack[i][j];
        input_stack[i][j+offset] = input_stack[i][j];
      }
    }
    
    //Read blank line
    fgets(buf, sizeof(buf),pFile);
    
    //Read instruction set
    while (fscanf(pFile,"move %d from %d to %d ", &ins_move_count, &ins_from, &ins_to) != EOF)
    {
       printf("ins_count=%d, ins_from=%d, ins_to=%d \n", ins_move_count, ins_from, ins_to);
        // set the indexes properly
        ins_from--;
        ins_to--;

        int tmp_fr, tmp_to=0;
       for(i=0;i<ins_move_count;i++)
       {
        //formula for part a
        //tmp_to = ((MAX_COLS*MAX_ITEMS_PER_STACK)-1) - input_col_count[ins_to] -i;
        //tmp_fr = ((MAX_COLS*MAX_ITEMS_PER_STACK)-1) - input_col_count[ins_from] +i + 1;

        //formula for part b
        tmp_to = ((MAX_COLS*MAX_ITEMS_PER_STACK)-1) - input_col_count[ins_to] -ins_move_count +i +1;
        tmp_fr = ((MAX_COLS*MAX_ITEMS_PER_STACK)-1) - input_col_count[ins_from] +1 +i;
        input_stack[ins_to][tmp_to] =  input_stack[ins_from][tmp_fr];
        // clear out the origin
        input_stack[ins_from][tmp_fr] = ' ';
       } 
       input_col_count[ins_from] = input_col_count[ins_from] - ins_move_count;
       input_col_count[ins_to] = input_col_count[ins_to] + ins_move_count;
        
    } 

   
    // ========================================================
    // FINAL ANSWERS
    // ========================================================
    part_a_answer = 0;
    for(i=0;i< MAX_COLS;i++)
    {
      printf("%c",input_stack[i][((MAX_COLS*MAX_ITEMS_PER_STACK)-1) - input_col_count[i]+1]);
    }
    printf("\n");

    part_b_answer = 0;
    printf("\nAnswer to part A is =:%d\n",part_a_answer);
    printf("\nAnswer to part B is =:%d\n",part_b_answer);
    return 0;

}
