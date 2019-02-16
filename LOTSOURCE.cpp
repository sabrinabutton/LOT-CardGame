/********************************************************************************************
*																							*
*		By Sabrina Button                        											*                             
*       January 2019                                                      					*
*       Programmed in Dev C++ Version 5.11													*
*		The Legend Of Tarot ICS3U Summative Game by Sabrina Button							*
*		Data Dictionary (Global Variables):													*
*		(suitname)graphics[4] - string graphic for each of 4 cards in suit					*
*		(suitname)Stats[4][5] - 5 stats (owned, weak atk, reg atk, strong atk, suit value)	*
*									for each of 4 cards in given suit						*
*		username - users name for themselves												*
*		nickname - version of user's name for themselves consisting of 						*
*					first 2 letters and last 3												*
*		coins - amount of coins user has													*
*		playerhand[5] - stores card graphics in form (suit)graphic[x] within players hand	*
*						user holds 5 cards which game reads in battle to determine			*
*							stats and for visual purpose									*
*		userhealth - amount of health points user has										*
*		Data Dictionary (Main Menu Function):												*
*		keypress - integer which value corresponds to which key (which are defined			*
*						as getch values) is pressed											*
*		menucursorx - integer representing the x (vertical) location of the users cursor	*
*						which indicates where to print something							*	
*		menucursory - integer representing the y (horizontal) location of the users cursor	*
*						which indicates where to print something							*													
*																							*
*********************************************************************************************/
/******BRING IN LIBRARIES******/
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <cstdlib>
using namespace std;

/******DECLARE KEYS******/
#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77

/******GLOBAL VARIABLES******/
//card graphics
	//HEARTS
	string heartsgraphics[4] = {
	/*thefool*/ "\n _______________________\n|                       |\n| I THE FOOL            |\n|                       |\n|      ,d88b.d88b,      |\n|      88888888888      |\n|      `Y8888888Y'      |\n|        `Y888Y'        |\n|          `Y'          |\n|                       |\n|  R ATK: 4             |\n|                       |\n|  W ATK: 3             |\n|                       |\n|  S ATK: 6             |\n|                       |\n| Trumps Pentacles      |\n|_______________________|",
	/*thelovers*/ "\n _______________________\n|                       |\n| II THE LOVERS         |\n|                       |\n|      ,d88b.d88b,      |\n|      88888888888      |\n|      `Y8888888Y'      |\n|        `Y888Y'        |\n|          `Y'          |\n|                       |\n|  R ATK: 5             |\n|                       |\n|  W ATK: 3             |\n|                       |\n|  S ATK: 6             |\n|                       |\n| Trumps Pentacles      |\n|_______________________|",
	/*thehermit*/"\n _______________________\n|                       |\n| III THE HERMIT        |\n|                       |\n|      ,d88b.d88b,      |\n|      88888888888      |\n|      `Y8888888Y'      |\n|        `Y888Y'        |\n|          `Y'          |\n|                       |\n|  R ATK: 7             |\n|                       |\n|  W ATK: 7             |\n|                       |\n|  S ATK: 7             |\n|                       |\n| Trumps Pentacles      |\n|_______________________|",	
	/*thedevil*/"\n _______________________\n|                       |\n| IV THE DEVIL          |\n|                       |\n|      ,d88b.d88b,      |\n|      88888888888      |\n|      `Y8888888Y'      |\n|        `Y888Y'        |\n|          `Y'          |\n|                       |\n|  R ATK: 8             |\n|                       |\n|  W ATK: 5             |\n|                       |\n|  S ATK: 10            |\n|                       |\n| Trumps Pentacles      |\n|_______________________|"
	};
	
	//PENTACLES
	string pentaclesgraphics[4] = {
	/*thepriestess*/"\n _______________________\n|                       |\n| I THE HIGH PRIESTESS  |\n|                       |\n|          /`\\          |\n|    .----/---\\----.    |\n|     `'./     \\.'`     |\n|       /`'.'.'`\\       |\n|      /,-`   `-,\\      |\n|                       |\n|  R ATK: 3             |\n|                       |\n|  W ATK: 1             |\n|                       |\n|  S ATK: 5             |\n|                       |\n| Trumps Wands          |\n|_______________________|",
	/*theemporer*/"\n _______________________\n|                       |\n| II THE EMPORER        |\n|                       |\n|          /`\\          |\n|    .----/---\\----.    |\n|     `'./     \\.'`     |\n|       /`'.'.'`\\       |\n|      /,-`   `-,\\      |\n|                       |\n|  R ATK: 5             |\n|                       |\n|  W ATK: 4             |\n|                       |\n|  S ATK: 7             |\n|                       |\n| Trumps Wands          |\n|_______________________|",
	/*temperance*/"\n _______________________\n|                       |\n| III TEMPERANCE        |\n|                       |\n|          /`\\          |\n|    .----/---\\----.    |\n|     `'./     \\.'`     |\n|       /`'.'.'`\\       |\n|      /,-`   `-,\\      |\n|                       |\n|  R ATK: 7             |\n|                       |\n|  W ATK: 0             |\n|                       |\n|  S ATK: 7             |\n|                       |\n| Trumps Wands          |\n|_______________________|",
	/*thesun*/"\n _______________________\n|                       |\n| IV THE SUN            |\n|                       |\n|          /`\\          |\n|    .----/---\\----.    |\n|     `'./     \\.'`     |\n|       /`'.'.'`\\       |\n|      /,-`   `-,\\      |\n|                       |\n|  R ATK: 9             |\n|                       |\n|  W ATK: 9             |\n|                       |\n|  S ATK: 10            |\n|                       |\n| Trumps Wands          |\n|_______________________|"
	};
		
	//WANDS
	string wandsgraphics[4] = {
	/*wizard*/"\n _______________________\n|                       |\n| I THE WIZARD          |\n|                       |\n|   .^.:.               |\n|  <.*.'::.  *     .*   |\n|    |  .:''    .:'     |\n|    |  '::.  .:'       |\n|    |    ':::'    *    |\n|                       |\n|  R ATK: 3             |\n|                       |\n|  W ATK: 0             |\n|                       |\n|  S ATK: 8             |\n|                       |\n| Trumps Swords         |\n|_______________________|",	
	/*hangedman*/"\n _______________________\n|                       |\n| II THE HANGED MAN     |\n|                       |\n|   .^.:.               |\n|  <.*.'::.  *     .*   |\n|    |  .:''    .:'     |\n|    |  '::.  .:'       |\n|    |    ':::'    *    |\n|                       |\n|  R ATK: 4             |\n|                       |\n|  W ATK: 2             |\n|                       |\n|  S ATK: 8             |\n|                       |\n| Trumps Swords         |\n|_______________________|",					
	/*death*/   "\n _______________________\n|                       |\n| III DEATH             |\n|                       |\n|   .^.:.               |\n|  <.*.'::.  *     .*   |\n|    |  .:''    .:'     |\n|    |  '::.  .:'       |\n|    |    ':::'    *    |\n|                       |\n|  R ATK: 9             |\n|                       |\n|  W ATK: 6             |\n|                       |\n|  S ATK: 10            |\n|                       |\n| Trumps Swords         |\n|_______________________|",					
	/*themoon*/ "\n _______________________\n|                       |\n| IV THE MOON	        |\n|                       |\n|   .^.:.               |\n|  <.*.'::.  *     .*   |\n|    |  .:''    .:'     |\n|    |  '::.  .:'       |\n|    |    ':::'    *    |\n|                       |\n|  R ATK: 7             |\n|                       |\n|  W ATK: 8             |\n|                       |\n|  S ATK: 7             |\n|                       |\n| Trumps Swords         |\n|_______________________|"
	};									
			 
	//SWORDS
	string swordsgraphics[4] = {
	/*theempress*/"\n _______________________\n|                       |\n| I THE EMPRESS         |\n|                       |\n|          / \\          |\n|          | |          |\n|          |.|          |\n|        `--8--'        |\n|           8           |\n|                       |\n|  R ATK: 3             |\n|                       |\n|  W ATK: 3             |\n|                       |\n|  S ATK: 4             |\n|                       |\n| Trumps Runes          |\n|_______________________|",	
	/*thechariot*/"\n _______________________\n|                       |\n| II THE CHARIOT        |\n|                       |\n|          / \\          |\n|          | |          |\n|          |.|          |\n|        `--8--'        |\n|           8           |\n|                       |\n|  R ATK: 6             |\n|                       |\n|  W ATK: 1             |\n|                       |\n|  S ATK: 10            |\n|                       |\n| Trumps Runes          |\n|_______________________|",			 
	/*strength*/"\n _______________________\n|                       |\n| III STRENGTH          |\n|                       |\n|          / \\          |\n|          | |          |\n|          |.|          |\n|        `--8--'        |\n|           8           |\n|                       |\n|  R ATK: 9             |\n|                       |\n|  W ATK: 9             |\n|                       |\n|  S ATK: 0             |\n|                       |\n| Trumps Runes          |\n|_______________________|",			 
	/*thestar*/"\n _______________________\n|                       |\n| IV THE STAR           |\n|                       |\n|          / \\          |\n|          | |          |\n|          |.|          |\n|        `--8--'        |\n|           8           |\n|                       |\n|  R ATK: 3             |\n|                       |\n|  W ATK: 12            |\n|                       |\n|  S ATK: 12            |\n|                       |\n| Trumps Runes          |\n|_______________________|"
	};	
	
	//RUNES
	string runesgraphics[4] = {
	/*theheiro*/"\n _______________________\n|                       |\n| I THE HIEROPHANT      |\n|                       |\n|         _____         |\n|        / _  /         |\n|        \\// /          |\n|         / //\\         |\n|        /____/         |\n|                       |\n|  REMOVES RANDOM       |\n|                       |\n|  CARD FROM            |\n|                       |\n|  THE OPPONENT.        |\n|                       |\n| Trumps Hearts         |\n|_______________________|",	
	/*justice*/"\n _______________________\n|                       |\n| II JUSTICE            |\n|                       |\n|         _____         |\n|        / _  /         |\n|        \\// /          |\n|         / //\\         |\n|        /____/         |\n|                       |\n|  R: BOTH Ps HP+2      |\n|                       |\n|  W: OPPONENT HP +4    |\n|                       |\n|  S: PLAYER HP +5      |\n|                       |\n| Trumps Hearts         |\n|_______________________|",			 		 
	/*wof*/"\n _______________________\n|                       |\n| III WHEEL OF FORTUNE  |\n|                       |\n|         _____         |\n|        / _  /         |\n|        \\// /          |\n|         / //\\         |\n|        /____/         |\n|                       |\n|  RAISES THE           |\n|                       |\n|  WINNING MONEY        |\n|                       |\n|  BY 30%.              |\n|                       |\n| Trumps Hearts         |\n|_______________________|",			 		 
	/*judgement*/"\n _______________________\n|                       |\n| IV JUDGEMENT          |\n|                       |\n|         _____         |\n|        / _  /         |\n|        \\// /          |\n|         / //\\         |\n|        /____/         |\n|                       |\n|  8 HEALTH IS          |\n|                       |\n|  GIVEN TO THE         |\n|                       |\n|  LOSING PLAYER.       |\n|                       |\n| Trumps Hearts         |\n|_______________________|"
	};	
	
