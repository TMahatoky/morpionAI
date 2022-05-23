#include "Menu.hpp"
// MENU
void Menu :: initMenu(){
// initialisation of the contents of the menu 
    options.push_back("1 Start");
    options.push_back("2 Difficulty");
    options.push_back("0 Quit");
    choice = -1;
}
void Menu :: getChoice(){
// setting up of choice so that while may directly work
    choice = -1;
    while(choice<0 || choice>2){
        std::cout << "Enter : " << std::endl;
        for(int a(0); a<options.size();a++){
            std::cout << '\t' << options[a] << std::endl;
        }
        choice = digit(choice);
    }
}
void Menu :: manageChoice(){
    int chx = -1;
    switch(choice){
        // if the user chooses to start the game  
        case 1:
            in.setprof(0);
            std::cout << "\n\t\tThe game will start in easy mode" << std::endl;
            in.start();
            break;
        case 2:
            while(chx<0 || chx>2){
                std::cout << "Enter : " << std::endl;
                std::cout << "\t1 Easy " << std::endl;
                std::cout << "\t2 Normal " << std::endl;
                std::cout << "\t0 Return to Menu " << std::endl;
                chx = digit(chx);
                if(chx==1){
                    in.setprof(0);
                    std::cout << "\n\t\tThe game will start in easy mode" << std::endl;
                    in.start();
                }
                else if(chx==2){ 
                    in.setprof(6); 
                    std::cout << "\n\t\tThe game will start in normal mode" << std::endl;
                    in.start();                    
                }
                else if(chx==0){
                    getChoice();
                    manageChoice();
                }
            }
            break; 
        // if the user chooses to quit the game 
        case 0:
            break;
    }
}
int Menu::digit (int x){
    std::cout<<"Then, choose options from the menu :";
    std::cin>>x;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bad input, please only enter numbers" << "\n" << std::endl;
        digit(x);
    }
    else{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(x<0 || x>2){
            std::cout << "invalid choice" << std::endl;
        }
     return x;
    }
}
