#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string getPassword(int length) {
    string password = "";
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    
    // Seed random number generator
    srand(time(0));
    
    for(int i = 0; i < length; i++) {
        password += characters[rand() % characters.length()];
    }
    
    return password;
}

int main() {
    int length;
    
    cout << "Enter length of password: ";
    cin >> length;
    
    string password = getPassword(length);
    cout << "Generated Password: " << password << endl;
    
    return 0;
}