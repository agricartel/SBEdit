/*----------------SCOREBOARD EDITOR FOR SMASH CLUB----------------*/
// This command line tool modifies the text files in this directory using the commands below:
// p1s <integer>:   Overwrites file specified by PLAYER_1_SCORE to the value specified.             (Player 1 Score)
// p1n <string>:    Overwrites file specified by PLAYER_1 to the string specified.                  (Player 1 Name)
// p1i:             Increments the value in file specified by PLAYER_1_SCORE.                       (Player 1 Increment score)
// p1r:             Overwrites file specified by PLAYER_1_SCORE to 0.                               (Player 1 Reset score)
// p2s <integer>:   Changes PLAYER_2_SCORE to the value specified.                                  (Player 2 Score)
// p2n <string>:    Changes file specified by PLAYER_2 to the string specified.                     (Player 2 Name)
// p2i:             Increments value in the file specified by PLAYER_2_SCORE.                       (Player 2 Increment score)
// p2r:             Overwrites file specified by PLAYER_2_SCORE to 0.                               (Player 2 Reset score)
//
// mr <subcommand>: Overwrites file specified by ROUND to a string specified by the subcommands:    (Match Round)
//      w1:         Winner's Round 1
//      w2:         Winner's Round 2
//      w3:         Winner's Round 3
//      w4:         Winner's Round 4
//      wq:         Winner's Quarter-final
//      ws:         Winner's Semi-final
//      wf:         Winner's Final
//      gf:         Grand Final
//      br:         Grand Final (Bracket Reset)
//
//      l1:         Loser's Round 1
//      l2:         Loser's Round 2
//      l3:         Loser's Round 3
//      l4:         Loser's Round 4
//      lq:         Loser's Quarter-Final
//      ls:         Loser's Semi-Final
//      lf:         Loser's Final

#include <stdio.h>
#include "SB.h"

int main(int argc, const char *argv[])
{
    printf("\nLaunched successfully!");

    init();

    return 0;
}
