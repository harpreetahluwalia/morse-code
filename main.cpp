#include <iostream>
#include <cassert>
#include <vector>
#include<fstream>
using namespace std;
#include "tree.h"

int main() {
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


    cout<<"Enter Message : ";
    string input;
    getline(cin, input);

    tree.to_Morse(tree.getRootNode(),input);
    tree.printMorse();
    tree.decodeMorse(tree.getRootNode());

	return 0;
}
