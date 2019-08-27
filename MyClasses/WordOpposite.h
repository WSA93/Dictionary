#ifndef WORD_OPPOSITE_H
#define WORD_OPPOSITE_H
#include"WordsMeanings.h"

class WordOpposite : public WordsMeanings
{
    public:
            void addNewToList(string,string);
            void saveInFile();
            void loadDataFromFile();
            string findData(string);
            bool alreadyExist(string);
            void releaseMemory();
};
#endif


