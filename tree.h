/**
 *  @file   tree.h
 *  @author Harpreet Singh
 *  @brief  It includes declaration of tree class and deals with inserting node, encoding and decoding message.
 *  @date   23/11/2021
 ***********************************************/

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

// Including supporting libraries
#include <iostream>
#include <vector>

using namespace std;

/**
 *  @class  Tree
 *  @author Harpreet Singh
 *  @brief  It includes various Tree functions such as add node to tree, encode, decode etc along with member variables.
 *  @date   23/11/2021
 *  @file   tree.h
 ***********************************************/

class Tree{

    private:
            struct treeNode         // Defining structure treeNode
            {
                string alphabet;
                string morse_code;
                treeNode *left;
                treeNode *right;
            };
           treeNode *root;
           vector <string> morseCode;

    public:
            Tree(){root = NULL;}

            /**
            *
            * Method : printMorse()
            * @author Harpreet Singh
            * @date 23-11-2021
            * @brief It prints the encoded morse code to the console.
            * @param none
            **/

             struct treeNode* getRootNode(){
                return root;
            };

            /**
            *
            * Method : printMorse()
            * @author Harpreet Singh
            * @date 23-11-2021
            * @brief It prints the encoded morse code to the console.
            * @param none
            **/

            void printMorse();


            /**
             * Method : decodeMorse()
             * @author Harpreet Singh
             * @date 23-11-2021
             * @brief It prints the encoded morse code to the console.
             * @param none
            */
            void decodeMorse(struct treeNode *node);

            /**
             * Method : to_Morse()
             * @author Harpreet Singh
             * @date 23-11-2021
             * @brief It encodes the string message to morse code.
             * @param node It is a node of structure treeNode
             * @param line It is string representing user input that needs to be converted to morse code.
            */
            void to_Morse(struct treeNode *node,string line);

            /**
             * Method : encode()
             * @author Harpreet Singh
             * @date 23-11-2021
             * @brief It encodes the alphabets to their respective morse code.
             * @param node It is a node of structure treeNode
             * @param alphabet It represents an alphabet which needs to be converted to its respective morse code.
            */
            void encode(struct treeNode *root, string alphabet);


            /**
             * Method : addToTree()
             * @author Harpreet Singh
             * @date 23-11-2021
             * @brief It inserts the node to the tree based on the node passed
             * @param node It is a node of structure treeNode
             * @param alphabet It represents an alphabet which needs to be converted to its respective morse code.
             * @param morse_code string holds morse code for its respective alphabet
            */
            void addToTree(treeNode *&tempNode, string alphabet, string morse_code);

            /**
             * Method : addToTree()
             * @author Harpreet Singh
             * @date 23-11-2021
             * @brief It is overloaded addToTree function which inserts alphabet and morse code to tree.
             * @param alphabet It represents an alphabet which needs to be converted to its respective morse code.
             * @param morse_code string holds morse code for its respective alphabet
            */
            void addToTree(string alphabet, string morse_code);

};

#endif // TREE_H_INCLUDED
