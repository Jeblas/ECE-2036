#include <iostream>
#include <fstream>
#include <string>

class WordUnit
{
    public:
        WordUnit();
        WordUnit(std::string inWord);
        int getFrequency();
        void incFrequency();
        std::string getWord();

    private:
        std::string word;
        int frequency;
};

class WordHistogram
{
    public:
        WordHistogram(std::string filename);
        int getSize();
        void exportHistogram(std::string filename);
        void sortFreqHistogram();
        void sortAlphaHistogram();
        void makeHistogram();

    private:
        WordUnit histogram[10000];
        std::string inputFilename;
        int size;
};
