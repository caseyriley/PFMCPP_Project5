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

struct Wizard 
{
    Wizard();
    ~Wizard();

    int languages;
    char rune;
    int age;
    int magicItems;
    struct Spell
    {
        Spell();
        ~Spell();
        std::string phrase;
        std::string ingredient = "mushroom";
        float time = 12.39f;
        int steps = 7;
        bool allowed = true;
    };

    void castSpell(std::string nameOfSpell);
    int runAway(int howFar);
    bool hide(bool hidingPlace);
};

Wizard::Wizard() :
languages(5),
rune('Y'),
age(70),
magicItems(4)
{
    std::cout <<"CONSTRUCTING Wizard" << " With number of magic languages: " << languages << std::endl;
}

Wizard::~Wizard()
{
    std::cout << "DESTRUCTING Wizard" << " With number of magic languages: " << languages << std::endl;
}

void Wizard::castSpell(std::string nameOfSpell = "boof!")
{
    std::cout << "Wizard casts " << nameOfSpell << std::endl;
}

int Wizard::runAway(int howFar)
{
    std::cout << "Wizard runs " << howFar << " feet away." << std::endl;
    return 0;
}

bool Wizard::hide(bool hidingPlace)
{
    if (hidingPlace)
    {
        std::cout << "Wizard hides" << std::endl;
        return true;
    }
    std::cout << "Wizard hides poorly and is still visible." << std::endl;
    return false;
}
/*
 UDT 2:
 */
struct Fighter 
{
    Fighter();
    ~Fighter();

    std::string weapon;
    char signet;
    std::string armor;
    float money;
    struct Moves 
    {
        Moves();
        ~Moves();
        std::string bestMove = "swing sword";
        std::string worstMove = "seduce enemy";
        bool canBeCalm = false;
        bool fightsDrunk = true;
        bool smellsBad = true;
    };
    std::string fight(std::string weaponUsed);
    int block(int speed);
    int drink(int stamina);
};

Fighter::Fighter() :
weapon("Sword"),
signet('L'),
armor("none"),
money(0.0f)
{
    std::cout <<"CONSTRUCTING Fighter with" << weapon  << std::endl;
}

Fighter::~Fighter()
{
    std::cout << "DESTRUCTING Fighter" << std::endl;
}

std::string Fighter::fight(std::string weaponUsed)
{
    if (weaponUsed != "fists")
    {
        std::cout << "Fighter fights with " << weaponUsed << std::endl;
        return "Fighter fights with " + weaponUsed;
    }
    std::cout << "Fighter fights with fists" << std::endl;
    return "Fighter fights with fists";
}

int Fighter::block(int speed)
{
    std::cout << "Fighter blocks with a speed of " << speed << std::endl;
    return speed;
}

int Fighter::drink(int stamina)
{
    if (stamina > 12)
    {
        std::cout << "Fighter manages to drink another round!";
        return 0;
    }
    std::cout << "Unable to hold his drink the Fighter collapses" << std::endl;
    return 1;
}
/*
 UDT 3:
 */
struct Priestess 
{
    Priestess();
    ~Priestess();
    std::string favoriteFood;
    std::string leastFavoriteThing;
    int crystals;
    int illusions;
    std::string home;
    int castGrowSpell(int numPlants = 1);
    std::string castBanish(std::string thingToBeBanished);
    int castIllusions(int numIllusions = 1);
};

Priestess::Priestess() :
favoriteFood("Salad"),
leastFavoriteThing("Bad Smells"),
crystals(12),
illusions(20),
home("Tree house")
{
    std::cout << "CONSTRUCTING Priestess with " << crystals << " ctrystals"  << std::endl;
}

Priestess::~Priestess()
{
    std::cout << "Deconstructing Priestess" << std::endl;
}

int Priestess::castGrowSpell(int numPlants)
{
    for (int i = 0; i < crystals; ++ i)
    {
        ++numPlants;
    }
    std::cout << "Priestess casts grow and " << numPlants << " plants grow immediately" << std::endl;
    return numPlants;
}

std::string Priestess::castBanish(std::string thingToBeBanished)
{
    if (thingToBeBanished != leastFavoriteThing)
    {
        std::cout << "Priestess casts banish and " << thingToBeBanished << " are banished for 2 rounds" << std::endl;
        return "Priestess casts banish and " + thingToBeBanished + " are banished for 2 rounds";
    }
    std::cout << "Priestess casts banish and " << leastFavoriteThing << " are banished for 2 rounds" << std::endl;
    return "Priestess casts banish and " + leastFavoriteThing + " are banished for 2 rounds";
}

