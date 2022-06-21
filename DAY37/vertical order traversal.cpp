class Solution {
public:
    map<int, map<int, multiset<int>>> m;
void dfs(TreeNode* r, int x, int y) {
  if (r != nullptr) {
    m[x][y].insert(r->val);
    dfs(r->left, x - 1, y + 1);
    dfs(r->right, x + 1, y + 1);
  }
}
vector<vector<int>> verticalTraversal(TreeNode* r, vector<vector<int>> res = {}) {
  dfs(r, 0, 0);
  for (auto itx = m.begin(); itx != m.end(); ++itx) {
      res.push_back(vector<int>());
      for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity) {
          res.back().insert(end(res.back()), begin(ity->second), end(ity->second));
      }
  }
  return res;
    }

};