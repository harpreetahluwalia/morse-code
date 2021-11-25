/**
 *  @file   main.cpp
 *  @brief  It is the main program file. It drives the whole application and interacts with the user inputs.
 *  @author Harpreet Singh
 *  @date   23/11/2021
 ***********************************************/

/**
 @mainpage Morse Code Encode/Decode
 @author Harpreet Singh
 @date   23/11/2021


This program implements a morse code encoder/decoder in the C++. In this, user provides a string input and it converts the user
input to the equivalent morse code and prints the code. It also decode the same morse code to its respective alphabets and prints the
decoded message as well.

*/



// Including supporting libraries
#include <iostream>
#include<fstream>
#include<conio.h>
using namespace std;


// Including header file
#include "tree.h"

int main() {

    cout<<"\n******************** Assignment 5 *************************\n";
    Tree tree;          // Creating class Tree object
    ifstream morseFile("morsecode.txt");
    string morse_code;
    string alphabet;
    string line;
    int pos = 1;
    tree.addToTree("ROOT", "");     // Inserting empty root node to tree

    while(getline(morseFile, line)){        // Reading file
        string morse_code = line.substr(pos+1);
        string alphabet = string(1,line[0]);
        tree.addToTree(alphabet, morse_code);       // Inserting nodes to tree
    }


    cout<<"\nEnter Message : ";
    string input;
    getline(cin, input);
    tree.to_Morse(tree.getRootNode(),input);        // Encoding user input message to Morse code

    cout<<"\nEncoded Message : ";
    tree.printMorse();
    cout<<"\n\nDecoded Message : ";
    tree.decodeMorse(tree.getRootNode());           // Decoding morse code to its respective alphabets

    cout<<"\n\nPress any key to exit.";
    getch();
	return 0;
}
