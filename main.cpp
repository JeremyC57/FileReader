#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
  string fileName; //to get the name of the file to open
  string line; //to store a single line of a text file
  fstream fileStream; //to open a file for reading
  int lineNum; //to store number of lines
  int charNum; //to store number of characters
  char yesNo;


  do
  {
  lineNum = 0;
  charNum = 0;

  cout<<"What file do you want to open? ";
  getline(cin, fileName);
  
  //STEP 1: open the fileStream for input, using the fileName specified
  fileStream.open(fileName.c_str() ,fstream::in);  
  if( fileStream.good() )
  {
    cout<<fileName<<" opened.\nFILE CONTENTS:\n";
    
    //STEP 3: repeat the following until the end-of-file (eof) has been reached...
    while(!fileStream.eof())
    {
         // 3A: read a line from fileStream into the variable line
         getline(fileStream, line);
         if(!line.empty())
         {
              lineNum++;
              charNum += line.length();
              
              
              // 3B: display the line, followed by an endline
              cout<<line<<endl;
         }
    }

    cout<<"METADATA" << endl <<"File: "<< fileName << endl << "Lines: " << lineNum << endl << "Characters: " << charNum << endl;
    
    
    
  
    //STEP 4: close the fileStream
    fileStream.close(); 
  }
  else
  {
    cout<<fileName<<" could not be opened.\n";
        cout<<"METADATA" << endl <<"File: "<< fileName << endl << "Lines: " << lineNum << endl << "Characters: " << charNum << endl;

  }
  cout << "Analyze another file (y/n)? ";
  cin >> yesNo;
  cin.ignore();
  }while( tolower(yesNo) == 'y');

  return 0;
}
