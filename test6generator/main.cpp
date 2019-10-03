#include <iostream>
#include <fstream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <string>
using namespace std;

int main()
{
    ifstream ifile("data5.txt");
    ofstream ofile("data6.txt");
    int n;
    int c;
    string string1, string2;
    bool randomized;
    srand(time(0));
    if (ifile.is_open()) {
        while (!ifile.eof()) {
            getline(ifile,string1);
            ofile<<string1<<endl;

            randomized = false;
            while(randomized==false){
                n = rand()%string1.length();
                c = rand() % 52;
                if(c<26 &&!(string1[n]==(char)(65 + c))){
                    randomized =true;
                }else if(!string1[n]==(char)(97 + c)){
                    randomized=true;;
                }
            }
            if(c<26){
                 string1[n] = (char)(65 + c);
            }else{
                string1[n] =  (char)(97 + c);
            }
            ofile<<string1<<endl;
        }
        }
        ifile.close();
        ofile.close();
}
