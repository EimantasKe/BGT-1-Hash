#include <iostream>// getline
#include <fstream> // ifstream, ofstreamm, eof, is_open, close
#include <string>  // append, length, substr, c_str
#include <sstream> // stringstream
#include <cstring> // strcmp
#include <cstdlib> // atoi
#include <iomanip> // setprecision

using namespace std;

string hash_function(string input);
string hextobin(string s);

void test_one_file(string file1); //data4
void test_two_files(string file1, string file2); //data1a, data1b, data2a, data2b, data3a, data3b
void test5(string file); //data5
void test6(string file); //data6
void konstitucija(string file); //konstitucija.txt

int main(int argc, char* argv[])
{
    string input;
    int choice;
    if(argc==1){
        cout<<"Pasirinkimai: "<<endl;
        cout<<"1. Testas '1' - 2 failai po viena simboli"<<endl;
        cout<<"2. Testas '2' - 2 failai po 100,000 simboliu "<<endl;
        cout<<"3. Testas '3' - 2 failai po 100,000 simboliu, bet skiriasi tik 1 simboliu"<<endl;
        cout<<"4. Testas '4' - tuscias failas (jei neveikia, failas pradingo)"<<endl;
        cout<<"5. Testas '5' - tikrinamos 100,000 poru"<<endl;
        cout<<"6. Testas '6' - tikrinamos 200,000 poru, kurios skiriasi 1 simboliu"<<endl;
        cout<<"7. Testas 'Konstitucija' - nuskaitomas konstitucija.txt failas (greiti matuot paduodant tiesiai i argumenta)"<<endl;
        cout<<"8. Irasyti savo teksto eilute"<<endl;
        cout<<"---------"<<endl;
        cout<<"Pasirinkimas: ";
        cin>>choice;
        cout<<"---------"<<endl;
        switch(choice){
            case 1:
                cout<<"Testas 1:"<<endl<<endl;
                test_two_files("data1a.txt","data1b.txt");
                break;
            case 2:
                cout<<"Testas 2:"<<endl<<endl;
                test_two_files("data2a.txt","data2b.txt");
                break;
            case 3:
                cout<<"Testas 3:"<<endl<<endl;
                test_two_files("data3a.txt","data3b.txt");
                break;
            case 4:
                cout<<"Testas 4:"<<endl<<endl;
                test_one_file("data4.txt");
                break;
            case 5:
                cout<<"Testas 5:"<<endl<<endl;
                test5("data5.txt");
                break;
            case 6:
                cout<<"Testas 6:"<<endl<<endl;
                test6("data6.txt");
                break;
            case 7:
                cout<<"Testas 'Konstitucija':"<<endl<<endl;
                konstitucija("konstitucija.txt");
                break;
            case 8:
                cout<<"Sava ivestis:"<<endl<<endl;
                cout<<"Input: ";
                cin>>input;
                cout<<"Output: "<<hash_function(input)<<endl;
                break;
            default:
                cin>>input;
        }
    }else if(argc==2){
        if(strcmp("data5.txt",argv[1])==0){
            test5("data5.txt");
        }else if(strcmp("konstitucija.txt",argv[1])==0){
            konstitucija("konstitucija.txt");
        }else if(strcmp("data6.txt",argv[1])==0){
            test6("data6.txt");
        }else{
            test_one_file(argv[1]);
        }
    }else if(argc==3){
        test_two_files(argv[1],argv[2]);
    }
}

