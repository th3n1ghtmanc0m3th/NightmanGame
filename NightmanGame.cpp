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
    player_hp_ = 100;
    Charlie_Is_Free = 0;
    Artemis_Is_Free = 0;
    Maidens_Free = 0;
    puzzle_is_solved = 0;
}

void NightmanGame::Start()
{
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
        case 11:
            DennisChamber();
        }
    }
    cout << "The game is over.\n";

}

void NightmanGame::Tavern()
{
    cout << "Sitting in a lively tavern you notice a crusty and highly inebriated\n"
    << "dwarf shooting dark glances in your direction. After an hour and several\n"
    << "more pints, the dwarf staggers over to you.\n" << '"' << "You ever "
    << "heard of the Treasure of the Nightman?" << '"' << "\n"
    << "Y/N" << endl;

    PlayerAnswer();

    if(player_answer == 'Y')
    {
        current_room = 2;
    }
    else
    {
        cout << "Dwarf:" << '"' << "What? You're an idiot, why am I talking to you?"
        << '"' << "\nThe dwarf then pulls out his hammer and proceeds to bash you like"
        << " a rat.\n" << "Great. Smart move. Now you're dead. You know, next time\n"
        << "someone asks you about the Nightman's Treasure, don't ask questions\n"
        << "just say, 'Yes'" << "\n" << endl;

        PlayAgain();
    }
}

