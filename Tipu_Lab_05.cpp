#include <iostream>
#include <vector>
using namespace std;

class Person
{
public:
    string name,birthday;
    Person() {};
    Person(string name,string birthday)
    {
        this->name=name;
        this->birthday=birthday;
    }
    void viewPerson()
    {
        cout<<"Name : "<<this->name<<endl;
        cout<<"Birthday : "<<this->birthday<<endl;
    }

};

class PlayerCategory
{
public:
    string category;
    PlayerCategory() {};
    PlayerCategory(string category)
    {
        this->category=category;
    }
    void viewPlayerCategory()
    {
        cout<<"Player Category : "<<this->category<<endl;
    }
};

class Player : public Person
{
public:
    PlayerCategory category;
    int noOfMatchesPlayed,noOfRunsScored,noOfWicketsTaken;
    Player() {};
    Player(string name,string birthday,PlayerCategory category,int noOfMatchesPlayed,int noOfRunsScored,int noOfWicketsTaken) : Person(name,birthday)
    {
        this->category=category;
        this->noOfRunsScored=noOfRunsScored;
        this->noOfWicketsTaken=noOfWicketsTaken;
    }

    void viewPlayer()
    {
        viewPerson();
        category.viewPlayerCategory();
        cout<<"Birthday : "<<this->birthday<<endl;
        cout<<"Runs Scored : "<<this->noOfRunsScored<<endl;
        cout<<"Wickets Taken : "<<this->noOfWicketsTaken<<endl;
    }

    string getCategory()
    {
        return category.category;
    }

    int getBirthday()
    {
        int sum=0;
        for(int i=birthday.length()-4; i<birthday.length(); i++)
        {
            sum*=10;
            sum+=(birthday[i]-48);
        }
        return sum;
    }
};

class Coach : public Person
{
public:
    string country;
    Coach() {};
    Coach(string name, string birthday, string country) : Person(name,birthday)
    {
        this->country=country;
    }
    void viewCoach()
    {
        viewPerson();
        cout<<"Coach's Country : "<<this->country<<endl;
    }
};

int main()
{
    PlayerCategory *playerCategories[4]=
    {
        new PlayerCategory("Batsman"),
        new PlayerCategory("Fast Bowler"),
        new PlayerCategory("Spin Bowler"),
        new PlayerCategory("Wicket Keeper")
    };
    Player *players[16]=
    {
        new Player("Tamim Iqbal","12-02-1989",*playerCategories[0],230,12675,0),
        new Player("Shakib Al Hassan","04-12-1990",*playerCategories[2],245,9985,245),
        new Player("Mashrafee Bin Murtaza","19-07-1990",*playerCategories[1],290,3678,350),
        new Player("Mushfiqur Rahim","11-06-1988",*playerCategories[3],250,10775,10),
        new Player("Mahmudullah Riad","18-02-1989",*playerCategories[2],212,7890,120),
        new Player("Soumya Sarkar","02-02-1994",*playerCategories[0],86,4675,0),
        new Player("Nasir Hossain","13-11-1983",*playerCategories[0],120,4980,87),
        new Player("Sabbir Ahmed","16-04-1995",*playerCategories[0],65,2640,13),
        new Player("Rubel Hossain","09-11-1992",*playerCategories[1],180,1690,180),
        new Player("Taskin Ahmed","12-09-1996",*playerCategories[1],56,675,76),
        new Player("Taijul Islam","23-06-1997",*playerCategories[2],35,675,54),
        new Player("Abu Haider Rony","18-01-1996",*playerCategories[1],15,275,34),
        new Player("Nazmul Hassan Shanto","28-06-1997",*playerCategories[2],12,75,18),
        new Player("Mehedi Hasan Miraz","14-12-1996",*playerCategories[2],45,2675,37),
        new Player("Shafiul Islam","18-05-1992",*playerCategories[1],150,1875,135),
        new Player("Imrul Kayes","06-03-1990",*playerCategories[0],230,5870,0)
    };

    Coach *coach=
    {
        new Coach("Shaun Gabriel","11-03-1976","West Indies")
    };

    int batsmanCount=0,BowlerCount=0,WicketkeeperCount=0,greaterThan25=0;
    vector <int> selected;

    for(int i=0; i<16; i++)
    {
        int birthday= players[i]->getBirthday();
        birthday-=2018;
        if(players[i]->getCategory()=="Wicket Keeper" && WicketkeeperCount<1 && players[i]->noOfRunsScored>=4500)
        {
            if(greaterThan25<5 && birthday>=25)
            {
                WicketkeeperCount++;
                selected.push_back(i);
                greaterThan25++;
            }
            else if(birthday<25)
            {
                WicketkeeperCount++;
                selected.push_back(i);
            }

        }
        else if(players[i]->getCategory()=="Batsman" && batsmanCount<=6 && players[i]->noOfRunsScored>=200)
        {
            if(greaterThan25<5 && birthday>=25)
            {
                batsmanCount++;
                selected.push_back(i);
                greaterThan25++;
            }
            else if(birthday<25)
            {
                batsmanCount++;
                selected.push_back(i);
            }
        }
        else
        {
            if(players[i]->noOfWicketsTaken>=70 && BowlerCount<5)
            {
                if(greaterThan25<5 && birthday>=25)
                {
                    BowlerCount++;
                    selected.push_back(i);
                    greaterThan25++;
                }
                else if(birthday<25)
                {
                    BowlerCount++;
                    selected.push_back(i);
                }
            }
        }
    }
    cout<<"SELECTED PLAYERS LIST ACCORDING TO THEIR PERFORMANCE"<<endl<<endl;

    for(int i=0; i<selected.size(); i++)
    {
        cout<<i+1<<". "<<players[selected[i]]->name<<endl<<endl;
    }
}


