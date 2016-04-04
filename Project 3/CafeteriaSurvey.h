
// Byron Burdette
// COP2535.0M1



/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                            CLASS SPECIFICATION FILE FOR THE CLASS "CafeteriaSurvey"
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/





/**********************************************                PREPROCESSOR DIRECTIVES            **************************************************/
#pragma once                                                        //   include guard ensures this file is included, but only once

#include<iostream>                                                  //   includes the library for standard I/O stream objects
#include<fstream>                                                   //   includes the library for file stream objects
#include<string>                                                    //   includes the library for string types
#include<iomanip>                                                   //   includes the library for I/O manipulation
/*********************************************************************************************************************************************************/


using namespace std;                                                //   lifts all entities in the standard namespace into the current global namespace




class CafeteriaSurvey                                                //   begins the class declaration
{
private:
   ifstream* inFile;                                                 //   declares a pointer "inFile" to an ifstream object. We'll use this to access the input file later
   int* size;                                                        //   declares a pointer "size" to an int. This represents the number of different food items in the survey and will be used to make arrays as well as in "for" loop conditions
   string* food;                                                     //   declares a pointer "food" to a string. Later on, this will point to a string[] holding the names of the different food items in the survey

/*   declare a pointer "survey" to a pointer to an int. Later on, survey will point to a dynamically allocated array of int pointers (one pointer for each food item) which will themselves
   point to dynamically allocated int array of 2 elements. This creates a dynamically allocated 2d array which we will use to store the number of likes and dislike for each menu item
   (am I even saying this right?)   */
   int** survey;

   int* index;                                                      //   declares a pointer "index" to an int. We're just going to use this as the index for our "for" loops
   string* nextLine;                                                //   declares a pointer "nextLine" to a string. We'll use this as temporary storage for each line read from the input file using getline()
   string* grub;                                                    //   declares a pointer "grub" to a string. We'll use this to keep track of which menu item we're tallying results for


public:
   CafeteriaSurvey();                                               //   prototype for the constructor. We'll use this to open the input file and dynamically allocate all the memory we need
   void description();                                              //   prototype for function that displays the purpose of the program for the user
   void tallySurvey();                                              //   prototype for function that reads the input file and tallys up the results of the survey
   void output();                                                   //   prototype for function that displays the results of the survey in a table
   ~CafeteriaSurvey();                                              //   prototype for the destructor. We'll use this to free up all the memory we allocated in the constructor
};                                                                  //   end of the class declaration

/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                            THIS MARKS THE END OF THE CLASS SPECIFICATION FILE
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/