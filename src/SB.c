//
//  SB.c
//  SBUpdater
//
//  Created by Craig Stone on 3/2/20.
//  Copyright © 2020 Craig Stone. All rights reserved.
//

#include "SB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// .txt file defines
#define PLAYER_1 "Player1.txt"
#define PLAYER_1_SCORE "Player1Score.txt"
#define PLAYER_2 "Player2.txt"
#define PLAYER_2_SCORE "Player2Score.txt"
#define ROUND "Round.txt"

// Round subcommands
#define W1 "Winner's Round 1"
#define W2 "Winner's Round 2"
#define W3 "Winner's Round 3"
#define W4 "Winner's Round 4"
#define WQ "Winner's Quarter-final"
#define WS "Winner's Semi-final"
#define WF "Winner's Final"
#define GF "Grand Final"
#define BR "Grand Final - Bracket Reset"
#define L1 "Loser's Round 1"
#define L2 "Loser's Round 2"
#define L3 "Loser's Round 3"
#define L4 "Loser's Round 4"
#define LQ "Loser's Quarter-final"
#define LS "Loser's Semi-final"
#define LF "Loser's Final"

const char delim[2] = " ";
int p1score = 0;
int p2score = 0;
char *rounds[2][16] =
{
    {W1, W2, W3, W4, WQ, WS, WF, GF, BR, L1, L2, L3, L4, LQ, LS, LF},
    {"w1", "w2", "w3", "w4", "wq", "ws", "wf", "gf", "br", "l1", "l2", "l3", "l4", "lq", "ls", "lf"}
};

void init()
{
    printf("\nUMBC Smash Club Scoreboard Editor\n");
    // Setup all text files
    overwriteFile(PLAYER_1, "Player 1");
    overwriteFile(PLAYER_2, "Player 2");
    overwriteFile(ROUND, W1);
    updateScore(1, 0);
    updateScore(2, 0);

    mainLoop();
}

void mainLoop()
{
    int quitCommand = 0;
    while (quitCommand != 1)
    {
        printf("> ");
        char input[80];
        scanf("%[^\n]s", input);
        quitCommand = getCommand(input);
        fflush(stdin);
    }
}

int getCommand(char *input)
{
    char *command;
    char *subcommand;
    subcommand = strchr(input, ' ');
    subcommand++; // Since strchr returns a pointer to the specified character, add one to subcommand to have it point to the first character of the su
    command = strtok(input, delim);

    // Is there a better way to do this instead of a ton of if statements?
    if (strcmp(command, "help") == 0)
    {
        printHelp();
    }
    else if (strcmp(command, "p1s") == 0)
    {
        if (subcommand != NULL)
        {
            int score = atoi(subcommand);
            updateScore(1, score);
        }
        else
        {
            printf("Error: Expected score after command p1s\n");
        }
    }
    else if (strcmp(command, "p1n") == 0)
    {
        if (subcommand != NULL)
        {
            overwriteFile(PLAYER_1, subcommand);
        }
        else
        {
            printf("Error: Expected name after command p1n\n");
        }
    }
    else if (strcmp(command, "p1i") == 0)
    {
        updateScore(1, p1score + 1);
    }
    else if (strcmp(command, "p1r") == 0)
    {
        updateScore(1, 0);
    }
    else if (strcmp(command, "p2s") == 0)
    {
        if (subcommand != NULL)
        {
            int score = atoi(subcommand);
            updateScore(2, score);
        }
        else
        {
            printf("Error: Expected score after command p2s\n");
        }
    }
    else if (strcmp(command, "p2n") == 0)
    {
        if (subcommand != NULL)
        {
            overwriteFile(PLAYER_2, subcommand);
        }
        else
        {
            printf("Error: Expected name after command p2n\n");
        }
    }
    else if (strcmp(command, "p2i") == 0)
    {
        updateScore(2, p2score + 1);
    }
    else if (strcmp(command, "p2r") == 0)
    {
        updateScore(2, 0);
    }
    else if (strcmp(command, "mr") == 0)
    {
        if (subcommand != NULL)
        {
            for (int i = 0; i < 16; i++)
            {
                if (strcmp(subcommand, rounds[1][i]) == 0)
                {
                    overwriteFile(ROUND, rounds[0][i]);
                    break;
                }
            }
        }
        else
        {
            printf("Error: Expected round subcommand after command mr\n");
        }
    }
    else if (strcmp(command, "exit") == 0)
    {
        return 1;
    }
    else
    {
        printf("Invalid command.");
    }

    return 0;
}

void overwriteFile(char *filename, char *content)
{
    //int size = strlen(content);
    FILE *file;
    file = fopen(filename, "w+");
    fwrite(content, sizeof(char), strlen(content), file);
    fclose(file);
}

void updateScore(int player, int score)
{
    char strscore[2];
    strscore[0] = score + 0x30;
    if (player == 1)
    {
        p1score = score;
        overwriteFile(PLAYER_1_SCORE, strscore);
    }
    else if (player == 2)
    {
        p2score = score;
        overwriteFile(PLAYER_2_SCORE, strscore);
    }
}

void printHelp()
{
    printf("----------------SCOREBOARD EDITOR FOR SMASH CLUB----------------\n");
    printf("This command line tool modifies the text files in this directory using the commands below:\n");
    printf("help:            Displays this help menu\n");
    printf("exit:            Exits the program\n");
    printf("p1s <integer>:   Overwrites Player 1's score file to the value specified.\n");
    printf("p1n <string>:    Overwrites Player 1's name file to the string specified.\n");
    printf("p1i:             Increments Player 1's score.\n");
    printf("p1r:             Resets Player 1's score back to 0.\n");
    printf("p2s <integer>:   Overwrites Player 2's score file to the value specified.\n");
    printf("p2n <string>:    Overwrites Player 2's name file to the string specified.\n");
    printf("p2i:             Increments Player 2's score.\n");
    printf("p2r:             Resets Player 2's score back to 0.\n");
    printf("mr <subcommand>: Modifies the current round specified by the subcommands:\n");
    printf("     w1:         Winner's Round 1\n");
    printf("     w2:         Winner's Round 2\n");
    printf("     w3:         Winner's Round 3\n");
    printf("     w4:         Winner's Round 4\n");
    printf("     wq:         Winner's Quarter-final\n");
    printf("     ws:         Winner's Semi-final\n");
    printf("     wf:         Winner's Final\n");
    printf("     gf:         Grand Final\n");
    printf("     br:         Grand Final (Bracket Reset)\n");
    printf("     l1:         Loser's Round 1\n");
    printf("     l2:         Loser's Round 2\n");
    printf("     l3:         Loser's Round 3\n");
    printf("     l4:         Loser's Round 4\n");
    printf("     lq:         Loser's Quarter-final\n");
    printf("     ls:         Loser's Semi-final\n");
    printf("     lf:         Loser's Final\n");
}
