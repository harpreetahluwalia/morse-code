/**
 *  @file   tree.cpp
 *  @author Harpreet Singh
 *  @brief  It includes implementation of tree class and deals with inserting node, encoding and decoding message.
 *  @date   23/11/2021
 ***********************************************/



// Including header files
#include "tree.h"

// Including supporting libraries
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


/**
 * Method : printMorse()
 * @author Harpreet Singh
 * @date 23-11-2021
 * @brief It prints the encoded morse code to the console.
 * @param none
*/
void Tree:: printMorse(){

    for (int i = 0; i<morseCode.size(); i++){
        cout<<morseCode[i]<<" ";
    }
}


/**
 * Method : decodeMorse()
 * @author Harpreet Singh
 * @date 23-11-2021
 * @brief It prints the encoded morse code to the console.
 * @param none
*/
void Tree::decodeMorse(struct treeNode *node){
    if (node != NULL){

    for (int k= 0; k<morseCode.size();k++){
        string mCode;
        treeNode* tempNode = node;      // creating temporary node
        mCode = morseCode[k];
        if (mCode == "/"){          // if space is encountered
            cout<<" ";
            continue;
        }

        for(int i = 0; i < mCode.size(); i++)
            {
                if (mCode[i] == '.')            // If there is dot . in code, it will check for left node and move left.
                {
                    if (tempNode->left != NULL)
                    tempNode = tempNode->left;
                else
                {
                    break;
                }
            }
        else
        {

            if (tempNode->right != NULL)        // If there is dash - in code, it will check for right node and move right.
                tempNode = tempNode->right;
            else
                {
                break;
                }
            }
        }
    cout<<tempNode->alphabet;           // Printing the alphabet
    }

}

}


void Tree::to_Morse(struct treeNode *node,string line){
    for (int i=0; i<line.length(); i++){
        encode(node,string(1, tolower(line[i])));       // calling the encode function
        }
}


void Tree::encode(struct treeNode *root, string alphabet){

    if (root != NULL){              // if root node is null
        if (alphabet == " "){               // If space is encountered
            morseCode.push_back("/");
        }else{                                      // traversing the tree
            if (root->alphabet == alphabet){
                string s = root->morse_code;
                morseCode.push_back(s);
            }
            encode(root->left,alphabet);
            encode(root->right,alphabet);
        }
    }
}

void Tree::addToTree(treeNode *&tempNode, string alphabet, string morse_code)
{
    if(tempNode == NULL)            // if passed node is null, add new node.
    {
        tempNode = new treeNode;
        tempNode->alphabet = alphabet;
        tempNode->morse_code = morse_code;
        tempNode->left = tempNode->right = NULL;            // setting child nodes of new node Null.
    }
}

void Tree::addToTree(string alphabet, string morse_code)
{
    treeNode **tempNode = &root;            // creating treeNode pointer and refering root node
    if(*tempNode != NULL)
    {
        for(int i = 0; i < morse_code.length(); i++)
        {
            if(morse_code[i] == '.') {                      // If there is dot ., it will move to left node and store
                tempNode = &((*tempNode)->left);
            }

            else if(morse_code[i] == '-'){                  // If there is dash -, it will move to right node and store
                    tempNode = &((*tempNode)->right);
            }
            else
                break;
        }
        addToTree(*tempNode, alphabet, morse_code);         // recursively calls the addToTree function
    }
    else {
            addToTree(root, alphabet, morse_code);
    }
}

