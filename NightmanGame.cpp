#include <iostream>
#include "CinReader.h"
#include "NightmanGame.h"

NightmanGame::NightmanGame()
{
    current_room = 1;
    player_has_DC = 0;
    player_has_torch = 0;
    player_has_glue = 0;
    player_has_shiv = 0;
    player_has_stick = 0;
    player_has_star = 0;
    player_has_salt = 0;
    player_has_catfood = 0;
    player_has_rumham = 0;
    Cricket_dead = 0;
    Snail_is_Alive = 1;
    McPoyles_Alive = 1;
    player_hp_ = 300;
    Charlie_Is_Free = 0;
    Artemis_Is_Free = 0;
    Nightman_is_Alive = 1;
    Maidens_Free = 0;
    puzzle_is_solved = 0;
}

void NightmanGame::Start()
{
    cout << "Come one, come all to a beautiful game!!\n"
         << "It's gonna be awesome and some other stuff!!\n"
         << "Do dee do dee do dee do dee do dee dee do do dee, some other musical stuff!!\n" << endl;
    cout << "You are playing a text based dungeon adventure game with an It's Always Sunny motif.\n"
         << "Simply follow the on screen prompts and have a good time!\n" << endl;

    while((Charlie_Is_Free == 0)&&(player_hp_ > 0))
    {
        switch(current_room)
        {
        case 1:
            Tavern();
            break;
        case 2:
            CaveEntrance();
            break;
        case 3:
            ChamberRoom();
            break;
        case 4:
            CricketRoom();
            break;
        case 5:
            BirdTunnel();
            break;
        case 6:
            ArtemisBin();
            break;
        case 7:
            McPoyleChamber();
            break;
        case 8:
            MaidenJail();
            break;
        case 9:
            SnailTrail();
            break;
        case 10:
            MaidenJail();
            break;
        case 11:
            DennisChamber();
            break;
        case 12:
            NightmanChamber();
            break;
        case 13:
            CharliesCage();
            break;
        }
    }

    ReturntoTown();

    cout << "The game is over.\n";

}

void NightmanGame::Tavern()
{
    cout << "After picking up the latest edition of AKU, the issue with an expose on the Nightman's Treasure.\n"
         << "Seems there is some lost and priceless treasure in a cave outside of the village.\n"
         << "Done with your daily reading you head to get a drink.\n" << endl;

    cout << "Sitting in a lively tavern you notice a crusty and highly inebriated dwarf shooting dark glances\n"
         << "in your direction. After an hour and several more pints, the dwarf staggers over to you.\n"
         << '"' << "You know of the Nightman's Treasure?\n" << '"' << "Y/N\n" << endl;

    PlayerAnswer();

    if(player_answer_ == 'Y')
    {
        cout << "Even though you clearly said yes, the dwarf or troll, whatever the hell he is, begins telling you\n"
             << "of the Nightman's Treasure. The details seem half nonsense, half gibberish. It's a mess really.\n"
             << "You find yourself wanting to extricate yourself from the situation, but it's then you notice his\n"
             << "bloody club. Honestly, it looks like this thing has killed more people than the plague.\n"
             << "What you can gather of this wild tale is that in a forlorn cave outside of the village there is a\n"
             << "treasure or maybe person of some kind, that part is vague. You may or may not have to fight what\n"
             << "may or may not be monsters. After he finishes word vomiting he actually hands you the bashing stick!\n"
             << "And just when you're thinking yes! I can bash him and get out this, you notice in his other hand is\n"
             << "an even bigger, bloodier bashing stick. He asks you, " << '"' << "Will you attempt to solve this quest?"
             << '"' << "\nY/N\n" << endl;

        PlayerAnswer();

        switch(player_answer_)
        {
        case 'Y':
            cout << "Here we go.\n" << endl;
            current_room = 2;
            break;
        case 'N':
            cout << "Dwarf:" << '"' << "What? You're an idiot, why am I talking to you?" << '"' << "\n"
                << "The dwarf then pulls out his hammer and proceeds to bash you like a rat.\n"
                << "Great. Smart move. Now you're dead. You know, next time someone asks you about\n"
                << "the Nightman's Treasure, don't ask questions. Just say, " << '"' << "Yes." << '"' << "\n" << endl;

            PlayAgain();
        }
    }
    else
    {
        cout << "Dwarf:" << '"' << "What? You're an idiot, why am I talking to you?" << '"' << "\n"
             << "The dwarf then pulls out his hammer and proceeds to bash you like a rat.\n"
             << "Great. Smart move. Now you're dead. You know, next time someone asks you about\n"
             << "the Nightman's Treasure, don't ask questions. Just say, " << '"' << "Yes." << '"' << "\n" << endl;

        PlayAgain();
    }
}

