//
// Created by phamt on 10/1/2019.
//

#include "Wizard.h"
#include <string>
#include <ctime>

static int trackFoundable = 0;
const string fullRarityTypeWarning = "You have found all Foundables at that level of rarity!";

Wizard::Wizard() {
    SetToughness(rand() % MAX_START_TOUGH + MIN_START_TOUGH);
    SetLevel(1);
}

Wizard::Wizard(string name) {
    SetName(name);
//    SetToughness(rand() % MAX_START_TOUGH + MIN_START_TOUGH);
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
    return trackFoundable;
}

void Wizard::SetName(string name) {
    m_name = name;
}

void Wizard::SetToughness(int toughness) {
    m_toughness += toughness;
}

void Wizard::SetLevel(int level) {
    m_level = level;
}

void Wizard::CountLoses() {
    m_losses++;
}

void Wizard::InsertFoundable(Foundable newFoundable) {
    if (trackFoundable < NUM_FOUNDABLE) {
        m_foundables[NUM_FOUNDABLE] = newFoundable;
        trackFoundable++;
        srand(time(NULL));
        IncreaseLevel();
        SetToughness(rand() % LEVEL_TOUGH_INCREASE + 1);
    }
    if (trackFoundable == NUM_FOUNDABLE) {
        cout << "Cannot insert anymore. Your Foundable is full. " << endl;
    }
}

//This can be a function to check a defeated foundable of a particular rarity.
//What rarity of foundable would you like to challenge (1-5)?
//4
//You have found all Foundables at that level of rarity!
// MUST MODIFIED THIS AND ADD MORE ARRAY
bool Wizard::CheckFoundable(Foundable newFoundable) {
    bool isExist;
    bool isNameEqual;
    bool isTypeEqual;
    bool isRarityEqual;
    bool isToughnessEqual;
    for (int i = 0; i < NUM_FOUNDABLE; ++i) {
        if (m_foundables[NUM_FOUNDABLE].GetName() == newFoundable.GetName()) {
            isNameEqual = true;
        }
        if (m_foundables[NUM_FOUNDABLE].GetType() == newFoundable.GetType()) {
            isTypeEqual == true;
        }
        if (m_foundables[NUM_FOUNDABLE].GetRarity() == newFoundable.GetRarity()) {
            isRarityEqual = true;
        }
        if (m_foundables[NUM_FOUNDABLE].GetToughness() == newFoundable.GetToughness()) {
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
        CountLoses();
    }
    if (enemy.GetToughness() < GetToughness()) {
        isDefeated = true;
    }
    return isDefeated;
}

void Wizard::PrintMyFoundables() {
    if (trackFoundable == 0) {
        cout << "You have not defeated any foundables yet.";
    }
    if (trackFoundable != 0) {
        for (int i = 0; i < trackFoundable; ++i) {
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

