#include "Area.h"
// Sets all the variables in the constructor
Area::Area(int ID, string name, string desc, int N, int E, int S, int W) {
    m_ID = ID;
    m_name = name;
    m_desc = desc;

    m_direction[0] = N;
    m_direction[1] = E;
    m_direction[2] = S;
    m_direction[3] = W;
}
// Getters for name, id, and desc
string Area::GetName() {
    return m_name;
}

int Area::GetID() {
    return m_ID;
}
string Area::GetDesc() {
    return m_desc;
}
// it takes in user input and checks if it's a valid direction, returns -1 if it isn't
int Area::CheckDirection(char myDirection) {
    if (myDirection != 'n' && myDirection != 'e' && myDirection != 's' && myDirection != 'w') {
        return -1;
    } else {
        direction actual;
        if (myDirection == 'n')
            actual = n;
        else if (myDirection == 'e') {
            actual = e;
        }
        else if (myDirection == 's') {
            actual = s;
        }
        else if (myDirection == 'w') {
            actual = w;
        }
        return m_direction[actual];
    }
}
    /*if ((myDirection == 'N') || (myDirection == 'n')) {
        return myDirection;
    }
    else if ((myDirection == 'E') || (myDirection == 'e')) {
        return myDirection;
    }
    else if ((myDirection == 'S') || (myDirection == 's')) {
        return myDirection;
    }
    else if ((myDirection == 'W') || (myDirection == 'w')) {
        return myDirection;
    }
    else{
        return -1;
    }*/

// prints the area the player is at like the the name and description than possible exits
void Area::PrintArea() {
    cout << "\n" << GetName() << endl;
    cout << GetDesc() << endl;
    if (m_direction[0] != -1) {
        cout << "Possible Exits: " << 'N' << endl;
    }
    else if (m_direction[1] != -1) {
        cout << "Possible Exits: " << 'E' << endl;
    }
    else if (m_direction[2] != -1) {
        cout << "Possible Exits: " << 'S' << endl;
    }
    else if (m_direction[3] != -1) {
        cout << "Possible Exits: " << 'W' << endl;
    }
}