void NightmanGame::CaveEntrance()
{
    if(player_has_torch == 0)
    {
        cout << "You find yourself standing at the entrance to an ominous and\n"
             << "foreboding cave. The entrance is littered with bones and signs that are\n"
             << "barely legible. You notice a few odd items strewn about. There is a sword,\n"
             << "half buried in the dirt. Nearby is a torch and right next to the entrance is\n"
             << "a half baked chicken in denim shorts, a denim chicken.\n" << endl;

        cout << "Would you like to pick up the sword?\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer_ == 'Y')
        {
            cout << "Think you're so smart, picking up the big bad sword. Well guess what?\n"
                 << "You sliced an artery digging it out. You're dead.\n" << endl;

            PlayAgain();

        }
        else
        {
            cout << "Yeah, makes sense. Blades aren't really your style. I mean being a part of the AKU.\n"
                 << "You're a born smasher, clearly.\n" << endl;
        }

        cout << "Would you like to pick up the torch?\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer_ == 'Y')
        {
            player_has_torch =1;

            cout << "Fresh, you got a torch.\n" << endl;

        }
        else
        {
            player_has_torch = 0;

            cout << "Ok, no torch then.\n" << endl;
        }
    }
    else
    {
        cout << "You have the torch already. Why are you here? Oh yeahhhh, the CHICKEN.\n" << endl;
    }

    if(player_has_DC == 0)
    {
            cout << "Would you like to pick up the denim chicken?\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer_ == 'Y')
        {
            player_has_DC = 1;

            cout << "Hang on. Denim Chicken?\n" << endl;
        }
        else
        {
            cout << "Hmm, I don't know man, Denim Chicken though.\n" << endl;
        }
    }
    else
    {
        cout << "Oh, fret not. You got the denim chicken. Seriously though, now, why are you here.\n";
    }

    cout << "So you have made your preparations. Would you like to enter the cave?\nY/N\n" << endl;

    PlayerAnswer();

    if(player_answer_ == 'Y')
    {
        current_room = 3;
    }
    else
    {
        cout << "Frank Dwarf shows up and you guessed it, bashes you like a rat.\n"
             << "Dude, I think he wants you in the cave.\n" << endl;

        PlayAgain();
    }
}

void NightmanGame::ChamberRoom()
{
    if(player_has_torch == 1)
    {
        cout << "Dang doodle, this room would have been dark as night had you not brought that\n"
             << "torch. Good thinking. So, looking around, you see you are in the opening room\n"
             << "of the cave. There is two openings to the left and right. Above the left entrance\n"
             << "you see a poorly spelled sign reading 'Herr leyes Criket'. On the right it reads\n"
             << "'Bird Wif Teeth'. Weird.\n" << endl;

        if(player_has_glue == 0)
        {
            cout << "Looking around you don't see much except for a bottle of glue. It's pretty intense\n"
                 << "stuff. Industrial grade. I'd be careful with who you show that to.\n"
                 << "Would you like to pick up the glue?\nY/N\n" << endl;

            PlayerAnswer();

            if(player_answer_ == 'Y')
            {
                player_has_glue = 1;

                cout << "Sweet, bro. What's a little glue between friends?\n"
                     << "You now have a bottle of glue.\n" << endl;
            }
            else
            {
                player_has_glue = 0;
                cout << "I see someone is afraid to party. You have no glue.\n" << endl;
            }
        }
        else
        {
            cout << "Well you're back in the chamber room and the glue is gone.\n" << endl;
        }

        cout << "Choose which room you'd like to enter?\nC for Cricket's Chamber or B for Bird Tunnel.\n";

        player_answer_ = toupper(reader.readChar("CBcb"));

        if(player_answer_ == 'C')
        {
            current_room = 4;
        }
        else
        {
            current_room = 5;
        }
    }
    else
    {
        cout << "As you walk further into the chamber you realize it is dark. So turning around\n"
             << "you head back out and hit your head pretty hard.\n" << endl;

        player_hp_ = player_hp_ - 10;

        cout << "Player HP: " << player_hp_ << "\n" <<endl;

        current_room = 2;
    }
}

void NightmanGame::BirdTunnel()
{
    cout << "Following the dimly lit path down the hallway you are feeling the presence of\n"
         << "....something annoying.\n" << endl;

    if(player_has_stick == 0)
    {
        cout << "You notice a long stick with rope wrapped around one end.\n Do you pick it"
             << " up?\nY/N\n" << endl;

        PlayerAnswer();

        if((player_answer_ == 'Y')&&(player_has_shiv == 0))
        {
            cout << "Oh sweet bro a stick with rope. With a knife... or shiv, you could have a spear.\n" << endl;

            player_has_stick = 1;
        }
        else if((player_answer_ == 'Y')&&(player_has_shiv == 1))
        {
            player_has_stick = 1;
            player_has_spear = 1;

            cout << "Yeah bro sweet!! With your shiv, this rope and stick will make a bad ass spear!!.\n"
                 << "Someone could get totally blasted in the throat with this thing!!\n" << endl;
        }
        else
        {
            cout << "Geez, I dunno. These decisions you make, they just like get me up to here with it.\n" << endl;
        }
    }
    else
    {
        cout << "You have already picked up the stick and rope.\n" << endl;
    }

    if(player_has_star == 0)
    {
        cout << "You see a throwing star on the ground. It calls to you. Will you pick\n"
             << "it up.\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer_ == 'Y')
        {
            player_has_star = 1;

            cout << "Oh yeah! Totally sick throwing star for martial arts style activity!\n" << endl;
        }
        else
        {
            cout << "Huh. I don't know man, seems like it was calling to you.\n" << endl;
        }
    }
    else
    {
        cout << "You already have the throwing star in your possession.\n" << endl;
    }

    cout << "Getting close to the sound you see what looks like a giant bird. Just staring at you.\n"
         << "The bird lady starts yammering on. It's unbearable dude. She's talking about the Snail,\n"
         << "some deranged brothers, Cricket. She's squawking that it's not her fault she's stuck here.\n"
         << "This just keeps going, with things like, maybe Charlie was right about the glue and cat food,\n"
         << "she's not a giant bird and those guys are jerks, Frank is using you, watch out for Dennis's ham.\n"
         << "It's all so much! Finally you snap and yell shut up bird!\n" << endl;

    for(int i = 0; i < 14; i++)
    {
        cout << "\n";
    }
    cout << endl;

    cout << "After The bird shuts up, you see three exits.\n"
         << "Pressing A will take you to Artemis's Bin. Pressing M will take you to the McPoyle Chamber and\n"
         << "pressing C will take you back to the Chamber Room.\n" << endl;

     player_answer_ = toupper(reader.readChar("AMCamc"));

     switch(player_answer_)
     {
     case 'A':
        current_room = 6;
        break;
     case 'M':
        current_room = 7;
        break;
     case 'C':
        current_room = 3;
        break;
     }
}

