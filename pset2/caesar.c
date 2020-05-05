#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool check_digit(string s);
string convert_to_cipher(string s, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        bool k = check_digit(argv[1]);
        if (k == true)
        {
            int key = atoi(argv[1]);
            string plain_text = get_string("plaintext: ");
            string cipher_text = convert_to_cipher(plain_text, key);
            printf("ciphertext: %s\n", cipher_text);
            printf("0 \n");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }
}

bool check_digit(string s)
{
    bool digit = true;
    //string s = argv[1];
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            digit = false;
        }
    }
    if (digit == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

string convert_to_cipher(string s, int k)
{
    string cipher = s;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //check uppercase
        if (isalpha(s[i]) != 0 && isupper(s[i]) != 0)
        {
            char u = (((s[i] - 65) + k) % 26) + 65;
            //printf("%c", u);
            cipher[i] = u;
        }
        else if (isalpha(s[i]) != 0 && islower(s[i]) != 0)
        {
            char l = (((s[i] - 97) + k) % 26) + 97;
            //printf("%c", l);
            cipher[i] = l;
        }
        else
        {
            //printf("%c\n", s[i]);
            cipher[i] = s[i];
        }
    }
    return cipher;
}







