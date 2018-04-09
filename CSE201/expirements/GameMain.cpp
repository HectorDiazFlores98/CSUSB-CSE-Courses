#include <iostream>
#include "Skeleton.h"
#include "Hero.h"
#include <string>
using namespace std;

int main()
{
    Skeleton Badguy1;
    Badguy1.attack = 2;
    Badguy1.defence =1;
    
    Hero DefaultHero;
    
    
    int TotalPoints = 5;
    
    while(TotalPoints > 0)
    {
        cout << "You have 5 points to distribute to attack and defence, choose wisely\n";
        cout << "Attack: ";
        int AttackPoints = 0;
        cin >> AttackPoints;
        
        while(AttackPoints > TotalPoints)
        {
            cout << "Error, you only have a max of " << TotalPoints << " left to distribute\n";
            cout << "Attack: ";
            cin >> AttackPoints;
        }
        
        TotalPoints = TotalPoints - AttackPoints;
        int DefencePoints = TotalPoints;
        
        cout << "\nThat means you have " << DefencePoints << " in defence\n\n";
        
        DefaultHero.SetHeroStrength(AttackPoints);
        DefaultHero.SetHeroDefence(DefencePoints);
        
        TotalPoints = 0;
        }
    
    cout << "Name your hero: ";
        string HeroName;
        cin >> HeroName;
        cout <<"\n";
        
    DefaultHero.SetHeroName(HeroName);
    
    DefaultHero.CharacterOverview();
        

}