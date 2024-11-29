struct trie {
    trie* content[75] {};
    vector<string> files;
};
class Solution {
    trie root;
    void dfs(vector<vector<string>>& res, trie* node) {
        if(node->files.size() >= 2) {
            res.push_back(node->files);
        }
        for(int i = 0; i < 75; ++i) {
            if(node->content[i] != nullptr) dfs(res, node->content[i]);
        }
    }
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        for(auto& files : paths) {
            int i = 0, n = files.length();
            while(files[i] != ' ') ++i;
            string dir(files.substr(0, i++));

            while(i < n) {
                int j = i;
                while(files[i] != '(') ++i;
                string filename(files.substr(j, i++ - j));
                
                trie* node = &root;
                while(files[i] != ')') {
                    char c = files[i++] - '0';
                    if(node->content[c] == nullptr) {
                        node->content[c] = new trie;
                    }
                    node = node->content[c];
                }
                node->files.push_back(dir + '/' + filename);
                i += 2;
            }   
        }
        vector<vector<string>> res;
        dfs(res, &root); //Collect the duplicates using dfs
        return res;
    }
};