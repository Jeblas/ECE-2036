#include "histogram.h"

// Functions for WordUnit class
WordUnit::WordUnit()
{
    frequency = 0;
    word = "";
}

WordUnit::WordUnit(std::string inWord)
{
    frequency = 1;
    word = inWord;
}

int WordUnit::getFrequency()
{
    return frequency;
}

void WordUnit::incFrequency()
{
    ++frequency;
}

std::string WordUnit::getWord()
{
    return word;
}


// Functions for WordHistogram class
//using namespace WordHistogram;
WordHistogram::WordHistogram(std::string filename)
{
    ///const int MAX_SIZE = 10000;
    size = 0;
    inputFilename = filename;
    //histogram = new WordUnit[MAX_SIZE];
}


int WordHistogram::getSize()
{
    return size;
}

void WordHistogram::exportHistogram(std::string filename)
{
    std::ofstream outFile(filename, std::ios::out);

    for(int i = 0; i < size; i++)
    {
        outFile << histogram[i].getWord() << " " << histogram[i].getFrequency() << std::endl;
    
    }

    outFile.close();

}

void WordHistogram::sortFreqHistogram()
{
    WordUnit temp;
    for(int i = 0; i < size; ++i)
    {
        temp = histogram[i];
        int j = i - 1;
        while(j >= 0 && histogram[j].getFrequency() < temp.getFrequency())
        {
            histogram[j+1] = histogram[j];
            --j;
        }
        histogram[j+1] = temp;
    }
}

void WordHistogram::sortAlphaHistogram()
{
    WordUnit temp;
    for(int i = 0; i < size; ++i)
    {
        temp = histogram[i];
        int j = i - 1;
        while(j >=0 && histogram[j].getWord() > temp.getWord())
        {
            histogram[j+1] = histogram[j];
            --j;
        }
        histogram[j+1] = temp;
    }

}


void WordHistogram::makeHistogram()
{
    bool wordExists;
    std::ifstream inFile(inputFilename, std::ios::in);
    std::string word;
    // loop through each word
    while(inFile >> word)
    {
        wordExists = false;
        for(int i = 0; i < size; ++i)
        {
            if(word == histogram[i].getWord() )
            {
                histogram[i].incFrequency();
                wordExists = true;
                break;
            }
        }

        if (!wordExists)
        {
            histogram[size] = WordUnit(word);
            ++size;
        }
    }

    inFile.close();
}

