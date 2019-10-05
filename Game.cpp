//
// Created by phamt on 10/1/2019.
//

#include "Game.h"
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

Game::Game() {
    int count;
    string wizardName;
    cout << "What is the name of your wizard?" << endl;
    cin >> wizardName;
    m_wizard.SetName(wizardName);
//    m_wizard.SetToughness(20);
//    cout << m_wizard.GetToughness();
    count = LoadFoundables();
//    PrintFoundables();
    cout << "Welcome to Harry Potter: Wizard Unite" << endl;
    cout << count << " Foundables loaded" << endl;
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
//    int count1 = 0;
//    int count2 = 0;
//    int count3 = 0;
//    int count4 = 0;
//    int count5 = 0;
    for (int i = 0; i < NUM_FOUNDABLE; ++i) {
        cout << i << "/ " << m_allFoundables[i].GetName() << " " << m_allFoundables[i].GetType() << " "
             << m_allFoundables[i].GetRarity() << " " << m_allFoundables[i].GetToughness() << endl;
//        if (m_allFoundables[i].GetRarity() == 1) {
//            count1++;
//        }
//        if (m_allFoundables[i].GetRarity() == 2) {
//            count2++;
//        }
//        if (m_allFoundables[i].GetRarity() == 3) {
//            count3++;
//        }
//        if (m_allFoundables[i].GetRarity() == 4) {
//            count4++;
//        }
//        if (m_allFoundables[i].GetRarity() == 5) {
//            count5++;
//        }
    }
//    cout << "Rarity 1 " << count1 << endl;
//    cout << "Rarity 2 " << count2 << endl;
//    cout << "Rarity 3 " << count3 << endl;
//    cout << "Rarity 4 " << count4 << endl;
//    cout << "Rarity 5 " << count5 << endl;
}

void Game::WizardStat() {
    cout << "Information about Wizard " << m_wizard.GetName() << endl;
    cout << "Level: " << m_wizard.GetLevel() << endl;
    cout << "Toughness " << m_wizard.GetToughness() << endl;
    cout << "Foundables found:" << m_wizard.GetWins() << endl;
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
            SelectFoundableToAttack(rarityChoice);
            break;
        case 2:
            SelectFoundableToAttack(rarityChoice);
            break;
        case 3:
            SelectFoundableToAttack(rarityChoice);
            break;
        case 4:
            SelectFoundableToAttack(rarityChoice);
            break;
        case 5:
            SelectFoundableToAttack(rarityChoice);
            break;
        default:
            cout << "Invalid choice. Please choose again" << endl;

    }
}

