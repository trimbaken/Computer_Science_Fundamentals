#include<stdio.h>
#include<float.h>
#include<math.h>
#include<stdlib.h>

typedef struct point_t
{
	int x;
	int y;
} Point;

float min(float a, float b)
{
	return (a<b)? a : b;
}

float dist(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float brut_force(Point p[], int n)
{
	float min = FLT_MAX;
	int i =0;
	int j =0;
	float d =0;

	for(i =0; i<n; i++)
	{
		for(j =i+1; j<n; j++)
		{
			d = dist(p[i], p[j]);
			if(d < min)
				min = d;
		}
	}
	return min;
}

// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float closest_strip(Point p[], int size, float d)
{
	int i =0;
	int j =0;
	float min = d;
	qsort(p, size, sizeof(Point), compareY);
	for(i =0; i< size; i++)
	{
		for(j = i+1; j<size && (p[j].y - p[i].y) < min; j++)
		{
			if(dist(p[i], p[j]) < min)
			{
				min = dist(p[i], p[j]);
			}
		}
	}
	return min;
}

float closest(Point p[], int n)
{
	int mid = 0;
	float dl = 0;
	float dr = 0;
	float d = 0;
	float temp_dist;
	int i = 0;
	int j = 0;

	Point strip[n];
	if(n <= 3)
	{
		return brut_force(p, n);
	}
	mid = n/2;
	dl = closest(p, mid);
	dr = closest(p + mid, n-mid);
	d = min(dl, dr);
	for(i =0; i< n; i++)
	{
		temp_dist = abs(p[i].x - p[mid].x);
		if(temp_dist > 0 && temp_dist < d)
		{
			strip[j] = p[i];
			j++;
		}
	}
	return min(d, closest_strip(strip, j, d));
}

int main(void)
{
	Point point[6] = {{2, 3}, {3, 4}, {5, 1}, {12, 10}, {12, 30}, {40, 50}};
	printf("\n Distance of closest pair is = %f\n", closest(point, 6));
	printf("\nProgram to get closest pair of points\n");
	return 0;
}