string hash_function(string input){

    string salt1 = "C7QrTgOOWGo5sC1PGnOo9rDYdzpr5x7aGfzrl5fy";
    string salt2 = "l2Kx9uBxoZEIewzdydZUle4HIrDy2koMa7ct3HZk";
    string pepper1 = "19cdb0ac0e84885e2c6d6787b17f385836e4b086";
    string pepper2 = "1a8ad21a46d83817fb2ad912676e8b0817fddb5b";
    string output="";
    int output_array[20];
    int pepper1_array[20]; //nebutina
    int pepper2_array[20]; //nebutina
    int I; //pozicija output_array

    //pridedami salts
    input.append(salt1);
    input=salt2.append(input);

    int string_length = input.length();

    //aspkaiciuojama string value
    int string_value=0;
    for(int i = 0; i < string_length; i++){
        string_value+=int(input[i]);
    }

    //sudaramos pradinis output array
    for(int i = 0; i < 20; i++){
        pepper1_array[i]=atoi((pepper1.substr(38-i*2,2)).c_str());
        pepper2_array[i]=atoi((pepper2.substr(38-i*2,2)).c_str());
        output_array[i]=(((pepper1_array[i] * string_length)%128) + ((pepper2_array[i]*string_value)%128))%256;
    }

    //main hash
    for(int i = 0; i < string_length; i++){
        I=i%20;
        //bit overlap = 113.1(~70-30 split) -- 0 collisions (out of 100,000 pairs)
        //output_array[I]=(output_array[I]+(unsigned int)input[i])%256;

        //bit overlap = 113.2(~70-30 split) -- 0 collisions (out of 100,000 pairs)
        //output_array[I]=(output_array[I]+((unsigned int)input[i]+25)*2)%256;

        //bit overlap = 90.69 (~55-45 split) -- 36 collisions (out of 100,000 pairs)
        //output_array[I]=(output_array[I]*string_value+((unsigned int)input[i]+string_value))%256;

        //bit overlap = 90.73(~55-45 split) -- 0 collisions (out of 100,000pairs)
        output_array[I]=(output_array[I]+(unsigned int)input[i]*string_value)%256;
    }

    // output_array -> output
    // int[] -> string
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

//hex skaicius verciamas i binary
string hextobin(string s){
    string out;
    char n;
    int string_length = s.length();
    for(int i = 0; i < string_length;i++){
        if((s[i] <= '9') && (s[i] >= '0')){
            n = s[i] - '0';
        }else{
            n = 10 + s[i] - 'A';
        }

        for(char j = 4; j > 0; --j){
            if(n&(1<<(j-1))){
                out.append("1");
            }else{
                out.append("0");
            }
        }
    }
        return out;
}

void test5(string file){
    ifstream ifile(file);
    string string1,string2;
    int identical_pair_count = 0;
    while (!ifile.eof()) {
        getline(ifile,string1);
        getline(ifile,string2);

        if(hash_function(string1).compare(hash_function(string2))==0){
            cout<<endl<<string1<<endl<<string2<<endl;
            cout<<hash_function(string1)<<endl<<hash_function(string2)<<endl;
            identical_pair_count += 1;
        }
    }
    cout<<"Sutampa "<< identical_pair_count << " poru"<<endl;
    ifile.close();
}

void konstitucija(string file){
    ifstream ifile(file);
    string string1;
    while (!ifile.eof()) {
        getline(ifile,string1);
            cout<<hash_function(string1)<<endl;
    }
    ifile.close();
}

void test6(string file){
    ifstream ifile(file);
    string string1, string2, string1h, string2h, string1b,string2b, string3b, string4b;
    int overlapping_bits=0;
    float total_overlapping_bits=0;
    int max_overlap=0;
    int min_overlap=160;

    while (!ifile.eof()) {
        overlapping_bits=0;
        getline(ifile,string1);
        getline(ifile,string2);

        string1h = hash_function(string1);
        string2h = hash_function(string2);

        string1b = hextobin(string1h);
        string2b = hextobin(string2h);

        for(int i = 0; i < 160; i++){ //string1b.length == 20 x 4?
            if(string1b[i]==string2b[i]){
                overlapping_bits++;
            }
        }
        if(overlapping_bits>max_overlap){
            max_overlap=overlapping_bits;
        }
        if(overlapping_bits<min_overlap){
            min_overlap=overlapping_bits;
        }
        total_overlapping_bits+=overlapping_bits;
    }
    cout<<"Didziausias overlap: "<<max_overlap<<endl;
    cout<<"Maziausias overlap: "<<min_overlap<<endl;
    cout<<"Average overlapping bits: "<<setprecision(4)<< total_overlapping_bits/200000<<endl;
    ifile.close();
}

void test_one_file(string file1){
    ifstream ifile(file1);
    string string1;
    getline(ifile,string1);
    cout<<"Input: "<<string1<<endl;
    cout<<"Output: "<<hash_function(string1)<<endl;
    ifile.close();
}

void test_two_files(string file1, string file2){
        string string1;
        string string2;
        ifstream ifile(file1);
        ifstream i2file(file2);
        getline(ifile,string1);
        getline(i2file,string2);
        cout<<"Input1: "<<string1<<endl;
        cout<<"Input2: "<<string2<<endl;
        cout<<"Output1: "<<hash_function(string1)<<endl;
        cout<<"Output2: "<<hash_function(string2)<<endl;

        if(strcmp(hash_function(string1).c_str(),hash_function(string2).c_str())==0){
            cout<<"Sutampa"<<endl;
        }else{
            cout<<"Nesutampa"<<endl;
        }
        ifile.close();
        i2file.close();
}
