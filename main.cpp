#include <iostream>
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
class Example : public olc::PixelGameEngine
{
public:
	class Square {
	public:
		float width = 2 + rand() % 6;
		float length = 22;
		float x = rand() % 246;
		float y = rand() % 220;
		float rcolor = rand() % 255;
		float gcolor = rand() % 255;
		float bcolor = rand() % 255;
		float speed = 70 + rand() % 20;
		float speedfast = 70 + rand() % 100;
	};
	Example()
	{
		
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		
		Clear(olc::Pixel(173,216,230));
		

		for (int i = 0; i < 100; i++) {
			FillRect(s[i].x, s[i].y, s[i].width, s[i].length, olc::Pixel(255, 255, 255));
			if (s[i].width >= 6) {
				s[i].y += fElapsedTime * s[i].speedfast;
			}
			else {
				s[i].y += fElapsedTime * s[i].speed;
			}
			
			if (s[i].y >= 250) {
				s[i].y = -20;
				s[i].x = rand() % 246;

			}
		}
			
		return true;
	}
	private:
		float y =1;
		float x = 20;
		Square s[100];
		

};

int main()
{
	srand(time(NULL));
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}
