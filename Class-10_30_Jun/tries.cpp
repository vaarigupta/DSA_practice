#include<iostream>
using namespace std;

class node
{
    public:
    char data;
    unordered_map<char, node*> m;
    bool isTerminal;

    node(char d)
    {
        data a=d;
        isTerminal = false;
    }



};
class Trie
{
    node * root;
public:
    Trie()
    {
        root = new node('\0');
    }

    void addWord(char word[])
    {        node * temp = root;

        for(int i=0;word[i]!='\0';i++)
        {
            char ch = word[i];
        }
    }
};
int main()
{

}
