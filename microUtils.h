#include <string.h>

#ifndef MICORUTILS_H
#define MICORUTILS_H

#define delay(ms) HAL_Delay(ms)
typedef struct button button;
typedef struct seg7 seg7;
typedef struct seg28 seg28;

struct button{
    char pin;
    char gpio;
    int vari=0;

    button(char gpio,int pin){
        this.pin = pin+'0';
        char gpioPin[];
        char gpioType[];
        
        strcat(gpioType,'GPIO');
        strcat(gpioType,gpio)

        strcat(gpioPin,'GPIO_PIN_');
        strcat(gpioPin,this.pin);
    }

    int read(){
        if (HAL_GPIO_ReadPin(gpioType,gpioPin)==0){
            if(vari==0){
                vari =1;
                return 1;
            }
            else{
                vari = 0;
                return 0;
            }
        }
    }
};

struct seg7{
    char gpio;
    int pinArr[];
    int numArr[12]={0x3f8,0x180,0x368,0x3c8,0x198,0x2d8,0x2f8,0x380,0x3f8,0x398,0x4,0x0}; //0,1,2,3,4,5,6,7,8,9,dot,null
    int dis;

    seg7(char gpio,int pin){
        this.gpio = gpio;
        this.pinArr = pinArr;

        this.dis = pin - 4
        char gpioType[];

        strcat(gpioType,'GPIO');
        strcat(gpioType,this.gpio);

    }

    show(int number){
        HAL_GPIO_WritePin(gpioType,numArr[number]<<dis, GPIO_PIN_SET);
    }
}

struct seg28{
    char gpio;
    int pinArr[];
    int numArr[12]={0x3f8,0x180,0x368,0x3c8,0x198,0x2d8,0x2f8,0x380,0x3f8,0x398,0x4,0x0}; //0,1,2,3,4,5,6,7,8,9,dot,null
    int controlArr[4] = {0x4,0x8.0x10,0x20};
    int dis;

    seg7(char gpio,int pin){
        this.gpio = gpio;
        this.pinArr = pinArr;

        this.dis = pin - 4
        char gpioType[];

        strcat(gpioType,'GPIO');
        strcat(gpioType,this.gpio);

    }
    void show(int data[4]){
        for(int i=0;i<o;i++){
            HAL_GPIO_WritePin(gpioType,controlArr[i], GPIO_PIN_RESET);
            HAL_GPIO_WritePin(gpioType,data[i], GPIO_PIN_SET);
        }
    }
}


//0 = abcdef 
//1 = bc     
//2 = abdeg  
//3 = abcdg  
//4 = bcfg   
//5 = acdfg  
//6 = acdefg 
//7 = abc    
//8 = abcdefg
//9 = abcfg  
//dot = h
//0 = 
//1 = 
//2 = 
//3 = 
//4 = 
//5 = 
//6 = 
//7 = 
//8 = 
//9 = 
//null
//
//9 : 
//15 14 13 12  11 10    9 8  7 6 5 4  3 2| 1 0
//                      a b  c d e f  g h
//
//
//void setbutton(char buttonName[],char GPIO[6],int pinNumber){
//    char pin[] = pinNumber + '0';
//    char gpioPin[14];
//    strcat(gpioPin,"GPIO_PIN_SET");
//    strcat(gpioPin,pin);
//    #define buttonName HAL_GPIO_ReadPin(GPIO, gpioPin);
//}


#endif
