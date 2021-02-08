#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> parseSentences(string text)
{
    vector<string> sentences;
    string nextSentence;
    for (int i = 0; i < text.size(); i++)
    {
        nextSentence.push_back(text[i]);
        if (text[i] == '.')
        {
            sentences.push_back(nextSentence);
            nextSentence = "";
            while (i + 1 < text.size() && text[i + 1] == ' ')
                i++;
        }
    }
    return sentences;
}

vector<string> search(vector<string> sentences, string word)
{
    vector<string> targetSentences;
    string wordUpperCase = word;
    for (auto &c : wordUpperCase)
        c = toupper(c);
    for (auto sentence : sentences)
    {
        char previous, next;
        string newSentence = "";
        bool flag = false;
        for (int i = 0; i < sentence.size() - word.size(); i++)
        {
            previous = (i == 0) ? ' ' : sentence[i - 1];
            next = (i + word.size() + 1 == sentence.size()) ? ' ' : sentence[i + word.size()];

            if (word == sentence.substr(i, word.size()) && previous == ' ' && (next == ' ' || next == '.'))
            {
                newSentence += wordUpperCase;
                i += word.size() - 1;
                flag = true;
            }
            else
            {
                newSentence += sentence[i];
            }
        }
        if (flag)
            targetSentences.push_back(newSentence + sentence.substr(newSentence.size()));
    }
    return targetSentences;
}

int main()
{
    fstream fin("in.txt");
    fstream fout("out.txt");
    string text;
    getline(fin, text);
    vector<string> s = parseSentences(text);
    for (auto l : s)
    {
        cout << l << endl;
    }
    int number;
    fin >> number;
    for (int i = 0; i < number; i++)
    {
        string targetWord;
        fin >> targetWord;
        vector<string> updatedSentences = search(s, targetWord);
        fout << updatedSentences.size() << endl;
        for (int j = 0; j < updatedSentences.size(); j++)
        {
            fout << updatedSentences[j] << " ";
        }
        fout<<endl;
    }

    return 0;
}
