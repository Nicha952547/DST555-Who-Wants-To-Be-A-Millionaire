#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h> 

void setConsoleColor(int color) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
  char *compliments[] = {
    "A good beginning makes a good ending",
    "Choose to shine",
    "Try to be the best version of yourself",
    "The First to forget is the happiest",
    "It is bad day, not a bad life"
  };

  srand(time(NULL));
  char name[100];
  int menu, number, number2, a, Again;
  int index = rand() % (sizeof(compliments) / sizeof(compliments[0]));

  do {
    setConsoleColor(6);
    printf("--- Welcome to DST555 ---\n");
    setConsoleColor(3);
    printf("Game Mode\n");
    
    // Menu Selection Loop
    do {
      printf("Number Guessing(1) Number Hight-Low(2)\n");
      scanf("%d", &menu);
      if (menu < 1 || menu > 2) {
        setConsoleColor(12);
        printf("Mai Took! Just 1 or 2.\n");
        setConsoleColor(3);
      }
    } while (menu < 1 || menu > 2);

    // --- Game Mode 1: Number Guessing ---
    if (menu == 1) {
      setConsoleColor(6);
      printf("Kai Yak Pen Sed Thi? \n");
      setConsoleColor(15);
      
      // Name Input Loop (No space check)
      do {
        setConsoleColor(15);
        printf("Enter your name (don't press space bar*): ");
        // **Note:** The scanf below is for string input and uses a common technique for name input in C.
        scanf("%99[^\n]", name);
        if (strchr(name, ' ') != NULL) {
          setConsoleColor(12);
          printf("You pressed the space bar! Please don't press the space bar.\n");
          setConsoleColor(15);
        }
      } while (strchr(name, ' ') != NULL);

      // Lucky Number Input Loop (1-99 check)
      do {
        setConsoleColor(14);
        printf("%s, Tell me what is your lucky number 1-99\n", name);
        scanf("%d", &number);
        if (number < 1 || number > 99) {
          setConsoleColor(12);
          printf("Please enter a number between 1 and 99.\n");
          setConsoleColor(14);
        }
      } while (number < 1 || number > 99);

      // Game Logic
      int randomNumber = rand() % 99 + 1;
      setConsoleColor(6);
      printf("The Number is: %d\n", randomNumber);
      if (number == randomNumber) {
        setConsoleColor(2);
        printf("WOW! You Won!\n");
      } else {
        setConsoleColor(3);
        printf("%s\n", compliments[index]);
        setConsoleColor(10);
        printf("Try Again\n");
      }
    } 
    
    // --- Game Mode 2: High-Low ---
    else if (menu == 2) {
      setConsoleColor(8);
      printf("--- R u l e ---\nif your number > computer random = high\nif your number < computer random = low\n");
      setConsoleColor(11);
      
      // Lucky Number Input Loop (1-99 check)
      do {
        printf("Give me your lucky number 1-99\n");
        scanf("%d", &number2);
        if (number2 < 1 || number2 > 99) {
          setConsoleColor(12);
          printf("Please enter a number between 1 and 99.\n");
          setConsoleColor(11);
        }
      } while (number2 < 1 || number2 > 99);

      // High/Low Guess Loop
      do {
        setConsoleColor(6);
        printf("Do you think the number is High(1) or Low(2)\n");
        scanf("%d", &a);
        if (a < 1 || a > 2) {
          setConsoleColor(12);
          printf("Mai Took! Just 1 or 2. \n");
          setConsoleColor(6);
        }
      } while (a < 1 || a > 2);

      // Game Logic
      int randomNumber = rand() % 99 + 1;
      
      if (number2 > randomNumber) { // The lucky number is higher than the random number
        setConsoleColor(6);
        printf("High\n");
        if (a == 1) { // Guessed High (Correct)
          setConsoleColor(9);
          printf("Computer random is: %d\n", randomNumber);
          setConsoleColor(2);
          printf("you win\n");
        } else if (a == 2) { // Guessed Low (Incorrect)
          setConsoleColor(9);
          printf("Computer random is: %d\n", randomNumber);
          setConsoleColor(4);
          printf("you lost\n");
        }
      } else if (number2 < randomNumber) { // The lucky number is lower than the random number
        setConsoleColor(6);
        printf("Low\n");
        if (a == 2) { // Guessed Low (Correct)
          setConsoleColor(9);
          printf("The Number is: %d\n", randomNumber);
          setConsoleColor(2);
          printf("you win\n");
        } else if (a == 1) { // Guessed High (Incorrect)
          setConsoleColor(9);
          printf("The Number is: %d\n", randomNumber);
          setConsoleColor(4);
          printf("you lost\n");
        }
      }
    }

    setConsoleColor(6);
    printf("\nDo you want to play again? Yes(1), No(0): ");
    scanf("%d", &Again);
  } while (Again);

  setConsoleColor(13);
  printf("Thank You :) \n Nicha Gunhasin 6630202228\n Kamontat Inthawong 6630202007\n");
  return 0;
}
