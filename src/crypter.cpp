#include <windows.h>
#include <stdio.h>
#include <iostream>

char* crypter(char* text, int key1, int key2, char* keychar1, char* keychar2, int selectedindex, int currentindex, BOOL encrypt, int crypterversion)
{
    switch (crypterversion)
    {
    case 45:
    {
        int index = 0;

        for (int i = 0; i < (strlen(text) + strlen(keychar1) + strlen(keychar2)); i++)
        {
            index++;
        }

        printf("\nCrypter ver0.4.5exdbgbld\n");
        printf("\nYou need enter or create key for security\nWrite they in safe place\nFormat of key looks like <1234567890 12345>\nDEBUG BUILD VERSION EX4.5");
        printf("\nPlease enter a string:\t");
        std::cout << text;
        printf("\nPlease choose following options:\n");
        printf("1 = Encrypt the string.\n");
        printf("2 = Decrypt the string.\n");
        std::cout << selectedindex << std::endl;
        printf("Create or Provide Exist Key:\n");
        std::cout << key1 << " " << key2;
        for (int i = 0; (i < 1024 && text[i] != '\0'); i++)
            text[i] = text[i] - key1 + key2 - 25 + 213 + 1 - 2 - key1 - index; // the key for encryption is 3 that is subtracted to ASCII value
        printf("\nYou Decrypted String!\n");
        printf("\nDecrypted string: %s\n", text);
        printf("\naddr %p | %p | %p", text, key2, key1);
        break;
    }

    case 4:
    {
        int index = 0;

        for (int i = 0; i < (strlen(text) + strlen(keychar1) + strlen(keychar2)); i++)
        {
            index++;
        }

        printf("\nCrypter ver0.4exdbgbld\n");
        printf("\nYou need enter or create key for security\nWrite they in safe place\nFormat of key looks like <1234567890 12345>\nDEBUG BUILD VERSION EX4");
        printf("\nPlease enter a string:\t");
        std::cout << text;
        printf("\nPlease choose following options:\n");
        printf("1 = Encrypt the string.\n");
        printf("2 = Decrypt the string.\n");
        std::cout << selectedindex << std::endl;
        printf("Create or Provide Exist Key:\n");
        std::cout << key1 << " " << key2;
        for (int i = 0; (i < 1024 && text[i] != '\0'); i++)
            text[i] = text[i] - key1 + key2 - 25 + 213 + 1 - 2 - key1 - index; // the key for encryption is 3 that is subtracted to ASCII value
        printf("\nYou Decrypted String!\n");
        printf("\nDecrypted string: %s\n", text);
        printf("\naddr %p | %p | %p", text, key2, key1);
        break;
    }

    case 3:
    {
        printf("\nCrypter ver0.3\n");
        printf("\nYou need enter or create key for security\nWrite they in safe place\nFormat of key looks like <1234567890 12345>\nDEBUG BUILD VERSION 3");
        printf("\nPlease enter a string:\t");
        std::cout << text;
        printf("\nPlease choose following options:\n");
        printf("1 = Encrypt the string.\n");
        printf("2 = Decrypt the string.\n");
        std::cout << selectedindex << std::endl;
        printf("Create or Provide Exist Key:\n");
        std::cout << key1 << " " << key2;
        for (int i = 0; (i < 1024 && text[i] != '\0'); i++)
            text[i] = text[i] - key1 + key2 - 25 + 213 + 1 - 2 - key1; // the key for encryption is 3 that is subtracted to ASCII value
        printf("\nYou Decrypted String!\n");
        printf("\nDecrypted string: %s\n", text);
        printf("\naddr %p | %p | %p", text, key2, key1);
        break;
    }

    case 2:
    {
        printf("\nCrypter ver0.2dbgbld\n");
        printf("\nYou need enter or create key for security\nWrite they in safe place\nFormat of key looks like <1234567890 12345>\nDEBUG BUILD VERSION 2");
        printf("\nPlease enter a string:\t");
        std::cout << text;
        printf("\nPlease choose following options:\n");
        printf("1 = Encrypt the string.\n");
        printf("2 = Decrypt the string.\n");
        std::cout << selectedindex << std::endl;
        printf("Create or Provide Exist Key:\n");
        std::cout << key1 << " " << key2;
        for (int i = 0; (i < 512 && text[i] != '\0'); i++)
            text[i] = text[i] - key1 + key2; // the key for encryption is 3 that is subtracted to ASCII value
        printf("\nYou Decrypted String!\n");
        printf("\nDecrypted string: %s\n", text);
        printf("\naddr %p | %p | %p", text, key2, key1);
        break;
    }

    case 1:
    {
        printf("\nCrypter ver0.1\n");
        printf("\nYou need enter or create two keys for security\nWrite they in safe place\nTHIS PROGRAM CONTAINS BUGS");
        printf("\nPlease enter a string:\t");
        std::cout << text;
        printf("\nPlease choose following options:\n");
        printf("1 = Encrypt the string.\n");
        printf("2 = Decrypt the string.\n");
        std::cout << selectedindex << std::endl;
        printf("Create or Provide Exist Key:\n");
        std::cout << key1 << std::endl;
        printf("Create or Provide Exist Second Key:\n");
        std::cout << key2;
        for (int i = 0; (i < 512 && text[i] != '\0'); i++)
            text[i] = text[i] - key1 + key2; // the key for encryption is 3 that is subtracted to ASCII value
        printf("\nYou Decrypted String!\n");
        printf("\nDecrypted string: %s\n", text);
        printf("\naddr %p | %p | %p", text, key2, key1);
        break;
    }

    default:
        MessageBox(NULL, TEXT("Wrong Crypter Version"), TEXT("Error"), MB_OK | MB_ICONERROR);
        break;
    }
}