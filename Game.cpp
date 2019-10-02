//
// Created by phamt on 10/1/2019.
//

#include "Game.h"
#include <fstream>
#include <string>
//#include <sstream>

Game::Game() {
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

    cout << count << endl;
    for (int i = 0; i < NUM_FOUNDABLE; ++i) {
        cout << i << "/ " << m_allFoundables[i].GetName() << " " << m_allFoundables[i].GetType() << " "
             << m_allFoundables[i].GetRarity() << " " << m_allFoundables[i].GetToughness() << endl;

    }

    theFile.close();
}

