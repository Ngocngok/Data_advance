#include <stdio.h>
#include <stdlib.h>

int main()
{
    int wordCount;

    scanf("%d\n", &wordCount);
    char c;
    int charCount = 0;
    
    char *wordList[100];

    for(int i = 0; i < wordCount; i++)
    {
        char word[101];
        char repWord[5];
        while(1)
        {
            if((c = getchar()) == '\n')
            {
                if(charCount > 9)
                {
                    repWord[0] = word[0];
                    repWord[3] = word[charCount-1];
                    repWord[1] = (charCount/10) + '0';
                    repWord[2] = (charCount%10) + '0';
                    repWord[4] = '\0';
                    wordList[i] = repWord;
                }

                else
                {
                    wordList[i] = word;
                }
                for(int i = 0; i < 100; i++)
                word[i] = '\0';

                charCount = 0;
                break;
            }

            else
            {
                word[charCount] = c;
                charCount++;
            }

        }
        

    }

    for(int j = 0; j < wordCount; j++)
    {
        puts(wordList[j]);
    }


    return 0;
}