//card stats
	//HEARTS (suit 1)
	int heartsStats[4][5] ={
	/*thefoolStats*/       {/*owned? 1 = yes*/1, /*weak atk*/ 3, /*reg atk*/ 4, /*strongatk*/ 6, /*suit no.*/ 1} ,    
	/*theloversStats*/     {0, 3, 5, 6, 1},
	/*thehermitStats*/     {0, 7, 7, 7, 1},
	/*thedevilStats*/	  {0, 5, 8, 10, 1}
	};
	
	//PENTACLES (suit 2)
	int pentaclesStats[4][5]={
		/*thepriestessStats*/  {1, 1, 3, 5, 2},
	 /*theemporerStats*/	{0, 4, 5, 7, 2},
	/*temperanceStats*/    {0, 0, 7, 7, 2},
	/*thesunStats*/        {0, 9, 9, 10, 2}
	};
	
	
	//WANDS (suit 3)
	int wandsStats[4][5] = {
		/*thewizardStats*/     {1, 0, 3, 8, 3},
	/*thehangedStats*/	   {0, 2, 4, 8, 3},
	/*deathStats*/		   {0, 6, 9, 10, 3},
	/*themoonStats*/	   {0, 8, 7, 7, 3}
	};
	

	//SWORDS (suit 4)
	int swordsStats[4][5] = {
		/*theempressStats*/     {1, 3, 3, 4, 4},
	/*thechariotStats*/     {0, 6, 1, 10, 4},
	/*strengthStats*/       {0, 9, 9, 0, 4},
	/*thestarStats*/        {0, 12, 3, 12, 4}
	};
	
	
	//RUNES (suit 5)
	//Runes are special ability cards, so they only have a ownership value and suit value (most of the time)
	//individual abilities are explained in the attack function
	int runesStats[4][5] = {
		/*thehieroStats*/       {/*owned*/1, /*null*/0, 0, 0,/*suit*/ 5},
	 /*justiceStats*/        {0, 4, 2, 5, 5},
	/*wofStats*/            {0, 0, 0, 0, 5},
	/*judgementStats*/     {0, 0, 0, 0, 5}
	};
 			 		 		 	
//user's name
string username;
//user's nickname
string nickname;
//user's money
int coins;
//user's deck graphics
string playerhand[5] = {heartsgraphics[0], pentaclesgraphics[0], wandsgraphics[0],swordsgraphics[0],runesgraphics[0]};
//user's health
int userhealth;

/******FUNCTION DECLARATIONS******/
//set cursor pos
void gotoxy(int eex, int eey);
//main menu
void mainmenu();
//introduction
void intro();
//voids for saving game to a text file and loading game variables from the same text file
void savegame();
void loadgame();
//vector for loading card graphics
vector<string> split(const string& cardgraphic);
//map
void map();
//shop
void shop();
//buy specific card branch of shop function
void buycard(int selectedsuitStats[4][5],string selectedsuitGraphics[4]);
//battle 
void battle();
//generate opponent function
void generateopponent(string &fOpponentName, string fOpponentHand[5], int &fOpponentHealth);
// attack
int attack(int opposinghealth, int &localhealth, string localHand[5], int &localPlayed, string awayHand[5], int &awayPlayed, int awayPreviousPlayed[4], int &bettedmoney, int roundNum);

/******MAIN FUNCTION******/
int main ()
{
	//execute main menu function to begin
	mainmenu();
}

/******MAIN MENU******/
void mainmenu()
{	
	//play music 
	PlaySound("mainmenumusic.wav", NULL, SND_ASYNC | SND_FILENAME);
	
	//set system colour to red
	system("Color 0c");
	//clear screen to avoid error messages
	system("cls");
	
	//LOCAL VARIABLES
	//getch values for user's input
	int keypress = 0;
	//values for coordinates
	int menucursorx = 5, menucursory = 4;
	
	//while the right key is not pressed
    while(keypress!=77)
    {
    	//show title and options
    	cout << " - = THE LEGEND OF TAROT = - \n\n      fantasy card game";
    	cout << "\n\n        PLAY";
    	cout << "\n        INSTRUCTIONS";
    	cout << "\n        EXIT";
    	//instruct user
		cout << "\n\n\n *press up and down to navigate*\n *press right arrow to select*";
    	
    	//set cursor 
			gotoxy(menucursorx,menucursory);
			//clear area of @
			printf (" ");
			//set cursor 
			gotoxy(menucursorx,menucursory);
			//print @ other option
			printf ("@");
			
    	//set key pressed value to 0
        keypress = 0;
			
		//switch based on c's value	
        switch((keypress=getch())) 
		{
			//if they press the up key
			case KEY_UP:
				if (menucursory!=4)
				{
					menucursory -= 1;					
				}
			break;
    			
    		//if they press down key
      	    case KEY_DOWN:
      	    	if (menucursory!=6)
				  {
				  		menucursory += 1;
				  }
      	    break;
      	    
      	    //if user presses right key (to select)
      	    case KEY_RIGHT:
      	    	//clear screen to prep to show new menu
      	    	system ("cls");
      	    	//if they select on play
      	    	if(menucursory == 4)
      	    	{
      	    		//set key pressed value to 0
        			keypress = 0;
    				
    				//while the right key is not pressed
    				while(keypress!=77)
   					 {
    						//show title and options for play
    						cout << " - = THE LEGEND OF TAROT = - \n\n      fantasy card game";
    						cout << "\n\n        NEW GAME";
    						cout << "\n        LOAD GAME";
    	
    						//set cursor 
								gotoxy(menucursorx,menucursory);
								//clear area of @
								printf (" ");
								//set cursor 
								gotoxy(menucursorx,menucursory);
								//print @ other option
								printf ("@");
			
    						//set key pressed value to 0
        					keypress = 0;
			
							//switch based on c's value	
        					switch((keypress=getch())) 
							{
								//if they press the up key
									case KEY_UP:
									if (menucursory!=4)
									{
										menucursory -= 1;					
									}
								break;
    			
    							//if they press down key
      	    					case KEY_DOWN:
      	    						if (menucursory!=5)
									  {
									  		menucursory += 1;
									  }
      	    					break;
      	    
      	   					 //if user presses right key (to select)
      	   					 case KEY_RIGHT:
      	    						//if they select on play
      	    						if(menucursory == 4)
      	    						{
      	    							//run the intro
      	    							intro();
									}
      	    						//if they select on loadgame
      	    						if(menucursory == 5)
      	    						{
      	    							//clear screen to not interfere with menu
      	    							system("cls");
      	    							//set keypress = 0 so loop doesnt glitch
      	    							keypress = 0;
      	    							//run loadgame function to grab variables from text file
      	    							loadgame();
      	    							//tell user their progress was loaded after loadgame completes and ask them to press enter before continueing because getchar
      	    							cout << " Progress loaded. If you had not previously saved a file, this may seriously effect gameplay. \n Please do not manually edit the save file, as the game may have trouble reading the file.";
      	    							cout << "\n USERNAME: " <<username<<"\n HEALTH: "<<userhealth<<"\n COINS: "<<coins;
										 cout << " \n Press [Enter] to continue. ";
      	    							getchar();
      	    							//goto map 
      	    							map();
									}
      	   					 break;	
    						}
    						
    						//clear screen
    						system("cls");
    					}
    				
				}
				
      	    	//if they select on instructions
      	    	if(menucursory == 5)
      	    	{
      	    		//clear screen
      	    		system("cls");
      	    		
      	    		//explain game
					cout << "\nIn the Legend of Tarot, you will battle opponents with the Elven Tarot deck. \nThe goal is to defeat the final opponent and be the master of tarot. \n\n"
					"Elven Tarot has five suits: hearts, pentacles, wands, swords and runes. \n\nThe power order goes as follows: \n"
					"Hearts > Pentacles > Wands > Swords > Runes > Hearts\n\nKeep in mind, if 2 suits are not directly beside eachother on the power order, \nthey are nuetral to eachother and" 
					"their attack value is average. If one suit is better, it will user its strong attack value.\nThe weaker of the two will use a weak attack value.\n\n"
					"You can own as many cards as you like, however you can only store 5 in your hand at one time.\\nnIn a game, the goal is to make the opponent run out of"
					"health before you do.";
					cout << "\n\nPress [Enter] to go back.";
					//hold
					getchar();
					//set c = 0 so loops since c is no longer right key value (77)
      	    		keypress = 0;
				}
				
      	    	//if they select on exit
      	    	if(menucursory == 6)
      	    	{
      	    		exit(EXIT_FAILURE);
				}
      	    break;	
    	}
    	
		//clear screen	
		system("cls");
    }
}

