//
// Created by phamt on 10/1/2019.
//

#include "Game.h"
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

Game::Game() {
    int count;
    GetWizardName();
    count = LoadFoundables();
    cout << "Welcome to Harry Potter: Wizard Unite" << endl;
    cout << count << " Foundables loaded" << endl;
    MainMenu();
}

void Game::GetWizardName() {
    string wizardName;
    cout << "What is the name of your wizard?" << endl;
    cin >> wizardName;
    m_wizard.SetName(wizardName);
}

void Game::MainMenu() {
    int choice;
    bool isQuit = false;
    while (!isQuit) {
        cout << "What would you like to do?" << endl;
        cout << "1. Wizard information" << endl;
        cout << "2. List My Foundables" << endl;
        cout << "3. List All Foundables" << endl;
        cout << "4. Attack Foundables" << endl;
        cout << "5. Quit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                WizardStat();
                break;
            case 2:
                PrintMyFoundables();
                break;
            case 3:
                PrintFoundables();
                break;
            case 4:
                AttackFoundable();
                break;
            case 5:
                isQuit = true;
                break;
            default:
                cout << "Invalid choice. Please choose again" << endl;
        }
    }
}

int Game::LoadFoundables() {
    int count = 0;
    char comma = ',';
    string line;
    string m_name; //Name of the Foundable
    string m_type; //Type of the Foundable
    int m_rarity; //Rarity of the Foundable (1-5)
    string tempRarity;
    int m_toughness; //Toughness of the Foundable
    string tempToughness;

    ifstream theFile(FILE_NAME);
    if (!theFile.is_open()) {
        cout << " Failed to open" << endl;
    } else {
        cout << "File Opened Successfully" << endl;
    }

    while (theFile.good()) {
        getline(theFile, m_name, comma);
        getline(theFile, m_type, comma);
        getline(theFile, tempRarity, comma);
        m_rarity = stoi(tempRarity);
        getline(theFile, tempToughness, '\n');
        m_toughness = stoi(tempToughness);
        Foundable tempFoundable(m_name, m_type, m_rarity, m_toughness);
        m_allFoundables[count] = tempFoundable;
        ++count;
        if (count == NUM_FOUNDABLE) {
            theFile.close();
            break;
        }
    }

    return NUM_FOUNDABLE;
}

void Game::PrintFoundables() {
    int number = 1;
    for (int i = 0; i < NUM_FOUNDABLE; ++i) {
        cout << number + i << "/ " << m_allFoundables[i].GetName() << " " << m_allFoundables[i].GetType() << " "
             << m_allFoundables[i].GetRarity() << " " << m_allFoundables[i].GetToughness() << endl;
    }
}

void Game::WizardStat() {
    double ONE_HUNDRED = 100;
    double winRate = 0;
//    if (m_wizard.GetWins() == 0 && m_wizard.GetLosses() == 0) {
//        winRate = 0;
//    }
    if (m_wizard.GetWins() != 0 || m_wizard.GetLosses() != 0) {
        winRate = (m_wizard.GetWins() * ONE_HUNDRED) / (m_wizard.GetWins() + m_wizard.GetLosses());
    }

    cout << "Information about Wizard " << m_wizard.GetName() << endl;
    cout << "Level: " << m_wizard.GetLevel() << endl;
    cout << "Toughness " << m_wizard.GetToughness() << endl;
    cout << "Foundables found:" << m_wizard.GetWins() << endl;
    cout << "Wins " << m_wizard.GetWins() << " Loses " << m_wizard.GetLosses() << endl;
    cout << fixed;
    cout << setprecision(2);
    cout << "Win Rate: " << winRate << "%" << endl;
}

void Game::PrintMyFoundables() {
    if (m_wizard.GetWins() == 0) {
        cout << "You haven't defeated any Foundable" << endl;
    }
    if (m_wizard.GetWins() != 0) {
        m_wizard.PrintMyFoundables();
    }
}