void NightmanGame::CricketRoom()
{
    if(player_has_shiv == 0)
    {
        cout << "Walking down the winding corridor, you are immediately overwhelmed by a series of\n"
             << "foul odors, something reminiscent of burnt baking soda. There is also an unusual amount\n"
             << "of stray dogs roaming around.\n" << endl;

        if(player_has_glue == 1)
        {
            cout << "Cricket speaks to you.\n" << '"' << "Hey, what's up man? Oh wow sweet! Is that industrial\n"
                 << "grade glue? Why don't you give your old pal cricks a taste?\nY/N\n" << endl;

            PlayerAnswer();

            if(player_answer_ == 'Y')
            {
                cout << "Being a generous egg, you hand over the glue to Crick's. Big mistake. After several prolonged\n"
                     << "pulls on the glue, Cricket goes into a glue frenzy.\n" << endl;

                enemy_hp_ = 500;

                fight_outcome_ = StartFight(3);

                if(fight_outcome_ == 'W')
                {
                    Cricket_dead = 1;

                    cout << "What a jabroni, haha!\n" << endl;

                    CricksIsOut();
                }
                else
                {
                    cout << "You are bashed like a rat with Crick's sweet steel drums.\n" << endl;

                    PlayAgain();
                }
            }
            else
            {
                cout << "With as much indignation as you can muster you say, " << '"' << "Shut up street rat" << '"'
                     << "\n" << "Cricket lunges to attack, but without glue, let's be honest. He is a street urchin.\n"
                     << endl;

                enemy_hp_ = 25;
                enemy_damage_ = 1;

                fight_outcome_ = StartFight(3);

                switch(fight_outcome_)
                {
                case 'W':
                    cout << "With his last gasp, maybe, he says, " << '"' << "You don't know what he's up to. "
                         << '"' << "The troll toll, it's real.\n" << endl;
                    CricksIsOut();
                    break;
                case 'L':
                    cout << "How in the hell did that happen.\n" << endl;
                    PlayAgain();
                    break;
                }
            }
        }
        else
        {
            cout << "Cricket just babbles and babbles about Archangels and hips and nips.\nYou should just head out"
                 << " and come back later with something a little more interesting.\nPress C to go back to the Chamber"
                 << " Room\n" << endl;

            player_answer_ = toupper(reader.readChar("Cc"));

            if(player_answer_ == 'C')
            {
                current_room = 3;
            }
        }
    }
    else
    {
        if(player_has_shiv == 1)
        {
            cout << "Dude, Cricks is already unconscious or dead, who cares, but the point is. You got his shiv and this\n"
                 << "place is just dogs and a urine soaked street rat.\nPress C to go back to the Chamber Room.\n" << endl;

            player_answer_ = toupper(reader.readChar("Cc"));

            if(player_answer_ == 'C')
            {
                current_room = 3;
            }
        }
        else
        {
            cout << "Oh now do you want the shiv?\nY/N\n" << endl;

            player_answer_ = PlayerAnswer();

            if((player_answer_ == 'Y')&&(player_has_stick == 0))
            {
                player_has_shiv = 1;

                cout << "Finally.\n" << endl;

                cout << "Time to leave this dump. Press C to go back to the Chamber Room.\n" << endl;

                player_answer_ = toupper(reader.readChar("Cc"));

                if(player_answer_ == 'C')
                {
                    current_room = 3;
                }
            }
            else if((player_answer_ == 'Y')&&(player_has_stick == 1))
            {
                player_has_shiv = 1;
                player_has_spear = 1;

                cout << "Yeah bro sweet!! With your shiv, this rope and stick will make a bad ass spear!!.\n"
                     << "Someone could get totally blasted in the throat with this thing!!\n" << endl;

                cout << "Time to leave this dump. Press C to go back to the Chamber Room.\n" << endl;

                player_answer_ = toupper(reader.readChar("Cc"));

                if(player_answer_ == 'C')
                {
                    current_room = 3;
                }
            }
            else
            {
                cout << "Whyyyyyyy?????\n" << endl;

                cout << "Time to leave this dump. Press C to go back to the Chamber Room.\n" << endl;

                player_answer_ = toupper(reader.readChar("Cc"));

                if(player_answer_ == 'C')
                {
                    current_room = 3;
                }
            }
        }
    }
}

