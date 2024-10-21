class Solution {
public:
    // Helper function to split the string s into words
    vector<string> words(string s){
        vector<string> m;
        s = s + " ";  // Add space at the end to capture the last word
        int l = s.length();
        int left = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == ' '){
                string p = s.substr(left, i-left);  // Extract word
                left = i + 1;
                m.push_back(p);
            }
        }
        return m;
    }
    
    bool wordPattern(string pattern, string s) {
        vector<string> m = words(s);  // Get the list of words from string s
        
        // If pattern length and number of words don't match, return false
        if (m.size() != pattern.length()) return false;
        
        map<string, char> wordToChar;  // To map words to characters
        map<char, string> charToWord;  // To map characters to words
        
        int n = m.size();  // Number of words
        
        for(int i = 0; i < n; i++){
            string word = m[i];
            char c = pattern[i];
            
            // Check if the word is already mapped to a different character
            if (wordToChar.find(word) != wordToChar.end()) {
                if (wordToChar[word] != c) return false;
            } else {
                wordToChar[word] = c;  // Assign the word to character
            }
            
            // Check if the character is already mapped to a different word
            if (charToWord.find(c) != charToWord.end()) {
                if (charToWord[c] != word) return false;
            } else {
                charToWord[c] = word;  // Assign the character to word
            }
        }
        
        return true;  // If all checks passed, the pattern matches the string
    }
};
