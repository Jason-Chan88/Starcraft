#include "Game.h"
// Default constructor
Game::Game() {
    m_curArea = 0;
    m_curZerg = nullptr;
    m_numRests = 0;
    m_numSpecial = 0;
    m_filename = "";
    m_wins = 0;
}
// Overload constructor
Game::Game(string filename) {
    m_curArea = START_AREA;
    m_curZerg = nullptr;
    m_numRests = NUM_RESTS;
    m_numSpecial = NUM_SPECIAL;
    m_filename = FILE_NAME;
    m_wins = START_WINS;
}
// Destructor to delete everything
Game::~Game() {
    for (unsigned int i = 0; i < m_myMap.size(); i++) {
        delete m_myMap.at(i);
    }
    delete m_curZerg;
    delete m_myTerran;
}
// Load the map that we are given
void Game::LoadMap() {
    ifstream myfile;
    // everything in there is gonna be a string
    string ID = "";
    string name = "";
    string desc = "";
    string north = "";
    string east = "";
    string south = "";
    string west = "";

    myfile.open(FILE_NAME);
    if (myfile.is_open()) {
        // getline all of them, don't delimiter the last one as that will mess up the code
        while (getline(myfile, ID, DELIMITER)) {
            (getline(myfile, name, DELIMITER));
            (getline(myfile, desc, DELIMITER));
            (getline(myfile, north, DELIMITER));
            (getline(myfile, east, DELIMITER));
            (getline(myfile, south, DELIMITER));
            (getline(myfile, west));
            // create a new area pointer and put all the info in there, use stoi to change string to integer
            Area* temp = new Area (stoi (ID), string (name), string(desc), stoi(north), stoi(east), stoi(south), stoi(west));
            m_myMap.push_back(temp);
        }
        cout << "Loading file: " << FILE_NAME << endl;
    }
    else {
        cout << "your file doesn't open, try another" << endl;
    }
  }
// Creating a new terran based off your choice
void Game::TerranCreation() {
    string name = "JD";
    int choice = 0;

    cout << "Enter name:" << endl;
    cin >> name;

    cout << "Terran Name: " << name << endl;
    // makes sure they choose between the choices
    while (choice < 1 || choice > 4) {
        cout << "Select a class" << endl;
        cout << "1. Marine" << endl;
        cout << "2. Ghost" << endl;
        cout << "3. Battlecruiser" << endl;
        cout << "4. No Class" << endl;
        cin >> choice;

    }
    if (choice == 1) {
        m_myTerran = new Marine( "Marine", MARINE_HEALTH);
    }
    else if (choice == 2) {
        m_myTerran = new Ghost( "Ghost", GHOST_HEALTH);
    }
    else if (choice == 3) {
        m_myTerran = new Battlecruiser( "Battlecruiser", BATTLECRUISER_HEALTH);
    }
    else if (choice == 4) {
        m_myTerran = new Terran( "Terran", TERRAN_HEALTH);
    }
}
// This is the start of the game and it's a lot of calling existing function
void Game::StartGame() {
    LoadMap();
    cout << "Welcome to UMBC Starcraft!" << endl;
    TerranCreation();
    m_myMap.at(m_curArea)->PrintArea();
    Action();
}
// This is the menu for the game
void Game::Action() {
    RandomZerg();
    int decision = 0;
    // game will run until you quit or your health is 0
    while (decision != 6 && m_myTerran->GetHealth() != 0) {
        cout << "What would you like to do?" << endl;
        cout << "1. Look" << endl;
        cout << "2. Move" << endl;
        cout << "3. Attack Zerg" << endl;
        cout << "4. Rest" << endl;
        cout << "5. Check Stats" << endl;
        cout << "6. Quit" << endl;
        cin >> decision;


        if (decision == 1) {
            m_myMap.at(m_curArea)->PrintArea();
        }
        else if (decision == 2) {
            // clearing m_curZerg than assigning random zerg
            if (m_curZerg != nullptr) {
                delete m_curZerg;
            }
            m_curZerg = RandomZerg();
            Move();
        }
        else if (decision == 3) {
            // only attack if theirs a Zerg in the area
            if (m_curZerg != nullptr) {
                Attack();
            }
            else {
                cout << "No zerg to attack" << endl;
            }
        }
        else if (decision == 4) {
            Rest();
        }
        else if (decision == 5) {
            Stats();
        }
    }
    cout << "Good Bye!" << endl;
}
// Creates a random zerg for each area
Entity *Game::RandomZerg() {
    int num = (rand() % 4) + 1;
    // 25% chance for each one happening, and return the zerg that is chosen
    if (num == 1) {
        cout << "It is peaceful here." << endl;
        return m_curZerg = nullptr;
    }
    else if (num == 2) {
        cout << "A small terrifying zergling waits here." << endl;
        return m_curZerg = new Zergling( "Zergling", ZERGLING_HEALTH);
    }
    else if (num == 3) {
        cout << "A large flying mutalisk hovers here." << endl;
        return m_curZerg = new Mutalisk( "Mutalisk", MUTALISK_HEALTH);
    }
    else if (num == 4) {
        cout << "A medium sized hydralisk slithers here waiting to cover you with acid." << endl;
        return m_curZerg = new Hydralisk( "Hydralisk", HYDRALISK_HEALTH);
    }
}