/******LOAD GAME FUNCTION******/
void loadgame()
{
	//line string for each line of loading cards
	string line;
	//string for card graphic building
	string cardgraphic;
	//integer for vounting which line card buidler is on
	int linecounter = 0;
	
	//tell user loadgame was executed
	cout << " Loadgame executed...\n";
	
	//declare variable for loading file for userstats
	ifstream loadFileUserStats;
	//variable for loading user's money
	ifstream loadFileCoins;
	//declare variable for loading file of each playerhand card
	ifstream loadFilePH1;
	ifstream loadFilePH2;
	ifstream loadFilePH3;
	ifstream loadFilePH4;
	ifstream loadFilePH5;
	//declare files for loading 1s and 0s idicating whether a user owns a card
	ifstream loadFileCardOwned;

	//open loadfile from "legendoftarotSave.txt" and get the input stream 
    loadFileUserStats.open ("legendoftarotUserStats.txt", ifstream::in);
    //get user saved variables from the file
	loadFileUserStats >> username >> userhealth;
	//close loaded file
    loadFileUserStats.close();
    
    //open loadfile from "legendoftarotSave.txt" and get the input stream 
    loadFileCoins.open ("legendoftarotCoins.txt", ifstream::in);
    //get user saved variables from the file
	loadFileCoins >> coins;
	//close loaded file
    loadFileCoins.close();
	
	//load file containing player's card 1
	loadFilePH1.open ("legendoftarotPH1.txt", ifstream::in);
	//if/when file is open      
  	if (loadFilePH1.is_open())
  	{
  		//set card graphic to nothing to prep for new
  		string cardgraphic = "";
  		//set line to nothing to prep for new
  		line = "";
  		//set line counter to 0 to begin recount
  		linecounter = 0;
  		
  		//getline in file as line and add line to card graphic
   		 while (getline (loadFilePH1, line))
   		 {
   		 	//if line counter is more than 0, so being past the first line
				if (linecounter>0)
				{
					//add a new line to beggining 
					cardgraphic +="\n";
				}	
			
    		cardgraphic += line;
						
			//set line counter +1
			linecounter++;			            	
   		 }
    
   		 //do vector 
  		vector<string> str_split = split(cardgraphic);
  		vector<double> num;
    
   		 string one;
   		 for(vector<string>::size_type i = 0; i != str_split.size(); ++i)
   		 {
    		num.push_back(atoi(str_split[i].c_str()));	
   		 }

    
		//set specific playerhand bit to cardgraphic 
		playerhand[0] = cardgraphic;
		//closefile                                      
   		loadFilePH1.close();
  	}
	
	//load file containing player's card 1
	loadFilePH2.open ("legendoftarotPH2.txt", ifstream::in);
		//if/when file is open      
  	if (loadFilePH2.is_open())
  	{
  		//set card graphic to nothing to prep for new
  		string cardgraphic = "";
  		//set line to nothing to prep for new
  		line = "";
  		//set line counter to 0 to begin recount
  		linecounter = 0;
  		
  		//getline in file as line and add line to card graphic
   		 while (getline (loadFilePH2, line))
   		 {
   		 	//if line counter is more than 0, so being past the first line
				if (linecounter>0)
				{
					//add a new line to beggining 
					cardgraphic +="\n";
				}	
    		cardgraphic += line;	
			
			//set line counter +1
			linecounter++;					            	
   		 }
    
   		 //do vector 
  		vector<string> str_split = split(cardgraphic);
  		vector<double> num;
    
   		 string one;
   		 for(vector<string>::size_type i = 0; i != str_split.size(); ++i)
   		 {
    		num.push_back(atoi(str_split[i].c_str()));	
   		 }

    
		//set specific playerhand bit to cardgraphic 
		playerhand[1] = cardgraphic;
		//closefile                                      
   		loadFilePH2.close();
  	}
	
	//load file containing player's card 1
	loadFilePH3.open ("legendoftarotPH3.txt", ifstream::in);
		//if/when file is open      
  	if (loadFilePH3.is_open())
  	{
  		//set card graphic to nothing to prep for new
  		string cardgraphic = "";
  		//set line to nothing to prep for new
  		line = "";
  		//set line counter to 0 to begin recount
  		linecounter = 0;
  		
  		//getline in file as line and add line to card graphic
   		 while (getline (loadFilePH3, line))
   		 {
   		 	//if line counter is more than 0, so being past the first line
				if (linecounter>0)
				{
					//add a new line to beggining 
					cardgraphic +="\n";
				}	
    		cardgraphic += line;	
			
			//set line counter +1
			linecounter++;		            	
   		 }
    
   		 //do vector 
  		vector<string> str_split = split(cardgraphic);
  		vector<double> num;
    
   		 string one;
   		 for(vector<string>::size_type i = 0; i != str_split.size(); ++i)
   		 {
    		num.push_back(atoi(str_split[i].c_str()));	
   		 }

    
		//set specific playerhand bit to cardgraphic 
		playerhand[2] = cardgraphic;
		//closefile                                      
   		loadFilePH3.close();
  	}
	
	//load file containing player's card 1
	loadFilePH4.open ("legendoftarotPH4.txt", ifstream::in);
		//if/when file is open      
  	if (loadFilePH4.is_open())
  	{
  		//set card graphic to nothing to prep for new
  		string cardgraphic = "";
  		//set line to nothing to prep for new
  		line = "";
  		//set line counter to 0 to begin recount
  		linecounter = 0;
  		
  		//getline in file as line and add line to card graphic
   		 while (getline (loadFilePH4, line))
   		 {
   		 	//if line counter is more than 0, so being past the first line
				if (linecounter>0)
				{
					//add a new line to beggining 
					cardgraphic +="\n";
				}		
    		cardgraphic += line;	
			
			//set line counter +1
			linecounter++;					            	
   		 }
    
   		 //do vector 
  		vector<string> str_split = split(cardgraphic);
  		vector<double> num;
    
   		 string one;
   		 for(vector<string>::size_type i = 0; i != str_split.size(); ++i)
   		 {
    		num.push_back(atoi(str_split[i].c_str()));	
   		 }

    
		//set specific playerhand bit to cardgraphic 
		playerhand[3] = cardgraphic;
		//closefile                                      
   		loadFilePH4.close();
  	}
	
	//load file containing player's card 1
	loadFilePH5.open ("legendoftarotPH5.txt", ifstream::in);
		//if/when file is open      
  	if (loadFilePH5.is_open())
  	{
  		//set card graphic to nothing to prep for new
  		string cardgraphic = "";
  		//set line to nothing to prep for new
  		line = "";
  		//set line counter to 0 to begin recount
  		linecounter = 0;
  		
  		//getline in file as line and add line to card graphic
   		 while (getline (loadFilePH5, line))
   		 {
   		 	//if line counter is more than 0, so being past the first line
				if (linecounter>0)
				{
					//add a new line to beggining 
					cardgraphic +="\n";
				}		
    		cardgraphic += line;	
			
			//set line counter +1
			linecounter++;					            	
   		 }
    
   		 //do vector 
  		vector<string> str_split = split(cardgraphic);
  		vector<double> num;
    
   		 string one;
   		 for(vector<string>::size_type i = 0; i != str_split.size(); ++i)
   		 {
    		num.push_back(atoi(str_split[i].c_str()));	
   		 }

    
		//set specific playerhand bit to cardgraphic 
		playerhand[4] = cardgraphic;
		//closefile                                      
   		loadFilePH5.close();
  	}
	
	//load file containing 1s and 0s indicating if user owns a card
	loadFileCardOwned.open ("legendoftarotCardOwned.txt", ifstream::in);
	//save what cards user owns (0th spot in each array)
	for(int i=4;i>0;i--)
	{	
		loadFileCardOwned >> heartsStats[i][0];
		loadFileCardOwned >> pentaclesStats[i][0];
		loadFileCardOwned >> wandsStats[i][0];
		loadFileCardOwned >> swordsStats[i][0];
		loadFileCardOwned >> runesStats[i][0];
	}
	//close file
	loadFileCardOwned.close();
}

