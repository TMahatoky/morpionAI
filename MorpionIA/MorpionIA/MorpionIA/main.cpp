#include <iostream>
#include "Menu.hpp"

int main(){
	Menu home;
	Jeu morp;
	home.initMenu();
	home.getChoice();
	home.manageChoice();
	morp = home.in;
	return 0;
}
