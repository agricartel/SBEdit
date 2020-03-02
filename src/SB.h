//
//  SB.h
//  SBUpdater
//
//  Created by Craig Stone on 3/2/20.
//  Copyright © 2020 Craig Stone. All rights reserved.
//

#ifndef SB_h
#define SB_h

// Sets up output files, and calls main loop
void init(void);

// Main loop where user input is passed in
void mainLoop(void);

// By default, returns zero, unless quit command is entered, then returns 1
// Parses user input to determin which command was entered
int getCommand(char *input);

// Overwrites/creates file filename, replaces what was in that file with content.
void overwriteFile(char *filename, char *content);

// Updates a player's score.
void updateScore(int player, int score);

// Prints the help documents (self-explanatory)
void printHelp(void);

#endif /* SB_h */
