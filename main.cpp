#include <iostream>
int dogSymbolNumber ( std::string dogCheckEmail ){
    int position = 0;

    for(int i = 0; i<= dogCheckEmail.length(); ++i){
        if(dogCheckEmail[i] == '@'){
            position = i;
            break;
        }
    }
  return (position);
}

bool checkDot( std::string emailForCheckDot){
    bool check = true;
    for (int i = 0; i < emailForCheckDot.length(); ++i){
        if( emailForCheckDot[i] =='.' && emailForCheckDot[i-1]=='.'){
            check = false;
        }
    }
    if(emailForCheckDot[0] == '.'){
        check = false;
    }
    if(emailForCheckDot[emailForCheckDot.length()]=='.'){
        check = false;
    }
    return(check);
}

bool checkSymbol(std::string emailForCheck){
    bool check = true;
    std::string simbolList = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&'*+-/=?^_`{|}~.";
    std::string contrEmail;
    for(int i =0; i<=emailForCheck.length(); i++) {
        for (int j = 0; j <= simbolList.length(); ++j) {
            if (simbolList[j] == emailForCheck[i]) {
                contrEmail += simbolList[j];
                break;
            }
        }
    }
    if (emailForCheck.find(contrEmail)==0){
    check = false;

    }

    return(check);
}
bool firstPart (std::string emailForSearch ){
    std::string firstPart;
    bool valid = true;
    int dog = dogSymbolNumber(emailForSearch);
    for(int i =0; i <dog; ++i ){
        firstPart += emailForSearch[i];
    }
   valid =  checkSymbol(firstPart) && checkDot(firstPart);
    if(firstPart.length()>63){
        valid = false;
    }
    return(valid);
}
bool secundPart (std::string emailForSearchSecund ) {
    std::string secundPart;
    bool valid = true;
    int dog = dogSymbolNumber(emailForSearchSecund);
    for (int i = dog + 1; i < emailForSearchSecund.length(); ++i) {
        secundPart += emailForSearchSecund[i];
    }
    valid = checkSymbol(secundPart) && checkDot(secundPart);
    if (secundPart.length()>62){
        valid = false;
    }
    return (valid);

}
    int main() {
        std::string email;
        std::cout << "Enter E-mail" << std::endl;
        std::cin >> email;

        bool valid = true;
        int dog = dogSymbolNumber(email);
        valid = firstPart(email)  && secundPart(email) && dog>0 ;
        if (valid) {
            std::cout << " Valid";
        } else {
            std::cout << " Invalid!";
        }
        return 0;
    }
