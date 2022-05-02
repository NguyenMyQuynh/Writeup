#include <iostream>
#include <cstring>

using namespace std;

string ciphertext = "arln_pra_dfgafcchsrb_l{ieeye_ea}";
string plaintext= "********************************";

int main()
{
    int count=2;
    for (int i=0;i<10;i++)
    {
        plaintext[count] = ciphertext[i];
        count+=3;
    }
    count=0;
    for (int i=0;i<11;i++)
    {
        plaintext[count] = ciphertext[i+10];
        count+=3;
    }
    count=1;
    for (int i=0;i<11;i++)
    {   
        plaintext[count] = ciphertext[i+10+11];
        count+=3;
    }
    cout<<(plaintext);
}
