#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <ctime>

using namespace std;


struct SForFile
{
	char Familiya[100];
	char Name[100];
	char FatherName[100];
	char Date[11];
	char Telefon[30];
	char Favourite[4];
};

unsigned long parsedate(string sdate)
{
	char d[3];
	char m[3];
	char y[5];
	memset(d,0,3);
	memset(m,0,3);
	memset(y,0,5);
	char * link = (char *)sdate.c_str();
	int i,j,l;
	i=0;
	j=0;
	l=sdate.size();
	while (link[j]!='.'&&j<l&&i<2){d[i]=link[j];j++;i++;}
	if (link[j]=='.')j++;
	i=0;
    while (link[j]!='.'&&j<l&&i<2){m[i]=link[j];j++;i++;}
	if (link[j]=='.')j++;
	i=0;
    while (j<l&&i<4){y[i]=link[j];j++;i++;}
	return atoi(y)*10000+atoi(m)*100+atoi(d);
}

class Person{
public:
Person(){}
~Person(){}

string GetFamiliya(){ return persFamiliya;}
string GetName(){ return persName;}
string GetFatherName() { return persFatherName;}
string GetData(){ return persData;}
string GetTelefon(){ return persTelefon;}
string GetFavourite() { return persFavourite; }

void SetFamiliya(string fam){ persFamiliya=fam;}
void SetName(string name){ persName=name;}
void SetFatherName(string fname) { persFatherName = fname; }
void SetData(string data){ persData=data;}
void SetTelefon(string tel){ persTelefon=tel;}
void SetFavourite(string fav) { persFavourite = fav; }

void Print();

 void toFileS(SForFile *sf);
 void fromFileS(SForFile *sf);

bool operator<(Person a)
{
	bool ret=false;	
	switch(Person::cmpfield)
	{
	case 0:
		return persFamiliya<a.persFamiliya;
	case 1:
		return persName<a.persName;
	case 2:
		return persFatherName < a.persFatherName;
	case 3:
		return parsedate(persData)<parsedate(a.persData);
	case 4:
		return persTelefon<a.persTelefon;
	case 5:
		return persFavourite < a.persFavourite;
	case 6:
		return (persFamiliya<a.persFamiliya)&&
			   (persName<a.persName) && (persFatherName < a.persFatherName) &&
			   (persData<a.persData) &&
			   (persTelefon<a.persTelefon) &&(persFavourite < a.persFavourite);
	}
	return ret;
}

bool operator>(Person a)
{
	bool ret=false;
	switch(Person::cmpfield)
	{
	case 0:
		return persFamiliya>a.persFamiliya;
	case 1:
		return persName>a.persName;
	case 2:
		return persFatherName > a.persFatherName;
	case 3:
		return persData>a.persData;
	case 4:
		return persTelefon>a.persTelefon;
	case 5:
		return persFavourite > a.persFavourite;
	case 6:
		return (persFamiliya>a.persFamiliya)&&
			   (persName>a.persName) && (persFatherName > a.persFatherName) &&
			   (persData>a.persData) &&
			   (persTelefon>a.persTelefon) &&(persFavourite > a.persFavourite);
	}
	return ret;
}

bool operator==(Person a)
{
	bool ret=false;
	switch(Person::cmpfield)
	{
	case 0:
		return persFamiliya==a.persFamiliya;
	case 1:
		return persName==a.persName;
	case 2:
		return persFatherName == a.persFatherName;
	case 3:
		return persData==a.persData;
	case 4:
		return persTelefon==a.persTelefon;
	case 5:
		return persFavourite == a.persFavourite;
	case 6:
		return (persFamiliya==a.persFamiliya)&&
			   (persName==a.persName) && (persFatherName == a.persFatherName) &&
			   (persData==a.persData) &&
			   (persTelefon==a.persTelefon)&&(persFavourite == a.persFavourite);
	}
	return ret;
}

static void Person::setCmpF(int cf){cmpfield=cf;}
static int Person::getCmpF(){return cmpfield;} 

private:
string persFamiliya;
string persName;
string persFatherName;
string persData;
string persTelefon;
string persFavourite;
static int cmpfield;
};

int Person::cmpfield;

