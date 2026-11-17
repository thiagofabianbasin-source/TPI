
#include <iostream>
#include "rlutil.h"
using namespace std;

void marco() {
    // Horizontales
    for (int x = 30; x <= 100; x++) {
        rlutil::locate(x, 8);
        cout << "\xE2\x95\x90"; // Í

        rlutil::locate(x, 20);
        cout << "\xE2\x95\x90"; // Í
    }

    // Verticales
    for (int y = 9; y < 20; y++) {
        rlutil::locate(30, y);
        cout << "\xE2\x95\x91"; // º

        rlutil::locate(100, y);
        cout << "\xE2\x95\x91"; // º
    }

    // Esquinas
    rlutil::locate(30, 8);
    cout << "\xE2\x95\x94"; // É

    rlutil::locate(100, 8);
    cout << "\xE2\x95\x97"; // »

    rlutil::locate(30, 20);
    cout << "\xE2\x95\x9A"; // È

    rlutil::locate(100, 20);
    cout << "\xE2\x95\x9D"; // ¼
}


void marco2() {
    // Horizontales
    for (int x = 30; x <= 100; x++) {
        rlutil::locate(x, 8);
        cout << "\xE2\x95\x90"; // Í

        rlutil::locate(x, 30);
        cout << "\xE2\x95\x90"; // Í
    }

    // Verticales
    for (int y = 9; y < 30; y++) {
        rlutil::locate(30, y);
        cout << "\xE2\x95\x91"; // º

        rlutil::locate(100, y);
        cout << "\xE2\x95\x91"; // º
    }

    // Esquinas
    rlutil::locate(30, 8);
    cout << "\xE2\x95\x94"; // É

    rlutil::locate(100, 8);
    cout << "\xE2\x95\x97"; // »

    rlutil::locate(30, 30);
    cout << "\xE2\x95\x9A"; // È

    rlutil::locate(100, 30);
    cout << "\xE2\x95\x9D"; // ¼
}


void marco3() {
    // Horizontales
    for (int x = 40; x <= 100; x++) {
        rlutil::locate(x, 8);
        cout << "\xE2\x95\x90"; // Í

        rlutil::locate(x, 40);
        cout << "\xE2\x95\x90"; // Í
    }

    // Verticales
    for (int y = 9; y < 40; y++) {
        rlutil::locate(40, y);
        cout << "\xE2\x95\x91"; // º

        rlutil::locate(100, y);
        cout << "\xE2\x95\x91"; // º
    }

    // Esquinas
    rlutil::locate(40, 8);
    cout << "\xE2\x95\x94"; // É

    rlutil::locate(100, 8);
    cout << "\xE2\x95\x97"; // »

    rlutil::locate(40, 40);
    cout << "\xE2\x95\x9A"; // È

    rlutil::locate(100, 40);
    cout << "\xE2\x95\x9D"; // ¼
}
