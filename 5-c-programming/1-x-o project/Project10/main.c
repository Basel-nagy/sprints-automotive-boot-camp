#define _CRT_SECURE_NO_WARNINGS
                        /*************************************including section**********************************/

#include <stdio.h>

                            /*************************************typedef section**********************************/
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

                      /*************************************functions prototype section**********************************/
void drawBoard(uint8_t* board);
void updateBoard(uint8_t* board, uint8_t position, uint8_t value);
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol);
void setPlayerConfig(uint8_t* configArray);
void loadAndUpdate(uint8_t playerNumber);
void getGameState(uint8_t* board, uint8_t* gameState);


/******************************************************global variables**********************************************************/
//this is my x-o board frame from 1->9
uint8_t arr[] =     { 218,196,194,196,194,196,191,'\n',
                      179,'1',179,'2',179,'3',179,'\n',
                      195,196,197,196,197,196,180,'\n',
                      179,'4',179,'5',179,'6',179,'\n',
                      195,196,197,196,197,196,180,'\n',
                      179,'7',179,'8',179,'9',179,'\n',
                      192,196,193,196,193,196,217,'\n','\0' };

uint8_t player_1[2] = { '1' };
uint8_t player_2[2] = { '2' };

uint8_t player_location[9] = { 0 };
uint8_t counter = 0;


int main()
{

again:
    uint8_t another_game = 0;
    uint8_t state;
    uint8_t player_flag = 0;

    setPlayerConfig(player_1);
    while (getchar() != '\n');
    setPlayerConfig(player_2);
    system("cls");
    while(counter<9)
    {
        loadAndUpdate(player_1[0]);
        getGameState(arr, &state);
        if (state == 0)
        {
            player_flag = 1;

            break;
        }
        else
        {
           //do nothing
        }
        system("cls");
        loadAndUpdate(player_2[0]);
        getGameState(arr, &state);
        if (state == 0)
        {
            player_flag = 2;
            break;
        }
        else
        {
           //do nothniug
        }
        system("cls");

    }
    system("cls");
    drawBoard(arr);
    if (player_flag == 1)
    {
        printf("player_1 is WIN");
    }
    else if (player_flag == 2)
    {
        printf("player_2 is WIN");
    }
    else if (player_flag == 0)
    {
        printf("the match is draw");
    }
    else
    {
        //do nothing
    }

}

/***************************************************functions impelementation******************************************************/

/*
* description : This function will take a board as an input and prints it on the console
* input arguments: pointer to the board
* return: void
*/
void drawBoard(uint8_t* board)
{
    uint16_t i;
    for (i = 0;board[i] != 0;i++)
    {
        printf("%c", board[i]);
    }
}



/*
* description : - This function will take the board, position to update and value to set in this position
* input arguments: pointer to the board,position from 1->9,value to but in this position which is X OR Y
* return: void
*/
void updateBoard(uint8_t* board, uint8_t position, uint8_t value)
{
    uint8_t flag = 0;
    uint8_t i;

  loop:
  for (i = 0; player_location[i] != '\0';i++)
  {
    if (player_location[i] == position)
    {
        flag = 1;
        break;
    }
  }
  if (flag == 1)
  {
    printf("this location is taken before\n");
    flag = 0;
    while (getchar() != '\n');
    scanf("%c", &position);
    goto loop;
  }
  else
  {
    switch (position)
    {
    case '1': board[9] = value; break;
    case '2':board[11] = value;break;
    case '3':board[13] = value;break;
    case '4':board[25] = value;break;
    case '5':board[27] = value;break;
    case '6':board[29] = value;break;
    case '7':board[41] = value;break;
    case '8':board[43] = value;break;
    case '9':board[45] = value;break;
    default: flag = 1;break;
    }
    if (flag == 1)
    {
        printf("this position is not in the range please choose form 1->9\n");
        while (getchar() != '\n');

        scanf("%c", &position);
        flag = 0;
        goto loop;
    }
    else
    {
        player_location[counter] = position;
        counter++;
    }
  }
}



/*
* description : This function will take the player's number and asks the player to choose between X and O (case insensitive)
* input arguments: player number , pointer to the symbol choosen
* return: return 0 if input isnot choosen before and valid  and return 1 if input is choosen before or invalid
*/
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol)
{
    static uint8_t sym;
    uint8_t sym_2;
    if (playerNumber == '1')
    {
        printf("player_1 please choose your preferred symbol X OR O\n");
        scanf("%c", &sym);
        if ((sym == 'x' || sym == 'X' || sym == 'o' || sym == 'O'))
        {
            *symbol = sym;

            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        printf("player_2 please choose your preferred symbol X OR O\n");
        scanf("%c", &sym_2);
        if ((sym_2 != sym) && (sym_2 == 'x' || sym_2 == 'X' || sym_2 == 'o' || sym_2 == 'O'))
        {
            *symbol = sym_2;
            return 0;
        }
        else
        {
            return 1;
        }
    }
}



/*
* description : This function will prompt and asks each user about their preferred symbols and saves it in the configArray
* input arguments: pointer to each player config.
* return: void
*/
void setPlayerConfig(uint8_t* configArray)
{
    while (getPlayerSymbol(configArray[0], &configArray[1]) != 0)
    {
        system("cls");
        printf("invalid choice\n");
        while (getchar() != '\n');

    }
}


/*
* description : This function will take the player's number then load his config, ask him for the position then updates the board
* input arguments: player number
* return: void
*/
void loadAndUpdate(uint8_t playerNumber)
{
    uint8_t flag = 0;
    uint8_t position;
    uint8_t i;
    drawBoard(arr);
    if(counter<9)
    {
        if (playerNumber == '1')
        {
         while (getchar() != '\n');
            printf("player_1 please choose your position\n");
            scanf("%c", &position);
            updateBoard(arr, position, player_1[1]);
        }
        else
        {
            while (getchar() != '\n');
            printf("player_2 please choose your position\n");
            scanf("%c", &position);
            updateBoard(arr, position, player_2[1]);
        }
    }
    else
    {
        //do nothing
    }
}



/*
* description : This function will check after each move if there is a win, draw or continue playing.
                Returns 0 for winning, Returns 1 for a draw, Returns 2 to continue
* input arguments:pointer to board,buffer to store the game state
* return: void
*/
void getGameState(uint8_t* board, uint8_t* gameState)
{
    if ((board[9] == board[11]) && (board[9] == board[13]) )
    {
        *gameState = 0;
    }
    else if ((board[25] == board[27]) && (board[25] == board[29]))
    {
        *gameState = 0;
    }
    else if ((board[41] == board[43]) && (board[41] == board[45]))
    {
        *gameState = 0;
    }
    else if ((board[9] == board[25]) && (board[25] == board[41]))
    {
        *gameState = 0;
    }
    else if ((board[11] == board[27]) && (board[11] == board[43]))
    {
        *gameState = 0;
    }
    else if ((board[13] == board[29]) && (board[13] == board[45]))
    {
        *gameState = 0;
    }
    else if ((board[9] == board[27]) && (board[9] == board[45]))
    {
        *gameState = 0;
    }
    else if ((board[13] == board[27]) && (board[13] == board[41]))
    {
        *gameState = 0;
    }
    else if(counter==8)
    {
        *gameState = 1;
    }
    else
    {
        *gameState = 2;
    }
}
