// Mehek Ghattora
// 12.02.2024
// How to calculate a home's value

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// function to calculate the housing PE
double getHousingPE(int homePrice, int monthlyRent) {
    double annualRent = monthlyRent * 12;
    return static_cast<double>(homePrice) / annualRent;
}

int main()
{
    //declare size of arrays
    const int size = 100;
    int homePrice[size];
    int homeRent[size];
    
    ifstream inFile;
	string fileName;
	
	//read file name from input
	cout<<"Please enter in the file name"<<endl;
	cin >> fileName;
	
	//open file
	inFile.open(fileName);
	
	//prints to screen if file does not open
	if(!inFile.is_open())
	{
		cout<<"error opening the file for input"<<endl;
		return -1;
	}
	
	// start at index 0
	int index = 0;
	
	// while loop to read values from text file and input into corresponding arrays
	while(inFile >> homePrice[index] >> homeRent[index]) {
		index++;
		
		if(index >= size) {
		    break;
		}
		
	}
	
	//close file
	inFile.close();
	
	//for loop to calculate housing PE and output is based on PE ratio
	for (int i = 0; i < index ; ++i) {
	    double ratioPE = getHousingPE(homePrice[i], homeRent[i]);
	    
	    cout << fixed << setprecision(2); 
        cout << "House #" << (i + 1) << " P/E Ratio: " << ratioPE << " -> ";

        if (ratioPE > 19) {
            cout << "House #" << (i + 1) << " is way overpriced." << endl;
        } else if (ratioPE > 16) {
            cout << "House #" << (i + 1) << " is somewhat overpriced." << endl;
        } else if (ratioPE < 9) {
            cout << "Buy House #" << (i + 1) << ", it is a deal." << endl;
        } else if (ratioPE < 12) {
            cout << "House #" << (i + 1) << " might be a good deal." << endl;
        } else {
            cout << "House #" << (i + 1) << " is average." << endl;
        }
	    
	}
	
	return 0;
	
}