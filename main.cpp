#include <iostream>
#include <unistd.h>
#include <chrono>
#include<string>
#include "colours.h"
#include <vector>
using namespace std;

void write(string hello) {

int x=0;
while ( hello[x] != '\0')
{
	cout << FOREGRN << hello[x];
	usleep(10000);
	x++;
};


}

string found_planets = "";
int pf = 0;

string type[] {

	"Gas Planet",
	"Terrestrial",
	"Water World",
	"Warm Terrestrial"

};

string star[] {

	"Red dwarf",
	"Orange dwarf",
	"Blue dwarf",
	"Yellow dwarf",
	"Brown dwarf",
	"Red dwarf & orange dwarf (binary)",
	"Yellow & orange dwarf (binary)",
	"Blue dwarf & yellow dwarf (binary)",
	"Red dwarf & red dwarf (binary)"

};

string life[] {

	"Single celled life",
	"Atmospheric life",
	"Terrestrial life",
	"Intelligent life",
	"Intelligent civilisation"

};

//points
int points = 10;

void genPlanet() {

	//damn bro this is gonna be hard...
	//lets go tho
	//hmsstt
	// we do need 
	// MASS, TYPE, STAR, LIFE, SATTELITES

	//Let mass be 1 earths to 150 earths.
	struct planet {
		int mass;
		string type;
		string star;
		string life = "None";
		int satellites;
	};

	planet NewPlanet;

	//Well here we go setting the stuff...

	NewPlanet.mass = rand() % 50 + 1;
	NewPlanet.type = type[rand() % 3];
	NewPlanet.star = star[rand() % 8];

	//life?
	int temp = rand() % 100;
	if (temp == 1) {
		NewPlanet.life = life[rand() % 4];
	}

	NewPlanet.satellites = rand() % 10;

	write("\nPlanet found!\n\n");
	write("Mass: " + to_string(NewPlanet.mass) + " earth masses\n");
	write("Type: " + NewPlanet.type + "\n");
	write("Star: " + NewPlanet.star + "\n");
	write("Any life?: " + NewPlanet.life + "\n");
	write("Satellites: " + to_string(NewPlanet.satellites) + "\n");

	pf++;
	found_planets += "RJ" + to_string(pf) + "\nMass (earth masses): " + to_string(NewPlanet.mass) + "\nType: " + NewPlanet.type + "\n\n";
	points++;

	cout << RED("\nPress any key to continue...\n");
	getchar();



}

int main() {

	write("Welcome to Mission Procoyon!\n\n");

	sleep(2);

	write("Your job is to find and study planets. When you find a planet, you get points!\n\n");

	sleep(2);

	write("You'll start off with 10 points. Enjoy!\n\n");

	sleep(2);	

	write(">> Welcome to Mission Procoyon! <<\n");
	write("    Press 1 to search planets\n");
	write("   Press 2 to view your points\n");
	write("   Press 3 to view your planets\n");
	write("==================================\n");

	string input;

	do {
		//Input
		string input;

		//Get input
		write(">");
		getline(cin, input);

		if (input == "1") {

			if (rand() % 5 == 2) {
				genPlanet();
			} else {
				write ("\nBad luck, you didn't find anything.\n");

				cout << RED("\nPress any key to continue...\n");
				getchar();
			}

		}	else if (input == "2") {

			write("\nYou have " + to_string(points) + " points.\n\n");

		} else if (input == "3") {

			write("You have found these planets\n\n");
			write(found_planets);

		} else {

			write("Thats not a valid option.\n");

		}

	} while (true);
  
}