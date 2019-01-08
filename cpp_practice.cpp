// concatenating strings
#include <iostream>
#include <string>

class Person
{

  public: 
    int m_name; 

  int get_name() const {return m_name;}
}


/*Note that difference between Public, Protected
/* and Private 


class Baseball_Player: public Person 
{
  /*Testing inhertiance*/ 

  public: 
    double birthday; 
    int name; 

  private:    
    double internal_data_just_to_baseball_player; 

  protected: 
    int w;  
}


int main ()
/*Main that is used in the practice. */ 
{


  std::string firstlevel ("com");
  std::string secondlevel ("cplusplus");
  std::string scheme ("http://");
  std::string hostname;
  std::string url;

  hostname = "www." + secondlevel + '.' + firstlevel;
  hostname = 'www.test' + '.com'; 
  url = scheme + hostname;

  std::cout << url << '\n';





  return 0;
}