void NightmanGame::ArtemisBin()
{
    if(Artemis_Is_Free == 0)
    {
        cout << "You have walked into a pretty strange situation. I mean this one is unusual. So there is a\n"
             << "Swamp Witch stuck in some kind of trash pile. Honestly it is hard to tell whether or not she is\n"
             << "upset with her situation or enthralled. Against your better judgment, you ask the witch if she's ok.\n"
             << endl;

        cout << '"' << "Well hello there handsome. How's about helping my out this" << '"' << "\n" << endl;
        cout << "Would you like to help Artemis out of the trash pile?\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer_ == 'Y')
        {
            cout << '"' << "You want some salt to go with that sweet sugar," << '"' << " She purrs at you.\n"
                 << "Y/N\n" << endl;

            PlayerAnswer();

            if(player_answer_ == 'Y')
            {
                cout << "Right on bro you got some salt.\n" << endl;
                player_has_salt = 1;
                //fix loop
            }
            else
            {
                cout << "This probably won't end well.\n" << endl;
            }
        }
        else
        {
            cout << "Fine whateves, beat feet stink meat.\n" << endl;
        }

        cout << "Time to leave again. Press B to go back to the Bird Tunnel.\n" << endl;

        player_answer_ = toupper(reader.readChar("Bb"));

        if(player_answer_ == 'B')
        {
            current_room = 5;
        }
    }
    else
    {
        cout << "Back in the Bin, Artemis is free.\n" << endl;

        if(player_has_salt == 1)
        {
            cout << "You have the salt. I'd suggest getting out of here. Like now.\n" << endl;
        }
        else
        {
            cout << "She knows why you are back. Looking at you so deep in the eyes that you feel\n"
                 << "your soul burn, she whispers," << '"' << "Wanna get salty?\nY/N\n" << endl;

            PlayerAnswer();

            if(player_answer_ == 'Y')
            {
                player_has_salt = 1;

                cout << "You have obtained the salt. I would seriously consider leaving jabroni.\n" << endl;
                //Run functions for non-school version. Artemis and Frank.
            }
            else
            {
                cout << "No salt, nothing left for you here bozo.\n" << endl;
            }
        }

        cout << "Time to leave again. Press B to go back to the Bird Tunnel.\n" << endl;

        player_answer_ = toupper(reader.readChar("Bb"));

        if(player_answer_ == 'B')
        {
            current_room = 5;
        }
    }
}

void NightmanGame::McPoyleChamber()
{
    if(McPoyles_Alive == 1)
    {
        cout << "Alright this Nightman's Treasure has become more of a nightmare. What you are seeing is a bit\n"
             << "hard to comprehend. There are two humanoid like creatures that could be described as brothers, maybe.\n"
             << "They are wearing heavily grease stained robes, one of them has an eye patch and there is an odor that\n"
             << "has apparently killed most of the other living beings dumb enough to pass through here.\n" << endl;

        cout << "They both stare at you for what feels like an eon. Finally the one with the eye patch speaks.\n" << endl;

        cout << '"' << "Here's the deal turkey. You walked into the wrong room," << '"' << " Liam bellows.\n" << endl;
    }
    else
    {
        cout << "The McPoyle's limp lifeless bodies are really stinking up the place. Better get a move on.\n"
             << "Press B for Bird Tunnel, J for Maiden Jail or S for Snail Trail.\n" << endl;

        player_answer_ = toupper(reader.readChar("BbJjSs"));

        switch(player_answer_)
        {
        case 'B':
            current_room = 5;
            break;
        case 'J':
            current_room = 8;
            break;
        case 'S':
            current_room = 9;
            break;
        }
    }

    if((player_has_star == 1)&&(player_has_spear == 1))
    {
        cout << "The brothers attack, but you had the good foresight to bring some serious weaponry.\n"
             << "You throw the spear first, instantly killing Ryan. Liam goes to attack next but you throw\n"
             << "the star and it takes out his only good eye. He stumbles around and falls off his post.\n"
             << "In the fall his neck breaks.\n" << endl;

        McPoyles_Alive = 0;

        cout << "You have defeated the McPoyle's.\n" << "Press B for Bird Tunnel, J for Maiden Jail or S for Snail Trail.\n" << endl;

        player_answer_ = toupper(reader.readChar("BbJjSs"));

        switch(player_answer_)
        {
        case 'B':
            current_room = 5;
            break;
        case 'J':
            current_room = 8;
            break;
        case 'S':
            current_room = 9;
            break;
        }
    }
    else if((player_has_star == 1)&&(player_has_spear == 0))
    {
        cout << "The brothers move to attack, but you thankfully brought that throwing star. Hurling it with all\n"
             << "your might, it takes out Liam's good eye. He falls off his platform and breaks his neck.\n"
             << '"' << "You killed Liam!!" << '"' << " Ryan screams and moves to attack.\n" << endl;

        fight_outcome_ = StartFight(1);

        if(fight_outcome_ == 'W')
        {
            McPoyles_Alive = 0;

            cout << "You have defeated the McPoyle's.\n" << "Press B for Bird Tunnel, J for Maiden Jail or S for Snail Trail.\n" << endl;

            player_answer_ = toupper(reader.readChar("BbJjSs"));

            switch(player_answer_)
            {
            case 'B':
                current_room = 5;
                break;
            case 'J':
                current_room = 8;
                break;
            case 'S':
                current_room = 9;
                break;
            }
        }
        else
        {
            PlayAgain();
        }
     }
    else if((player_has_star == 0)&&(player_has_spear == 1))
    {
        cout << "When the brothers go to attack, you throw your spear. Hitting Ryan square in the throat there\n"
             << "an arterial spray that paints the nearby walls red. Liam, enraged, comes snarling toward you.\n"
             << endl;

        fight_outcome_ = StartFight(2);

        if(fight_outcome_ == 'W')
        {
            McPoyles_Alive = 0;

            cout << "You have defeated the McPoyle's.\n" << "Press B for Bird Tunnel, J for Maiden Jail or S for Snail Trail.\n" << endl;

            player_answer_ = toupper(reader.readChar("BbJjSs"));

            switch(player_answer_)
            {
            case 'B':
                current_room = 5;
                break;
            case 'J':
                current_room = 8;
                break;
            case 'S':
                current_room = 9;
                break;
            }
        }
        else
        {
            PlayAgain();
        }
    }
    else
    {
        cout << "Ryan steps forward first.\n" << endl;

        fight_outcome_ = StartFight(1);

        if(fight_outcome_ == 'W')
        {
            cout << "With Ryan's broken body laying at your feet. Liam lunges toward you.\n" << endl;

            fight_outcome_ = StartFight(2);

            if(fight_outcome_ == 'W')
            {
                McPoyles_Alive = 0;

                cout << "You have defeated the McPoyle's.\n" << endl;
            }
            else
            {
                PlayAgain();
            }
        }
        else
        {
            PlayAgain();
        }
    }
}