/******SAVE GAME FUNCTION******/
void savegame()
{
	//generate a save file variable for USER STATS
	ofstream saveFileUserStats ("legendoftarotUSERSTATS.txt");
	//save user variables in file
	saveFileUserStats << username;
    saveFileUserStats << " ";
    saveFileUserStats << userhealth;
    saveFileUserStats << " ";
    //close file
    saveFileUserStats.close();  
    
    //genera0te savefile for user's coins
    ofstream saveFileCoins("legendoftarotCoins.txt");
    	//save coins in file
    	saveFileCoins << coins;
    //close created file
    saveFileCoins.close();
    
    //generate a save file variable for PLAYERHAND1
	ofstream saveFilePH1 ("legendoftarotPH1.txt");
		
		//write playerhand 1st value
		saveFilePH1 << playerhand[0];
		
	//close file 
	saveFilePH1.close(); 
	
	//generate a save file variable for PLAYERHAND1
	ofstream saveFilePH2 ("legendoftarotPH2.txt");
		
		//write playerhand 2 value
		saveFilePH2 << playerhand[1];
		
	//close file 
	saveFilePH2.close(); 
	
	//generate a save file variable for PLAYERHAND1
	ofstream saveFilePH3 ("legendoftarotPH3.txt");
		
		//write playerhand 3 value
		saveFilePH3 << playerhand[2];
		
	//close file 
	saveFilePH3.close(); 
	
	//generate a save file variable for PLAYERHAND1
	ofstream saveFilePH4 ("legendoftarotPH4.txt");
		
		//write playerhand 4 value
		saveFilePH4 << playerhand[3];
		
	//close file 
	saveFilePH4.close(); 
	
	//generate a save file variable for PLAYERHAND1
	ofstream saveFilePH5 ("legendoftarotPH5.txt");
		
		//write playerhand 5 value
		saveFilePH5 << playerhand[4];
		
	//close file 
	saveFilePH5.close();  
    
    
    //file for saving whether a card is owned or not (1 or 0)
    ofstream saveFileCardOwned("legendoftarotCardOwned.txt");
    
	//save what cards user owns (0th spot in each array)
	for(int i=0;i<4;i++)
	{	
		saveFileCardOwned << heartsStats[i][0];
		saveFileCardOwned << " ";
		saveFileCardOwned << pentaclesStats[i][0];
		saveFileCardOwned << " ";
		saveFileCardOwned << wandsStats[i][0];
		saveFileCardOwned << " ";
		saveFileCardOwned << swordsStats[i][0];
		saveFileCardOwned << " ";
		saveFileCardOwned << runesStats[i][0];
		saveFileCardOwned << " ";
	}

	//close file 
	saveFileCardOwned.close();  
}

/******INTRO FUNCTION******/
void intro()
{
	//set user's coins to 200 for default
	coins = 205;
	
	//set user's health to 20 for default
	userhealth = 20;
	
	//LOCAL VARIABLES
	//username length
	int usernamelen;
	
	//clear screen from last function
	system("cls");
	
	//introduce game and ask name
	cout << "Welcome to the Legend of Tarot.\n\nWhat is your name?\nNAME: ";
	getline(cin, username);
	
	//MAKE NICKNAME
	//usernamelength
	usernamelen = username.length();
	//nickname is equal to the first 3 letters of first name and last 2 letters
	nickname=username.substr(0, 3)+username.substr(usernamelen-2, 2);
	//get nickname length
	int nicklen=nickname.length();
	//make name lowercase
 	for (int i=0; i<=nicklen; i++)
 	{
 		nickname[i] = tolower (nickname[i]);
	}
	//make first letter uppercase
	nickname[0] = toupper (nickname[0]);
	
	//say hello to user with full username
	cout << "\nAh. Hello, " << username << ". Nice to meet you. ";
	//tell user nickname
	cout << "\nI'll call you " << nickname << ".";
	getchar();
	
	//explain game
	cout << "\nIn the Legend of Tarot, you will battle opponents with the Elven Tarot deck. \nThe goal is to defeat the final opponent and be the master of tarot. \n\n"
	"Elven Tarot has five suits: hearts, pentacles, wands, swords and runes. \n\nThe power order goes as follows: \n"
	"Hearts > Pentacles > Wands > Swords > Runes > Hearts\n\nKeep in mind, if 2 suits are not directly beside eachother on the power order, \nthey are nuetral to eachother and" 
	"their attack value is average. If one suit is better, it will user its strong attack value.\nThe weaker of the two will use a weak attack value.\n\n"
	"You can own as many cards as you like, however you can only store 5 in your hand at one time.\n\nIn a game, the goal is to make the opponent run out of"
	" health before you do.\n\nYour starter deck is as follows: THE FOOL of Hearts, THE PRIESTESS of Pentacles,\nTHE WIZARD of Wands, THE EMPRESS of Swords,"
	"and THE HIEROPHANT of Runes. \nYou will start with " << coins << " coins and "<< userhealth << " health."
	"\n\n Press [Enter] when you're ready to begin!";
	getchar();
	//goto the map
	map();
}

/******MAP FUNCTION******/
void map()
{
	//clear screen from previous function
	system("cls");
	
	//LOCAL VARIABLES
	//getch values for user's input
	int keypress = 0;
	//values for coordinates
	int mapcursorx = 5, mapcursory = 2;
	
	//while the right key is not pressed
    while(keypress!=77)
    {
    	//show title and options
    	//tell user they are on the map
		cout << " ~MAP~";
    	cout << "\n\n        BATTLE";
    	cout << "\n        SHOP";
    	cout << "\n        SAVE GAME";
    	//instruct user
		cout << "\n\n\n *press up and down to navigate*\n *press right arrow to select*";
    	
    	//set cursor 
			gotoxy(mapcursorx,mapcursory);
			//clear area of @
			printf (" ");
			//set cursor 
			gotoxy(mapcursorx,mapcursory);
			//print @ other option
			printf ("@");
			
    	//set key pressed value to 0
        keypress = 0;
			
		//switch based on c's value	
        switch((keypress=getch())) 
		{
			//if they press the up key
			case KEY_UP:
				if (mapcursory!=2)
				{
					mapcursory -= 1;					
				}
			break;
    			
    		//if they press down key
      	    case KEY_DOWN:
      	    	if (mapcursory!=4)
				  {
				  		mapcursory += 1;
				  }
      	    break;
      	    
      	    //if user presses right key (to select)
      	    case KEY_RIGHT:
      	    	//clear screen to prep to show new menu
      	    	system ("cls");
      	    	//if they select on play
      	    	if(mapcursory == 2)
      	    	{
      	    		//goto battle
      	    		battle();
				}
      	    	//if they select on shop
      	    	if(mapcursory == 3)
      	    	{
      	    		//goto shop
      	    		shop();
				}
				
      	    	//if they select on savegame
      	    	if(mapcursory == 4)
      	    	{
      	    		//set keypress to 0 so loop reloops
      	    		keypress = 0;
      	    		//clear screen
      	    		system("cls");
      	    		//save the game
      	    		savegame();
      	    		//tell user game was saved
      	    		cout << " Game saved. Press [Enter] to continue.";
      	    		getchar();
				}
      	    break;	
    	}
    	
		//clear screen	
		system("cls");
	}
}

