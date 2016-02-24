/**********************************************************************
 *
 * Author:      sugarfreeoh
 * Date:        2016 Feb 23
 * File name:   SplitTheNumber.cpp
 * Description: You are given a number N and a pattern. The pattern
 *              consists of lowercase latin letters and one operation
 *              "+" or "-". The challenge is to split the number and
 *              evaluate it according to the following pattern:
 *              1232 ab+cd -> a:1, b:2, c:3, d:2 -> 12 + 32 -> 44
 *********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int StringToInt(string val);

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile, line))
        {
            stringstream lineStream;
            string lhs;
            string rhs;
            string numbers;
            string operation;

            size_t delimiterLocation;
            size_t operationLocation;

            char del = ' ';
            char plus = '+';
            char minus = '-';

            bool add = false;
            //bool subtract = false;

            int first;
            int second;

            int result;

            //cout << line << endl;

            //find where the numbers end and the operation sequence begins
            delimiterLocation = line.find(del);
            
            //the numbers
            numbers = line.substr(0,delimiterLocation);

            //the operation sequence. a + or a - will be in here somewhere
            operation = line.substr(delimiterLocation+1, line.size()-delimiterLocation-1);

            //cout << "Numbers: " << numbers << endl;
            //cout << "Operation: " << operation << endl;

            //find the + or -
            operationLocation = operation.find(plus);

            if(operationLocation == string::npos)
            {
                operationLocation = operation.find(minus);

                if(operationLocation != string::npos)
                {
                    //cout << "Minus operation at: " << operationLocation << endl;
                    //subtract = true;
                }
            }
            else
            {
                //cout << "Plus operation at: " << operationLocation << endl;
                add = true;
            }

            //pull out the numbers to the left and right of where the operation character is at
            lhs = numbers.substr(0,operationLocation);
            rhs = numbers.substr(operationLocation,numbers.size()-operationLocation);   

            //cout << "LHS: " << lhs << endl;
            //cout << "RHS: " << rhs << endl;

            first = StringToInt(lhs);
            second = StringToInt(rhs);

            //cout << "First: " << first << endl;
            //cout << "Second: " << second << endl;

            if(add)
            {
                result = first + second;
            }
            else
            {
                result = first - second;
            }

            cout << result << endl;
        }
    }
    else
    {
        cout << "Error with input file" << endl;
    }

    return 0;
}

int StringToInt(string val)
{
    int result;

    stringstream valStream(val);

    valStream >> result;

    return result;
}