void NightmanGame::SnailTrail()
{
    if(Snail_is_Alive == 1)
    {
        cout << "It smells pathetic in here. That's not even a smell, but it is quite literally the only thing that you can think.\n"
             << "Gail the Snail is here. The garbage pail cousin herself. Imagine if a turd grew to human size, took on a vaguely\n"
             << "human form and started to obnoxiously speak. That's Gail. Thats's the Snail.\n" << endl;

        if(player_has_salt == 1)
        {
            Snail_is_Alive = 0;

            cout << "Thankfully you saved you trash witch. That was a good call. Cause now you can use that salt and\n"
                 << "salt this damn snail.\n" << endl;

            cout << "The Snail slithers away to die a salty death. I get it. You don't feel good about yourself, you salted\n"
                 << "a person. No one ever wants to have to salt another human being.\n" << endl;

            cout << "Time to move on. Press M to go back or I to go forward.\n" << endl;

            player_answer_ = toupper(reader.readChar("MmIi"));

            switch(player_answer_)
            {
            case 'M':
                current_room = 7;
                break;
            case 'I':
                current_room = 11;
                break;
            }
        }
        else
        {
            cout << "There is absolutely no reasoning with this one. Prepare for battle.\n" << endl;

            fight_outcome_ = StartFight(4);

            if(fight_outcome_ == 'W')
            {
                Snail_is_Alive = 0;

                cout << "With the Snail completely trashed and stomped out, it is time for you to move one.\n"
                     << "Press M for McPoyle's Chamber or I for the Implication Room.\n" << endl;

                player_answer_ = toupper(reader.readChar("MmIi"));

                switch(player_answer_)
                {
                case 'M':
                    current_room = 7;
                    break;
                case 'I':
                    current_room = 11;
                    break;
                }
            }
            else
            {
                PlayAgain();
            }
        }
    }
    else
    {
        cout << "You have already salted the snail. It's time to bounce.\n"
             << "Press M for McPoyle Chamber or I for The Implication Room.\n" << endl;

        player_answer_ = toupper(reader.readChar("MmIi"));

        switch(player_answer_)
        {
        case 'M':
            current_room = 7;
            break;
        case 'I':
            current_room = 11;
            break;
        }
    }
}

void NightmanGame::MaidenJail()
{
    cout << "You have entered a dimly lit bunker type room. There are empty cans of sardines and cat food lying\n"
         << "around and a jail cell in the corner.\n" << endl;

    if(Maidens_Free == 0)
    {
        cout << "Inside the jail cell, you see Jackie DeNardo the town page and Waitress from the Taddy's Tavern.\n"
             << "Jackie seems visibly shaken and disturbed, while the Waitress just seems drunk.\n" << endl;

        cout << "Would you like to speak to the captives?\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer_ == 'Y')
        {
            cout << "You make your greetings to the captives. Jackie is too disheveled to respond but the Waitress seems talkative.\n"
                 << '"' << "Hey I know you, " << '"' << "She says.\n" << endl;
        }
        else
        {
            cout << "You say nothing and neither do they. This is weird.\n" << endl;
        }

        cout << "Would you like to free the captives?\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer_ == 'Y')
        {
            Maidens_Free = 1;

            player_has_catfood = 1;

            cout << "The captives are free. The Waitress spits out a large glob of phlegm at your feet and leaves. But\n"
                 << "Jackie thanks you with her last can of cat food.\n" << endl;
        }
        else
        {
            cout << "Enraged by your complete lack of empathy, Jackie and the Waitress tear off the cell door and rush you.\n"
                 << "Using the bones of previous captives, they bash you like a rat.\n" << endl;

            GameOver();
        }

        cout << "Time to move on. Press M for McPoyle Chamber or I for Implication Room.\n" << endl;

        player_answer_ = toupper(reader.readChar("MmIi"));

        switch(player_answer_)
        {
        case 'M':
            current_room = 7;
            break;
        case 'I':
            current_room = 11;
            break;
        }
    }
    else
    {
        cout << "You have already freed the maiden's in the jail. Time to move on.\n"
             << "Press M for McPoyle's Chamber and I for Implication Room.\n" << endl;

        player_answer_ = toupper(reader.readChar("MmIi"));

        switch(player_answer_)
        {
        case 'M':
            current_room = 7;
            break;
        case 'I':
            current_room = 11;
            break;
        }
    }
}

