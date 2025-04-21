#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void getPassword(uint32_t length, char password[]) {
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    
    srand(time(0)); 
    
    for (uint32_t i = 0; i < length; i++) {
        password[i] = characters[rand() % (sizeof(characters) - 1)];
    }
    password[length] = '\0';  
}

int main() {
    uint32_t length;
    char password[100];
    
    printf("Enter password length: ");
    scanf("%u", &length);
    
    getPassword(length, password);  
    printf("Generated Password: %s\n", password);
    
    return 0;
}
