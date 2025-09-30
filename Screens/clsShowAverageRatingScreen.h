#pragma once
#include <iostream> 
#include"Screens/clsScreen.h"
#include"Libraries/clsInputValidate.h"
#include"Objects/clsMovie.h"
#include<iomanip>

using namespace std;

class clsShowAverageRatingScreen :protected clsScreen
{
public:
	static void ShowAverageRatingScreen()
	{
		_DrawScreenHeader("Show Average Rating");

		float AverageRating = clsMovie::GetAverageRating();

		if (AverageRating == 0)
		{
			cout << "\nThere is No Ratings Until Now..";
			return;
		}

		cout << "\n\nAverage Rating is: " << AverageRating << endl;

	}
};

