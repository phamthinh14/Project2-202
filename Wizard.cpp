//
// Created by phamt on 10/1/2019.
//

#include "Wizard.h"
#include <string>
#include <ctime>

const string fullRarityTypeWarning = "You have found all Foundables at that level of rarity!";

Wizard::Wizard() {
    SetToughness((rand() % MIN_START_TOUGH) + MIN_START_TOUGH);
    SetLevel(1);
    SetWin(0);
    SetLose(0);
}

Wizard::Wizard(string name) {
    SetName(name);
    SetToughness((rand() % MIN_START_TOUGH) + MIN_START_TOUGH);
    SetLevel(1);
}

string Wizard::GetName() {
    return m_name;
}

int Wizard::GetToughness() {
    return m_toughness;
}

int Wizard::GetLevel() {
    return m_level;
}

int Wizard::GetLosses() {
    return m_losses;
}

int Wizard::GetWins() {
    return m_wins;
}

void Wizard::SetName(string name) {
    m_name = name;
}

void Wizard::SetToughness(int toughness) {
    m_toughness = toughness;
}

void Wizard::SetLevel(int level) {
    m_level = level;
}

void Wizard::SetWin(int wins) {
    m_wins = wins;
}

void Wizard::SetLose(int lose) {
    m_losses = lose;
}

void Wizard::CountLoses() {
    m_losses++;
}

void Wizard::CountWins() {
    m_wins++;
}

//void Wizard::IncreaseToughness() {
//    m_toughness +=
//}

void Wizard::InsertFoundable(Foundable newFoundable) {

    m_foundables[GetWins()] = newFoundable;
    CountWins();
    srand(time(NULL));
    IncreaseLevel();


}

//This can be a function to check a defeated foundable of a particular rarity.
//What rarity of foundable would you like to challenge (1-5)?
//4
//You have found all Foundables at that level of rarity!
// MUST MODIFIED THIS AND ADD MORE ARRAY
bool Wizard::CheckFoundable(Foundable newFoundable) {
    bool isExist;
    bool isNameEqual = false;
    bool isTypeEqual = false;
    bool isRarityEqual = false;
    bool isToughnessEqual = false;
    for (int i = 0; i < NUM_FOUNDABLE; ++i) {
        if (m_foundables[i].GetName().compare(newFoundable.GetName()) == 0) {
            isNameEqual = true;
        }
        if (m_foundables[i].GetType().compare(newFoundable.GetType()) == 0) {
            isTypeEqual = true;
        }
        if (m_foundables[i].GetRarity() == newFoundable.GetRarity()) {
            isRarityEqual = true;
        }
        if (m_foundables[i].GetToughness() == newFoundable.GetToughness()) {
            isToughnessEqual = true;
        }
    }
    if (isNameEqual && isTypeEqual && isRarityEqual && isToughnessEqual) {
        isExist = true;
    } else {
        isExist = false;
    }
    return isExist;
}

bool Wizard::AttackFoundable(Foundable enemy) {
    bool isDefeated;
    if (enemy.GetToughness() >= GetToughness()) {
        isDefeated = false;

    }
    if (enemy.GetToughness() < GetToughness()) {
        isDefeated = true;
//        InsertFoundable(enemy);
    }
    return isDefeated;
}

void Wizard::PrintMyFoundables() {
    if (GetWins() == 0) {
        cout << "You have not defeated any foundables yet.";
    }
    if (GetWins() != 0) {
        for (int i = 0; i < GetWins(); ++i) {
            cout << m_foundables[i].GetName() << " " << m_foundables[i].GetType() <<
                 " Rarity: " << m_foundables[i].GetRarity() << " Toughness: " << m_foundables[i].GetToughness()
                 << endl;
        }
    }
}

void Wizard::IncreaseLevel() {
    m_level++;
}

//    bool isFoundableAcquired;
//    switch (newFoundable.GetRarity()) {
//        case 1:
//            if (acquiredRarity1 < limitOfRarity1) {
//                InsertFoundable(newFoundable);
//                acquiredRarity1++;
//                isFoundableAcquired = true;
//            }
//            if (acquiredRarity1 == limitOfRarity1) {
//                cout << fullRarityTypeWarning << endl;
//                isFoundableAcquired = false;
//            }
//            break;
//        case 2:
//            if (acquiredRarity2 < limitOfRarity2) {
//                InsertFoundable(newFoundable);
//                acquiredRarity2++;
//                isFoundableAcquired = true;
//            }
//            if (acquiredRarity2 == limitOfRarity2) {
//                cout << fullRarityTypeWarning << endl;
//                isFoundableAcquired = false;
//            }
//            break;
//        case 3:
//            if (acquiredRarity3 < limitOfRarity3) {
//                InsertFoundable(newFoundable);
//                acquiredRarity3++;
//                isFoundableAcquired = true;
//            }
//            if (acquiredRarity3 == limitOfRarity3) {
//                cout << fullRarityTypeWarning << endl;
//                isFoundableAcquired = false;
//            }
//            break;
//        case 4:
//            if (acquiredRarity4 < limitOfRarity4) {
//                InsertFoundable(newFoundable);
//                acquiredRarity4++;
//                isFoundableAcquired = true;
//            }
//            if (acquiredRarity4 == limitOfRarity4) {
//                cout << fullRarityTypeWarning << endl;
//                isFoundableAcquired = false;
//            }
//            break;
//        case 5:
//            if (acquiredRarity5 < limitOfRarity5) {
//                InsertFoundable(newFoundable);
//                acquiredRarity5++;
//                isFoundableAcquired = true;
//            }
//            if (acquiredRarity5 == limitOfRarity5) {
//                cout << fullRarityTypeWarning << endl;
//                isFoundableAcquired = false;
//            }
//    }
//    return isFoundableAcquired;

