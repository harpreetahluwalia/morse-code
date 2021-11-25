#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED


class Tree{

    private:
            struct treeNode
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

             struct treeNode* getRootNode(){
                return root;
            };


            void printMorse();

            void decodeMorse(struct treeNode *node);

            void to_Morse(struct treeNode *node,string line);

            void encode(struct treeNode *root, string alphabet);

            void addToTree(treeNode *&tempNode, string alphabet, string morse_code);

            void addToTree(string alphabet, string morse_code);

};


#endif // TREE_H_INCLUDED
