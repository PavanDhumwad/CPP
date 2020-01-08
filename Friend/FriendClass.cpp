#include<iostream>
class Rectangle
	{
		int L,B;

		public:
		Rectangle()
		{
			L=10;
			B=20;
		}

		friend class Square;        //Statement 1
	};

	class Square
	{
		int S;
		public:
		Square()
		{
			S=5;
		}

		void Display(Rectangle Rect)
		{
			std::cout<<"\n\n\tLength : "<<Rect.L;
			std::cout<<"\n\n\tBreadth : "<<Rect.B;
			std::cout<<"\n\n\tSide : "<<S<<std::endl;;
		}
	};

	int main()
	{
		Rectangle R;
		Square S;
		S.Display(R);  
        return 1;     //Statement 2
	}