/******BATTLE FUNCTION******/
void battle()
{
	//play music 
	PlaySound("battlemusic.wav", NULL, SND_ASYNC | SND_FILENAME);
	//clear screen to prep for new function
	system ("cls");
	//initialize random function
	srand(time(NULL));
	
	/********LOCAL VARIABLES********/
	//char value for key input while in battle
	int battlec;
	//value for user's choice of card
	int selectedcard = 0;
	//opponent's name
	string opponentName;
	//opponent's hand
	string opponentHand[5];
	//opponent's health
	int opponentHealth;
	//users health during battle, which begins at user's initial health
	int battleUserhealth = userhealth;
	//opponent's play
	int opponentsPlay;
	//array for opponents previous plays, starts at 6 (since their play can only equal up to 4) and slowly fills
	int oppPrevPlay[4] = {6, 6, 6, 6};
	//array for user's previous plays, same method as opp
	int userPrevPlay[4] = {6, 6, 6, 6};
	//amount of coins user is betting
	int betamount=0;
	
	//show match was initiated
	cout << " ~MATCH INITIATED~\n\n";
	//getting bet amount
	do
	{
		//ask user what they want the bet amount to be and save as betamount
		cout << " Please set a bet amount.\n BET: ";
		cin >> betamount;
		getchar();
		
		//if user can afford
		if (betamount<=coins)
		{
			//tell user bet amount was set
			cout << "\n Bet amount set! Press [Enter] to start game.";
			//hold to start round until user presses getchar
			getchar();
		}
		//if user cannot afford
		else
		{
			//tell user they cannot aford this
			cout << "\n You cannot afford this bet. Try again.\n";
		}
		
	//loop while user cannot afford bet amount 
	}while(betamount>coins);
	
	
	/********GENERATE OPPONENT********/
	generateopponent(opponentName, opponentHand, opponentHealth);
	
	/********BATTLE LOOP********/
	//loop for five rounds
	for(int battleround=1;battleround<=5;battleround++)
	{
		
		//if no one has won, so no ones health is at 0 or less
	   if (opponentHealth!=0&&battleUserhealth!=0)
	  {
		//clear screen from previous function or loop
		system("cls");
		
		//set battlec to 0 so user can re select
		battlec = 0;
		
		//while the up key is not pressed
        while(battlec!=72)
        {
    	//display opponent, round, healths and bet amounts and instruct user
    	cout << " Now Playing: " << opponentName << "\n";
    	cout << " Opponent Health: " <<opponentHealth << "\n Your Health: "<< battleUserhealth << "\n";
    	cout << " Bet Amount: " << betamount <<"\n";
    	cout << " Round: " << battleround;
    	cout << "\n\n ~CHOOSE A CARD TO PLAY!~\n\n";
    	cout << " press side arrows to navigate\n";
    	cout << " press up arrow to play card\n";
    	//if their selected card has not already been played
		if (selectedcard != userPrevPlay[0]&&selectedcard != userPrevPlay[1]&&selectedcard != userPrevPlay[2]&&selectedcard != userPrevPlay[3])
		{
			//show selected card from player's hand		
			cout << playerhand[selectedcard];
		}
		//if it has already been played
		else
		{
			//show a blank card
			cout << "\n _______________________\n|                       |\n|                       |\n|                       |\n|                       |\n|                       |\n|                       |\n|                       |\n|                       |\n|                       |\n| SELECTED CARD         |\n| HAS ALREADY           |\n| BEEN PLAYED.          |\n|                       |\n|                       |\n|                       |\n|                       |\n|_______________________|";
	
		}
    	//show arrows to signify to press left or right
       	cout << "\n\n       <--- / --->";
    	
    	//set key pressed value to 0
        battlec = 0;
			
		//switch based on c's value	
        switch((battlec=getch())) 
		{
			//if they press the up key
			case KEY_UP:
				//if their selected card has not already been played
				if (selectedcard != userPrevPlay[0]&&selectedcard != userPrevPlay[1]&&selectedcard != userPrevPlay[2]&&selectedcard != userPrevPlay[3])
				{
					//set user prev play for round number(-1 since array starts at 0) to user's play
					userPrevPlay[battleround-1] = selectedcard; 
					//clear screen
					system("cls");	
					//show stats of game
					cout << " Now Playing: " << opponentName << "\n";
    				cout << " Round: " << battleround << "\n\n";
    				//tell they've played a card
    				cout << " CARD PLAYED!\n\nPress [ENTER] to contine.";
    				//hold until enter is pressed
    				getchar();
				}
				//if they have already played this card
				else
				{
					//set battlec to zero so loop reloops
					battlec = 0;
				}
				
			break;
				
    		//if they press up key
      	    case KEY_LEFT:
      	    	//if they are not already on the lowest card
       		 	if(selectedcard>0)
        		{
        			//change value of card graphic to 1 less
        			selectedcard--;
				}
				
          	break;
            
            //if they press right key
    		case KEY_RIGHT:
    			//if they are not at farthest card
				if (selectedcard<4)
      		  	{
      		  		//change value of card graphic to 1 more
        			selectedcard++;		
				}
				
			break;	
    	}
    	
    		//clear screen
    		system("cls");
   	   }
   	   
   	   //generate opponent's play 
    do
    {
    	//generate a random number from 0-4 to pick a card from opponents hand
    	opponentsPlay = rand() % 4;
    	
    //keep doing while this number is same as a previous play to prevent playing same card twice	
	}while(opponentsPlay == oppPrevPlay[0]||opponentsPlay == oppPrevPlay[1]||opponentsPlay == oppPrevPlay[2]||opponentsPlay == oppPrevPlay[3]);
	
	//set opponent prev play for round number(-1 since array starts at 0) to opponent's play
	oppPrevPlay[battleround-1] = opponentsPlay;
    
    //show round statistics
    cout << " Now Playing: " << opponentName << "\n";
    cout << " Round: " << battleround << "\n";
    cout << "\n --------------------------------------------";
    //show player's selected card, which corresponds to selectedcard+1
    cout << "\n YOUR PLAY:\n"<<playerhand[selectedcard];
    cout << "\n\n --------------------------------------------";
    //show opponent's selected card, corresponding to opponentsPlay
    cout << "\n OPPONTENTS PLAY:\n" << opponentHand[opponentsPlay];
    cout << "\n\n--------------------------------------------";
    cout << "\n ROUND OVERVIEW: \n";
    cout << "\n\n OPPONENT: \n";
    //set health to health after attack
    opponentHealth = attack(opponentHealth, battleUserhealth, playerhand, selectedcard, opponentHand, opponentsPlay, oppPrevPlay, betamount, battleround);
    cout << "\n Opponent Remaining Health: " << opponentHealth;
    cout << "\n\n PLAYER: \n";
    //set health to health after attack
    battleUserhealth = attack(battleUserhealth, opponentHealth, opponentHand,opponentsPlay,playerhand, selectedcard, userPrevPlay, betamount, battleround);
    cout << "\n Your Remaining Health: " << battleUserhealth;
    //wait until they press enter
	getchar();
	
	}
	
  }	
  
  //clear screen after game is finished
  system("cls");
  
  //show battle end title
  cout << " ~BATTLE ENDDED~";
  
  //at this point someones health has reached zero, since loop ended, so someone has won OR no one won
  //if opponent health reached zero
  if (opponentHealth<=0)
  {
  	//give user winning money
  	coins+=betamount;
  	//tell user they won
  	cout << "\n\n Congratulations! You have won. You have earned " <<betamount << " coins for winning.\n Press [Enter] to continue.";
  	//hold until user presses enter
  	getchar();
  }
  //if user health reached zero
  else if(battleUserhealth<=0)
  {
  		//take bet money from user
  		coins-=betamount;
  		//tell user they won
  		cout << "\n\n Oh no! You have lost. You have lost " <<betamount << " coins for losing.\n Press [Enter] to continue.";
  		//hold until user presses enter
  		getchar();
	}	
	//if no one won
	else
	{
		//tell they tied 
  		cout << "\n\n You have tied. There is no reward nor loss for this position. \n Press [Enter] to continue.";
  		//hold until user presses enter
  		getchar();
	}
	
	//return to map
	map();
}