void Person::toFileS(SForFile *sf)
{	
	size_t size= persFamiliya.size();
	if (size>99)size=99;
	memcpy((void *)sf->Familiya,(void *)persFamiliya.c_str(),size+1);	
	size=persName.size();
	if (size>99)size=99;
    memcpy((void *)sf->Name,(void *)persName.c_str(),size+1);
	size = persFatherName.size();
	if (size > 99)size = 99;
	memcpy((void*)sf->FatherName, (void*)persFatherName.c_str(), size + 1);
	size=persData.size();
	if (size>10)size=10;
	memcpy((void *)sf->Date,(void *)persData.c_str(),size+1);
	size=persTelefon.size();
	if (size>29)size=29;
	memcpy((void *)sf->Telefon,(void *)persTelefon.c_str(),size+1);
	size = persFavourite.size();
	if (size > 3)size = 3;
	memcpy((void*)sf->Date, (void*)persData.c_str(), size + 1);
}

void Person::fromFileS(SForFile *sf)
{
 persFamiliya = sf->Familiya;
 persName = sf->Name;
 persFatherName = sf->FatherName;
 persData = sf->Date;
 persTelefon = sf->Telefon;
 persFavourite = sf->Favourite;
}

vector <Person> pers;

class Rus {
public:
Rus(const char* text): data(new char [strlen( text)+1]) {CharToOemA( text, data);}
~Rus() {delete [] data;};
operator const char* () const {return data;}

private:
char* data;
};


void Person::Print()
{	
  HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute ( H, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE| BACKGROUND_INTENSITY );
  printf("| %-20.20s| %-12.12s| %-12.12s| %-12.12s | %-12.12s    | %-12.12s    |\n",persFamiliya.c_str(),persName.c_str(), persFatherName.c_str(),persData.c_str(),persTelefon.c_str(), persFavourite.c_str());
}

void PrintMenu()
{

        cout<<endl;
               std::cout <<Rus("Выбирите действие")<<std::endl;
              std::cout <<Rus("1. - Вывести книгу")<<std::endl;
               std::cout <<Rus("2. - Сортировка")<<std::endl;
               std::cout <<Rus("3. - Поиск")<<std::endl;
               std::cout <<Rus("4. - Добавить")<<std::endl;
               std::cout <<Rus("5. - Удалить")<<std::endl;
			   std::cout <<Rus("6. - Сохраненить в файл")<<std::endl;
   			   std::cout <<Rus("7. - Загрузить из файла")<<std::endl;
               std::cout <<Rus("8. - Выход")<<std::endl;


std::cout <<"-------------------------------------------------" << std::endl;
}

void PrintAll()
{
system("cls");
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute ( H, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE| BACKGROUND_INTENSITY );


	cout<<Rus("                    ТЕЛЕФОННАЯ КНИГА")<<std::endl;
	cout<<"----------------------------------------------------------------"<<endl;
cout<<Rus("|    Фамилия          | Имя         |  Отчество   |Дата рождения|  Tелефон    | Избранное |")<<std::endl;
	cout<<"----------------------------------------------------------------------------------------------"<<endl;
	cout<<"|                     |             |             |             |             |           |"<<endl;


for(unsigned int n=0; n<pers.size(); n++)
{
pers[n].Print();
}

cout<<"-----------------------------------------------------------------\n";
}


int GetNumber(int imin, int imax){
 int number=imin-1;
 while(true)
 {
   cin >> number;
   if((number>=imin) && (number <=imax)) break;
   else
   {
        cout <<Rus( "Повторите ввод" )<< endl;
		cin.clear();
        while(cin.get()!='\n'){}
   }
 }
 return number;
}

void SortPerson_p(int field)
{
	Person::setCmpF(field);
	sort(pers.begin(),pers.end());
}

