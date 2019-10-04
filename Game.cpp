//
// Created by phamt on 10/1/2019.
//

#include "Game.h"
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const int limitOfRarity1 = 71;
const int limitOfRarity2 = 83;
const int limitOfRarity3 = 13;
const int limitOfRarity4 = 19;
const int limitOfRarity5 = 6;
int acquiredRarity1 = 0;
int acquiredRarity2 = 0;
int acquiredRarity3 = 0;
int acquiredRarity4 = 0;
int acquiredRarity5 = 0;
//Wizard wizard;

Game::Game() {
    int count;
    string wizardName;
    cout << "What is the name of your wizard?" << endl;
    cin >> wizardName;
    m_wizard.SetName(wizardName);
//    m_wizard.SetToughness(20);
//    cout << m_wizard.GetToughness();

//    count = LoadFoundables();
//    PrintFoundables();
//    cout << "Welcome to Harry Potter: Wizard Unite" << endl;
//    cout << count << " Foundables loaded" << endl;
    MainMenu();
}

void Game::GetWizardName() {
    cout << "Wizard Name: " << m_wizard.GetName();
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
        cout << "Opened OK" << endl;
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
    }
    theFile.close();
    return NUM_FOUNDABLE;
}

void Game::PrintFoundables() {
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    for (int i = 0; i < NUM_FOUNDABLE; ++i) {
        cout << i << "/ " << m_allFoundables[i].GetName() << " " << m_allFoundables[i].GetType() << " "
             << m_allFoundables[i].GetRarity() << " " << m_allFoundables[i].GetToughness() << endl;
        if (m_allFoundables[i].GetRarity() == 1) {
            count1++;
        }
        if (m_allFoundables[i].GetRarity() == 2) {
            count2++;
        }
        if (m_allFoundables[i].GetRarity() == 3) {
            count3++;
        }
        if (m_allFoundables[i].GetRarity() == 4) {
            count4++;
        }
        if (m_allFoundables[i].GetRarity() == 5) {
            count5++;
        }
    }
    cout << "Rarity 1 " << count1 << endl;
    cout << "Rarity 2 " << count2 << endl;
    cout << "Rarity 3 " << count3 << endl;
    cout << "Rarity 4 " << count4 << endl;
    cout << "Rarity 5 " << count5 << endl;
}

void Game::WizardStat() {
    cout << "Information about Wizard " << m_wizard.GetName() << endl;
    cout << "Level: " << m_wizard.GetLevel() << endl;
    cout << "Toughness " << m_wizard.GetToughness()<< endl;
    cout << "Foundables found" << endl;
    cout << "Wins " << " Loses " << endl;
    cout << "Win Rate: " << endl;
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

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;
        case 5:

            break;
        default:
            cout << "Invalid choice. Please choose again" << endl;

    }
}

//    while (getline(theFile, line)) {
//        stringstream ss(line);
//        getline(ss, m_name, ',');
//        getline(ss, m_type, ',');
//        getline(ss, tempRarity, ',');
//        m_rarity = stoi(tempRarity);
//        getline(ss, tempToughness, ',');
//        m_toughness = stoi(tempToughness);
//        m_rarity = stoi(tempRarity);
//        Foundable tempFoundable(m_name, m_type, m_rarity, m_toughness);
//        m_allFoundables[count] = tempFoundable;
//        count++;
//    }