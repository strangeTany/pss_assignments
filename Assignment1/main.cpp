#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Breaks the input text into sentences
 * 
 * @param text string containing text that should be divided into sentences. Sentences are separated by dots.
 * @return vector<string> containing all sentences in the original text separated into distinct strings
 */

vector<string> parseSentences(string text) {
    vector<string> sentences;
    string nextSentence;

    for (int i = 0; i < text.size(); i++) {
        nextSentence.push_back(text[i]);
        if (text[i] == '.') {
            sentences.push_back(nextSentence);
            nextSentence = "";
            while (i + 1 < text.size() && text[i + 1] == ' ')  //inore all spaces after a dot
                i++;
        }
    }

    return sentences;
}

/**
 * @brief Search the word and highlight it
 * 
 * @param sentences Sentences where word should be searched
 * @param word Word for search
 * @return vector<string> All sentences containing requested word. The searched word became uppercase 
 */

vector<string> search(vector<string> sentences, string word) {
    vector<string> targetSentences;
    string wordUpperCase = word;

    for (auto &c : wordUpperCase)  //converting original word to uppercase
        c = toupper(c);

    for (auto sentence : sentences) {
        char previous, next;
        string newSentence = "";
        bool containsWord = false;  //indicator that searched word is contained in current sentence
        for (int i = 0; i < sentence.size() - word.size(); i++) {
            previous = (i == 0) ? ' ' : sentence[i - 1];
            next = (i + word.size() + 1 == sentence.size()) ? ' ' : sentence[i + word.size()];

            if (word == sentence.substr(i, word.size()) && previous == ' ' && (next == ' ' || next == '.')) {  //check if substring is equal to terget word, and check if this substring is a word
                newSentence += wordUpperCase;
                i += word.size() - 1;
                containsWord = true;
            } else {
                newSentence += sentence[i];
            }
        }
        if (containsWord)
            targetSentences.push_back(newSentence + sentence.substr(newSentence.size()));
    }
    return targetSentences;
}

int main() {
    fstream fin("in.txt");
    fstream fout("out.txt");
    string text;
    getline(fin, text);
    vector<string> separatedSentences = parseSentences(text);
    int number;
    fin >> number;

    for (int i = 0; i < number; i++) {
        string targetWord;
        fin >> targetWord;
        vector<string> updatedSentences = search(separatedSentences, targetWord);
        fout << updatedSentences.size() << endl;
        for (int j = 0; j < updatedSentences.size(); j++) {
            fout << updatedSentences[j] << endl;
        }
    }

    return 0;
}