void NightmanGame::DennisChamber()
{
    if(puzzle_is_solved == 0)
    {
        cout << "Two things immediately catch you're attention. A magical glowing Rebus puzzle on the wall behind you\n"
             << "and a very vain man in black robes stroking his reflection in the mirror. He is muttering the same\n"
             << "phrase repeatedly, but you are two far too hear.\n" << endl;

        cout << "Looking more closely at the puzzle you can see that it has scratches above that read 'Dennis is'\n"
             << "The robed man must be Dennis. The Rebus puzzle contains the word man with a 5 star rating next to it.\n"
             << "Using your inherent knowledge of magic you deduce that this puzzle remaining unsolved is keeping Dennis\n"
             << "stuck in his muttering loop.\n" << endl;

        cout << "You walk closer and notice a beautiful glistening ham obscured by the robed man. The robed man speaks.\n"
             << '"' << "If you can tell me what I am, I will give you that which the Nightman covets above all others,"
             << '"' << "Dennis says.\n" << endl;

        cout << "Please enter your answer to the puzzle in the form of 'a blank blank blank'\n" << endl;

        player_answer_string = reader.readString("a five star man");

        if(player_answer_string == "a five star man")
        {
            player_has_rumham = 1;

            puzzle_is_solved = 1;

            cout << "Dennis weeps silently." << '"' << "Thank you" << '"' << " He whispers.\n"
                 << "He shuffles away, possibly vindicated. You have no clue what just happened.\n" << endl;
        }
        else
        {
            cout << "Wrong.\nWould you like to try again?\nY/N\n" << endl;

            player_answer_ = toupper(reader.readChar("YyNn"));

            if(player_answer_ == 'Y')
            {
                Puzzle();
            }
            else
            {
                cout << "Ok, then.\n" << endl;
            }
        }

        cout << "Press J for the Maiden Jail, N for the Nightman's Chamber or S for the Snail Trail.\n" << endl;

        player_answer_ = toupper(reader.readChar("JjNnSs"));

        switch(player_answer_)
        {
        case 'J':
            current_room = 9;
            break;
        case 'N':
            current_room = 12;
            break;
        case 'S':
            current_room = 10;
            break;
        }
    }
    else
    {
        cout << "Puzzle Solved, Dennis gone, you have rum ham.\n" << endl;

        cout << "Press J for the Maiden Jail, N for the Nightman's Chamber or S for the Snail Trail.\n" << endl;

        player_answer_ = toupper(reader.readChar("JjNnSs"));

        switch(player_answer_)
        {
        case 'J':
            current_room = 9;
            break;
        case 'N':
            current_room = 12;
            break;
        case 'S':
            current_room = 10;
            break;
        }
    }
}

void NightmanGame::NightmanChamber()
{
    cout << "You have made it to the final cavern of this truly unspeakable nightmare. I mean honestly imagine your\n"
         << "dreams now after the influence this game has reeked havoc upon them. But here you stand before another in\n"
         << "a long line of bizarre and outrageous characters. The Nightman is going around making awkward" << '('
         << "see:awesome" << ')' << "\n" << "movements. He is also speaking heavily to himself. You don't want to interrupt him, because\n"
         << "it's from him that you are going to get the most information out of. It seems Frank, who by the way is a troll, has\n"
         << "been luring people out here under the premise of freeing Charlie. He starts to say more but then notices you.\n"
         << endl;

    if(Nightman_is_Alive == 1)
    {
        if(player_has_rumham == 1)
        {
            cout << "You give the rumham to the Nightman. But it is like way poisoned. I mean it was\n"
                 << "from Dennis, so. He eats it and dies.\n" << endl;

            Nightman_is_Alive = 0;

            cout << "Approach Charlie's Cage?\nY/N\n" << endl;

            PlayerAnswer();

            if(player_answer_ == 'Y')
            {
                current_room = 13;
            }
            else
            {
                current_room = 11;
            }
        }
        else
        {
            cout << "You try to talk Nightman down. No Luck. He stands in some sort of pseudo karate stance.\n"
                 << "Prepare for combat.\n" <<endl;

            fight_outcome_ = StartFight(5);

            if(fight_outcome_ == 'W')
            {
                Nightman_is_Alive = 0;

                cout << "You've lived as Dayman, fought the Nightman and you have totally conquered him, man.\n" << endl;

                cout << "Approach Charlie's Cage?\nY/N\n" << endl;

                PlayerAnswer();

                if(player_answer_ == 'Y')
                {
                    current_room = 13;
                }
                else
                {
                    cout << "Charlie yells out, " << '"' << "Hey, dude come on let me out man!!\n" << endl;

                    cout << "Just then you hear the familiar thud of a troll. Looks like you are now paying the toll.\n"
                         << "Frank has bashed you again.\n" << endl;

                    PlayAgain();
                }
            }
            else
            {
                PlayAgain();
            }
        }
    }
    else
    {
        cout << "Nightman is already dead.\n";cout << "Approach Charlie's Cage?\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer_ == 'Y')
        {
            current_room = 13;
        }
        else
        {
            cout << "Charlie yells out, " << '"' << "Hey, dude come on let me out man!!\n" << endl;

            cout << "Just then you hear the familiar thud of a troll. Looks like you are now paying the toll.\n"
                 << "Frank has bashed you again.\n" << endl;

            PlayAgain();
        }
     }
}

