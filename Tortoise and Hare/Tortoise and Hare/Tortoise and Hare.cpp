/****************************************
 * John Velazquez
 * CIS 3340
 * Chapter 8 Homework
 * The Tortoise and the Hare
 ****************************************
 * This program simulates the tortoise vs
 * the hare race. A random number 1 to 10
 * is generated and a move for both the 
 * turtle and the rabbit is decided based
 * on the number that was selected
 ****************************************/

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;


/***********************************
 **                               **
 **	 Tortoise class and methods   **
 **                               **
 ***********************************/
class tortoise
{
	public:
		int square;

		tortoise();
		bool victor();
		void win();
		void fastPlod();
		void slip();
		void slowPlod();
}turtle;

tortoise::tortoise() //Default constructor
{
	square = 1;
}

bool tortoise::victor() //Check for if victory condition is met
{
	bool victory;

	if(square < 70)
		victory = false;
	else
		victory = true;

	return victory;
}

void tortoise::win()
{
	cout << "\nTORTOISE WINS!!! YAY!!!" << endl;
}

void tortoise::fastPlod() //Move 3 Squares to the right
{
	square += 3;
	if(square > 70)
		square = 70;
}

void tortoise::slip() //Move 6 Squares to the left
{
	square -= 6;
	if(square < 1)
		square = 1;
}

void tortoise::slowPlod() //Move 1 Squares to the right
{
	square += 1;
}

/*******************************
 **                           **
 **	 Hare class and methods   **
 **                           **
 *******************************/
class hare
{
	public:
		int square;

		hare();
		bool victor();
		void win();
		void bigHop();
		void bigSlip();
		void smallHop();
		void smallSlip();
}rabbit;

hare::hare() //Default constructor
{
	square = 1;
}

bool hare::victor() //Check for if victory condition is met
{
	bool victory;

	if(square < 70)
		victory = false;
	else
		victory = true;

	return victory;
}

void hare::win() //Rabbit win output
{
	cout << "\nHare wins. Yuch." << endl;
}

void hare::bigHop() //Move 9 Squares to the right
{
	square += 9;

	if(square > 70)
		square = 70;
}

void hare::bigSlip() //Move 12 squares to the left
{
	square -= 12;

	if(square < 1)
		square = 1;
}

void hare::smallHop() //Move 1 square to the right
{
	square += 1;
}

void hare::smallSlip() //Move 2 squares to the left
{
	square -= 2;

	if(square < 1)
		square = 1;
}

/*******************************
 **                           **
 **	 Main class and methods   **
 **                           **
 *******************************/

void tick();
void displayOutput();

int main()
{
	cout << "BANG !!!!!" << "\nAND THEY'RE OFF !!!!!" << endl;

	while(!(turtle.victor() || rabbit.victor()))
	{
		
		this_thread::sleep_for(chrono::seconds(1)); //This line sends a pause of 1 second to the thread
		tick();
	}

	if(turtle.victor() && rabbit.victor()) //Checks for tiw
		cout << "IT'S A TIE!!!";
	else if(turtle.victor()) //Checks for turtle winning
		turtle.win();
	else
		rabbit.win(); //Checks for rabbit winning

	return 0;
}

void tick() //Generates random number to decide moves for tortoise and hare
{
	srand(time(0)); //Resets the random number generator

	int random = rand() % 10 + 1; //Generates random number from 1-10 inclusive

	//Moves for turtle based on random number
	if(random < 5)
		turtle.fastPlod();
	else if(random < 7)
		turtle.slip();
	else
		turtle.slowPlod();

	//Moves for rabbit based on random number
	if((random >= 2) && (random < 4))
		rabbit.bigHop();
	else if(random < 5)
		rabbit.bigSlip();
	else if(random < 8)
		rabbit.smallHop();
	else if(random < 10)
		rabbit.smallSlip();

	displayOutput();
}

void displayOutput() //Displays output to show the progression of the race
{
	cout << endl;

	if(turtle.square < rabbit.square) //Output for when turtle is behind rabbit
	{
		for(int i = 1; i < turtle.square; i++)
			cout << '_';

		cout << 'T';

		for(int i = 1; i < (rabbit.square - turtle.square); i++)
			cout << '_';

		cout << 'H';

		for(int i = 1; i < (70 - rabbit.square); i++)
			cout << '_';

		cout << endl;
	}
	else if(rabbit.square < turtle.square) //Output for when rabbit is behind turtle
	{
		for(int i = 1; i < rabbit.square; i++)
			cout << '_';

		cout << 'H';

		for(int i = 1; i < (turtle.square - rabbit.square); i++)
			cout << '_';

		cout << 'T';

		for (int i = 1; i < (70 - turtle.square); i++)
			cout << '_';

		cout << endl;
	}
	else //Output for when both are on same square
	{
		for (int i = 1; i < rabbit.square; i++)
			cout << '_';

		cout << 'B';

		for (int i = 1; i < (70 - rabbit.square); i++)
			cout << '_';

		cout << endl << "OUCH !!!" << endl;
	}

}