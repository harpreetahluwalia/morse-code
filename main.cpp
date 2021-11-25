#include <iostream>
#include <cassert>
#include <vector>
#include<fstream>
#include<conio.h>
using namespace std;
#include "tree.h"

int main() {

    cout<<"\n******************** Assignment 5 *************************\n";
    Tree tree;
    ifstream morseFile("morsecode.txt");
    string morse_code;
    string alphabet;
    string line;
    int pos = 1;
    tree.addToTree("ROOT", "");

    while(getline(morseFile, line)){
        string morse_code = line.substr(pos+1);
        string alphabet = string(1,line[0]);
        tree.addToTree(alphabet, morse_code);
    }


    cout<<"\nEnter Message : ";
    string input;
    getline(cin, input);
    tree.to_Morse(tree.getRootNode(),input);

    cout<<"\nEncoded Message : ";
    tree.printMorse();
    cout<<"\n\nDecoded Message : ";
    tree.decodeMorse(tree.getRootNode());

    cout<<"\n\nPress any key to exit.";
    getch();
	return 0;
}
