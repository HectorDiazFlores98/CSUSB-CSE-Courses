using namespace std;
class Hero
{
    public:
    
    void SetHeroName(string HeroName)
    {
        this->HeroName = HeroName;
    }

    void SetHeroStrength(int HeroStrength)
    {
        this->HeroStrength = HeroStrength;
    }
    
    void SetHeroDefence(int HeroDefence)
    {
        this->HeroDefence = HeroDefence;
    }
    
    void CharacterOverview()
    {
        cout << "Character Overview:\n" << "Name: " << HeroName << "\nStrength: " << HeroStrength << "\nDefence: " << HeroDefence;
        cout << "\n\n";
    }
    
    private:
        string HeroName;
        int HeroStrength;
        int HeroDefence;
};