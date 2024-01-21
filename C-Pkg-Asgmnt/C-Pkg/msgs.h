#include <stdio.h>
#include <stdlib.h>

//Start game message
#define WELCOME "Welcome to the Epic Treasure Hunt!\n"
#define MSG1 "You find yourself at the entrance of a mysterious island cave.\n"\
              "What's your first move?\n"

//Main menu options
#define MAINMENU "\nOptions:\n1. Enter the cave.\n"\
                  "2. Decide to leave.\nEnter your choice (1 or 2): "

#define SUMMARYFILE "game_summary.txt"

#define FILEOPEN_ERROR  "Error opening the summary file.\n"

#define SUMMARYHDR "Game Summary:\n"

//Main case 1 options
#define MSG2 "\nYou step into the cave, revealing a network of tunnels.\n"
#define ENTEREDCAVE_MSG "Entered the cave.\n"
#define OPTION1_MENU "Options:\n3. Left path: A dark corridor.\n"\
                      "4. Right path: An underground river.\n"\
                      "5. Climb up: A hidden chamber.\n"\
                      " 6. Descend: A deep chasm.\nChoose (3, 4, 5, 6): "

#define CASE3MSG "\nThe left path leads to a dark corridor with ancient markings.\n"

#define CASE4MSG "\nVentured right to find an underground river shimmering with mystery.\n"

#define CASE5MSG "\nClimbing up, you discover a hidden chamber with glimmering treasure!\n"

#define CASE6MSG "\nDescending into a deep chasm, you encounter a challenge.\n"
#define OPTION_CASE6 "Options:\n"\
                      "7. Attempt to jump across.\n"\
                      "8. Return and explore another path.\n"\
                       "Choose (7 or 8): "

#define CASE7MSG "\nYou bravely attempt to jump across and succeed! A hidden chamber awaits\n"
#define CASE8MSG "\nDecided not to risk jumping and returned to explore another path.\n"


//Main case 2 options
#define THANKS "\nYou decided not to enter the cave. Thanks for playing!\n"
#define INVALIDCHOICE "\nInvalid choice. Please enter a valid option.\n"