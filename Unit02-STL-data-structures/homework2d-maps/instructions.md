# Maps

## Instructions

For this assignment you will build a text-generation tool that you train on real data. In a very simplified way, this is fundamentally how large language models (LLMs) work. However, instead of using a neural net to model word relationships, you'll use a map.

There are two parts to this assignment:
1. Train and use a basic model (`basic_text_generation.cpp`)
2. Add a feature of your choosing to improve the tool (`improved_text_generation.cpp`; see options below)

### Part 1 - `basic_text_generation.cpp`

#### 1a - Training the model

To train the basic model, write a function that takes an `istream&` (e.g. `cin`, `ifstream`, or `istringstream`) and returns an `unordered_map<string, vector<string>>`.

Group every word by it's previous word. Use the empty string `""` for the first previous word. The pattern for tracking the previous word looks something like:

```c++
string prev = "";
string curr;
while (in >> curr) {
    // do something with curr and prev
    prev = curr;
}
```

The returned map should map each word found to all the words that came after it.

For example, for the sentence

> one fish two fish red fish blue fish

you would get a mapping like

```text
: one   // i.e. "" came before "one"
one: fish
fish: two, red, blue
two: fish
red: fish
blue: fish
```

#### 1b - Generating text

Using your model from step 1a, you can now generate text.

Write a function that takes your model, the first word, the number of words to emit, and an `ostream&` (e.g. `cout` or `ofstream`, etc.).

Use `""` (the empty string) as your first word.

The algorithm is as follows:
- Select the bucket of words that followed the previous word
- Randomly select a word from that bucket
- Print the word to the provided stream followed by a space
- Set the previous word to the current word
- Repeat until the specified number of words have been printed

#### 1c - Putting it together

Write a program that takes an input file and an integer representing how many words to generate.

Train the model on the input file. Then generate the specified number of words and print them to `cout`.

Put your implementation in `basic_text_generation.cpp`


### Part 2 - Improved Text Generation

Implement **at least one** of the following features:
  - accept the starting word from the commandline (instead of using `""` as the starting word)
  - train on an input file of your choosing
    - instead of using the provided text files, create your own. Be creative.
    - rename your file to have the suffix `".custom-input.txt"` (e.g. `"pres-nelson.custom-input.txt"`) and submit it with your code
  - train on multiple input files
    - read them all into the same map, then generate text from the aggregated model
    - try sources that are similar and sources that are dissimilar
  - group by prev 2 words
    - use `"", ""` as the "starting word"
  - group by prev N words
    - N can be defined in the code, or taken as an argument from the commandline
    - stretch goal: 
      - include previous N, N-1, N-2, etc. words as keys
      - if the previous N words isn't in the map, use N-1, etc.
  - treat punctuation (e.g. `.,!?`) as separate tokens
    - stretch goal:
      - handle spacing and capitalization appropriately

Put your improved text generation code in `improved_text_generation.cpp`.

Submit your code and a screenshot or output file demonstrating your elective feature(s) in action.


## Grading

Submit to Gradescope:
- `basic_text_generation.cpp`
- `improved_text_generation.cpp`
- a screenshot or file that demonstrates your improved tool in action
  - for example, you can run your program to generate new text and save that text in a new file
  - or you can take a screenshot of your terminal showing the program run and the text it generates
  - etc.
  - include as many files/images as necessary to demonstrate your program's features
- any additional files that go with your improved tool (such as custom input files, etc.)

### Points

| Autograder                                                                                            | Points |
| ----------------------------------------------------------------------------------------------------- | ------ |
| `basic_text_generation.cpp` compiles                                                                  | 10     |
| `improved_text_generation.cpp` compiles                                                               | 10     |
| The basic program outputs reasonable text (each word pair in the output must also exist in the input) | 40     |
| **Total for autograder**                                                                              | **60** |

| Manual                                                                                    | Points |
| ----------------------------------------------------------------------------------------- | ------ |
| Code quality                                                                              | 50     |
| It is clear from the code in `improved_text_generation.cpp` which feature you implemented | 10     |
| Screenshot of improved application in action looks reasonable                             | 30     |
| **Total manual grading**                                                                  | **90** |