/******ATTACK FUNCTION******/
int attack(int opposinghealth, int &localhealth, string localHand[5], int &localPlayed, string awayHand[5], int &awayPlayed, int awayPreviousPlayed[4], int &bettedmoney, int roundNum)
{
	//LOCAL VARIABLES
	//variable for user played suit where H = hearts, P = pentacles, W = wands, S = swords and R = runes
	char localplayedsuit;
	//variable for player's played card statistics, correspond to specific stats of card played
	int localplayedcard[5];
	//variable for user's attack value
	int localAtk;
	//variable for opponent's played suit
	char awayplayedsuit;
	//int for card number that gets selected set to i so we know which specific card was plated
	int localcardvalue;
	
	//loop to check each card(4 in suits)
	for(int i=0;i<4;i++)
	{
		//LOCAL STATS
		//if user played a heart
		if( localHand[localPlayed] == heartsgraphics[i])
		{
			//set played suit to h
			localplayedsuit = 'h';
			
			//change each stats of played card to stats for the played card
			for(int j=0;j<=4;j++)
			{
				//get stats for specific card
				localplayedcard[j] = heartsStats[i][j];
			}
			
		}
		//if user played a pentacle
		else if( localHand[localPlayed] == pentaclesgraphics[i])
		{
			//set played suit to p
			localplayedsuit = 'p';
			
			//change each stats of played card to stats for the played card
			for(int j=0;j<=4;j++)
			{
				//get stats for specific card
				localplayedcard[j] = pentaclesStats[i][j];
			}
			
		}
		//if user played a wand
		else if( localHand[localPlayed] == wandsgraphics[i])
		{
			//set played suit to w
			localplayedsuit = 'w';
		
			//change each stats of played card to stats for the played card
			for(int j=0;j<=4;j++)
			{
				//get stats for specific card
				localplayedcard[j] = wandsStats[i][j];
			}
			
		}
		//if user played a sword
		else if( localHand[localPlayed] == swordsgraphics[i])
		{
			//set played suit to s
			localplayedsuit = 's';
		
			//change each stats of played card to stats for the played card
			for(int j=0;j<=4;j++)
			{
				//get stats for specific card
				localplayedcard[j] = swordsStats[i][j];
			}
			
		}
		//if user played a rune
		else if( localHand[localPlayed] == runesgraphics[i])
		{
			
			//set played suit to r
			localplayedsuit = 'r';
		
			//set card value to whatever i was when it found the correct card
			localcardvalue = i;
			
			//change each stats of played card to stats for the played card
			for(int j=0;j<=4;j++)
			{
				//get stats for specific card
				localplayedcard[j] = runesStats[i][j];
			}
			
		}
		
		//AWAY (OPPONENT) STATS (in relation to what was sent)
		//if user played a heart
		if( awayHand[awayPlayed] == heartsgraphics[i])
		{
			//set played suit to h
			awayplayedsuit = 'h';
		}
		//if user played a pentacle
		else if( awayHand[awayPlayed] == pentaclesgraphics[i])
		{
			//set played suit to p
			awayplayedsuit = 'p';
		}
		//if user played a wand
		else if( awayHand[awayPlayed] == wandsgraphics[i])
		{
			//set played suit to w
			awayplayedsuit = 'w';
		}
		//if user played a sword
		else if( awayHand[awayPlayed] == swordsgraphics[i])
		{
			//set played suit to s
			awayplayedsuit = 's';
		}
		//if user played a rune
		else if( awayHand[awayPlayed] == runesgraphics[i])
		{
			//set played suit to r
			awayplayedsuit = 'r';
		}
	}
	
	
	//test relation of the 2 played cards, see if user has upperhand or lowerhand and if opponent has lower or upper
	//if user has upperhand
	if ((localplayedsuit == 'h' && awayplayedsuit == 'p') || (localplayedsuit == 'p' && awayplayedsuit == 'w') || (localplayedsuit == 'w' && awayplayedsuit == 's') || (localplayedsuit == 's' && awayplayedsuit == 'r') || (localplayedsuit == 'r' && awayplayedsuit == 'h'))
	{
		//attack is strong, slot 4(3)
		localAtk = localplayedcard[3];
	}
	//if opponent has upperhand
	else if((awayplayedsuit == 'h' && localplayedsuit == 'p') || (awayplayedsuit == 'p' && localplayedsuit == 'w') || (awayplayedsuit == 'w' && localplayedsuit == 's') || (awayplayedsuit == 's' && localplayedsuit == 'r') || (awayplayedsuit == 'r' && localplayedsuit == 'h'))
	{
		//attack is weak, slot 2(1)
		localAtk = localplayedcard[1];
	}
	//if nuetral
	else
	{
		//attack/move is slot 3(2)
		localAtk = localplayedcard[2];
	}
	
	//if player did not play a rune
	if (localplayedsuit!='r')
	{
		//say they were hit for however much health
		cout << "\n Hit for " << localAtk << " health points!"; 
		//subtract atk from health
		opposinghealth-=localAtk;
	}
	
	//if they did play a rune (so special attack)
	else if (localplayedsuit=='r')
	{
		//do different things based on which rune was played
			//if they played the hiero
			if (localcardvalue == 0)
			{
				//tell that opponents card was taken 
				cout << "\n Card taken from player!";
				//take 3rd card from opponent by making it already played
				awayPreviousPlayed[roundNum] = 3;
			}
			
			//if they played justice
			else if(localcardvalue == 1)
			{
				//if the attack is 4
				if (localAtk==4)
				{
					//give 4 health to the opponent
					opposinghealth+=localAtk;
					//say opponent was given howevermuch health
					cout << "\n Player iven " << localAtk << " health points!";
				}
				//if the attack is 2
				else if (localAtk==2)
				{
					//give 2 health to the opponent
					opposinghealth+=localAtk;
					//give 2 health to local
					localhealth+=localAtk;
					//say players were given howevermuch health
					cout << "\n Both players given " << localAtk << " health points!";
				}
				//if the attack is 4
				else if (localAtk==5)
				{
					//give 5 health to local
					localhealth+=localAtk;
					//say player was given howevermuch health
					cout << "\n Other player given " << localAtk << " health points!";
				}
			}
			
			//if they played wheel of fortune
			else if(localcardvalue == 2)
			{
				//tell user bet money increased
				cout << "\n Bet money increased by 30%!";
				//set bet money to 30% more
				bettedmoney = bettedmoney*1.3;
			}
			
			//if they played judgement
			else if(localcardvalue == 3)
			{
				//tell that otlosingplayer was given 8 health
					cout << "\nLosing player given 8 health!";
				//if opponenthealth is highest 
				if (opposinghealth>localhealth)
				{
					//give local health 8
					localhealth+=8;
				}
				//if other is highest
				else
				{
					//give opposing health 8
					opposinghealth+=8;
				}
			}
	}
	
	//return new health value for opposing player to what was sent
	return (opposinghealth);
}

/******GENERATE OPPONENT FUNCTION*****/
void generateopponent(string &fOpponentName, string fOpponentHand[5], int &fOpponentHealth)
{
	//initialize random function
	srand(time(NULL));
	
	//int that represents suit of card that is randomly generated
	int opponentSuitGenerate;
	//int for card within randomly generated suit
	int opponentCardGenerate;
	
	//GENERATE NAME
	//generate random number for name
	int opponentnamecounter = rand() % 16 + 1;
	//switch name based on random number
	switch(opponentnamecounter)
	{
		case 1:
			fOpponentName = "Aseth";
		break;
		case 2:
			fOpponentName = "Ayrea";
		break;
		case 3:
			fOpponentName = "Cereldamyr";
		break;
		case 4:
			fOpponentName = "Lilyell";
		break;
		case 5:
			fOpponentName = "Vivialiynn";
		break;
		case 6:
			fOpponentName = "Wadrus";
		break;
		case 7:
			fOpponentName = "Yarieth";
		break;
		case 8:
			fOpponentName = "Sagyal";
		break;
		case 9:
			fOpponentName = "Cerenol";
		break;
		case 10:
			fOpponentName = "Nyries";
		break;
		case 11:
			fOpponentName = "Maluris";
		break;
		case 12:
			fOpponentName = "Dafran";
		break;
		case 13:
			fOpponentName = "Radris";
		break;
		case 14:
			fOpponentName = "Theadon";
		break;
		case 15:
			fOpponentName = "Elitia";
		break;
		case 16:
			fOpponentName = "Cynysae";
		break;	
	}
	
	//GENERATE CARDS
	//int for max card value to control opponent power
	int maxCard;
	//loop that will run 5 times to pick 5 cards and put in corresponding value of opponent's hand
	for (int i=0;i<=4;i++)
	{
		//generate a number from 1 - 5 to pick suit
		opponentSuitGenerate = rand() % 5 +1;
		//if user's ith card is 0
		if (playerhand[i] == heartsgraphics[0] ||playerhand[i] ==pentaclesgraphics[0]||playerhand[i] ==wandsgraphics[0]||playerhand[i] ==swordsgraphics[0]||playerhand[i] ==runesgraphics[0])
		{
			//set maxCard to 0
			maxCard = 0;
		}
		//if user's ith card is 1
		if (playerhand[i] == heartsgraphics[1]||playerhand[i] ==pentaclesgraphics[1]||playerhand[i] ==wandsgraphics[1]||playerhand[i] ==swordsgraphics[1]||playerhand[i] ==runesgraphics[1])
		{
			//set maxCard to 0
			maxCard = 1;
		}
		//if user's ith card is 2
		if (playerhand[i] == heartsgraphics[2]||playerhand[i] ==pentaclesgraphics[2]||playerhand[i] ==wandsgraphics[2]||playerhand[i] ==swordsgraphics[2]||playerhand[i] ==runesgraphics[2])
		{
			//set maxCard to 2
			maxCard = 2;
		}
		//if user's ith card is 3
		if (playerhand[i] == heartsgraphics[3]||playerhand[i] ==pentaclesgraphics[3]||playerhand[i] ==wandsgraphics[3]||playerhand[i] ==swordsgraphics[3]||playerhand[i] ==runesgraphics[3])
		{
			//set maxCard to 3
			maxCard = 3;
		}
		
		//add 2 to maxCard to add difficulty possibility
		maxCard+=2;
		
		//generate a random number from 0-maxCard+1 to determine card in suit
		opponentCardGenerate = rand() % maxCard;
		
		//switch for suit generation
		switch(opponentSuitGenerate)
		{
				//if random number is 1 for hearts
				case 1:
					//set playerhand[loop value] to generated card from generated suit
					fOpponentHand[i] = heartsgraphics[opponentCardGenerate];
				break;
				//if random number is 2 for pentacles
				case 2:
					//set playerhand[loop value] to generated card from generated suit
					fOpponentHand[i] = pentaclesgraphics[opponentCardGenerate];
				break;
				//if random number is 3 for wands
				case 3:
					//set playerhand[loop value] to generated card from generated suit
					fOpponentHand[i] = wandsgraphics[opponentCardGenerate];
				break;
				//if random number is 4 for swords
				case 4:
					//set playerhand[loop value] to generated card from generated suit
					fOpponentHand[i] = swordsgraphics[opponentCardGenerate];
				break;
				//if random number is 5 for runes
				case 5:
					//set playerhand[loop value] to generated card from generated suit
					fOpponentHand[i] = runesgraphics[opponentCardGenerate];
				break;
		}
	}
	
	//GENERATE HEALTH
	//int for max opponent health and min opponenthealth
	int opponenthealthmin = userhealth-10;
	int opponenthealthmax = userhealth+6;
	//health must be within points of player health, so up to userhealth+6 starting at userhealth-10 
	fOpponentHealth = rand() % opponenthealthmax + opponenthealthmin;	
}

