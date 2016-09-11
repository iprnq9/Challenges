#include <iostream>
#include "math.h"

using namespace std;

bool isPrimeNumber(int val){
    bool isPrime = true;
    for(int j=2; (j<=sqrt(val)) && isPrime; j+=2){
        if(!(val%j)){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int howMany, line, i;

int main() {
    cin >> howMany;
    while(howMany > 0){
        howMany--;
        cin >> line;
        cin >> i;
        //1 or less is not prime in this case
        if(i<=1){
            cout << line << " " << i << " NO" << endl;
        }
        //7 is smallest happy prime and won't be detected by this method
        else if(i == 7){
            cout << line << " " << i << " YES" << endl;
        }
        else{
            int num = i;
            bool possiblyHappy;
            if(isPrimeNumber(num)){
                do{
                    //get digits of number
                    int digits[5] = {0,0,0,0,0};
                    //int num = data[i][1];
                    int count = 4;
                    while(num > 9){
                        digits[count] = num%10;
                        num = num/10;
                        count--;
                    }
                    digits[count] = num;
                    //determine if number is happy
                    int sum = pow((digits[0]),2) + pow((digits[1]),2) + pow((digits[2]),2) + pow((digits[3]),2) + pow((digits[4]),2);
                    num = sum;
                    possiblyHappy = true;
                    if(sum == 1){
                        cout << line << " " << i << " YES" << endl;
                        possiblyHappy = false;
                    }
                    else if(sum < 7){
                        possiblyHappy = false;
                        cout << line << " " << i << " NO" << endl;
                    }
                }while(possiblyHappy);
            }
            else{
                cout << line << " " << i << " NO" << endl;
            }
        }
    }

    return 0;
}