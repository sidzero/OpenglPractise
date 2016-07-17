//#include<iostream>
//#include <fstream>
//#include<conio.h>
//#include<cctype>
//
//bool isSorted(const int *ar, int size);
//bool isUnique(const int *ar, int size);
//int findChar(const char *s, char ch);
//
//void myToUpperCase(const char *source, char *dest);
//int main(int argc, char** argv)
//
//{
//	int a[] = {1,1,3,4,22};
//
//
//	char c[10] = "abbcb";
//	char d[20];
//
//
//	myToUpperCase(c,d);
//	
//	
//	getch();
//	return 1;
//};
//
//bool isSorted(const int *ar, int size)
//{
//	int currentValue=*ar;//holds value of current pointer 
//	for (int i = 1; i < size; i++)
//	{
//		ar++;//shift pointer to next block
//		
//		if (currentValue>*(ar))
//		{
//		
//			return false;//exit if not ascending
//		}
//		currentValue = *ar;
//		
//    }
//
//	return true;
//};
//
//bool isUnique(const int *ar, int size)
//{
//	int currentValue;
//
//	//Checks chosen charater with  all other charater
//	for (int i = 0; i < size; i++)
//	{
//		currentValue=*ar;//holds value of current pointer 
//		for (int j = 1; j < size; j++)
//		{
//		
//			if (currentValue==*(ar+j))
//			{
//				return false;
//			}
//
//		}
//		ar++;//shift pointer to next block
//
//	}
//
//
//	return true;
//}
//
//int findChar(const char *s, char ch)
//{
//	int currentIndex = 0;//holds index
//	while (*(s)!='\0')//loop till end of string reaches
//	{
//		
//		if (*(s)==ch)
//		{
//			return currentIndex;
//		}
//		s++;//shift pointer to next block
//		currentIndex++;
//	}
//	return -1;
//}
//
//void myToUpperCase(const char *source, char *dest)
//{
//
//	while (*(source) != '\0')
//	{
//
//		*dest = toupper(*source);
//		std::cout <<*source << " "<<*dest << "\n";
//
//		dest++;     //shift pointer to next block
//		source++;	//shift pointer to next block
//	}
//	
//	*dest = '\0';//end of string 
//	
//
//}