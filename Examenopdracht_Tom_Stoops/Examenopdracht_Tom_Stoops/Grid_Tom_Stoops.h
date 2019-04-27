#pragma once
class Grid
{
public:
	Grid(float xmin, float xmax, float ymin, float ymax, int xstep, int ystep);
	~Grid();

private:
	// Input check functies
	float checkStep(float step);
	bool checkRange(float min, float max);

	// Gridparameters
	int xstep;
	int ystep;
	float xmin;
	float xmax;
	float ymin;
	float ymax;
};

