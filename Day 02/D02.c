#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
      int i,j,k=0;
      int count=0;
      int part_a_answer=0;
      int part_b_answer=0;
      char opp_play;
      char opp_plan;
      char your_play;
      char your_outcome;
      char buf[255];
      int round_score=0;
      int total_score=0;
            
    printf("Advent 2022 - Day 01a\n\n");

    // Read in the initial dataset 
    FILE *pFile;
    pFile = fopen ("input_full.txt", "r");
    if (pFile == NULL)
    {
      printf ("error opening file");
      return 0;
    }

    //while (fgets(buf, sizeof(buf),pFile) != NULL)
    while (fscanf(pFile,"%c %c ", &opp_play, &your_play) != EOF)
    {
        printf("Opponents play=%c\t Your play = %c\n",opp_play, your_play);
         count++;
         round_score = 0;

        if (opp_play =='A' && your_play == 'X' ||
            opp_play == 'B' && your_play == 'Y' ||
            opp_play == 'C' && your_play == 'Z')
        {
          printf("Tie\n");
          round_score = 3;
        } else if (opp_play =='A' && your_play == 'Y' ||
                  opp_play == 'B' && your_play == 'Z' ||
                  opp_play == 'C' && your_play == 'X')
        {
          round_score = 6; 
        } else 
        {
          round_score =  0;
        }


        if (your_play == 'X')
        {
          round_score = round_score + 1;
        } else if (your_play =='Y')
        {
          round_score = round_score + 2;
        }
        else
        { 
          round_score = round_score + 3;
        }

        total_score = total_score+ round_score;
    }
    part_a_answer = total_score;
  fclose(pFile);

    printf("Advent 2022 - Day 01b\n\n");
    // Read in the initial dataset 
    FILE *zFile;
    zFile = fopen ("input_full.txt", "r");
    if (zFile == NULL)
    {
      printf ("error opening file");
      return 0;
    }

    //while (fgets(buf, sizeof(buf),pFile) != NULL)
    total_score =0;
    while (fscanf(zFile,"%c %c ", &opp_plan, &your_outcome) != EOF)
    {
        printf("Opponents play=%c\t Your play = %c\n",opp_plan, your_outcome);
         count++;
         round_score = 0;

        switch (your_outcome)
        {
          case 'X':
          printf("Loss\n");
          round_score = 0;
            if (round_score == 0)
            {
              printf("debug");
            }
            if (opp_plan == 'A')
            {
              your_play = 'Z';
            }  else if ( opp_plan == 'B')
            {
              your_play = 'X';
            } else if  ( opp_plan == 'C')
            {
              your_play = 'Y';
            }
            break;


          case 'Y':
          round_score = 3; 
          if (opp_plan == 'A')
            {
              your_play = 'X';
            }  else if ( opp_plan == 'B')
            {
              your_play = 'Y';
            } else
            {
              your_play = 'Z';
            }
            break;
        
         
          case 'Z':
          round_score =  6;
            if (opp_plan =='A')
            {
              your_play = 'Y';
            }  else if ( opp_plan == 'B')
            {
              your_play = 'Z';
            } else
            {
              your_play = 'X';
            }
            break;
        }

        if (your_play == 'X')
        {
          round_score = round_score + 1;
        } else if (your_play =='Y')
        {
          round_score = round_score + 2;
        }
        else
        { 
          round_score = round_score + 3;
        }

        total_score = total_score+ round_score;
    }
    part_b_answer = total_score;



    // ========================================================
    // FINAL ANSWERS
    // ========================================================
    printf("\nAnswer to part A is =:%d\n",part_a_answer);
    printf("\nAnswer to part B is =:%d\n",part_b_answer);
    return 0;
}