int Priestess::castIllusions(int numIllusions)
{
    int index = crystals;
    while (index > 0)
    {
        numIllusions *= 2;
        -- index;
    }
    std::cout << "Priestess casts Illusions and " << numIllusions << " illusions appear instantly" << std::endl;
    return numIllusions;
}
/*
 new UDT 4:
 */
 struct Thief 
 {
     Thief();
     ~Thief();
     int tools;
     std::string guild;
     bool secretLanguage;
     double speed = 33.50;
     struct Techniques 
     {
         Techniques(std::string main);
         ~Techniques();
         std::string main = "sneak";
         std::string second = "climb";
         std::string third = "back stab";
         std::string fourth = "pick pocket";
         std::string fifth = "read lips";
     };
     bool performCartwheel(int dexterity = 13);
     bool smoothTalk();
     float steal(float amount = 50.00f);
 };

 Thief::Thief() :
 tools(15),
 guild("Secret"),
 secretLanguage(true)
 {
     std::cout << "CONSTRUCTING Thief with " << guild << " guild" << std::endl;
 }

 Thief::~Thief()
 {
     std::cout << "DECONSTRUCTING Thief" << std::endl;
 }

bool Thief::performCartwheel(int dexterity)
{
    if (dexterity >= 13  )
    {
        std::cout << "Thief performs cartwheels no problem" << std::endl;
        return true;
    }
    std::cout << "Thief fails to perform a carwheel and is vulnerable to insults for 2 rounds" << std::endl;
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
    if (randomNum() > 11)
    {
        std::cout << "Theif smooth talks effectively" << std::endl;
        return true;
    }
    std::cout << "Theif thinks he's so smooth but is not" << std::endl;
    return false;
}

float Thief::steal(float amount)
{
    if (randomNum() > 10)
    {
        std::cout << "Theif steals amount of " << amount << std::endl;
        return amount; 
    }
    std::cout << "Theif gets caught red handed trying to steal and amount of " << amount << std::endl;
    return amount;
}

/*
 new UDT 5:
 */
struct Bard 
{
    Bard();
    ~Bard();
    std::string instrument;
    bool sings = true;
    bool loud = true;
    std::string bestAsset = "Looks";
    int songs = 99;
    double beautyRest(double time = 12.00);
    std::string playMusic(std::string nameOfSong = "Did it all myself");
    float jump(float howHigh = 6.0f);
};
Bard::Bard() :
instrument("Lute")
{
    std::cout << "CONSTRUCTING Bard with " << Bard::instrument << std::endl;
}

Bard::~Bard()
{
    std::cout << "DECONSTRUCTING Bard " << std::endl;
}

double Bard::beautyRest(double time)
{
    std::cout << "Bard gets needed beauty rest for " << time << " hours." << std::endl;
    return time;
}

std::string Bard::playMusic(std::string nameOfSong)
{
    std::cout << "Bard plays " << nameOfSong << std::endl;
    return nameOfSong;
}

float Bard::jump(float howHigh)
{
    std::cout << "Bard jumps " << howHigh << " feet" << std::endl;
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
    std::cout << "Haha! Fizban of " << Fizban.age << " years boofed you!" << std::endl;
    Fighter Mooky;
    Mooky.fight("mace");
    Mooky.block(66);
    Mooky.drink(11);
    std::cout << "Haha! Mooky with the signet " << Mooky.signet << " gets dragged off by gnomes" << std::endl;
    Priestess Pearl;
    Pearl.castGrowSpell(7);
    Pearl.castBanish("Bad Smells");
    Pearl.castIllusions(7);
    Thief Smarkles;
    Smarkles.performCartwheel(13);
    Smarkles.smoothTalk();
    Smarkles.steal(100.00f);
    Bard Fabio;
    Fabio.beautyRest();
    Fabio.playMusic();
    Fabio.jump(5.0f);
    Wizard Barth;
    Fighter Marmy;
    Priestess Periwinkle;
    Thief Sammy;
    Bard Ahsia;
    std::cout << "good to go!" << std::endl;
}