void Game::Rest() {
    // if there's no zerg, if area exist, and you have at least 1 rest than you can rest
    if (m_curZerg == nullptr && m_curArea != -1 && m_numRests > 0) {
        cout << "You rest and wake up refreshed" << endl;
        // use set than get than + the rest heal to plus 10 health
        m_myTerran->SetHealth(m_myTerran->GetHealth() + REST_HEAL);
        // reset number of special
        m_numSpecial = NUM_SPECIAL;
        m_numRests--;
    }
    // if statements if the case didn't work
    if (m_curZerg != nullptr) {
        cout << "You cannot rest with a zerg in the area" << endl;
    }

    if (m_curArea == -1) {
        cout << "this area doesn't exist" << endl;
    }

    if (m_numRests <= 0) {
        cout << "you don't have any rest to use" << endl;
    }
}

void Game::Move() {
    char direction = 0;
    // keeps asking the direction if currArea would equal -1 as that mean it doesn't exist
    while (m_myMap.at(m_curArea)->CheckDirection(direction) == -1) {
        cout << "Which direction? " << "(N E S W)" << endl;
        cin >> direction;
    }
   cout << direction << endl;
    // sets current area to the direction you are now going
   m_curArea = m_myMap.at(m_curArea)->CheckDirection(direction);
   m_myMap.at(m_curArea)->PrintArea();

}
// deals with your attacks and the computers attacks during a fight
void Game::Attack() {

    int damage = 0; // damage for player
    int zurgDamage = 0; // damage for computer
    bool player = true; // keeps track if player is aive
    bool enemy = true; // keeps track if computer is alive
    int attack = 0; // for player choosing attack
    int ranAttack = 0; // takes in the random number to decide if zerg does special attack
    // while both you and computer are alive keep while loop going
    while (m_myTerran->GetHealth() > 0 && m_curZerg->GetHealth() > 0) {
        while ((attack < 1 || attack > 2) && m_myTerran->GetHealth() > 0 && m_curZerg->GetHealth() > 0) {
            cout << "1. Normal Attack" << endl;
            cout << "2. Special Attack" << endl;
            cin >> attack;
        }
    }
        // if they do normal attack
        if (attack == 1) {
            // damage variable holds what is returned by attack
            damage = m_myTerran->Attack();
            cout << damage << endl;
            // decreasing the health of the computer
            m_curZerg->SetHealth(m_curZerg->GetHealth() - damage);
        }
        // if they do special attack
        else if (attack == 2) {
            // checks to see if you have a special attack to use
            if (m_numSpecial != 0) {
                // damage variable holds what is returned by special attack
                damage = m_myTerran->SpecialAttack();
                cout << damage << endl;
                m_curZerg->SetHealth(m_curZerg->GetHealth() - damage);
                m_numSpecial--;
            }
            else {
                cout << "you don't have special attack available" << endl;
            }
        }
        ranAttack = (rand() % 4) + 1;
        // zerg uses special attack if ranAttack equals 1, else it will do regular attack
        if (ranAttack == 1) {
            zurgDamage = m_curZerg->SpecialAttack();
        }
        else {
            zurgDamage = m_curZerg->Attack();
        }
        cout << zurgDamage << endl;
        m_myTerran->SetHealth(m_myTerran->GetHealth() - zurgDamage);
        // if both are still alive print out their health
        if (m_myTerran->GetHealth() > 0 && m_curZerg->GetHealth() > 0) {
            cout << m_myTerran->GetName() << "'s health:" << m_myTerran->GetHealth() << endl;
            cout << m_curZerg->GetName() << "'s health:" << m_curZerg->GetHealth() << endl;
        }

    // if either's health is 0 change to false aka they dead
    if (m_myTerran->GetHealth() <= 0) {
        player = false;
    }
    if (m_curZerg->GetHealth() <= 0) {
        enemy = false;
    }
    // put player and enemy into process battle
    ProcessBattle(enemy, player);
    // delete m_curZerg
    if (m_curZerg != nullptr) {
        delete m_curZerg;
        m_curZerg = nullptr;
    }
}
// prints out player stats
void Game::Stats() {
    cout << "Name: " << m_myTerran->GetName();
    cout << "HP: " << m_myTerran->GetHealth();
    cout << "Rests: " << m_numRests;
    cout << "Special: " << m_numSpecial;
    cout << "Wins: " << m_wins;

}
// this prints out who won the battle by checking their bool
void Game::ProcessBattle(bool zergAlive, bool alive) {
    int ranRest;
    if (zergAlive) {
        cout << m_curZerg->GetName() << " has defeated you." << endl;
    }
    // if you are alive you win and wins it incremented
    else if (alive) {
        cout << "You have defeated the " << m_curZerg->GetName() << "." << endl;
        m_wins++;
        // there's a 10% that you get an extra rest after you win
        ranRest = (rand() % 10) + 1;
        if (ranRest == 1) {
            m_numRests++;
            cout << "You have earned another rest action!" << endl;
        }
    }
    // if both die it prints out this
    if (!zergAlive && !alive){
        cout << "both were completely destroyed, so sad" << endl;
    }
}
