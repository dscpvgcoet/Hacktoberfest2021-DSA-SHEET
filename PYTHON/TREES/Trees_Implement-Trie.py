# as seen in Leetcode: Implement Trie
class TrieNode():
    def __init__(self):
        self.dict = {} # letter : TrieNode()...
        self.endOfWord = False
        
class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        
    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: None
        """
        cur = self.root
        for c in word:
            if c not in cur.dict:
                cur.dict[c] = TrieNode()
            cur = cur.dict[c]
        cur.endOfWord = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        cur = self.root
        for c in word:
            if c not in cur.dict:
                return False
            cur = cur.dict[c]
        return cur.endOfWord
            
    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        cur = self.root
        for c in prefix:
            if c not in cur.dict:
                return False
            cur = cur.dict[c]
        return True
# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
