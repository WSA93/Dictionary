#include"WordOpposite.h"

void WordOpposite::addNewToList(string d1,string d2)
{
    WordsMeanings::addNewToList(d1,d2);
}

void WordOpposite::loadDataFromFile()
{
  string read1 = "";
  string read2 = "";

  ifstream load;
  load.open("WordsOpposites.txt");
  if(!load)
  {

  }
  else
  {
    while(load >> read1)
    {
        load.ignore(4);
        getline(load,read2);

        if(start == NULL)                    /// Making first node.
        {
           Node* newNode = new Node;
           newNode->data1 = read1;
           newNode->data2 = read2;

           newNode->next = start;
           start = newNode;
        }
        else
        {                                   /// After first node every node will be inserted in the end.
           Node* newNode = new Node;
           newNode->data1 = read1;
           newNode->data2 = read2;

           Node* triverse = start;
           while(triverse->next != NULL)
           {
               triverse = triverse->next;
           }
           newNode->next = NULL;
           triverse->next = newNode;
        }
    }

  }

}

void WordOpposite::saveInFile()
{
    Node* triverse = start;
    ofstream save;
    save.open("WordsOpposites.txt");

    while(triverse != NULL)                              /// Saving the whole list in the file
    {
        save << triverse->data1 << " -> " <<triverse->data2 <<"\n";
        triverse = triverse->next;
    }
    save.close();
}

bool WordOpposite::alreadyExist(string d1)
{
   return WordsMeanings::alreadyExist(d1);
}

string WordOpposite::findData(string data)
{
   return WordsMeanings::findData(data);
}

void WordOpposite::releaseMemory()
{
   WordsMeanings::releaseMemory();
}

