//TRIES APPROACH 
class Solution {
    struct Trie
    {
      std::vector<std::vector<int>> trie;
      std::vector<int> index;
      
      Trie()
      {
        trie.push_back(std::vector<int>(26));
        index.push_back(-1);
      }
      
      void insert(const std::string& str, int idx)
      {
        int node = 0;
        for(char c: str)
        {
          if(trie[node][c-'a']==0)
          {
            trie[node][c-'a'] = trie.size();
            trie.push_back(std::vector<int>(26));
            index.push_back(-1);
          }
          node = trie[node][c-'a'];
        }
        index[node] = idx;
      }
      
      bool is_palindrome(const std::string& str, int lo, int hi)
      {
        while(lo<hi)
        {
          if(str[lo]!=str[hi])
            return false;
          ++lo;
          --hi;
        }
        return true;
      }
      
      void dfs(int node, std::vector<int>& result, std::string& current)
      {
        if(index[node]!=-1 && is_palindrome(current, 0, int(current.size())-1))
        {
          result.push_back(index[node]);
        }
        
        for(int i=0; i < trie[node].size(); ++i)
        {
          if(trie[node][i]!=0)
          {
            current.push_back('a'+i);
            dfs(trie[node][i], result, current);
            current.pop_back();
          }
        }
      }
      
      std::vector<int> find_all(const std::string& str)
      {
        std::vector<int> result;
        
        int node = 0;
        for(int i=0; i < str.size(); ++i)
        {
          // assume str is "ab" and we found "a" so far
          // then check if the rest of str("b") is palindrome
          if(index[node]!=-1 && is_palindrome(str, i, int(str.size())-1))
          {
            result.push_back(index[node]);
          }
          
          char c = str[i];
          if(trie[node][c-'a']==0)
            return result;
          
          node = trie[node][c-'a'];
        }
        
        // we fully matched str in trie. now search this node recursively to find palindromes underneath
        // ab ...... ba => any palindrome in between will result palindrome in overall
        std::string current;
        dfs(node, result, current);
        return result;
      }
    };
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {

      Trie reverse;
      for(int i=0; i < words.size(); ++i)
      {
        auto word = words[i];
        std::reverse(word.begin(), word.end());
        reverse.insert(word, i);
      }
      
      std::vector<std::vector<int>> result;
      for(int i=0; i < words.size(); ++i)
      { 
        auto indexes = reverse.find_all(words[i]);
        for(int index: indexes)
        {
          if(index!=i)
          {
            result.push_back({i, index});
          }
        }
      }
      return result;
    }
};