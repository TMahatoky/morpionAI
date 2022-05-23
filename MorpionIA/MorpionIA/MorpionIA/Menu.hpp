#include "Jeu.hpp"
#include <vector>
class Menu {
// attributes
public:
    std::vector <std::string> options;
    int choice;
    Jeu in;
// methods
    void initMenu();
    void getChoice();
    void manageChoice();
    int digit(int x);
};
