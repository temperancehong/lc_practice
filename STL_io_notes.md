# C++ STL notes

## `map` and `unordered_map`


# IO notes

## Strings
### Cut a sentence into words and save in vector

That is to say separate the sentence according to the spaces.
```c++
    // put the sentence into words
    // create an input stream
    std::istringstream iss(s);
    // Create a vector to store the words
    std::vector<std::string> words;
    // Tokenize the string and store the words in the vector
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
```