#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#include "tree.h"


void Tree:: printMorse(){
    cout<<"\nCoded Message : ";
    for (int i = 0; i<morseCode.size(); i++){
        cout<<morseCode[i]<<" ";
    }
}



void Tree::decodeMorse(struct treeNode *node){
    cout<<"\nDecoded Message : ";
    if (node != NULL){

    for (int k= 0; k<morseCode.size();k++){
        string mCode;
        treeNode* tempNode = node;
        mCode = morseCode[k];
        if (mCode == "/"){
            cout<<" ";
            continue;
        }

        for(int i = 0; i < mCode.size(); i++)
            {
                if (mCode[i] == '.')
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

            if (tempNode->right != NULL)
                tempNode = tempNode->right;
            else
                {
                break;
                }
            }
        }
    cout<<tempNode->alphabet;
    }

}

}


void Tree::to_Morse(struct treeNode *node,string line){
    for (int i=0; i<line.length(); i++){
        encode(node,string(1, tolower(line[i])));
        }
}


void Tree::encode(struct treeNode *root, string alphabet){

    if (root != NULL){
        if (alphabet == " "){
            morseCode.push_back("/");
        }else{
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
    if(tempNode == NULL)
    {
        tempNode = new treeNode;
        tempNode->alphabet = alphabet;
        tempNode->morse_code = morse_code;
        tempNode->left = tempNode->right = NULL;
    }
}

void Tree::addToTree(string alphabet, string morse_code)
{
    treeNode **tempNode = &root;
    if(*tempNode != NULL)
    {  //     std::string::size_type i = 0; i < morse_code.length(); i++)
        for(int i = 0; i < morse_code.length(); i++)
        {
            //assert(*tempNode);
            if(morse_code[i] == '.') {
                tempNode = &((*tempNode)->left);
            }

            else if(morse_code[i] == '-'){
                    tempNode = &((*tempNode)->right);
            }
            else
                break;
        }
        addToTree(*tempNode, alphabet, morse_code);
    }
    else {
            addToTree(root, alphabet, morse_code);
    }
}

