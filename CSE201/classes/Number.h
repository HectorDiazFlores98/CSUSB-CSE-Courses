
 /*--------------------------------------|
 |Number        //Name of Class         |
 |--------------------------------------|
 |-number: int                          |
 |--------------------------------------|
 |+input: int                           |
 |+isPrime: bool                        |
 |+diviser: int                         |
 |+isdivisibleby(diviser): bool         |
 |
  --------------------------------------*/

class Number
{
    public:
        Number(int input);
        bool isPrime(void);
        bool isDivisibleBy(int diviser);
    
    private:
        int number;
};

