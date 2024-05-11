#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main(void) {
    std::vector<std::string> inputs;
    std::string temp;
    while (true) {
        std::getline(std::cin, temp);
        if (temp == "!") {
            break;
        }
        else {
            if (temp.size() > 1) {
                inputs.push_back(temp);
            }
        }
    }
    struct Occurrence {
        std::string bigram[2];
        unsigned int count;
    };

    std::vector<Occurrence> occurrences;
    for (unsigned int i = 0; i < inputs.size(); i++) {
        for (unsigned int j = 0; j < inputs[i].size() - 1; j++) {
            bool found = false;
            for (unsigned int k = 0; k < occurrences.size(); k++) {
                if (occurrences[k].bigram[0] == inputs[i].substr(j, 1) &&
                    occurrences[k].bigram[1] == inputs[i].substr(j + 1, 1)
                    ) {
                    occurrences[k].count++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                Occurrence temp;
                temp.bigram[0] = inputs[i].substr(j, 1);
                temp.bigram[1] = inputs[i].substr(j + 1, 1);
                temp.count = 1;
                occurrences.push_back(temp);
            }
        }
    }
    Occurrence mostCommon, currentBigram;
    for (unsigned int i = 0; i < occurrences.size(); i++) {
        if (i == 0) {
            mostCommon = occurrences[i];
        }
        else {
            currentBigram = occurrences[i];
            if (currentBigram.count > mostCommon.count) {
                mostCommon = currentBigram;
            }
        }
    }
    std::sort(inputs.begin(), inputs.end());
    for (unsigned int i = 0; i < inputs.size(); i++) {
        if (inputs[i].find(mostCommon.bigram[0] + mostCommon.bigram[1]) != std::string::npos) {
            std::cout << inputs[i] << std::endl;
        }
    }
    return 0;
}