void NightmanGame::CharliesCage()
{
    cout << "Well here it is. After all the bashing, street urchins, bird ladies, trash witches, whatever the hell\n"
         << "the McPoyle's were. You are here standing before Charlie's cage. Will you open?\nY/N\n" << endl;

    PlayerAnswer();

    if((player_answer_ == 'Y')&&(player_has_catfood == 1))
    {
        cout << "Ah dude, see this is great. This why we are gonna work well together. You see some cat food,\n"
             << "you see a denim chicken, you don't ask questions, you just pick it up.\n" << endl;

        Charlie_Is_Free = 1;
    }
    else if((player_answer_ == 'Y')&&(player_has_catfood == 0))
    {
        cout << "You free Charlie and Frank shows up. He and Charlie are super hungry. Seeing how you forgot\n"
             << "to bring cat food, they have to eat you.\n" << endl;

        PlayAgain();
    }
    else
    {
        cout << "You won't let Charlie out. Lo and behold look who shows up. It's Frank. And you guessed it.\n"
             << "Bashed like a rat.\n" << endl;

        PlayAgain();
    }

}

void NightmanGame::ReturntoTown()
{
    cout << "You are heading out of this cave a changed individual. You have seen things, done things.\n"
         << "With Charlie in tow and surprise, surprise the troll Frank showing up you get a glimpse\n"
         << "of your new life. They call themselves the gruesome twosome. Frank leads you and Charlie back\n"
         << "to town. Along the way he eats the cat food " << '(' << "dude real quick that was a great decision"
         << ')' << ".\n" << " It's apparent that had he not been eating the cat food, you would have been on the\n"
         << "menu. Frank mentions a sequel of some kind, no longer the gruesome twosome, but the UnHoly Trinity.\n"
         << endl;

    cout << " THANK YOU VERY MUCH FOR PLAYING!!! Congrats on the main win by the way.\n" << endl;

    Charlie_Is_Free = 1;
}

void NightmanGame::PlayAgain()
{
    cout << "Would you like to play again?\nY/N\n";

    PlayerAnswer();

    if(player_answer_ == 'Y')
    {
     NightmanGame Game;
     Game.Start();
    }
    else
    {
        GameOver();
    }
}

char NightmanGame::PlayerAnswer()
{
	player_answer_ = toupper(reader.readChar("YNyn"));

	return player_answer_;
}

void NightmanGame::GameOver()
{
    cout << "They say cream rises to the top. Or not.\n" << endl;

    player_hp_ = 0;
    Charlie_Is_Free = 1;
}

void NightmanGame::Puzzle()
{
    cout << "Please enter your answer to the puzzle in the form of 'a blank blank blank'\n" << endl;

    player_answer_string = reader.readString("a five star man");

    if(player_answer_string == "a five star man")
    {
        puzzle_is_solved = 1;

        cout << "You have solved the magical riddle.\n" << endl;
    }
    else
    {
        cout << "Wrong.\nWould you like to try again?\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer_ == 'Y')
        {
            Puzzle();
        }
        else
        {
            cout << "Ok, then.\n" << endl;
        }
    }
}