/******SHOP FUNCTION*******/
void shop()
{
	
	
	//LOCAL VARIBALES
	//graphics for the shop menu
	string shopgraphics[3] = {" CARDS\n    _____\n   |A .  | _____\n   | /.\\ ||A ^  | _____\n   |(_._)|| / \\ ||A _  | _____\n   |  |  || \\ / || ( ) ||A_ _ |\n   |____V||  .  ||(_'_)||( v )|\n          |____V||  |  || \\ / |\n                 |____V||  .  |\n                        |____V|", " HEALTH\n\t    _\n\t  _| |_ \n\t |_   _|\n\t   |_|  ", " CHANGE NAME\n     ____\n    |    |\n    |    |\n    |    |\n    |____|\n     \\__/\n      \\/==================="};
	//selected option in shop
	int shopselect = 0;
	//key that is pressed 
	int keypress = 0;
	//shop cursor coords
	//set cursor 
	int shopcursorx = 5;
	int shopcursory = 5;
	
	//SETTINGS
	//play music 
	PlaySound("shopmusic.wav", NULL, SND_ASYNC | SND_FILENAME);
	//clear screen to prep
	system("cls");
	//set colour initilizer
	 HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); 
	//play music
	

	//loop while user does not press up button to select (so while keypressed is not upbutton value)
    while(keypress!=72)
    {
    	//set colour red
    	SetConsoleTextAttribute(color, 12);
    	//show menu title
    	cout << " ~SHOP~\n";
    	//show user's balance
    	cout << " Balance: "<< coins << " Coins\n";
    	//set colour white
    	SetConsoleTextAttribute(color, 15);
    	//show shop keeper and prompt user to select option, showing ascii graphic to indicate what option they are on
    	cout << "\n          .-\"```'.";
        cout << "\n         /   \\    \\";
        cout << "\n        /   / `\\__/";
        cout << "\n        | .'  _  _|";
        cout << "\n        \\(\\   6  6 ";
        cout << "\n         | \\   _\\ |";
        cout << "\n         |\\ `~`= `/";
        cout << "\n         | '.___.'";
        cout << "\n     .'` \\     |_";
        cout << "\n          '-__ / `-";
        //set colour red
    	SetConsoleTextAttribute(color, 12);
    	//ask user what they are looking to buy and print selected option
    	cout << "\n Shopkeep: What are you looking to buy?\n\n";
    	cout << " press side arrows to navigate\n";
    	cout << " press up arrow to select\n\n";
    	cout << shopgraphics[shopselect];
       	cout << "\n\n       <--- / --->";
       	
       	//set keypress to zero to prep for new value
        keypress = 0;
        //get value of key user pressed and save in keypress
        switch((keypress=getch())) 
		{
			//if user presses up key to select
			case KEY_UP:
				//clear screen to show new menu
				system("cls");
				//if user selects to buy cards 
				if (shopselect == 0)
				{
					//set keypress to zero to prep for new menu
					keypress = 0;
					
					//coordinate values for cardshop
					int cardshopcursorx = 5, cardshopcursory = 3;
					
					//loop while user doesn't press right to select
					while(keypress!=77)
					{
						//show cards title
						cout << " ~CARDS~";
						cout << "\n Select a Suit to buy from.";
						cout << "\n\n\t Hearts\n\n\t Pentacles \n\n\t Wands \n\n\t Swords \n\n\t Runes";
						
								//set cursor 
								gotoxy(cardshopcursorx,cardshopcursory);
								//clear area of @
								printf (" ");
								//set cursor 
								gotoxy(cardshopcursorx,cardshopcursory);
								//print @ other option
								printf ("@");
						
						
							//switch based on c's value	
        					switch((keypress=getch())) 
							{
								//if they press the up key
								case KEY_UP:
										//if user is not on top option
									if (cardshopcursory!=3)
									{
										//cursor y goes down 2
										cardshopcursory -= 2;					
									}
								break;
    			
    							//if they press down key
      	    					case KEY_DOWN:
      	    						//if user is not on last option
      	    						if (cardshopcursory!=11)
									  {
									  		//cursor y goes up 2
									  		cardshopcursory += 2;
									  }
      	    					break;
      	    
      	   					 //if user presses right key (to select)
      	   					 case KEY_RIGHT:
      	   					 		
      	    						//clear screen to prep for new menu
      	    						system("cls");
      	    						//switch based on what suit was chosen
      	    						switch(cardshopcursory)
      	    						{
      	    							//if they select hearts
      	    							case 3:
      	    								//output suit title
      	    								cout << " ~HEARTS~";
      	    								
      	    								//write options
      	    								cout << "\n1. THE FOOL I";
      	    								cout << "\n2. THE LOVERS II";
      	    								cout << "\n3. THE HERMIT III";
      	    								cout << "\n4. THE DEVIL IV";
      	    								
      	    								//do buy card function using hearts stats and hearts graphics
      	    								buycard(heartsStats, heartsgraphics);
      	    							
      	    								
      	    							break;
      	    							
      	    							//if they select pentacles
      	    							case 5:
      	    								//output suit title
      	    								cout << " ~PENTACLES~";
      	    								
      	    								//write options
      	    								cout << "\n1. THE HIGH PRIESTESS I";
      	    								cout << "\n2. THE EMPORER II";
      	    								cout << "\n3. TEMPERANCE III";
      	    								cout << "\n4. THE SUN IV";
      	    								
      	    								//do buy card function using pentacles stats and pentacles graphics
      	    								buycard(pentaclesStats, pentaclesgraphics);
      	    								
      	    							break;
      	    							
      	    							//if they select wands
      	    							case 7:
      	    								//output suit title
      	    								cout << " ~WANDS~";
      	    								
      	    								//write options
      	    								cout << "\n1. THE MAGICIAN I";
      	    								cout << "\n2. THE HANGED MAN II";
      	    								cout << "\n3. THE DEATH III";
      	    								cout << "\n4. THE MOON IV";
      	    								
      	    								//do buy card function using wands stats and wands graphics
      	    								buycard(wandsStats, wandsgraphics);
      	    								
      	    							break;
      	    							
      	    							//if they select swords
      	    							case 9:
      	    								//output suit title
      	    								cout << " ~SWORDS~";
      	    								
      	    								//write options
      	    								cout << "\n1. THE EMPRESS I";
      	    								cout << "\n2. THE CHARIOT II";
      	    								cout << "\n3. STRENGTH III";
      	    								cout << "\n4. THE STAR IV";
      	    								
      	    								//do buy card function using swords stats and swords graphics
      	    								buycard(swordsStats, swordsgraphics);
      	    								
      	    							break;
      	    							
      	    							//if they select runes
      	    							case 11:
      	    								//output suit title
      	    								cout << " ~RUNES~";
      	    								
      	    								//write options
      	    								cout << "\n1. THE HIEROPHANT I";
      	    								cout << "\n2. JUSTICE II";
      	    								cout << "\n3. THE WHEEL OF FORTUNE III";
      	    								cout << "\n4. JUDGEMENT IV";
      	    								
      	    								//do buy card function using runes stats and runes graphics
      	    								buycard(runesStats, runesgraphics);
      	    						
									  	break;
									  
									  }
									  
									  //return to map
									  map();
									  
						 		break;
								 }
      	    								
      	   					 	
      	   					 
      	   					   //clear screen for next loop
							   system("cls");
    						}
					
					}
					
					else if (shopselect == 1)
				{
					//set keyselect to 0 again for new menu
						keypress = 0;
					
					//int for amount to increase health by
					int healthincrease = 1;
					
					//while user does not confirm increase value (press right)
					while (keypress!=77)
					{
						cout << " ~HEALTH~";
						//Prompt user to add to health using arrows
						cout << " \n\n How much would you like to add to your health? \n\n Press [^] to increase, [v] to decrease. \n Press [>] to confirm.\n\n INCREASE: " << healthincrease;
						
						//set keyselect to 0 again for new value
						keypress = 0;
						
						//get value of key user pressed and save in keypress then switch based on value
						switch((keypress=getch()))
						{
							//if user presses up
							case KEY_UP:
								//if healthinrease is less than 7
								if(healthincrease<7)
								{
									//increase healthincrease by 1
									healthincrease++;
								}
							break;
							
							//if user presses down
							case KEY_DOWN:
								//if healthincrease is more than 1
								if (healthincrease>1)
								{
									//decrease health increase by 1
									healthincrease--;
								}
							break;
							
							//if user presses right
							case KEY_RIGHT:
								//tell user how much they are adding and how much it will cost, asking for confirmation.
								cout << "\n\n You are adding " << healthincrease << " to your health. This will cost " << healthincrease*150 << " coins. \n Press [Enter] to confirm.";
								getchar();
								
								//if user can afford this
								if (coins>=(healthincrease*150))
								{
									//deduct money from user
									coins-=healthincrease*150;
									//add health
									userhealth+=healthincrease;
									//tell them transaction was completed
									cout << "\n\nTransaction completed. Your health is now " << userhealth << ".";
									cout << "\nPress [Enter] to return to map.";
									//hold until user presses enter
									getchar();
								}
								
								//if they cannot afford
								else
								{
									//tell user they did not have enough coins
									cout << "\n\nTransaction failed. You could not afford this purchase.";
									cout << "\nPress [Enter] to return to map.";
									//hold until user presses enter
									getchar();
								}
								
								//go to map
								map();
								
							break;
						}
						
						//clear screen for next loop
						system("cls");
					}
					
				}
				
				//if they selected to change name
				else if (shopselect == 2)
				{
					//variable for user's possible new name before confirmation
					string possuser;
					//int for if user chooses to change name or not
					int changenameopt=1;
					
					//ask user what they want to change their name to then save in possuser 
					cout << " ~CHANGE NAME~";
					cout << "\n\n What would you like to change your name to?\n Press [Enter] to confirm.\n\n NAME: ";
					cin >> possuser;
					getchar();
					//clear screen
					system("cls");
					
					//ask if user is sure and get a number confirmation saved in changenameopt
					cout << " ~CHANGE NAME ~";
					cout << "\n\n Are you sure you want to change your name to " << possuser << "?\n It will cost 100 coins. \n Press [1] for yes, press [2] for no. \n Press [Enter] to confirm. \n OPTION: ";
					cin >> changenameopt;
					getchar();
					
					//if user says yes and they can afford it
					if (changenameopt == 1&&coins>=100)
					{
						//change username to possuser
						username = possuser;
						
						//deduct 100 coins from user
						coins-=100;
						
						//for loop to count down when user will be taken back to map
						for (int counter=5;counter>=1;counter--)
						{
							//clear screen to show new message
							system("cls");
							//tell user their option was not recognized and notify that they will return to the map in however many seconds left
							cout << "\n Name succesfully changed to " << username << ". Defaulting to map in " << counter << ".";
							//wait 1 seconds to reloop
							Sleep(1000);
						}
					}
					//if user says no or they can't afford it
					else if (changenameopt ==2||coins<100)
					{
						//for loop to count down when user will be taken back to map
						for (int counter=5;counter>=1;counter--)
						{
							//clear screen to show new message
							system("cls");
							//tell user their option was not recognized and notify that they will return to the map in however many seconds left
							cout << "\n Order cancelled. Defaulting to map in " << counter << ".";
							//wait 1 seconds to reloop
							Sleep(1000);
						}
					}
					//if input is invalid
					else
					{
						//for loop to count down when user will be taken back to map
						for (int counter=5;counter>=1;counter--)
						{
							//clear screen to show new message
							system("cls");
							//tell user their option was not recognized and notify that they will return to the map in however many seconds left
							cout << "\n Option entered not recognized. Defaulting to map in " << counter << ".";
							//wait 1 seconds to reloop
							Sleep(1000);
						}
						
					}
					
					//return to map
					map();
				}
				
			break;
    		
    		//if user presses left key to see other option
      	    case KEY_LEFT:
      	    	//if they are not at lowest option
       		 	if(shopselect>0)
        		{
        			//show previous option
        			shopselect--;
				}
				
          	break;
            
            //if user presses right key to see other option
    		case KEY_RIGHT:
    			//if they are not at highest option
				if (shopselect<2)
      		  	{
      		  		//show next option
        			shopselect++;		
				}
				
			break;	
    	}
    		
    		//clear screen to prep for next loop to show new option selection
    		system("cls");
	}
	
}

