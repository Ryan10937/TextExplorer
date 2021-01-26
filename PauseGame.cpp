#include<iostream>
#include<string>
#include "Color.h"

void Pause()
{
	std::cout << "Press ";
	SetColor(14);
	std::cout << "ENTER";
	ResetColor();
	std::cout << " to continue";

	// Clear input stream
	std::cin.clear();

	// Discard previous input
	std::cin.ignore(123, '\n');

	//"Pauses" to wait for any input ie: the enter button
	std::string pause;
	getline(std::cin, pause);

	// Clear input stream
	std::cin.clear();
}
