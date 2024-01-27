#include <vector>
using namespace std;

vector<int> randomGen(int len){
    vector<int> r;
    int x = len;
    for(int i=0; i<len; i++){
        r.push_back(x);
        x--;
    }
    return r;
}