void NightmanGame::CaveEntrance()
{
    cout << "You find yourself standing at the entrance to an ominous and\n"
    << "foreboding cave. The entrance is littered with bones and signs that are\n"
    << "barely legible. You notice a few odd items strewn about. There is a sword,\n"
    << "half buried in the dirt. Nearby is a torch and right next to the entrance is\n"
    << "a half baked chicken in denim shorts, a denim chicken." << "\n" << endl;

    cout << "Would you like to pick up the sword?\nY/N\n" << endl;

    PlayerAnswer();

    if(player_answer == 'Y')
    {
        cout << "Think you're so smart, picking up the big bad sword. Well guess what?\n"
             << "You sliced an artery digging it out. You're dead.\n" << endl;

        PlayAgain();

    }
    else
    {
        cout << "Moving on.\n" << endl;
    }

    if(player_has_torch == 0)
    {
        cout << "Would you like to pick up the torch?\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer == 'Y')
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
        cout << "You have the torch already.\n" << endl;
    }

    if(player_has_DC == 0)
    {
            cout << "Would you like to pick up the denim chicken?\nY/N\n" << endl;

        PlayerAnswer();

        if(player_answer == 'Y')
        {
            player_has_DC = 1;

            cout << "Hang on. Denim Chicken?\n";
        }
        else
        {
            cout << "Hmm, I don't know man, Denim Chicken though.\n";
        }
    }
    else
    {
        cout << "Oh, fret not. You got the denim chicken.\n";
    }

    cout << "So you have made your preparations. Would you like to enter the cave?\nY/N\n" << endl;

    PlayerAnswer();

    if(player_answer == 'Y')
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
             << "Bird Wif Teeth. Weird.\n" << endl;

        if(player_has_glue == 0)
        {
            cout << "Looking around you don't see much except for a bottle of glue. It's pretty intense\n"
                 << "stuff. Industrial grade. I'd be careful with who you show that to.\n"
                 << "Would you like to pick up the glue?\nY/N\n" << endl;

            PlayerAnswer();

            if(player_answer == 'Y')
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

        player_answer = toupper(reader.readChar("CBcb"));

        if(player_answer == 'C')
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
             << "you head back out and hit your head pretty hard.\n";

        player_hp_ = player_hp_ - 10;

        cout << "Player Health: " << player_hp_ << endl;

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

        if(player_answer == 'Y')
        {
            cout << "Oh sweet bro a stick with rope. With a pointed object, you could have a spear.\n" << endl;
            player_has_stick = 1;
        }
        else
        {
            cout << "Well, no stick for you.\n" << endl;
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

        if(player_answer == 'Y')
        {
            cout << "Oh yeah! Totally sick throwing star for karate!\n" << endl;
            player_has_star = 1;
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
         << "The bird lady starts squawking and you just look at her and you're just like,\n" << '"'
         << "Shut up bird" << '"' << "\n" << endl;

    cout << "After The bird shuts up, you see three exits. Pressing A will take you to Artemis's Bin.\n"
         << "Pressing M will take you to the McPoyle Chamber and pressing C will take you back to the\n"
         << "Chamber Room.\n" << endl;

     player_answer = toupper(reader.readChar("AMCamc"));

     switch(player_answer)
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

            if(player_answer == 'Y')
            {
                cout << "Being a generous egg, you hand over the glue to Crick's. Big mistake. After several prolonged\n"
                     << "pulls on the glue, Cricket goes into a glue frenzy. You are bashed like a rat with his sweet\n"
                     << "steel drums.\n" << endl;

                PlayAgain();
            }
            else
            {
                cout << "With as much indignation as you can muster you say," << '"' << "Shut up street rat" << '"'
                     << "\n" << "Cricket lunges to attack, but without glue, let's be honest. He is a street urchin\n"
                     << "Crick's drops a shiv he was carrying.\nDo you pick it up?\nY/N\n";

                PlayerAnswer();

                if(player_answer == 'Y')
                {
                    cout << "You have a shiv!\n";
                    player_has_shiv = 1;
                }
                else
                {
                    cout << "Dumb choice. You're taking the shiv.\n";
                    player_has_shiv = 1;
                }

                cout << "Press C to go back to the Chamber Room.\n" << endl;

                player_answer = toupper(reader.readChar("Cc"));

                if(player_answer == 'C')
                {
                    current_room = 3;
                }
            }
        }
        else
        {
            cout << "Cricket just babbles and babbles about Archangels and hips and nips.\nYou should just head out"
                 << " and come back later with something a little more interesting.\nPress C to go back to the Chamber"
                 << " Room\n" << endl;

            player_answer = toupper(reader.readChar("Cc"));

            if(player_answer == 'C')
            {
                current_room = 3;
            }
        }
    }
    else
    {
        cout << "Dude, Cricks is already unconscious or dead, who cares, but the point is. You got his shiv and this\n"
             << "place is just dogs and a urine soaked street rat.\nPress C to go back to the Chamber Room.\n" << endl;

        player_answer = toupper(reader.readChar("Cc"));

        if(player_answer == 'C')
        {
            current_room = 3;
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

        if(player_answer == 'Y')
        {
            cout << '"' << "You want some salt to go with that sweet sugar," << '"' << "She purrs at you.\n"
                 << "Y/N\n" << endl;

            PlayerAnswer();

            if(player_answer == 'Y')
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

        cout << "Change room.\n";
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

            if(player_answer == 'Y')
            {
                cout << "got salt.\n" << endl;
            }
            else
            {
                cout << "no salt.\n" << endl;
            }
        }

        cout << "Time to leave again. Press B to go back to the Bird Tunnel.\n" << endl;

        player_answer = toupper(reader.readChar("Bb"));

        if(player_answer == 'B')
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

        if((player_has_star == 1)&&(player_has_spear == 1))
        {
            cout << "The brothers attack, but you had the good foresight to bring some serious weaponry.\n"
                 << "You throw the spear first, instantly killing Ryan. Liam goes to attack next but you throw\n"
                 << "the star and it takes out his only good eye. He stumbles around and falls off his post.\n"
                 << "In the fall his neck breaks.\n" << endl;

                 McPoyles_Alive = 0;
        }
        else if((player_has_star == 1)&&(player_has_spear == 0))
        {
            cout << "The brothers move to attack, but you thsnkfully brought that throwing star. Hurling it with all\n"
                 << "your might, it takes out Liam's good eye. He falls off his platform and breaks his neck.\n"
                 << '"' << "You killed Liam!!" << '"' << " Ryan screams and moves to attack.\n" << endl;

            StartCombat();
        }
        else if((player_has_star == 0)&&(player_has_spear == 1))
        {
            cout << "When the brothers go to attack, you throw your spear. Hitting Ryan square in the throat there\n"
                 << "an arterial spray that paints the nearby walls red. Liam, enraged, comes snarling toward you.\n"
                 << endl;

            StartCombat();
        }
        else
        {
            //figure out what to do about fighting both.

            StartCombat();
        }

        McPoyles_Alive = 0;

        cout << "You have defeated the McPoyle's.\n" << "Press B for Bird Tunnel, J for Maiden Jail or S for Snail Trail.\n" << endl;

        player_answer = toupper(reader.readChar("BbJjSs"));

        switch(player_answer)
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
        cout << "The McPoyle's limp lifeless bodies are really stinking up the place. Better get a move on.\n"
             << "Press B for Bird Tunnel, J for Maiden Jail or S for Snail Trail.\n" << endl;

        player_answer = toupper(reader.readChar("BbJjSs"));

        switch(player_answer)
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
}

void NightmanGame::SnailTrail()
{
    if(Snail_is_Alive == 1)
    {
        cout << "Description for snail trail.\n" << endl;

        if(player_has_salt == 1)
        {
            cout << "Descrip for immediate salting.\n" << endl;

            cout << "She salted.\n" << endl;

            player_answer = toupper(reader.readChar("MmIi"));

            switch(player_answer)
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
            cout << "Combat with snail.\n" << endl;

            StartCombat();

            cout << "Next room.\n" << endl;

            player_answer =toupper(reader.readChar("MmIi"));

            switch(player_answer)
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
    else
    {
        cout << "You have already salted the snail. It's time to bounce.\n"
             << "Press M for McPoyle Chamber or I for The Implication Room.\n" << endl;

        player_answer =toupper(reader.readChar("MmIi"));

        switch(player_answer)
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

        if(player_answer == 'Y')
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

        if(player_answer == 'Y')
        {
            Maidens_Free = 1;
            player_has_catfood =1;

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

        player_answer = toupper(reader.readChar("MmIi"));

        switch(player_answer)
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

        player_answer = toupper(reader.readChar("MmIi"));

        switch(player_answer)
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
            puzzle_is_solved = 1;

            cout << "Solved the riddle.\n" << endl;
        }
        else
        {
            cout << "Wrong.\nWould you like to try again?\nY/N\n" << endl;

            player_answer = toupper(reader.readChar("YyNn"));

            if(player_answer == 'Y')
            {
                Puzzle();
            }
            else
            {
                cout << "Ok, then.\n" << endl;
            }
        }

        cout << "move.\n" << endl;

        player_answer = toupper(reader.readChar("JjNnSs"));

        switch(player_answer)
        {
        case 'J':
            current_room = 9;
            break;
        case 'N':
            //current_room = 12;
            cout << "almost.\n" << endl;
            break;
        case 'S':
            current_room = 10;
            break;
        }
    }
    else
    {
        cout << "Puzzle Solved, Dennis gone, you have rum ham.\n" << endl;

        cout << "move.\n" << endl;

        player_answer = toupper(reader.readChar("JjNnSs"));

        switch(player_answer)
        {
        case 'J':
            current_room = 9;
            break;
        case 'N':
            //current_room = 12;
            cout << "almost.\n" << endl;
            break;
        case 'S':
            current_room = 10;
            break;
        }
    }
}

void NightmanGame::NightmanChamber()
{

}

void NightmanGame::CharliesCage()
{
    cout << "Charlie's Cage. Open?\nY/N\n";

}

void NightmanGame::ReturntoTown()
{

}

void NightmanGame::StartCombat()
{
    enemy_hp_ = 100;

    do
	{
		cout << "would you like to hit?\n";

        PlayerAnswer();

        if(player_answer == 'Y')
        {
            cout << "You hit the enemy.\n";
            enemy_hp_ -= 25;
            cout << "enemy health is: " << enemy_hp_ << endl;
        }
        else
        {
            cout << "Enemy hits you.\n";
            player_hp_ =-25;
            cout << "player hp is: " << player_hp_ << endl;
        }
    }
    while((player_hp_ > 0)&&(enemy_hp_ > 0));

	if(player_hp_ > 0)
	{
		cout << "good job you won\n" << endl;
	}
	else
	{
		cout << "dang you died\n" << endl;

		PlayAgain();
	}
}

void NightmanGame::PlayAgain()
{
    cout << "Would you like to play again?\nY/N\n";

    PlayerAnswer();

    if(player_answer == 'Y')
    {
     Start();
    }
    else
    cout << "Game Over.\n";
    GameOver();
}

char NightmanGame::PlayerAnswer()
{
	player_answer = toupper(reader.readChar("YNyn"));

	return player_answer;
}

void NightmanGame::Puzzle()
{
    cout << "Please enter your answer to the puzzle in the form of 'a blank blank blank'\n" << endl;

    player_answer_string = reader.readString("a five star man");

    if(player_answer_string == "a five star man")
    {
        puzzle_is_solved = 1;

        cout << "Solved the riddle.\n" << endl;
    }
    else
    {
        cout << "Wrong.\nWould you like to try again?\nY/N\n" << endl;

        player_answer = toupper(reader.readChar("YyNn"));

        if(player_answer == 'Y')
        {
            //run puzzle function
        }
        else
        {
            cout << "Ok, then.\n" << endl;
        }
    }
}

void NightmanGame::GameOver()
{
    cout << "They say cream rises to the top. Or not.\n";

    player_hp_ = 0;
    Charlie_Is_Free = 1;
}

NightmanGame::Combat::Combat()
{
    enemy_hp_ = 150;
    player_damage_ = 10;
    enemy_damage_ = 5;
}

void NightmanGame::Combat::StartFight(int Enemy)
{
	switch(Enemy)
	{
	case kRyanMcPoyle:
		enemy_name_ = "Ryan McPoyle";
		cout << "Descrip about fighting Ryan.\n" << endl;
		break;
	case kLiamMcPoyle:
		enemy_name_ = "Liam McPoyle";
		cout << "Descrip about fighting Liam.\n" << endl;
		break;
	case kCricket:
		enemy_name_ = "Cricket";
		cout << "Descrip for fighting Cricket.\n" << endl;
		break;
	case kSnail:
		enemy_name_ = "Snail";
		cout << "Descrip for fighting Snail.\n" << endl;
		break;
	case kNightman:
		enemy_name_ = "Nightman";
		cout << "Descrip for fighting Nightman.\n" << endl;
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
			cout << "not yet titties.\n" << endl;
			break;
		}
	}
	while((player_hp_ > 0)&&(enemy_hp_ > 0));

	if(player_hp_ > 0 )
	{
		cout << "Dude! You smashed " << enemy_name_ << "'s" << " bitch ass good!\n" << endl;
	}
	else
	{
		cout << "Yup, you guessed it. " << enemy_name_ << " smashed you like a rat.\n" << endl;
	}
}

char Combat::PlayerAnswer()
{
    cin >> player_answer_;

    if(player_answer_ == 'Y')
        return player_answer_;
    else
        return player_answer_;
}

int Combat::RollToHit()
{
    dam_mult_ = 0;
	die_amount_ = ((rand()%6)+1);
	switch(die_amount_)
	{
	case 1:
		dam_mult_ = 2;
		break;
	case 2:
		dam_mult_ = 3;
		break;
	case 3:
		dam_mult_ = 4;
		break;
	case 4:
		dam_mult_ = 5;
		break;
	case 5:
		dam_mult_ = 6;
		break;
	case 6:
		dam_mult_ = 7;
		break;
    }

	return dam_mult_;
}

void Combat::HitEnemy()
{
    RollToHit();

	//damage will be pulled in from weapon character has, for now damage is..
	player_damage_ = 10;

	player_damage_ = player_damage_ * dam_mult_;

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

void NightmanGame::Combat::HitPlayer()
{
    ShowPlayerHP();

    cout << enemy_name_ << " is attacking you.\n" << endl;

	//damage comess in based on enemy stats.

	RollToHit();

	enemy_damage_ = 10;

	enemy_damage_ = enemy_damage_ * dam_mult_;

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

void NightmanGame::Combat::ShowPlayerHP()
{
    cout << "Player HP: " << player_hp_ << "\n" << endl;
}

void NightmanGame::Combat::ShowEnemyHP()
{
    cout << "Enemy HP: " << enemy_hp_ << "\n" << endl;
}
