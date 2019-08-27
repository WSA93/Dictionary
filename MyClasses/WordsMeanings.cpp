#include"WordsMeanings.h"

WordsMeanings::WordsMeanings()
{
    start = NULL;
}

void WordsMeanings::addNewToList(string d1,string d2)
{
    if(start == NULL)                /// Making first node
    {
        Node* newNode = new Node;
        newNode->data1 = d1;
        newNode->data2 = d2;

        newNode->next = start;
        start = newNode;
    }
    else if(start->data1 > d1) /// If given word is less than first node put it before first node
    {
        Node* newNode = new Node;
        newNode->data1 = d1;
        newNode->data2 = d2;

        newNode->next = start;
        start = newNode;
    }
    else
    {
        Node* triverse = start;
        while(triverse != NULL)
        {
            if(triverse->next == NULL)     /// Inserting node in last
            {
                Node* newNode = new Node;
                newNode->data1 = d1;
                newNode->data2 = d2;

                newNode->next = NULL;
                triverse->next = newNode;
                break;
            }
            else if(triverse->data1 < d1 && triverse->next->data1 > d1)
            {
                Node* newNode = new Node;   /// Inserting a node b\w two nodes
                newNode->data1 = d1;
                newNode->data2 = d2;

                newNode->next = triverse->next;
                triverse->next = newNode;
                break;
            }
            triverse = triverse->next;
        }

    }
}

 void WordsMeanings::loadDataFromFile()
{
  string read1 = "";
  string read2 = "";

  ifstream load;
  load.open("WordsMeanings.txt");
  if(!load)
  {

  }
  else
  {
    while(load >> read1)
    {
        load.ignore(4);
        getline(load,read2);

        if(start == NULL)                /// Making first node
        {
           Node* newNode = new Node;
           newNode->data1 = read1;
           newNode->data2 = read2;

           newNode->next = start;
           start = newNode;
        }
        else
        {                                 /// After first node every node will be inserted in the end.
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

bool WordsMeanings::alreadyExist(string d1)
{
    Node* triverse = start;
    while(triverse != NULL)
    {
        if(d1 == triverse->data1)       /// If given word is == to any word already present
        {                               /// in the list then return 1
            return 1;
        }
        triverse = triverse->next;
    }
    return 0;
}

void WordsMeanings::saveInFile()
{
    Node* triverse = start;
    ofstream save;
    save.open("WordsMeanings.txt");

    while(triverse != NULL)                    /// Saving the whole list in the file
    {
        save << triverse->data1 << " -> " <<triverse->data2 <<"\n";
        triverse = triverse->next;
    }
    save.close();
}

string WordsMeanings::findData(string data)
{
   if(start == NULL)
   {
       return "No File Exists";
   }
   else
   {
     Node* searchData = start;
     while(searchData != NULL)
     {
        if(data == searchData->data1)                  /// Searching for the given word.
        {
            return searchData->data2;
        }
        searchData = searchData->next;
     }
   }
   return "No Match Found";

}

void WordsMeanings::releaseMemory()
{
    while(start != NULL)
    {
        Node* deleteMem = start;
        start = deleteMem->next;
        delete deleteMem;
    }
}
