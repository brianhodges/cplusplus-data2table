#include <iostream>
using namespace std;

class Country {
    public:
        string name, population;
        void set_values(string, string);
};

void Country::set_values(string n, string p) {
    name = n;
    population = p;
}

int main(int argc, const char * argv[]) {
    Country c1;
    c1.set_values("USA", "350 million");
    
    Country c2;
    c2.set_values("China", "1.4 billion");
    
    Country c3;
    c3.set_values("Russia", "145 million");
    
    const string header = "Countries | Population";
    const string field = "Countries ";
    Country countries[3] = {c1, c2, c3};
    
    cout << endl;
    cout << "SANITIZED DUMP:" << endl;
    for (int i = 0; i < sizeof(countries)/sizeof(countries[0]); i++) {
        cout << " { :name => " << countries[i].name << ", :population => " << countries[i].population << " } " << endl;
    }
    
    cout << endl;
    cout << "TABLE:" << endl;
    cout << header << endl;
    cout << string(header.size(), '-') << endl;
    for (int i = 0; i < sizeof(countries)/sizeof(countries[0]); i++) {
        int ws = field.size() - countries[i].name.size();
        cout << countries[i].name << string(ws, ' ') << "|" << countries[i].population << endl;
    }
    cout << endl;
    return 0;
}