void Game::SelectFoundableToAttack(int chosenRarity) {
    int randomEnemyIndex;
    int countRarity = 0;
    int limitOfRarity;
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
        if (m_allFoundables[i].GetRarity() == 1) {
//            tempFoundableRare[index] = m_allFoundables[i];
            Foundable tempFoundable(m_allFoundables[i].GetName(), m_allFoundables[i].GetType(),
                                    m_allFoundables[i].GetRarity(), m_allFoundables[i].GetToughness());
            tempFoundableRare[index] = tempFoundable;
            ++index;
        }
    }
    while (m_wizard.CheckFoundable(tempFoundableRare[randomEnemyIndex])) {
        countRarity++;
        if (countRarity == limitOfRarity) {
            cout << "You have defeated all the Foundables of the rarity " << chosenRarity << endl;
            break;
        }
        if (countRarity < limitOfRarity) {
            randomEnemyIndex = rand() % limitOfRarity;
        }
    }
    if (countRarity <= limitOfRarity) {
        cout << tempFoundableRare[randomEnemyIndex].GetName() << " " << tempFoundableRare[randomEnemyIndex].GetType()
             << " "
             << tempFoundableRare[randomEnemyIndex].GetRarity() << " "
             << tempFoundableRare[randomEnemyIndex].GetToughness() << endl;
        if (m_wizard.AttackFoundable(tempFoundableRare[randomEnemyIndex])) {
            int newToughness = 0;
            cout << "You have defeated " << tempFoundableRare[randomEnemyIndex].GetName() << endl;
            m_wizard.InsertFoundable(tempFoundableRare[randomEnemyIndex]);
            newToughness = m_wizard.GetToughness() + rand() % LEVEL_TOUGH_INCREASE + 1;
            m_wizard.SetToughness(newToughness);
        }
        if (!m_wizard.AttackFoundable(tempFoundableRare[randomEnemyIndex])) {
            cout << "You have not defeated " << tempFoundableRare[randomEnemyIndex].GetName() << endl;
        }
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

//int randomEnemyIndex;
//int countRarity1 = 0;
//int countRarity2 = 0;
//int countRarity3 = 0;
//int countRarity4 = 0;
//int countRarity5 = 0;
//Foundable tempFoundableRare1[limitOfRarity1];
//Foundable tempFoundableRare2[limitOfRarity2];
//Foundable tempFoundableRare3[limitOfRarity3];
//Foundable tempFoundableRare4[limitOfRarity4];
//Foundable tempFoundableRare5[limitOfRarity5];

//randomEnemyIndex = rand() % limitOfRarity3;
//for (int i = 0; i < NUM_FOUNDABLE; ++i) {
//if (m_allFoundables[i].GetRarity() == 3) {
//tempFoundableRare3[i] = m_allFoundables[i];
//}
//}
//while (m_wizard.CheckFoundable(tempFoundableRare3[randomEnemyIndex])) {
//countRarity3++;
//if (countRarity3 == limitOfRarity3) {
//cout << "You have defeated all the Foundables of the rarity 3" << endl;
//break;
//}
//if (countRarity3 < limitOfRarity3) {
//randomEnemyIndex = rand() % limitOfRarity3;
//}
//}
//if (countRarity3 <= limitOfRarity3) {
//if (m_wizard.AttackFoundable(tempFoundableRare3[randomEnemyIndex])) {
//cout << "You have defeated " << tempFoundableRare3[randomEnemyIndex].GetName() << endl;
//}
//if (!m_wizard.AttackFoundable(tempFoundableRare3[randomEnemyIndex])) {
//cout << "You have not defeated " << tempFoundableRare3[randomEnemyIndex].GetName() << endl;
//}
//}

//randomEnemyIndex = rand() % limitOfRarity2;
//for (int i = 0; i < NUM_FOUNDABLE; ++i) {
//if (m_allFoundables[i].GetRarity() == 2) {
//tempFoundableRare2[i] = m_allFoundables[i];
//}
//}
//while (m_wizard.CheckFoundable(tempFoundableRare2[randomEnemyIndex])) {
//countRarity2++;
//if (countRarity2 == limitOfRarity2) {
//cout << "You have defeated all the Foundables of the rarity 2" << endl;
//break;
//}
//if (countRarity2 < limitOfRarity2) {
//randomEnemyIndex = rand() % limitOfRarity2;
//}
//}
//if (countRarity2 <= limitOfRarity2) {
//if (m_wizard.AttackFoundable(tempFoundableRare2[randomEnemyIndex])) {
//cout << "You have defeated " << tempFoundableRare2[randomEnemyIndex].GetName() << endl;
//}
//if (!m_wizard.AttackFoundable(tempFoundableRare2[randomEnemyIndex])) {
//cout << "You have not defeated " << tempFoundableRare2[randomEnemyIndex].GetName() << endl;
//}
//}

//randomEnemyIndex = rand() % limitOfRarity1;
//for (int i = 0; i < NUM_FOUNDABLE; ++i) {
//if (m_allFoundables[i].GetRarity() == 1) {
//tempFoundableRare1[i] = m_allFoundables[i];
//}
//}
//while (m_wizard.CheckFoundable(tempFoundableRare1[randomEnemyIndex])) {
//countRarity1++;
//if (countRarity1 == limitOfRarity1) {
//cout << "You have defeated all the Foundables of the rarity 1" << endl;
//break;
//}
//if (countRarity1 < limitOfRarity1) {
//randomEnemyIndex = rand() % limitOfRarity1;
//}
//}
//if (countRarity1 <= limitOfRarity1) {
//if (m_wizard.AttackFoundable(tempFoundableRare1[randomEnemyIndex])) {
//cout << "You have defeated " << tempFoundableRare1[randomEnemyIndex].GetName() << endl;
//}
//if (!m_wizard.AttackFoundable(tempFoundableRare1[randomEnemyIndex])) {
//cout << "You have not defeated " << tempFoundableRare1[randomEnemyIndex].GetName() << endl;
//}
//}