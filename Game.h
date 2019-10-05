#include <iostream>
#include <fstream>
#include <string>
#include "Wizard.h"
#include "Foundable.h"

using namespace std;

//constants
const string FILE_NAME = "proj2.txt"; //File name
static const int limitOfRarity1 = 72;
static const int limitOfRarity2 = 84;
static const int limitOfRarity3 = 14;
static const int limitOfRarity4 = 20;
static const int limitOfRarity5 = 7;

class Game {
public:
    // Name: Game() (Default constructor)
    // Preconditions: Foundable file must be loaded successfully into m_allFoundables
    // Postconditions: Creates new game
    Game();

    // Name: GetWizardName()
    // Preconditions: Requires valid string name
    // Postconditions: Returns wizard name
    void GetWizardName();

    // Name: MainMenu()
    // Preconditions: Requires valid string name and populated m_allFoundables
    // Postconditions: Manages win condition and game
    void MainMenu();

    // Name: LoadFoundables()
    // Preconditions: Requires valid file name and input file
    // Postconditions: Populates m_allFoundables
    int LoadFoundables();

    // Name: PrintFoundables()
    // Preconditions: Requires populated m_allFoundables
    // Postconditions: Displays all Foundables in game
    void PrintFoundables();

    // Name: WizardStat()
    // Preconditions: Requires Wizard to be created and populated
    // Postconditions: None (display function)
    void WizardStat();

    // Name: PrintMyFoundables()
    // Preconditions: Requires m_foundables in Wizard to be populated
    // Postconditions: None (display function)
    void PrintMyFoundables();

    // Name: AttackFoundable
    // Preconditions: Requires m_allFoundables to be populated
    // Postconditions: Wizard attacks and passes Foundables of specific rarity (1-5).
    //                 No duplicate Foundables can be attacked.
    void AttackFoundable();

    void SelectFoundableToAttack(int chosenRarity);

private:
    Wizard m_wizard; //Wizard for game (player)
    Foundable m_allFoundables[NUM_FOUNDABLE]; //Master list of all Foundables in game
};
