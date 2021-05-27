#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <windows.h> 
#include <functional>
#include <algorithm>
#include <ctime>

using namespace std;

void PrintMenu();
void PrintAll(); 
void PrintAll2();
void SortPerson(); 
void FindPerson(); 
void AddPerson(); 
void DeletePerson(); 
int GetNumber(int imin, int imax);
std::string & change(std::string & str);
void SaveToFile();
void LoadFromFile();
bool DataToFile(string filename);
bool DataFromFile(string filename);
bool Match(string e,string v);

BOOL SetConsoleAttrib(HANDLE _ConsoleOut,WORD wAttrib)
{
      SetConsoleTextAttribute(_ConsoleOut, wAttrib);
      CONSOLE_SCREEN_BUFFER_INFO csbi = {0};
      GetConsoleScreenBufferInfo(_ConsoleOut, &csbi);
      DWORD dw(0);
      COORD cr = {0, 0};
      return FillConsoleOutputAttribute(_ConsoleOut, 
            wAttrib, csbi.dwSize.X * csbi.dwSize.Y, cr, &dw);
}

int main()
{

bool exit=false;

DataFromFile("database");
while(true)
{
PrintMenu();
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleAttrib ( H, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE| BACKGROUND_INTENSITY );

switch(GetNumber(1,8)){
case 1: PrintAll2();break;
case 2: SortPerson(); break;
case 3: FindPerson(); break;
case 4: AddPerson(); break;
case 5: DeletePerson(); break;
case 6: SaveToFile(); break;
case 7: LoadFromFile();break;
case 8: exit=true; break;
}
if(exit) break;
}
DataToFile("database");
return 0;
}