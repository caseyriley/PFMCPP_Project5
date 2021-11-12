/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
=============================================
Since you didn't do Project 3:
=============================================
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) add 2 member functions to each of these 2 new types.
       These member functions should make use of the member variables. 
       Maybe interact with their properties or call their member functions.
       The purpose is to demonstrate that you know how to use a class's member variables and member functions when it is a member of another class.
 
 7) use at least 2 instances of each of your UDTs in main. 
       - call every member function of your UDTs to make sure they work as expected and don't produce warnings.
       - add some std::cout statements in main() that use your UDT's member variables.
       you have 5 UDTs and 2 nested UDTs, so there should be at minimum 14 UDTs declared in main(), as well as 14 * 3 function calls happening.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.
 */

/*
 UDT 1:
 */
 #include <iostream>
#include<string>
#include<cstdlib>
#include <random>
#include <iostream>
using namespace std;

struct Wizard 
{
    Wizard();
    ~Wizard();

    int languages;
    char rune;
    int age;
    int magicItems;
    struct Spell{
        Spell();
        ~Spell();
        string phrase;
        string ingredient = "mushroom";
        float time = 12.39f;
        int steps = 7;
        bool allowed = true;
    };

    void castSpell(string nameOfSpell);
    int runAway(int howFar);
    bool hide(bool hidingPlace);
};

Wizard::Wizard() :
languages(5),
rune('Y'),
age(70),
magicItems(4)
{
    cout <<"CONSTRUCTING Wizard" << " With number of magic languages: " << languages << endl;
}

Wizard::~Wizard()
{
    cout << "DESTRUCTING Wizard" << " With number of magic languages: " << languages << endl;
}

void Wizard::castSpell(string nameOfSpell = "boof!")
{
    cout << "Wizard casts " << nameOfSpell << endl;
}

int Wizard::runAway(int howFar)
{
    cout << "Wizard runs " << howFar << " feet away." << endl;
    return 0;
}

bool Wizard::hide(bool hidingPlace)
{
    if (hidingPlace){
        cout << "Wizard hides" << endl;
        return true;
    }
    cout << "Wizard hides poorly and is still visible." << endl;
    return false;
}
/*
 UDT 2:
 */
struct Fighter 
{
    Fighter();
    ~Fighter();

    string weapon;
    char signet;
    string armor;
    float money;
    struct Moves {
        Moves();
        ~Moves();
        string bestMove = "swing sword";
        string worstMove = "seduce enemy";
        bool canBeCalm = false;
        bool fightsDrunk = true;
        bool smellsBad = true;
    };
    string fight(string weaponUsed);
    int block(int speed);
    int drink(int stamina);
};

Fighter::Fighter() :
weapon("Sword"),
signet('L'),
armor("none"),
money(0.0f)
{
    cout <<"CONSTRUCTING Fighter with" << weapon  << endl;
}

Fighter::~Fighter()
{
    cout << "DESTRUCTING Fighter" << endl;
}

string Fighter::fight(string weaponUsed)
{
    if (weaponUsed != "fists")
    {
        cout << "Fighter fights with " << weaponUsed << endl;
        return "Fighter fights with " + weapon;
    }
    cout << "Fighter fights with fists" << endl;
    return "Fighter fights with fists";
}

int Fighter::block(int speed)
{
    cout << "Fighter blocks with a speed of " << speed << endl;
    return speed;
}

int Fighter::drink(int stamina)
{
    if (stamina > 12)
    {
        cout << "Fighter manages to drink another round!";
        return 0;
    }
    cout << "Unable to hold his drink the Fighter collapses" << endl;
    return 1;
}
/*
 UDT 3:
 */
struct Preistess 
{
    Preistess();
    ~Preistess();
    string favoriteFood;
    string leastFavoriteThing;
    int crystals;
    int illusions;
    string home;
    int castGrowSpell(int numPlants = 1);
    string castBanish(string thingToBeBanished);
    int castIllusions(int numIllusions = 1);
};

Preistess::Preistess() :
favoriteFood("Salad"),
leastFavoriteThing("Bad Smells"),
crystals(12),
illusions(20),
home("Tree house")
{
    cout << "CONSTRUCTING Preistess with " << crystals << " ctrystals"  << endl;
}

Preistess::~Preistess()
{
    cout << "Deconstructing Preistess" << endl;
}

int Preistess::castGrowSpell(int numPlants)
{
    for (int i = 0; i < Preistess::crystals; i += 1)
    {
        numPlants += 1;
    }
    cout << "Priestess casts grow and " << numPlants << " plants grow immediately" << endl;
    return numPlants;
}

