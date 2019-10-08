//
// Created by phamt on 10/1/2019.
//

#include "Foundable.h"

Foundable::Foundable() {
//    SetName("Ethan");
//    SetType("Wizard");
//    SetRarity(1);
//    SetToughness(10);
}

Foundable::Foundable(string name, string type, int rarity, int toughness) {
//    SetName(name);
//    SetType(type);
//    SetRarity(rarity);
//    SetToughness(toughness);
    m_name = name;
    m_type = type;
    m_rarity = rarity;
    m_toughness = toughness;
}

string Foundable::GetName() {
    return m_name;
}

string Foundable::GetType() {
    return m_type;
}

int Foundable::GetRarity() {
    return m_rarity;
}

int Foundable::GetToughness() {
    return m_toughness;
}

void Foundable::SetName(string newName) {
    m_name = newName;
}

void Foundable::SetType(string newType) {
    m_type = newType;
}

void Foundable::SetRarity(int newRarity) {
    m_rarity = newRarity;
}

void Foundable::SetToughness(int newToughness) {
    m_toughness = newToughness;
}
