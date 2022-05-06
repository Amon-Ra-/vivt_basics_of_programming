/*
Номер и вид работы: Лабораторная работа №2
Название работы: Классы
Ф.И.О.: 
Номер зачетной книжки: 
Группа: 
Вариант: №15
*/
/*
Вариант 15
Описать класс «записная книжка». Предусмотреть возможность работы
с произвольным числом записей, поиска записи по какому-либо признаку
(например, по фамилии, дате рождения или номеру телефона), добавления и
удаления записей, сортировки по разным полям.
Написать программу, демонстрирующую работу с этим классом.
Программа должна содержать меню, позволяющее осуществить проверку всех
методов класса.
*/

//Подключение стандартных библиотек
#include <iostream>   // std::cout 
#include <map>       // std::map
#include <string>    // std::string
#include <fstream>

//Описание класса телефонная книга
class PhoneBook
{
  public:
    PhoneBook(const std::string & filename_ = "text.txt") ;
    bool AddRecord(const std::string& , const std::string& );
    bool AddRecord(const std::pair <std::string, std::string>& );
    std::string FindPhoneByName (const std::string&);
    std::string FindNameByPhone(const std::string&);
//  void ShowAllRecords();
    void DeleteRecordByName(const std::string&);
    void DeleteRecordByNumber(const std::string&);
    void WriteFile();
    void ReadFile();
    void ClearFile();
    void ClearAll();
    friend std::ostream & operator << (std::ostream & os, const PhoneBook & phonebook);
 
protected :
    std::map <std::string, std::string> records;
    std::string filename;
};
 
//#include "PhBook.h"
 
 
PhoneBook::PhoneBook(const std::string & filename_ ):
    filename(filename_)
{
    
}
void PhoneBook::WriteFile() throw( std::ios_base::failure)
{
    std::ofstream outfile;
    outfile.open(filename);
    if(! outfile.is_open())
    throw( std::ios_base::failure("Error in opening file\n"));
for (std::map <std::string, std::string>::const_iterator iter = records.begin();
                   iter != records.end(); ++iter )  
  {          
       outfile <<  iter->first << ' ' << iter->second << std::endl;
  }
 
    outfile.close();
    
}
 
void PhoneBook::ReadFile() throw( std::ios_base::failure)
{
    std::ifstream infile;
    infile.open(filename);
    if(! infile.is_open())
    throw( std::ios_base::failure("Error in opening file\n"));
    std::string firststr, secondstr;
while(  infile >> firststr >>  secondstr)
  {          
       AddRecord( firststr, secondstr);
  }
    infile.close();
    
}
 
void PhoneBook::ClearFile() throw( std::ios_base::failure)
{
    std::ofstream clearfile;
    clearfile.open(filename);
    if( ! clearfile.is_open())
    throw( std::ios_base::failure("Error in opening file\n"));
    clearfile.close();
    
}
bool PhoneBook::AddRecord(const std::string& name_,const std::string& number_)
{
     std::pair<std::map <std::string, std::string>::iterator,bool> result; 
     result =  records.insert(std::make_pair(name_, number_));
     WriteFile();
     return result.second;
}
 
bool PhoneBook::AddRecord(const std::pair <std::string, std::string>& record)
{
     std::pair<std::map <std::string, std::string>::iterator,bool> result; 
     result =  records.insert(record);
     WriteFile();
     return result.second;
}
 
void PhoneBook::DeleteRecordByName(const std::string& name_)
{
     records.erase(name_);
}
 
void PhoneBook::DeleteRecordByNumber(const std::string& number_)
{
     records.erase(number_);
}
 
std::string PhoneBook::FindPhoneByName(const std::string& name_) throw( std::out_of_range)
{
   std::map <std::string, std::string>::iterator iter = records.find(name_);
   if ( iter == records.end())
      throw( std::out_of_range("Entry with Name " + name_ + " does not exist\n"));
   return iter->second;
}
 
std::string PhoneBook::FindNameByPhone(const std::string& number_) throw( std::out_of_range)
{
  for (std::map <std::string, std::string>::const_iterator iter = records.begin();
    iter != records.end(); ++iter ) 
  {
       if ( iter->second == number_)     
       return iter->first;
  }
  throw( std::out_of_range("Entry with Phone Number " + number_ + " does not exist\n"));
}
 
 std::ostream & operator << (std::ostream & os, const PhoneBook & phonebook)
{
    for (std::map <std::string, std::string>::const_iterator iter = phonebook.records.begin();
    iter != phonebook.records.end(); ++iter )       
    os <<  iter->first << "  " << std::setw( 30 - iter->first.length() )<< iter->second << std::endl;
   return os;
}
 
 void PhoneBook::ClearAll()
 {
     records.clear();
     ClearFile() ;
 }
 
//Подключение основных библиотек
#include <iostream>   // std::cout 
#include <map>       // std::map
#include <string>    // std::string
#include <iomanip>    // std::string
#include <fstream> 
#include "PhBook.h"
 
int main () 
{
    
 try
  {
      //формирование самой телефонной книги
           PhoneBook phonebook("C:\\code.txt");
           phonebook.ClearAll();
           phonebook.AddRecord("Helene", "0099777");
  
         if(! phonebook.AddRecord(std::make_pair("Olga", "799111")))
             std::cout << "Record has not been added\n";
 
             phonebook.AddRecord("Michail", "0099788");
    
  
          if(! phonebook.AddRecord("Olga", "799111"))
             std::cout << "Record has not been added\n";
 
          // Show All
          std::cout << phonebook << std::endl;
 
          std::cout << phonebook.FindPhoneByName("Olga") << std::endl;
          phonebook.DeleteRecordByNumber("Olga") ;
 
          // Show All
          std::cout << phonebook << std::endl;
 
}
   catch(std::exception & ex)
  {
      std::cout << ex.what();
  }
    system("pause");
 
  return ( 0 );
}