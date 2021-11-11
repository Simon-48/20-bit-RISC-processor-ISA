#include <bits/stdc++.h>

using namespace std;

#define checkBit(n,p) (bool)(n&(1<<p))



map<string,string> getMap(string path)
{
    string word,value;
    map<string,string> m;
    ifstream file(path);
    while(file>>word>>value)
    {
        m[word] = value;
    }
    file.close();
    return m;
}

string decToBin(int num,int length)
{
    string result = "";
    for(int i=0;i<length;i++)
    {
        if(checkBit(num,i))
        {
            result = "1" + result;
        }
        else
        {
            result = "0" + result;
        }
    }
    return result;
}

int main()
{

    int val;
    string ins,op,r1,r2,r3,cmnt;
    map<string,string> R_TYPE,I_TYPE,J_TYPE,RegisterValue;
    //Obtaining static values from storage
    R_TYPE = getMap("File/R_TYPE.txt");
    I_TYPE = getMap("File/I_TYPE.txt");
    J_TYPE = getMap("File/J_TYPE.txt");
    RegisterValue = getMap("File/RegisterValue.txt");
    ifstream inputFile("File/input.txt");

    ofstream outputFile("File/output.txt");
    while(getline(inputFile,ins))
    {
        stringstream ss;
        cout << ins << endl;
        //Checking if instruction is empty or not
        if(ins.size()==0)
        {
            cout << "Invalid: Instruction is empty" << endl;
            outputFile << "Invalid: Instruction is empty" << endl;
            continue;
        }
        ss << ins;
        ss >> op;
        //If operation code is J Type then the program will go in here
        if(J_TYPE.find(op)!=J_TYPE.end())
        {
            val = -1;
            ss >> val;
            if(val<0)
            {
                val -= 10;
            }
            val = ceil(val/4.0);
            //Checking instruction validities
            if(val<0)
            {
                cout << "invalid: value can not be neg" << endl;
                outputFile << "invalid: value can not be neg" << endl;
            }
            else if(val>67108869)
            {
                cout << "invalid: value is too large" << endl;
                outputFile << "invalid: value is too large" << endl;
            }


            else if(ss>>cmnt&&(cmnt[0]!='/'||cmnt[1]!='/'))
            {
            	cout << "Invalid: comment structure not maintained" << endl;
            	outputFile << "Invalid: comment structure not maintained" << endl;
            }


            //Printing machine code
            else
            {
                cout << J_TYPE[op] << " " << decToBin(val,19) << endl;
                outputFile << J_TYPE[op] << " " << decToBin(val,19) << endl;
            }
            continue;
        }


                ss >> r1;



           if(r1[0]!='$')
            {
                cout << "Invalid: '$' sign is missing before rd" << endl;
                outputFile << "Invalid: '$' sign is missing before rd" << endl;
               continue;
            }
           else if(r1[r1.size()-1]!=',')
            {
                cout << "Invalid: ',' is missing after rd" << endl;
                outputFile << "Invalid: ',' is missing after rd" << endl;
                continue;
            }
            r1.erase(r1.end()-1);



        //If operation code is R Type then the program will go in here
        if(R_TYPE.find(op)!=R_TYPE.end())
        {


        val = 0;

        ss >> r2;
                if(r2[0]!='$')
                {
                    cout << "Invalid: '$' sign is missing before rs" << endl;
                    outputFile << "Invalid: '$' sign is missing before rs" << endl;
                    continue;
                }
                else if(r2[r2.size()-1]!=',')
                {
                    cout << "Invalid: ',' is missing after rs" << endl;
                    outputFile << "Invalid: ',' is missing after rs" << endl;
                    continue;
                }
                r2.erase(r2.end()-1);

            ss >> r3;
            if(r3[0]!='$')
            {
                cout << "Invalid: '$' sign is missing before rt" << endl;
                outputFile << "Invalid: '$' sign is missing before rt" << endl;
                continue;
            }

            //Checking instruction validities
            print:
            if(r1=="$zero")
            {
                cout << "Invalid: $zero can not be used" << endl;
                outputFile << "Invalid: $zero can not be used" << endl;
            }
            else if(RegisterValue.find(r1)==RegisterValue.end())
            {
                cout << "Invalid: rd not found" << endl;
                outputFile << "Invalid: rd not found" << endl;
            }
            else if(RegisterValue.find(r2)==RegisterValue.end())
            {
                cout << "Invalid: rs not found" << endl;
                outputFile << "Invalid: rs not found" << endl;
            }

            else if(RegisterValue.find(r3)==RegisterValue.end())
            {
                cout << "Invalid: rt not found" << endl;
                outputFile << "Invalid: rt not found" << endl;
            }

            else if(val<0)
            {
                cout << "Invalid: value can not be neg" << endl;
                outputFile << "Invalid: value can not be neg" << endl;
            }
            else if(val>31)
            {
                cout << "Invalid: value is too large" << endl;
                outputFile << "Invalid: value is too large" << endl;
            }

            else if(ss>>cmnt&&(cmnt[0]!='/'||cmnt[1]!='/'))
            {
            	cout << "Invalid: comment structure not maintained" << endl;
            	outputFile << "Invalid: comment structure not maintained" << endl;
            }


            //Printing machine code if instruction is valid
            else
            {
                cout << R_TYPE[op] << " " << RegisterValue[r1] << " " << RegisterValue[r2] << " " << RegisterValue[r3] << " " << decToBin(val,4) << " " << decToBin(val,4) << endl;
                outputFile << R_TYPE[op] << " " << RegisterValue[r1] << " " << RegisterValue[r2] << " " << RegisterValue[r3] << " " << decToBin(val,4) << " " << decToBin(val,4) << endl;
            }
        }
        //If operation code is I Type then the program will go in here
        else if(I_TYPE.find(op)!=I_TYPE.end())
        {

        		ss >> r2 >> val;
        		if(r2[0]!='$')
                {
                    cout << "Invalid: '$' sign is missing before rs" << endl;
                    outputFile << "Invalid: '$' sign is missing before rs" << endl;
                    continue;
                }
                else if(r2[r2.size()-1]!=',')
                {
                    cout << "Invalid: ',' is missing after rs" << endl;
                    outputFile << "Invalid: ',' is missing after rs" << endl;
                    continue;
                }
        		r2.erase(r2.end()-1);
        		if(op=="addi")
        		{
        		    swap(r1,r2);
        		    if(r1=="$zero")
                    {
                        r1 = "";
                        cout << "Invalid: $zero can to be used" << endl;
                        outputFile << "Invalid: $zero can to be used" << endl;
                        continue;
                    }
        		}
        		else
        		{
        		    if(val<0)
                    {
                        val -= 10;
                    }
        			val = ceil(val/4.0);
        		}

        	//Checking instruction validities
            if(RegisterValue.find(r1)==RegisterValue.end())
            {
                cout << "Invalid: rd not found" << endl;
                outputFile << "Invalid: rd not found" << endl;
            }

            else if(RegisterValue.find(r2)==RegisterValue.end())
            {
                cout << "Invalid: rs not found" << endl;
                outputFile << "Invalid: rs not found" << endl;
            }

            else if(op!="addi"&&val<0)
            {
                cout << "Invalid: value can not be neg" << endl;
                outputFile << "Invalid: value can not be neg" << endl;
            }
            else if(val>32767)
            {
                cout << "Invalid: value is too large" << endl;
                outputFile << "Invalid: value is too large" << endl;
            }
            else if(val<-32768)
            {
                cout << "Invalid: value is too small" << endl;
                outputFile << "Invalid: value is too small" << endl;
            }


            else if(ss>>cmnt&&(cmnt[0]!='/'||cmnt[1]!='/'))
            {
            	cout << "Invalid: comment structure not maintained" << endl;
            	outputFile << "Invalid: comment structure not maintained" << endl;
            }

            //Printing machine code if instruction is valid
            else
            {
            	cout << I_TYPE[op] << " " << RegisterValue[r1] << " " << RegisterValue[r2] << " " << decToBin(val,12) << endl;
            	outputFile << I_TYPE[op] << " " << RegisterValue[r1] << " " << RegisterValue[r2] << " " << decToBin(val,12) << endl;
            }
        }


           else
           {
               cout << "Invalid: Op code not found" << endl;
        	   outputFile << "Invalid: Op code not found" << endl;
           }

    }
    inputFile.close();
}
