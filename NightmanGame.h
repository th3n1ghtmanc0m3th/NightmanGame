#include <iostream>
#include "CinReader.h"
#ifndef Gohner_NightmanGame_H
#define Gohner_NightmanGame_H

using namespace std;

class NightmanGame
{
  public:

    //This controls the game cycle and directs which room the player is in.
    NightmanGame();

    //this starts the game
    void Start();

    class Combat
    {
      public:

        int die_amount_, dam_mult_, enemy_damage_, player_damage_, damage_;
        string enemy_name_;
        enum Enemy
        {
        kRyanMcPoyle = 1,
        kLiamMcPoyle = 2,
        kCricket = 3,
        kSnail = 4,
        kNightman = 5
        };

        Combat();

        void StartFight(int enemy_);

      private:

        char PlayerAnswer();
        int RollToHit();
        void HitEnemy();
        void HitPlayer();
        void ShowPlayerHP();
        void ShowEnemyHP();
    };


  private:

    CinReader reader;
    int player_hp_;
    int enemy_hp_;
    int current_room;
    int Nightman_Health;
    char player_answer;
    string player_answer_string;
    bool player_has_DC;
    bool player_has_torch;
    bool player_has_glue;
    bool player_has_shiv;
    bool player_has_stick;
    bool player_has_star;
    bool player_has_salt;
    bool player_has_spear;
    bool player_has_catfood;
    bool player_has_rumham;
    bool Cricket_dead;
    bool Charlie_Is_Free;
    bool Artemis_Is_Free;
    bool Maidens_Free;
    bool McPoyles_Alive;
    bool Snail_is_Alive;
    bool puzzle_is_solved;
    bool combat_active_;

    //This function runs the tavern scenario.
    void Tavern();

    //This function runs the cave entrance scenario
    void CaveEntrance();

    //This function runs the Chamber Room scenario
    void ChamberRoom();

    //This function runs the Hallway 1 scenario
    void BirdTunnel();

    //This function runs the Cricket Room scenario
    void CricketRoom();

    //This function runs the Puzzle Room scenario
    void ArtemisBin();

    //This function runs the McPoyle Chamber scenario
    void McPoyleChamber();

    //This function runs the Snail Trail scenario
    void SnailTrail();

    //This function runs the Maiden Jail scenario
    void MaidenJail();

    //This function runs the Dennis Chamber scenario
    void DennisChamber();

    //This function runs the Nightman Chamber scenario
    void NightmanChamber();

    //This function runs the Charlie's Cage scenario
    void CharliesCage();

    //This function runs the end game scenario
    void ReturntoTown();

    //This function asks if you would like to play again
    void PlayAgain();

    //This is function that handles the yes or no player choice
    char PlayerAnswer();

    //This is a function that runs combat
    void StartCombat();

    //This function runs the puzzle
    void Puzzle();

    //This function ends the game. maybe,
    void GameOver();

};

#endif /*Gohner_NightmanGame_H*/
