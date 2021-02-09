
# Sentence parser and word search

The program gets text as an input and divides it into sentences. Then it searches for sentences that contain words from input and highlights them.</n>
<em>Remark:</em> The program is not sensitive to a case e.g ```drop``` is not equal to ```dRoP```

## Requirements

<b>Version of the language:</b> C++11 </n>
<b>Input:</b> file ```in.txt``` must be in the same folder as ```main.cpp```</n>
<b>Output:</b> file ```out.txt``` must be in the same folder as ```main.cpp```</n>

## Input

In the file ```in.txt``` in the first line should be a text. Sentences in the text must be separated by dots. The second line contains single number (the number of searched words). All following lines contain words (one word in each line).

#### Example:

```
Lorem Ipsum is simply a dummy text of the printing  and  type setting  industry.   LoremIpsum  has  been  the  industry’s  standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.  It was popularized in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing  software  like  Aldus  PageMaker  including versions of Lorem Ipsum.
2
dummy
release
```

## Output

In the file ```out.txt``` for each searched word there are

* Number of sentences containing the word
* Sentences with searched word in uppercase. Each sentence is in a separate line
  
#### Example:

```
2
Lorem Ipsum is simply a DUMMY text of the printing  and  type setting  industry.
LoremIpsum  has  been  the  industry’s  standard DUMMY text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.
1
It was popularized in the 1960s with the RELEASE of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing  software  like  Aldus  PageMaker  including versions of Lorem Ipsum.
 ```
 
