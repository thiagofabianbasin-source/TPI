#include <iostream>
#include "rlutil.h"
 using namespace std;
 void marco(){
 // marco
    //horizontales
    for (int x=30; x<=100; x++) {
        rlutil::locate(x,8);
        cout << (char)205;

        rlutil::locate(x,20);
        cout << (char)205;
    }
    //vericales
    for (int y=9; y<20; y++) {
        rlutil::locate(30,y);
        cout << (char)186;

        rlutil::locate(100,y);
        cout << (char)186;
    }

    // escquinas
    rlutil::locate(30,8);
    cout << (char)201;

    rlutil::locate(100,8);
    cout << (char)187;

    rlutil::locate(30,20);
    cout << (char)200;

    rlutil::locate(100,20);
    cout << (char)188;

 }

 void marco2(){
    // marco
    //horizontales
    for (int x=30; x<=100; x++) {
        rlutil::locate(x,8);
        cout << (char)205;

        rlutil::locate(x,30);
        cout << (char)205;
    }
    //vericales
    for (int y=9; y<30; y++) {
        rlutil::locate(30,y);
        cout << (char)186;

        rlutil::locate(100,y);
        cout << (char)186;
    }

    // escquinas
    rlutil::locate(30,8);
    cout << (char)201;

    rlutil::locate(100,8);
    cout << (char)187;

    rlutil::locate(30,30);
    cout << (char)200;

    rlutil::locate(100,30);
    cout << (char)188;
 }
 void marco3(){
    // marco
    //horizontales
    for (int x=40; x<=100; x++) {
        rlutil::locate(x,8);
        cout << (char)205;

        rlutil::locate(x,40);
        cout << (char)205;
    }
    //vericales
    for (int y=9; y<40; y++) {
        rlutil::locate(40,y);
        cout << (char)186;

        rlutil::locate(100,y);
        cout << (char)186;
    }

    // escquinas
    rlutil::locate(30,8);
    cout << (char)201;

    rlutil::locate(100,8);
    cout << (char)187;

    rlutil::locate(30,40);
    cout << (char)200;

    rlutil::locate(100,40);
    cout << (char)188;
 }
