#include <iostream>

using namespace std;

int main() {
    int n, score=0, ball=0, input;
    bool first, second, third;
    cin>>n;
    while(n--) {
        cin>>input;
        if (input == 1){
            ball += 1;
            if (ball == 4){
                if (first) {
                    if (second) {
                        if (third){
                            score++;
                            third = false;
                        }
                        else third = true;
                    }
                    else second = true;
                }
                else first = true;
                
            }
        }
    }
}