#ifndef SINGULAR_PLURAL_H
#define SINGULAR_PLURAL_H
#include"WordsMeanings.h"

class SingularPlural : public WordsMeanings
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