void PrintPage(int pagenum)
{
	system("cls");

        
cout<<Rus("                    ТЕЛЕФОННАЯ КНИГА  страница: ")<<pagenum+1<<std::endl;
	cout<<"---------------------------------------------------------------------------------------------"<<endl;
cout<<Rus("|    Фамилия          | Имя         |  Отчество   |Дата рождения|  Tелефон    | Избранное |") << std::endl;
cout << "----------------------------------------------------------------------------------------------" << endl;
cout << "|                     |             |             |             |             |           |" << endl;

unsigned int endh = pagenum*10+10;
if (endh>pers.size())endh=pers.size();
for(unsigned int n=(pagenum*10); n<endh; n++)
{
pers[n].Print();
}

cout<<"-----------------------------------------------------------------\n";
cout<<Rus("ESC - выход  1. - сортировка по фамилии 2. - по имени 3. - по отчеству 4. - по дате 5. - по телефону PgUp. - вверх PgDn. - вниз")<<endl;
}

void PrintAll2()
{
	unsigned int s = pers.size()/10+1;
    bool stop=false;
	int curpage = 0;
	

	while(!stop)
	{     
	 PrintPage(curpage);	 
     int cmd= getch();
	 if (cmd==224){cmd=getch()+1000;}	 
	 switch(cmd)
	 {
	 case 49:
		    SortPerson_p(0);curpage=0;
		    break;
	 case 50:
		    SortPerson_p(1);curpage=0;
		    break;
	 case 51:
		    SortPerson_p(2);curpage=0;
		    break;
	 case 52:
		 SortPerson_p(3); curpage = 0;
		 break;
	 case 53:
		    SortPerson_p(4);curpage=0;
		    break;
	 case 1073:
		    curpage--;if (curpage<0)curpage=0;
		    break;
	 case 1081:
		    curpage++;if(curpage>s)curpage=s;
		   break;
	 case 27:
		   system("cls");
		   stop=true;
		   break;
	 }
	}
}

void SortPerson()
{
  system("cls");
  HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute ( H, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE| BACKGROUND_INTENSITY );

  cout<<Rus("***----------  сортировка  ---------------***\n");
  cout<<Rus("Введите параметр\n");
  cout<<Rus(" 1 - Фамилия\n");
  cout<<Rus(" 2 - Имя\n");
  cout << Rus(" 3 - Отчество\n");
  cout<<Rus(" 4 - Телефон\n");
  cout<<Rus(" 5 - Выход\n");

  int vybor=GetNumber(1,5);

  if (vybor<5){
   switch(vybor)
   {
   case 1:
	    Person::setCmpF(0);		
	    break;
   case 2:
	    Person::setCmpF(1);		
	    break;
   case 3:
	   Person::setCmpF(2);
	   break;
   case 4:
	    Person::setCmpF(3);		
	    break;  
   case 5:
	      system("cls");
		  break;
   } 
   sort(pers.begin(),pers.end()); 
   PrintAll();
  }
}


int tolower_rus(int ch)
{
	string alf = Rus("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ");
	string alfl = Rus("абвгдеёжзийклмнопрстуфхцчшщьыъэюя");

	int pos = -1;
	for (int i=0;i<alf.size();i++)
	{if (alf[i]==ch){pos=i;break;}}	
	if (pos==-1)return ch;
	return alfl[pos];
}

bool Match(string expr2,string val2)
{
	string expr = expr2;
	string val = val2;
	int i,j,k,g;//указатели в строках
	int ml,mv;//длины строк
	int stat =0;//состояние автомата
	bool s;
    
	for (i=0;i<expr.size();i++)
	{expr[i] = tolower_rus(expr[i]);
	 expr[i] = tolower(expr[i]);
	}
	for (i=0;i<val.size();i++)
	{   val[i] = tolower_rus(val[i]);
		val[i] = tolower(val[i]);
	}

    i=0;
	j=0;
	ml=expr2.size();
	mv=val2.size();
	while(j<mv&&i<ml)
	{
	 switch(expr[i])
	 {
	 case '*'://несколько или ни одного
		 if (i+1<ml)
		 {
           k=i+1;
		   if (expr[k]==val[j]||expr[k]=='?')
		   {//здесь надо попытаться пройти по шаблону либо  до следующей звёздочки или ? либо до конца
              g=j;
			  s=true;
			  while(g<mv&&k<ml&&s)
			  {
				  switch(expr[k])
				  {
				  case '*':
					    j=g;i=k;
						s=false;
					  break;
				  case '?':
					    g++;k++;
					  break;
				  default:
					  if (expr[k]==val[g]){g++;k++;}
					  else 
					  {
						  j++;//добавляем одну букву к пройденому и пытаемся опять сверить строки
						  s=false;
					  }
				  }				  
			  }
			  if (k>=ml&&g>=mv)return true;              
			  if (k<ml&&g>=mv) return false;
			  if (s&&g<mv&&k>=ml)j++;			  
		   }
		   else		   
			   j++;		   
		 }
		 else
			 return true;//звёздочка на конце выражения дальше можно не смотреть
         break;
	 case '?'://один пропускаем
		 i++;j++;break;
	 default: // просто символ
		 if (expr[i]==val[j]){i++;j++;}
		 else {return false;}//посимвольное не совпадение
	 }	 
	}
	if (j<mv)return false;//выражение закончилось раньше чем строка
	if (i<ml)return false;//строка закончилась раньше чем выражение
	return true;
}

