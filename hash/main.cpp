#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>


using namespace std;

string hash_function(string input);

int main(int argc, char* argv[])
{
    string input;
    string output;

    if(argc==1){
        cin>>input;
        cout<<"Input: "<<input<<endl;
        cout<<"Output: "<<hash_function(input)<<endl;
    }else if(argc==2){
        string string1;
        string string2;
        ifstream ifile(argv[1]);

        if (ifile.is_open()) {
            if(strcmp("data5.txt",argv[1])==0){
                int identical_pair_count = 0;
                while (!ifile.eof()) {
                    getline(ifile,string1);
                    getline(ifile,string2);
                    /*cout<<endl<<string1<<endl<<string2<<endl;
                    cout<<hash_function(string1)<<endl<<hash_function(string2)<<endl;*/

                    if(hash_function(string1).compare(hash_function(string2))==0){
                        identical_pair_count += 1;
                    }
                }
                cout<<"Sutampa "<< identical_pair_count << " poru"<<endl;
            }else if(strcmp("konstitucija.txt",argv[1])==0){
                while (!ifile.eof()) {
                    getline(ifile,string1);
                    cout<<hash_function(string1)<<endl;
                }
            }else{
                getline(ifile,string1);
                cout<<"Input: "<<string1<<endl;
                cout<<"Output: "<<hash_function(string1)<<endl;
            }
        }

        ifile.close();
    }else if(argc==3){
        string strings[argc];
        ifstream ifile(argv[1]);
        ifstream i2file(argv[2]);

        getline(ifile,strings[0]);
        getline(i2file,strings[1]);
        cout<<"Input1: "<<strings[0]<<endl;
        cout<<"Input2: "<<strings[1]<<endl;
        cout<<"Output1: "<<hash_function(strings[0])<<endl;
        cout<<"Output2: "<<hash_function(strings[1])<<endl;

        if(strcmp(hash_function(strings[0]).c_str(),hash_function(strings[1]).c_str())==0){
            cout<<"Sutampa"<<endl;
        }else{
            cout<<"Nesutampa"<<endl;
        }

        ifile.close();
        i2file.close();
    }
}

string hash_function(string input){

    string salt1 = "C7QrTgOOWGo5sC1PGnOo9rDYdzpr5x7aGfzrl5fy";
    string salt2 = "l2Kx9uBxoZEIewzdydZUle4HIrDy2koMa7ct3HZk";
    string pepper1 = "19cdb0ac0e84885e2c6d6787b17f385836e4b086";
    string pepper2 = "1a8ad21a46d83817fb2ad912676e8b0817fddb5b";
    string output="";
    int output_array[20];
    int pepper1_array[20];
    int pepper2_array[20];
    int I;
    input.append(salt1);
    input=salt2.append(input);
    int string_length = input.length();
    int string_value=0;

    for(int i = 0; i < string_length; i++){
        string_value+=int(input[i]);
    }

    for(int i = 0; i < 20; i++){
        pepper1_array[i]=atoi((pepper1.substr(38-i*2,2)).c_str());
        pepper2_array[i]=atoi((pepper2.substr(38-i*2,2)).c_str());
        output_array[i]=(((pepper1_array[i] * string_length)%128) + ((pepper2_array[i]*string_value)%128))%256;
    }

    for(int i = 0; i < string_length; i++){
        I=i%20;
        output_array[I]=(output_array[I]+(unsigned int)input[i])%256;
    }

    stringstream sstream;
    for(int i = 0; i < 20; i++){
            if(output_array[i]<0x10){
                sstream << std::hex <<0<<output_array[i];
            }else{
                sstream << std::hex << output_array[i];
            }
    }
    output= sstream.str();
    return output;
}