/******BUY SPECIFIC CARD FROM SHOP FUNCTION******/
void buycard(int selectedsuitStats[4][5],string selectedsuitGraphics[4])
{ 
	//variable for selecting a card
    int cardselect;
    //bool for if card is equiped
    bool cardequipped=false;
    //int for if they want to equip a card
    int equipcardopt;
      	   					 		
	//ask option number
    cout << "\n\nOPTION: ";
    cin >> cardselect;
      	    								
    //clear screen to prep for buy screen
    system("cls");
    //show user they are in the buy menu
    cout << " ~BUY MENU~\n";
    
    getchar();
      	    								
    //output card graphic that corresponds
    cout << selectedsuitGraphics[cardselect-1];
    cout << "\n-------------------------------------";
      	    								
    //if card is owned
    if (selectedsuitStats[cardselect-1][0]==1)
    {
      	  //tell user card is owned
      	  cout << "\n STATUS: Owned";
      	  //look for selected card in playerhand
      	  for (int i=0;i<5;i++)
      	  {
      	    	//if specific playerhand card graphic is the same as the card selected
      	    	if (playerhand[i] == selectedsuitGraphics[cardselect-1])
      	    	{
      	    		//set card equipped to true
      	    		cardequipped = true;
				}
		  }
												
			//if user owns card
			if (cardequipped)
			{
				cout << "\n EQUIPPED: True";
			}
												
			//if user does not
			else
			{
				//which place user would like to replace with card
				int cardslotreplace;
													
				//ask user if they want to replace card
				cout << "\n EQUIPPED: False";
				cout << "\n Would you like to equip this card? [1] = yes, [2] = no\n OPTION: ";
				cin >> equipcardopt;
													
				if (equipcardopt==1)
				{
					//ask whc=ich slot they want to put it in
					cout << "\n Which card slot would you like to put it in? (1-5)\n OPTION: ";
					cin >>  cardslotreplace;
					//set that place to the new card
					playerhand[cardslotreplace-1] = selectedsuitGraphics[cardselect-1];
					cout << "\n Slot replaced. ";
				}
				
				//if they choose not to equip 
				else
				{
					cout << "\n Equipment cancelled. ";
				}
			}
	}
											 
	//if card is not owned
	else if (selectedsuitStats[cardselect-1][0]==0)
	{
		//tell user they do not own this card
		cout << "\n STATUS: NOT Owned";
											 	
		//int for if they would like to buy the card
		int buycardopt;
		
		//int for price of card
		/*cost determined by place in array*/
		int cardPrice = 200*(cardselect-1);
											 	
		//ask if they want to buy card
		cout << "\n Would you like to buy this card? It costs " << cardPrice << " coins. [1] = yes, [2] = no\n OPTION: ";
		cin >> buycardopt;
												
		//if they said yes and can afford it
		if (buycardopt == 1&&coins>=cardPrice)
		{
			//deduct money from user
			coins-=cardPrice;
			//change owned stat to 1 (yes)
			selectedsuitStats[cardselect=1][0] = 1;
			//tell them transaction was completed
			cout << "\n\nTransaction completed. You now own this card return to this menu to equip it. \nDefaulting to map.";
			//wait 3 seconds
			Sleep(3000);
		}
												
		//if they said no or cannot afford it
		else
		{
			//tell user transaction was cancelled
			cout << "Transaction failed. ";	
			//wait three seconds before returning to shop
			Sleep(3000);									
		}
	}
											
	//wait for user to press enter to return to old function
	cout << "\n\nPress [Enter] to exit menu.";
	getchar();
}

/******SET CURSOR (GOTOXY) FUNCTION******/
void gotoxy(int eex, int eey)
{
	//declare coord as a coordinate
  COORD coord;
  //make x coord = eex
  coord.X = eex;
  //make y coord = eey
  coord.Y = eey;
  //set the user's cursor position to the location of the current coordinate
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/******GETTING CARD GRAPHICS VECTOR******/
vector<string> split(const string& cardgraphic)
{
	//declare and define vector 
	vector<string> ret;
	typedef string::size_type string_size;
	//set string size i to 0
	string_size i = 0;
	
	//while i is not yet the size of senthe full card graphic
	while(i != cardgraphic.size())
	{
		//while i is not the sentence size and space where i part of the card graphic is
		while(i != cardgraphic.size() && isspace(cardgraphic[i]))
		//increase i
			++i;
		//set string size j to i
		string_size j = i;
		
		//while j is not the size of cardgraphic and there is a space at j
		while(j != cardgraphic.size() && !isspace(cardgraphic[j]))
		++j;
		
		//copy full string if string is found
		if(i != j)
		{
			ret.push_back(cardgraphic.substr(i, j - i));
			i=j;
		}
	
	}
	
	//return vector
	return ret;
}
