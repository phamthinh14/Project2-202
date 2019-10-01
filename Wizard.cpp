//
// Created by phamt on 10/1/2019.
//

#include "Wizard.h"
#include <string>

static int trackFoundable = 0;

Wizard::Wizard() {

}

Wizard::Wizard(string name) {
    SetName(name);
    SetToughness(1);
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

void Wizard::InsertFoundable(Foundable newFoundable) {

    if (trackFoundable < NUM_FOUNDABLE) {
        m_foundables[trackFoundable] = newFoundable;
        trackFoundable++;
    }
    if (trackFoundable == NUM_FOUNDABLE) {
        cout << "Cannot insert anymore. Your Foundable is full. " << endl;
    }
}

bool Wizard::CheckFoundable(Foundable newFoundable) {
    bool isExist;
    bool isNameEqual;
    bool isTypeEqual;
    bool isRarityEqual;
    bool isToughnessEqual;
    for (int i = 0; i < NUM_FOUNDABLE; ++i) {
        if (m_foundables[NUM_FOUNDABLE].GetName().compare(newFoundable.GetName()) == 0) {
            isNameEqual = true;
        }
        if (m_foundables[NUM_FOUNDABLE].GetType().compare(newFoundable.GetType()) == 0) {
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
    return false;
}

void Wizard::PrintMyFoundables() {
    for (int i = 0; i < trackFoundable; ++i) {
        cout << m_foundables[i].GetName() << " " << m_foundables[i].GetType() <<
             " Rarity: " << m_foundables[i].GetRarity() << " Toughness: " << m_foundables[i].GetToughness() << endl;
    }
}

void Wizard::IncreaseLevel() {
    m_level++;
}