string Preistess::castBanish(string thingToBeBanished)
{
    if (thingToBeBanished != Preistess::leastFavoriteThing)
    {
        cout << "Preistess casts banish and " << thingToBeBanished << " are banished for 2 rounds" << endl;
        return "praretess casts banish and " + thingToBeBanished + " are banished for 2 rounds";
    }
    cout << "Preistess casts banish and " << Preistess::leastFavoriteThing << " are banished for 2 rounds" << endl;
        return "preistess casts banish and " + Preistess::leastFavoriteThing + " are banished for 2 rounds";
}

int Preistess::castIllusions(int numIllusions)
{
    int index = Preistess::crystals;
    while (index > 0)
    {
        numIllusions *= 2;
        index --;
    }
    cout << "Preistess casts Illusions and " << numIllusions << " illusions appear instantly" << endl;
    return numIllusions;
}
/*
 new UDT 4:
 */
 struct Thief {
     Thief();
     ~Thief();
     int tools;
     string guild;
     bool secretLanguage;
     double speed = 33.50;
     class Techniques {
         Techniques(string main);
         ~Techniques();
         string main = "sneak";
         string second = "climb";
         string third = "back stab";
         string fourth = "pick pocket";
         string fifth = "read lips";
     };
     bool cartwheel(int dexterity = 13);
     bool smoothTalk();
     float steal(float amount = 50.00f);
 };

 Thief::Thief() :
 tools(15),
 guild("Secret"),
 secretLanguage(true)
 {
     cout << "CONSTRUCTING Thief with " << guild << " guild" << endl;
 }

 Thief::~Thief()
 {
     cout << "DECONSTRUCTING Thief" << endl;
 }

bool Thief::cartwheel(int dexterity)
{
    if (dexterity >= 13  ){
        cout << "Theif carwheels no problem" << endl;
        return true;
    }
    cout << "Theif fails at a cartwheel and is vulnerable to insults" << endl;
    return false;
}

int randomNum() 
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, 20);
  int result = dist(gen);
  return result;
}

bool Thief::smoothTalk()
{
    if (randomNum() > 11){
        cout << "Theif smooth talks effectively" << endl;
        return true;
    }
    cout << "Theif thinks he's so smooth but is not" << endl;
    return false;
}

float Thief::steal(float amount)
{
    if (randomNum() > 10)
    {
        cout << "Theif steals amount of " << amount << endl;
        return amount; 
    }
    cout << "Theif gets caught red handed trying to steal and amount of " << amount << endl;
    return amount;
}

/*
 new UDT 5:
 */
struct Bard {
    Bard();
    ~Bard();
    string instrument;
    bool sings = true;
    bool loud = true;
    string bestAsset = "Looks";
    int songs = 99;
    double beautyRest(double time = 12.00);
    string playMusic(string nameOfSong = "Did it all myself");
    float jump(float howHigh = 6.0f);
};
Bard::Bard() :
instrument("Lute")
{
    cout << "CONSTRUCTING Bard with " << Bard::instrument << endl;
}

Bard::~Bard()
{
    cout << "DECONSTRUCTING Bard " << endl;
}

double Bard::beautyRest(double time)
{
    cout << "Bard gets needed beauty rest for " << time << " hours." << endl;
    return time;
}

string Bard::playMusic(string nameOfSong)
{
    cout << "Bard plays " << nameOfSong << endl;
    return nameOfSong;
}

float Bard::jump(float howHigh)
{
    cout << "Bard jumps " << howHigh << " feet" << endl;
    return howHigh;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */


int main()
{
    Wizard Fizban;
    Fizban.castSpell("boof!");
    Fizban.runAway(30);
    Fizban.hide(false);
    cout << "Haha! Fizban of " << Fizban.age << " years boofed you!" << endl;
    Fighter Mooky;
    Mooky.fight("mace");
    Mooky.block(66);
    Mooky.drink(11);
    cout << "Haha! Mooky with the signet " << Mooky.signet << " gets dragged off by gnomes" << endl;
    Preistess Pearl;
    Pearl.castGrowSpell(7);
    Pearl.castBanish("Bad Smells");
    Pearl.castIllusions(7);
    Thief Smarkles;
    Smarkles.cartwheel(13);
    Smarkles.smoothTalk();
    Smarkles.steal(100.00f);
    Bard Fabio;
    Fabio.beautyRest();
    Fabio.playMusic();
    Fabio.jump(5.0f);
    Wizard Barth;
    Fighter Marmy;
    Preistess periwinkle;
    Thief sammy;
    Bard Ahsia;
    std::cout << "good to go!" << std::endl;
}
