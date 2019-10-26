#include <iostream>
#include <string>

#define uint unsigned int 

enum enum_month {
 jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

class Date{
  
private:

  uint _d; //day
  enum_month _m; //month
  uint _y; //year

  
public:

  //constructor and default destructor
  Date(const uint d, const enum_month m, const uint y);
  ~Date();

  //function that returns private variables
  uint day() const {return _d;}

  enum_month month() const {return _m;}

  uint year() const {return _y;}

  void add_days(const uint n);

  void print_date() const;
};


bool operator==(const Date& lhs, const Date& rhs){

	bool op = (lhs.day() == rhs.day()) and (lhs.month() == rhs.month()) and (lhs.year() == rhs.year());

	if(op){ return true; }

	else { return false;}

}

bool operator!=(const Date& lhs, const Date& rhs){

	bool op = (lhs.day() == rhs.day()) and (lhs.month() == rhs.month()) and (lhs.year() == rhs.year());

        if(op){ return false; }

        else { return true;}

}

std::ostream& operator<<(std::ostream& os, const Date& d) {


	os <<d.month()<<"/"<<d.day()<<"/"<<d.year()<<"\n";

}




int main(){

  uint d;
  uint m;
  uint y;
 
  std::cout<<"Hello, insert the current data: ";
  std::cout<<"M: ";
  std::cin>>m;
  std::cout<<"D: ";
  std::cin>>d;
  std::cout<<"Y: ";
  std::cin>>y;
  std::cout<<"\n";

  Date today(d, static_cast<enum_month>(m), y);

  today.print_date();

  today.add_days(6);

  today.print_date();
  
  return 0;

}




Date::Date(const uint d, const enum_month m, const uint y)
    : _d{d},
      _m{m},
      _y{y}
{}


Date::~Date() {}

void Date::add_days(const uint n){

  switch (_m){
    
  case jan: case mar: case may: case jul:
  case aug: case oct: case dec:

    if ((_d+n>31)){

      _d = (_d+n) - 31;

      if (_m == 12){
	_y++;
	_m = jan;
      }

      else{
	_m = static_cast<enum_month>(static_cast<int>(_m)+1);
      }

    }

    else {

      _d =_d+n;
      
    }

    break;

  case apr: case jun: case sep: case nov:

    if ((_d+n>30)){

      _d = (_d+n) - 30;
      _m = static_cast<enum_month>(static_cast<int>(_m)+1);
    }

    else {

      _d = _d+n;
      
    }

    break;

  case feb:

    if((_d+n)>28){

      _d = (_d+n) - 28;

      _m = static_cast<enum_month>(static_cast<int>(_m)+1);

    }

    else {

      _d =_d+n;

    }

  }


}


void Date::print_date() const{


  std::cout<<"Current data: ";
  std::cout<<_m<<"/"<<_d<<"/"<<_y<<std::endl;


}

