#include <iostream>
#include <string>
#include <cmath>

#define EXIT_SUCCESS  0

void tryThis1();
void tryThis2();
void tryThis3();
void tryThis4();
void drill();
void error(std::string s);

int main (void){
  drill();

  return EXIT_SUCCESS;
}
void tryThis1(){
  std::string name = "";
  double age = 0;
  std::cout << "What is your first name: ";
  std::cin >> name;
  std::cout << "How old are you: ";
  std::cin >> age;
  age = age * 12;
  std::cout << "Hi " << name << ", you are " << age << " months old!\n";
}
void tryThis2 (){
  std::cout << "Please Enter a flaoting point number!\n";
  int n = 0;
  std::cin >> n;
  std::cout << "n == " << n
    << "\nn + 1 == " << n+1
    << "\nn * 3 == " << n * 3
    << "\nn * 2 == " << n + n
    << "\nn / 2 == " << n/2
    << "\nsqrt of n == " << std::sqrt(n)
    << std::endl;
}
void tryThis3(){
  //repeated words, chars only equal if they have the same ASCII value (lowercase and upper case dont match)
  std::string previous = " ";
  std::string current;
  while(std::cin >>current){
    if(previous == current){
      std::cout << "repeated word: " << current << std::endl;
    }
    previous = current;
  }
}
void tryThis4(){
   //errors, no declarations
   //std::string s = "Goodbye cruel world!";
   //std::cOut << S << "\n";
}
void drill(){
  std::string first_name = "";
  std::string letter = "";
  std::cout << "\nWho are you writing to? ";
  std::cin >> first_name;
  letter = "\nDear " + first_name + ", "
    + "\n\tHow are you? I am fine, but I miss you"
    + "\n\tThis is the greatest letter of all time"
    + "\n\tEver of all time.. Don't you dare say otherwise";
  std::string friend_name = "";
  std::cout << "\n\nAnother Friend's Name? ";
  std::cin >> friend_name;
  letter += "\n\tHave you seen " + friend_name + " lately?";
  char friend_sex = 0;
  std::cout << "\n\nFriend's Gender f/m ";
  std::cin >> friend_sex;
  if(friend_sex == 'm')
    letter += "\n\tIf you see " + friend_name + " please ask him to call me.";
  if(friend_sex == 'f')
    letter += "\n\tIf you see " + friend_name + " please ask her to call me.";
  if(friend_sex == 'o')
    letter += "\n\tIf you see " + friend_name + " please ask them to call me.";
  int age = 0;
  std::cout << "\n\nAge ";
  std::cin >> age;
  if(age < 0 || age > 110)
    error("you're kidding");
  letter += "\n\tI hear you just had a birthday and you are "
    + std::to_string(age)
    + " years old.";
  if(age < 12)
    letter += "\n\tNext year you will be " + std::to_string(age + 1) + "!";
  if(age == 17)
    letter += "\n\tNext Year you will be able to vote!";
  if(age > 70)
    letter += "\n\tHope you are enjoying retirement!";
  letter += "\nYours sincerely\n\nLachlan \"The best in the universe\" Gower\n";
  std::cout << letter << std::endl;
}
void error (std::string s){
  throw std::runtime_error (s);
}
