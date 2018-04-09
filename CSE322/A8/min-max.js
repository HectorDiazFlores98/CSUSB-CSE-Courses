//declare class
class MinMax 
{
    //declare constructor
    constructor(numbers) 
    {
        //set this numbers = to numbers
        this.numbers = numbers;
        this.maxVar = this.numbers[0];
        this.minVar=this.numbers[0];
        
    }
    
    //Declare the find min and max functions
    findMinMax()
    {
        for(let i = 0; i <= this.numbers.length; i++)
        {
            if(this.maxVar<=this.numbers[i])
            {
                this.maxVar=this.numbers[i];
            }
            else if(this.minVar>=this.numbers[i])
            {
                this.minVar=this.numbers[i];
                
            }
        }
            console.log('The Min Value: '+this.minVar);
            console.log('The Max Value: '+this.maxVar);
    }
    
    removeMax()
    {
        let indexofMax = this.numbers.indexOf(this.maxVar);
        this.numbers.splice(indexofMax,1);
        console.log("Removing the Max value: "+this.maxVar);
    }
      
          
}

const testArray = new MinMax([3,9,0,1,7,9]);

testArray.findMinMax();
console.log(testArray);
testArray.removeMax();