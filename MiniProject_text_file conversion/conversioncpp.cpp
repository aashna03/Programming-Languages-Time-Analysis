#include <iostream>
#include <fstream>
#include <cctype>
#include <chrono>
#include <string>
#include<vector>

using namespace std;

int main() {
    vector<long long> time_taken; 
      ofstream file1;
      file1.open ("output.csv", ios::out | ios::app);
    for(int i = 200; i <= 1000; i+=200 ){
        string filename = "_"+to_string(i)+".txt";
        fstream file(filename, ios::in | ios::out);
        char ch;
        auto start = std::chrono::high_resolution_clock::now();
        while (file.get(ch)) {
            file.seekp(-1, ios::cur); 
            file.put(toupper(ch)); 
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
      file1 << duration.count() << ",\n";
      cout << duration.count() << ",\n";

        cout << endl;
    }
      file1.close();



    return 0;
}
