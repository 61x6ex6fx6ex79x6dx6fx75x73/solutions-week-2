#include <iostream>
#include <vector>
#include <cmath>


std::vector<std::vector<int>> allThePos;
bool solveForN(std::vector<std::vector<int>> allLimbs, int column, int n);

int main(){

	// welcome ^_^
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> allLimbs;
	
	bool leAns = solveForN(allLimbs, 0, n);



}

bool contained(std::vector<int> thisThing, std::vector<std::vector<int>> inThis){


	for (int i = 0; i < inThis.size(); ++i)
	{
		if(inThis[i] == thisThing){
			return true;
		}
	}
	return false;
}

bool touching(std::vector<std::vector<int>> limits, int x, int y){

	for (int i = 0; i < limits.size(); ++i)
	{	
		// if a queen is on the same x line
		if (limits[i][0] == x){
			return true;
		}
		if(limits[i][1] == y){
			return true;
		}
		if(std::abs(limits[i][1] - y) == std::abs(limits[i][0] - x)){
			return true;
		}
	}
	return false;
}



// why are you reading the comments?
bool solveForN(std::vector<std::vector<int>> allLimbs, int column, int n){

	// globals suck! imagine trying to handle all that like ... just make a pointer 
	static int thisIsTheAnswerToEverything = 0;


	if (column == n)
    {
    	thisIsTheAnswerToEverything+=1;
    	std::cout << thisIsTheAnswerToEverything << "\n";
    	return true;
   	}



	bool nopeNotHere = false;
	for (int i = 0; i < n; i++)
    {

    	if(!touching(allLimbs, column, i)){

    		std::vector<int> lim = {column, i};
    		std::vector<std::vector<int>> allLimbs2 = allLimbs;
    		allLimbs2.push_back(lim);

    		nopeNotHere = solveForN(allLimbs2, column + 1, n) || nopeNotHere;


    	}


    }
    return nopeNotHere;
}
