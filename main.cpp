#include <iostream>
#include <vector>
#include <string>
#include <locale>



#ifdef ZAD_4
#if !(defined(POL) || defined(ENG))
#error nie zdefiniowano jezyka
#endif

#if defined(POL)
#define MSG1 "podaj liczbe naturalna (0 konczy):"
#define MSG2 "maksymalna suma cyfr to: "
#define MSG3 " dla "
#elif defined(ENG)
#define MSG1 "enter a natural number (0 if done):"
#define MSG2 "Max sum of digits was "
#define MSG3 " for "
#endif

int main(){

    int aktNum,maxSum,resultNumber = 0;

    do{
        std::cout<<MSG1;
        std::cin>>aktNum;
        std::cout<<std::endl;

        int testNumber = aktNum;
        int aktSum = 0;
        do{
            aktSum += testNumber%10;
            testNumber /= 10;

        }while(testNumber != 0);

        if(maxSum <= aktSum){
            maxSum = aktSum;
            resultNumber = aktNum;
        }

    }while(aktNum != 0);

    std::cout << MSG2 << maxSum << MSG3 << resultNumber << std::endl;

    return 0;

}

#elif defined(ZAD_3)
int main(){

    int a,b,c;
    int maxNum;
    std::cin>>a>>b>>c;
    if(a > b)
        maxNum = a;
    if(maxNum < c)
        maxNum = c;


    for(int i = maxNum; i >= 0; i--){

        std::cout << (i>=a?' ':'*');
        std::cout << (i>=b?' ':'*');
        std::cout << (i>=c?' ':'*');

        std::cout<<std::endl;

    }


    return 0;

}

#elif defined(ZAD_2)
int main(){

#if !(defined(GETMAX) || defined(GETMIN))
#error brakArgumentu
#endif

    int finalNumber = 0;
    std::vector<int> nums;
    std::string aktNum = "";
    std::locale loc;
    while(std::toupper(aktNum, loc) != "STOP"){
        std::cin >> aktNum;
        try {
            int aktInt = std::stoi(aktNum);
            nums.push_back(aktInt);
        } catch( std::invalid_argument e1 ) {
            std::cout << "zmienna nie zostala zapisana" << std::endl;
        }
    }

    finalNumber = nums[0];


    #if defined(GETMAX)

    for(int num: nums){

        if(num>finalNumber){
            aktNum = finalNumber;
        }

    }

    std::cout << finalNumber;

    #elif defined(GETMIN)
    for(int num: nums){

        if(num<finalNumber){
            aktNum = num;
        }

    }

    std::cout << finalNumber;
    #endif

    return 0;
}

#elif defined(ZAD_1)
int main() {

    double wzrost;
    double waga;
    double bmi;

    std::cout << "podaj wzrost: ";
    std::cin >> wzrost;
    std::cout << std::endl;
    std::cout << "podaj wage: ";
    std::cin >> waga;
    std::cout << std::endl;

    bmi = waga/(wzrost*wzrost);

    std::cout << bmi << std::endl;

    return 0;
}

#endif