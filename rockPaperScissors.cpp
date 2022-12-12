#include <iostream> //	For input and output
#include <cstdlib> //	For rand() and srand()
#include <ctime> //	For time()

using namespace std; //	For cout, cin, endl

const int NUM_CHOICES = 3; // Number of choices in the game (rock, paper, scissors)
const string CHOICES[NUM_CHOICES] = {"rock", "paper", "scissors"}; // Possible choices
//initialize game count to keep track of games played
		int GAME_COUNT = 0;
			//initialize array to keep track of history
			string history[100];

// Function to generate a random choice for the computer
string getComputerChoice() {
  // Seed the random number generator using the current time
  srand(time(0));

  // Generate a random number between 0 and NUM_CHOICES-1
  int computerChoice = rand() % NUM_CHOICES;

  // Return the corresponding choice from the CHOICES array
  return CHOICES[computerChoice];



}

// Function to determine the winner of the game
string getWinner(string userChoice, string computerChoice) {
  // Check if the user chose rock
  if (userChoice == "1") {
    // If the computer chose scissors, the user wins
    if (computerChoice == "scissors") {
      return "user";
    }
    // If the computer chose paper, the computer wins
    else if (computerChoice == "paper") {
      return "computer";
    }
    // If the computer also chose rock, it's a tie
    else {
      return "tie";
    }
  }
  // Check if the user chose paper
  else if (userChoice == "2") {
    // If the computer chose rock, the user wins
    if (computerChoice == "rock") {
      return "user";
    }
    // If the computer chose scissors, the computer wins
    else if (computerChoice == "scissors") {
      return "computer";
    }
    // If the computer also chose paper, it's a tie
    else {
      return "tie";
    }
  }
  // If the user didn't choose rock or paper, they must have chosen scissors
  else {
    // If the computer chose rock, the computer wins
    if (computerChoice == "rock") {
      return "computer";
    }
    // If the computer chose paper, the user wins
    else if (computerChoice == "paper") {
      return "user";
    }
    // If the computer also chose scissors, it's a tie
    else {
      return "tie";
   
				}
		}
}

void  playGame () {
			// Input and output
		string userChoice;
	
		cout << " \n \n Enter your choice \n 1: rock, \n 2: paper, \n 3: scissors \n " << endl;
		cin >> userChoice;

		// Flow of control
		if (userChoice != "1" && userChoice != "2" && userChoice != "3") {
				cout << " \n \n You entered an invalid choice. Please try again" << endl;
				playGame();
		}

		// Function
		string computerChoice = getComputerChoice();
		string winner = getWinner(userChoice, computerChoice);
	
		// Output
		cout << "The computer chose " << computerChoice << "." << endl;
		if (winner == "user") {
				cout << "You win!" << endl;
				//add result to history	array
				history[GAME_COUNT] = "Win.";
			//increase game count
				GAME_COUNT++;
		}
		else if (winner == "computer") {
				cout << "The computer wins." << endl;
				//add result to history	array
				history[GAME_COUNT] = "Loss.";
				//increase game count
				GAME_COUNT++;
		}
		else {
				cout << "It's a tie." << endl;
				//add result to history	array
				history[GAME_COUNT] = "Tie.";
				//increase game count
				GAME_COUNT++;
		}
}

		//function to display menu after each game
int menu () {

	if (GAME_COUNT >= 100) { //if user has played 100 games
				cout << "You have played 100 games. Here is your game history" << endl;
				//display history
				for (int i = 0; i < 100; i++) {
						cout << "Game: " + i << endl;
						cout << "Result: " + history[i] << endl;
				}
				return 0; //exit program
		}

//initialize	string to keep store menu select
		string menuSelect;

		cout << "Select a choice \n 1: Play again \n 2: View game history \n 3: Exit" << endl;
		//let	user select from menu
		cin >> menuSelect;

		//	Flow of control
		//check for wrong input first
	if (menuSelect != "1" && menuSelect != "2" && menuSelect != "3") {
				cout << "You entered an invalid choice. Please try again" << endl;
				//call	menu function again so that user can try again
				menu();
		}

		if (menuSelect == "1") {
				playGame(); //call playGame function
		}
		else if (menuSelect == "2") {
				cout << "Game History" << endl;
				cout << "Game: " + GAME_COUNT << endl;
				//loop	through history array and display results
				for (int i = 0; i < GAME_COUNT; i++) {
						cout << "Result: " + history[i] + "\n" << endl; //display result
				}

		}
		//if user did not make a wrong choice and did not select 1 or 2, then they must have selected 3
		else {
				cout << "Thanks for playing!" << endl;
				return 0; //exit program
		}
		return 1; //return 1 to continue program
}



int main() {
	//Welcome message
	cout << "This program will play the game of rock, paper, scissors." << endl;
//call	function to play game
		playGame();
		cout <<	"Thanks for playing!" << endl;


		//call menu function to display menu
		while (GAME_COUNT < 101) { //while user has not played 100 games

				int control = menu();		//call menu function

				if (control == 0) { //check menu return value for control
						break; //if 0, exit program
				} else {
						continue; //if not zero (1), continue program
				}
		}

			return 0; //exit program
}


//if you dont know how to run c++ code follow the steps below

/* 
how to run this code using mysys2 

*/

//delete the comment below before presentation

/*


To run this C++ code with mysys2, you will need to first install the mysys2 software on your computer. 
Once it is installed, you can use the g++ command to compile your C++ code.
For example, if you have a file named rockPaperScissors.cpp, you can compile it using the following command:

g++ rockPaperScissors.cpp

This will create an executable file named a.exe in the same directory as your source file.
You can then run the code by typing the following command:

./a.exe

Keep in mind that the exact commands and steps for running C++ code with mysys2
may vary depending on the version of the software you are using and the specifics of your system setup.
It's always a good idea to consult the mysys2 documentation or support resources for detailed instructions on how to use it.
*/
