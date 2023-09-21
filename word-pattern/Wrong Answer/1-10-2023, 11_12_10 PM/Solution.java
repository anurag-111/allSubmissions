// https://leetcode.com/problems/word-pattern

class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");

        //pattern's character gets mapped with word
        HashMap<Character, String> map = new HashMap<>();
        //usage of the word
        HashMap<String, Boolean> used = new HashMap<>();

        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern.charAt(i);

            if (map.containsKey(ch) == false) {             // is the character mapped or not
                if (used.containsKey(words[i]) == true) {   // if the word to be mapped is already present
                    return false;
                } else {
                    used.put(words[i], true);               // now the word will be mapped to the character
                    map.put(ch, words[i]);
                }
            } else {
                String mapped_with = map.get(ch);           // if the character is present then find out what it is mapped with
                if(mapped_with.equals(words[i]) == false) { // if the character is mapped with some other word
                    return false;
                }
            }
        }
        return true;
    }
}