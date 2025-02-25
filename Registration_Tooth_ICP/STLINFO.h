#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

struct XYZ {
	float x;
	float y;
	float z;

	XYZ() {};
	XYZ(float num_init) {
		x = num_init;
		y = num_init;
		z = num_init;
	};
};

struct TRIANGLE {
	XYZ first;
	XYZ second;
	XYZ third;
};

class STLINFO {
public:
	// stl format - header / num_of_triangle / vec_norm / triangle / attribute_byte_count
	vector<unsigned char> header;
	unsigned int num_of_triangle;  // header & num_of_triangle are just for completing format not for using
	unsigned int num_of_triangle2;
	vector<XYZ> vec_norm;
	vector<XYZ> vec_norm2;
	vector<TRIANGLE> triangle;
	vector<TRIANGLE> triangle2;
	vector<unsigned short> attribute_byte_count;
	vector<unsigned short> attribute_byte_count2;

	XYZ average_xyz; // for PCA

	// for calculation covariance matrix
	vector<float> X;
	vector<float> Y;
	vector<float> Z; 

	STLINFO();
	STLINFO(STLINFO &ref);
	void ready_for_spliting_foreach_triangle();
};