#ifndef WORDS_MEANINGS_H
#define WORDS_MEANINGS_H
#include"Node.h"

class WordsMeanings
{
    public:
            WordsMeanings();
            virtual void addNewToList(string,string);
            virtual void saveInFile();
            virtual void loadDataFromFile();
            virtual string findData(string);
            virtual bool alreadyExist(string);
            virtual void releaseMemory();

    protected:
            Node* start;
};
#endif // WORDS_MEANINGS_H
