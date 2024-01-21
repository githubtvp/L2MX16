#include <stdio.h>
#include <stdlib.h>
#include "msgs.h"

#define pr(msg) printf(msg)

void startGame()
{
    pr(WELCOME);
    pr(MSG1);
}

void prToFile(FILE *aFilePtr, char *str)
{
    fprintf(aFilePtr, str);
}

void playGame()
{
    int choice;
    FILE *summaryFile = fopen(SUMMARYFILE, "w");
    if (summaryFile == NULL)
    {
        pr(FILEOPEN_ERROR);
        return;
    }
    prToFile(summaryFile, SUMMARYHDR);
    while (1)
    {
        pr(MAINMENU);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            pr(MSG2);
            pr(ENTEREDCAVE_MSG);
            pr(OPTION1_MENU);
            scanf("%d", &choice);

            switch (choice)
            {
            case 3:
                pr(CASE3MSG);
                prToFile(summaryFile, CASE3MSG);
                break;
            case 4:
                pr(CASE4MSG);
                prToFile(summaryFile, CASE4MSG);
                break;
            case 5:
                pr(CASE5MSG);
                prToFile(summaryFile, CASE5MSG);
                fclose(summaryFile);
                return;
            case 6:
                pr(CASE6MSG);
                prToFile(summaryFile, CASE6MSG);
                pr(OPTION_CASE6);
                scanf("%d", &choice);
                switch (choice)
                {
                case 7:
                    pr(CASE7MSG);
                    prToFile(summaryFile, CASE7MSG);
                    fclose(summaryFile);
                    return;
                case 8:
                    pr(CASE8MSG);
                    prToFile(summaryFile, CASE8MSG);
                    fclose(summaryFile);
                    break;
                default:
                    pr(INVALIDCHOICE);
                }
                break;
            default:
                pr(INVALIDCHOICE);
            }
            break;

        case 2:
            pr(THANKS);
            prToFile(summaryFile, THANKS);
            fclose(summaryFile);
            return;
        default:
            pr(INVALIDCHOICE);
        }
    }
}

int main()
{
    startGame();
    playGame();
    return 0;
}