char NightmanGame::StartFight(int Enemy)
{
	switch(Enemy)
	{
	case kRyanMcPoyle:
		enemy_name_ = "Ryan McPoyle";
		enemy_hp_ = 125;
		enemy_damage_ = 5;
		cout << "Ryan steps forward to defend his brother's honor. Your can only wonder why he chose to wear\n"
             << "just a bathrobe'\n" << endl;
		break;
	case kLiamMcPoyle:
		enemy_name_ = "Liam McPoyle";
		enemy_hp_ = 125;
		enemy_damage_ = 5;
		cout << "Liam steps forward to defend his brother's honor. Your can only wonder why he chose to wear\n"
             << "just a bathrobe'\n" << endl;
		break;
	case kCricket:
		enemy_name_ = "Cricket";
		cout << "Watch out for this crackhead, he will cut you.\n" << endl;
		break;
	case kSnail:
		enemy_name_ = "Snail";
		enemy_hp_ = 100;
		enemy_damage_ = 2;
		cout << "This is your chance. Rid the world of this garbage pail cousin, Gail, once and for all.\n" << endl;
		break;
	case kNightman:
		enemy_name_ = "Nightman";
		enemy_hp_ = 200;
		enemy_damage_ = 6;
		cout << "Hope you thought this through. He has the eyes of a cat.\n" << endl;
		break;
	}
	do
	{
		ShowEnemyHP();

		cout << "would you like to hit " << enemy_name_ << "\?\nY/N\n" << endl;

		PlayerAnswer();

		switch(player_answer_)
		{
		case 'Y':
			HitEnemy();
			break;
		case 'N':
			cout << "Terrible decision." << enemy_name_ << " hits you instead.\n" << endl;
			HitPlayer();
			break;
		}
	}
	while((player_hp_ > 0)&&(enemy_hp_ > 0));

	if(player_hp_ > 0 )
	{
		cout << "Dude! You smashed " << enemy_name_ << "'s" << " b**** ass good!\n" << endl;

		return 'W';
	}
	else
	{
		cout << "Yup, you guessed it. " << enemy_name_ << " smashed you like a rat.\n" << endl;

		return 'L';
    }
}

double NightmanGame::RollToHit()
{
    dam_mult_ = 0;
	die_amount_ = ((rand()%6)+1);
	switch(die_amount_)
	{
	case 1:
		dam_mult_ = .5;
		break;
	case 2:
		dam_mult_ = 1;
		break;
	case 3:
		dam_mult_ = 1.5;
		break;
	case 4:
		dam_mult_ = 2;
		break;
	case 5:
		dam_mult_ = 2.5;
		break;
	case 6:
		dam_mult_ = 3;
		break;
    }

	return dam_mult_;
}

void NightmanGame::HitEnemy()
{
    RollToHit();

	player_damage_ = 10;

	player_damage_ = (player_damage_ + (player_damage_ * dam_mult_));

	enemy_hp_ = enemy_hp_ - player_damage_;

	if((player_hp_ > 0)&&(enemy_hp_ > 0))
    {
        cout << "You have hit " << enemy_name_ << " for " << player_damage_
             << " units of damage.\n" << endl;

        ShowEnemyHP();

		HitPlayer();
	}
	else if((player_hp_ < 0)&&(enemy_hp_ > 0))
	{
		cout << "Bested by your opponent. This spells the end.\n" << endl;
	}
	else
    {
        cout << "Hit was worth: " << player_damage_ << "\n" << endl;

        cout << "This fight has ended. Go ahead, you know you want to. Spit on your defeated opponent.\n" << endl;
    }
}

void NightmanGame::HitPlayer()
{
    ShowPlayerHP();

    cout << enemy_name_ << " is attacking you.\n" << endl;

	//damage comess in based on enemy stats.

	RollToHit();

	enemy_damage_ = (enemy_damage_ + (enemy_damage_ * dam_mult_));

	player_hp_ = player_hp_ - enemy_damage_;

	if((enemy_hp_ > 0)&&(player_hp_ > 0))
	{
        cout << enemy_name_ << " has hit you for " << enemy_damage_ << " units of damage.\n"
             << endl;

		cout << "Player HP: " << player_hp_ << "\n" << endl;
	}
	else
	{
		cout << "Uh-oh.\n" << endl;
	}
}

void NightmanGame::ShowPlayerHP()
{
    cout << "Player HP: " << player_hp_ << "\n" << endl;
}

void NightmanGame::ShowEnemyHP()
{
    cout << "Enemy HP: " << enemy_hp_ << "\n" << endl;
}

void NightmanGame::CricksIsOut()
{
    cout << "Feel good about yourself? You just beat a street urchin to death or unconscious, whatevs.\n"
         << "He did drop a shiv tho. Wanna take it?\nY/N\n" << endl;

    PlayerAnswer();

    if((player_answer_ == 'Y')&&(player_has_stick == 1))
    {
        player_has_shiv = 1;
        player_has_spear = 1;

        cout << "Yeah bro sweet!! With your shiv, this rope and stick will make a bad ass spear!!.\n"
             << "Someone could get totally blasted in the throat with this thing!!\n" << endl;

        cout << "With Cricks out it's time to bounce! Press C to go back to the Chamber Room.\n" << endl;

        player_answer_ = toupper(reader.readChar("Cc"));

        if(player_answer_ == 'C')
        {
            current_room = 3;
        }
    }
    else if((player_answer_ == 'Y')&&(player_has_stick == 0))
    {
        player_has_shiv = 1;

        cout << "Sweet bro you got a shiv. with a few other handy cave materials you could have some\n"
             << "kind of awesome throwing atlatl type weapon...\n" << endl;

        cout << "With Cricks out it's time to bounce! Press C to go back to the Chamber Room.\n" << endl;

        player_answer_ = toupper(reader.readChar("Cc"));

        if(player_answer_ == 'C')
        {
            current_room = 3;
        }
    }
    else
    {
        cout << "Ok let's just leave a sweet shiv on the floor.\n" << endl;

        cout << "With Cricks out it's time to bounce! Press C to go back to the Chamber Room.\n" << endl;

        player_answer_ = toupper(reader.readChar("Cc"));

        if(player_answer_ == 'C')
        {
            current_room = 3;
        }
    }
}

void NightmanGame::ClearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}
