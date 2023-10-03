#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *link[26];
    bool flag = false;

    bool isContain(char ch)
    {
        return link[ch - 'a'] != NULL;
    }

    void putWord(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }

    Node *getNext(char ch)
    {
        return link[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

    void setEndToTrue()
    {
        flag = false;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->isContain(word[i]))
            {
                node->putWord(word[i], new Node());
            }
            node = node->getNext(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->isContain(word[i]))
                return false;
            node = node->getNext(word[i]);
        }
        return node->isEnd();
    }

    bool findPrefix(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->isContain(word[i]))
                return false;
            node = node->getNext(word[i]);
        }

        return true;
    }

    void deleteWord(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->isContain(word[i]))
                cout << "Can't delete becase Word is Not Present";
            node = node->getNext(word[i]);
        }
        node->setEndToTrue();
        cout<<"Given Word is succesfully deleted\n";
    }
};

int main()
{

    Trie t1;
    t1.insert("Aditya");
    cout << t1.search("Aditya")<<"\n";
    cout << t1.findPrefix("da")<<"\n";
    t1.deleteWord("Aditya");
    cout << t1.search("Aditya")<<"\n";
    return 0;
}