void FindPerson()
{
  system("cls");
  HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute ( H, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE| BACKGROUND_INTENSITY );
 
  cout<<Rus("--------------------- поиск записи -------------------------\n");
  cout<<Rus("Выбирите критерий поиска\n");
  cout<<Rus(" 1 - Фамилия\n");
  cout<<Rus(" 2 - Имя\n");
  cout << Rus(" 3 - Отчество\n");
  cout<<Rus(" 4 - Дата рождения\n");
  cout<<Rus(" 5 - Телефон\n");
  cout<<Rus(" 6 - Выход\n");
  int vybor=GetNumber(1,6);

  if (vybor<6)
  {
	  string key;
	  string vkey;
	  bool found = false;
	  switch(vybor)
	  {
	  case 1: cout<<Rus("Введите фамилию: ");break;
	  case 2: cout<<Rus("Введите имя: "); break;
	  case 3: cout << Rus("Введите Отчество: "); break;
	  case 4: cout<<Rus("Введите дату рождения: ");break;
	  case 5: cout<<Rus("Введите телефон: ");break;
      case 6:
	          system("cls");
		      break;
	  }
	  cin>>key;

         cout<<"-------------------------------------------------------------------------------------------------"<<endl;
         cout<<Rus("|    Фамилия          | Имя         |  Отчество   |Дата рождения|  Tелефон    | Избранное |") << std::endl;
		 cout << "----------------------------------------------------------------------------------------------" << endl;
		 cout << "|                     |             |             |             |             |           |" << endl;
	  unsigned int n=0;
      while (n<pers.size())
	  {	
         switch(vybor)
		 {
		 case 1:vkey=pers[n].GetFamiliya();break;
		 case 2:vkey=pers[n].GetName();break;
		 case 3:vkey = pers[n].GetFatherName(); break;
		 case 4:vkey=pers[n].GetData();break;
		 case 5:vkey=pers[n].GetTelefon();break;
		 }
         if (Match(key,vkey))
		 {
          found=true;
		  pers[n].Print();		           
		 }
		 n++;
	  }
	  cout<<"----------------------------------------------------------------"<<endl;
	  if (!found)	 	  
		  cout<<Rus("Нет такой записи\n");

  }
}



void AddPerson(){system("cls");
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute ( H, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE| BACKGROUND_INTENSITY );

string sbuf;
Person bufPers;
cout<<endl;

                cout<<Rus("----------------  Добавление записи ----------------\n");
cout<<Rus("Фамилия: ");
cin>>sbuf;
bufPers.SetFamiliya(sbuf);

cout<<endl;
cout<<Rus("Имя: ");
cin>>sbuf;
bufPers.SetName(sbuf);

cout << endl;
cout << Rus("Отчество: ");
cin >> sbuf;
bufPers.SetFatherName(sbuf);

cout<<endl;
cout<<Rus("Дата рождения: ");
cin>>sbuf;
bufPers.SetData(sbuf);

cout<<endl;
cout<<Rus("Телефон:");
cin>>sbuf;
bufPers.SetTelefon(sbuf);

cout << endl;
cout << Rus("Избранное:");
cin >> sbuf;
bufPers.SetFavourite(sbuf);

pers.push_back(bufPers);
cout<<"----------------------------------------------------------------"<<endl;
}