void Game::AttackFoundable() {
    int rarityChoice;

    cout << "What rarity of Foundable would you like to challenge (1-5)?" << endl;
    cin >> rarityChoice;
    switch (rarityChoice) {
        case 1:
            SelectFoundableToAttack(1);
            break;
        case 2:
            SelectFoundableToAttack(2);
            break;
        case 3:
            SelectFoundableToAttack(3);
            break;
        case 4:
            SelectFoundableToAttack(4);
            break;
        case 5:
            SelectFoundableToAttack(5);
            break;
        default:
            cout << "Invalid choice. Please choose again" << endl;

    }
}

void Game::SelectFoundableToAttack(int chosenRarity) {
    int randomEnemyIndex;
    int limitOfRarity;
    bool isAllFoundableDefeated = false;
    int countRarity = 0;
    int index = 0;
    switch (chosenRarity) {
        case 1:
            limitOfRarity = limitOfRarity1;
            break;
        case 2:
            limitOfRarity = limitOfRarity2;
            break;
        case 3:
            limitOfRarity = limitOfRarity3;
            break;
        case 4:
            limitOfRarity = limitOfRarity4;
            break;
        case 5:
            limitOfRarity = limitOfRarity5;
    }
    Foundable tempFoundableRare[85];

    randomEnemyIndex = rand() % limitOfRarity;
    for (int i = 0; i < NUM_FOUNDABLE; ++i) {
        if (m_allFoundables[i].GetRarity() == chosenRarity) {
//            tempFoundableRare[index] = m_allFoundables[i];
            Foundable tempFoundable(m_allFoundables[i].GetName(), m_allFoundables[i].GetType(),
                                    m_allFoundables[i].GetRarity(), m_allFoundables[i].GetToughness());
            tempFoundableRare[index] = tempFoundable;
            ++index;
        }
    }
    cout << "Size tempArray: " << index << endl;
    while (m_wizard.CheckFoundable(tempFoundableRare[randomEnemyIndex])) {

        if (countRarity == limitOfRarity) {
            cout << "You have defeated all the Foundables of the rarity " << chosenRarity << endl;
            isAllFoundableDefeated = true;
            break;
        }
//        if (countRarity < limitOfRarity) {
        randomEnemyIndex = rand() % limitOfRarity;
        countRarity++;
//        }
    }
    if (countRarity <= limitOfRarity) {
        if (m_wizard.AttackFoundable(tempFoundableRare[randomEnemyIndex]) && !isAllFoundableDefeated) {
            int newToughness = 0;
            cout << tempFoundableRare[randomEnemyIndex].GetName() << " "
                 << tempFoundableRare[randomEnemyIndex].GetType()
                 << " "
                 << tempFoundableRare[randomEnemyIndex].GetRarity() << " "
                 << tempFoundableRare[randomEnemyIndex].GetToughness() << endl;
            cout << "You have defeated " << tempFoundableRare[randomEnemyIndex].GetName() << endl;
            m_wizard.InsertFoundable(tempFoundableRare[randomEnemyIndex]);
            newToughness = m_wizard.GetToughness() + rand() % LEVEL_TOUGH_INCREASE + 1;
            m_wizard.SetToughness(newToughness);
        }
        if (!m_wizard.AttackFoundable(tempFoundableRare[randomEnemyIndex]) && !isAllFoundableDefeated) {
            cout << tempFoundableRare[randomEnemyIndex].GetName() << " "
                 << tempFoundableRare[randomEnemyIndex].GetType()
                 << " "
                 << tempFoundableRare[randomEnemyIndex].GetRarity() << " "
                 << tempFoundableRare[randomEnemyIndex].GetToughness() << endl;
            cout << "You have not defeated " << tempFoundableRare[randomEnemyIndex].GetName() << endl;
            m_wizard.CountLoses();
        }
    }
}

//void Game::ShowWinRate() {
//    if (m_wizard.GetWins() == 0 &&  m_wizard.GetLosses() == 0){
//
//    }
//}
