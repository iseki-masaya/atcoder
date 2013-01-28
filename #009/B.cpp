#include <iostream>
#include <vector>
int order[10];
 
int getNumber(int num){
    int realNum = 0;
    while(true){
        if(num == order[realNum])
            break;
        realNum++;
    }
    return realNum;
}
 
int main(int argc, const char * argv[])
{
    for(int i=0;i<10;i++){
        std::cin >> order[i];
    }
    int num;
    std::cin >> num;
    std::vector<std::string> list(num);
    for(int i=0;i<num;i++){
        std::cin >> list[i];
    }
    
    
    std::vector<std::string> sortedList(num);
    for(int i=0;i<num;i++){
        //search max length number
        int maxLength = 0;
        int maxValueKey;
        for(int j=0;j<num;j++){
            if(list[j].length()>maxLength){
                maxLength = (int) list[j].length();
                maxValueKey = j;
            }
            else if (list[j].length() == maxLength && list[j] != ""){
                bool isJudged = true;
                int checkKey = 0;
                while(isJudged){
                    int currentNum =  list[j][checkKey] - '0';
                    int pastNum = list[maxValueKey][checkKey] - '0';
                    if(getNumber(currentNum)>getNumber(pastNum)){
                        maxValueKey = j;
                        isJudged = false;
                    }
                    else if (list[j] == list[maxValueKey]){
                        isJudged = false;
                    }
                    else if(currentNum==pastNum){
                        checkKey++;
                    }
                    else{
                        isJudged = false;
                    }
                }
            }
        }
        sortedList[num-i-1] = list[maxValueKey];
        list[maxValueKey] = "";
    }
 
    for (int i=0; i<num; i++) {
        std::cout << sortedList[i] << std::endl;
    }    
}