void DeletePerson()
{
	string sbuf;
	int n = 0;
	bool find = false;

	system("cls");


	cout << Rus("----------------  Удаление записи ---------------\n");
	cout << Rus("Выбирите критерий выбора записей на удаление\n");
	cout << Rus(" 1 - Фамилия\n");
	cout << Rus(" 2 - Имя\n");
	cout << Rus(" 3 - Отчество\n");
	cout << Rus(" 4 - Дата рождения\n");
	cout << Rus(" 5 - Телефон\n");
	cout << Rus(" 6 - Избранное\n");
	cout << Rus(" 7 - Выход\n");
	int vybor = GetNumber(1, 7);

	if (vybor < 7)
	{
		string key;
		string vkey;
		bool found = false;
		switch (vybor)
		{
		case 1: cout << Rus("Введите фамилию: "); break;
		case 2: cout << Rus("Введите имя: "); break;
		case 3: cout << Rus("Введите отчество: "); break;
		case 4: cout << Rus("Введите дату рождения: "); break;
		case 5: cout << Rus("Введите телефон: "); break;
		case 6: cout << Rus("Подтвердите удаление избранного: "); break;
		case 7:
			system("cls");
			break;
		}
		cin >> key;
		cout << Rus("Удалены следующие записи:") << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << Rus("|    Фамилия          | Имя         |  Отчество   |Дата рождения|  Tелефон    | Избранное |") << std::endl;
		cout << "----------------------------------------------------------------------------------------------" << endl;
		cout << "|                     |             |             |             |             |           |" << endl;
		unsigned int n = 0;
		while (n < pers.size())
		{
			switch (vybor)
			{
			case 1:vkey = pers[n].GetFamiliya(); break;
			case 2:vkey = pers[n].GetName(); break;
			case 3:vkey = pers[n].GetFatherName(); break;
			case 4:vkey = pers[n].GetData(); break;
			case 5:vkey = pers[n].GetTelefon(); break;
			case 6:vkey = pers[n].GetFavourite(); break;
			}
			if (Match(key, vkey))
			{
				found = true;
				pers[n].Print();
				pers.erase(pers.begin() + n);
			}
			else
				n++;
		}
		cout << "----------------------------------------------------------------" << endl;
		if (!found)
			cout << Rus("Не найдено ни одной записи\n");
	}
}

  bool DataToFile(string filename)
  {   SForFile sf;
	  ofstream fout(filename.c_str(), ios_base::out | ios_base::binary);
	  if (fout.is_open())
	  {
		  size_t size = pers.size();
		  fout.write((char*)&size, sizeof(int));
		  for (size_t i = 0; i < size; i++)
		  {
			  memset(&sf, 0, sizeof(SForFile));
			  pers[i].toFileS(&sf);
			  fout.write((char*)&sf, sizeof(SForFile));
		  }
		  fout.close();
		  return true;
	  }
	  return false;
  }

void SaveToFile()
{
 string filename;
 
 cout<<Rus("Введите имя файла:");
 cin>>filename;
 if (DataToFile(filename))
 {
	  system("cls");
   cout<<Rus("Сохранение успешно завершено.\n");
 }
 else
 {
	 system("cls");
	 cout<<Rus("Ошибка сохранения в файл.\n");	
 }
}

bool DataFromFile(string filename)
{
 int size;
 SForFile sf;

 ifstream fin(filename.c_str());
 if( fin.is_open() )
 {
   pers.clear();
   fin.read((char*)&size, sizeof(int));
   for(int i=0; i<size; i++)
   {
     Person tmp;
     fin.read((char*)&sf, sizeof(SForFile));
	 tmp.fromFileS(&sf);
     pers.push_back(tmp);
   }
   fin.close();
   return true;
 }
 return false;
}

void LoadFromFile()
{
 string filename;
 cout<<Rus("Введите имя файла:");
 cin>>filename;
 if (DataFromFile(filename)){
   system("cls");
   cout<<Rus("Данные прочитаны.\n");	
 }else
 {
	 system("cls");
	 cout<<Rus("Ошибка чтения из файла.\n");	
 }
 
}

