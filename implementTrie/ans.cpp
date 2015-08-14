/**
 * @file ans.cpp
 * @brief
 * Implement a trie with insert, search, and startsWith methods.
 *
 * @version
 * @date 2015-08-14 15:38
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <cstddef>
#include <string>

using namespace std;

class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    // Initialize your data structure here.
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
private:
    void destroy(TrieNode* root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
                destroy(root->children[i]);
        }
        delete root;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        destroy(root);
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (p->children[word[i]-'a'] == NULL)
            {
                TrieNode* node = new TrieNode();
                p->children[word[i]-'a'] = node;
            }
            p = p->children[word[i]-'a'];
        }
        p->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (p->children[word[i]-'a'] == NULL)
                return false;

            p = p->children[word[i]-'a'];
        }

        return p->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
                TrieNode* p = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (p->children[prefix[i]-'a'] == NULL)
                return false;

            p = p->children[prefix[i]-'a'];
        }

        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

