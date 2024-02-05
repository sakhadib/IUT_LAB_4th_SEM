//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;

#include <bits/stdc++.h>
using namespace std;


int validate(string s){
    bool valid = false;
    if(s[0] == 'I' && s[1] == 'U' && s[2] == 'T'){
        if(s[5] == 'D' && s[6] == 'H' && s[7] == 'A'){
            if(s[21] == 'D' && s[22] == 'H' && s[23] == 'A'){
                
            }
        }
    }
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    string iut;
    string hsc_board;
    int hsc_roll;
    int hsc_year;
    string ssc_board;
    int ssc_roll;
    int ssc_year;
    
    cin >> iut >> hsc_board >> hsc_roll >> hsc_year >> ssc_board >> ssc_roll >> ssc_year;

    string s = iut + " " + hsc_board + " " + to_string(hsc_roll) + " " + to_string(hsc_year) + " " + ssc_board + " " + to_string(ssc_roll) + " " + to_string(ssc_year);


    cout << s;


    
    return 0;
}