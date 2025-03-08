#include <iostream>
#include <fstream>
#include <string>

//Creating struct for counting line/word/char
struct counter{
    int linecount;
    int wordcount;
    int charcount;
};

int main(){
//declaring variables
   counter MyCount;
   std::ifstream infs;
   char ch;
   std::string word;
   std::string line;
   std::string fileName;

//setting MyCount variables to 0
   MyCount.linecount = 0;
   MyCount.wordcount = 0;
   MyCount.charcount = 0;

//open file
   std::cin >> fileName;
   infs.open(fileName);

//check if file works
   if (!infs.is_open()){
      return 1;
   }

//while loop for linecount and going back to file start
   while (std::getline(infs, line)){
      MyCount.linecount++;
   }
   infs.clear();
   infs.seekg(0, std::ios::beg);

//while loop for wordcount and going back to file start
   while (infs >> word){
      MyCount.wordcount++;
   }
   infs.clear();
   infs.seekg(0, std::ios::beg);

//while loop for charcount and going back to file start
   while (infs.get(ch)){
      MyCount.charcount++;
   }
   infs.clear();
   infs.seekg(0, std::ios::beg);

//file close
   infs.close();

//outputs
   std::cout << MyCount.linecount << "	";
   std::cout << MyCount.wordcount << "	";
   std::cout << MyCount.charcount << " " << fileName << std::endl;

   return 0;
}
