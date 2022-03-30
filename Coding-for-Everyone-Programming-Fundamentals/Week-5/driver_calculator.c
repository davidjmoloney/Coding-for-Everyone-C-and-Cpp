/*
 * main.c
 *
 *  Created on: 26 Mar 2022
 *      Author: David Moloney
 * 
 *  Code shows the use of reference passing to functions and how to make structures
 *  two seperate functions have been made to take the two types of structure as input
 *  One function gives rough approximation for the price of a car
 *  The other gives a driving score for an individual
 *  This program may be a rough approximation of insurance brokers instant quotation software
 */


#include <stdint.h>
#include <stdio.h>

//Normal structure definition
struct CarInfo{
	int year;
	char model;
	float engine_size;
	int kilometres;
};


//Type def structure definition
typedef struct{
	int age;
	char gender;
	float years_no_claim;
}DriverInfo_t; 		//here we use _t to denote that this is a typedef and not enumeration




//Function Prototypes
float price_calc(struct CarInfo *pCar);
float driver_score(DriverInfo_t *pDriver);





int main(){

	//initialise of structure variables
	struct CarInfo VW;
	DriverInfo_t David;

	//Define properties of structure variables
	VW.year = 2012;
	VW.model = 'V';
	VW.engine_size = 1.59;
	VW.kilometres = 210000;

	David.age = 24;
	David.gender = 'M';
	David.years_no_claim = 5.5;


	float VW_price = price_calc(&VW);
	printf("Car price = %.2f\n", VW_price);

	float david_score = driver_score(&David);
	printf("David's driver score = %.2f\n", david_score);


	
}


//Function Definitions
float price_calc(struct CarInfo *pCar){
	return((pCar->engine_size*30000.0)*((pCar->year - 2000)/22.0)*((300000-pCar->kilometres)/300000.0)); //Returns rough approximations based on year, age and engine size of car
}

/*	Here we are using the "->" to dereference to the seperate data entries in the structure. 
 * 	Like using * to dereference pointer data but now the program will take into the account the affect having different datatypes in the structure
 */

float driver_score(DriverInfo_t *pDriver){
	float score = 50 + pDriver->age + (2*pDriver->years_no_claim);
	if(pDriver->gender == 'M'){
		return(score * 0.9);
	}
	else{
		return(score);
	}

}


