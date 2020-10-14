#include "EspRobotControl/Control/Filter.hpp"

FilterBuLp2::FilterBuLp2()
{
  v[0]=0.0;
  v[1]=0.0;
}

float FilterBuLp2::step(float x) //class II 
		{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = (1.000000000000000000e+0 * x)
				 + (-1.00000000000000000000 * v[0])
				 + (-2.00000000000000000000 * v[1]);
			return 
				 (v[0] + v[2])
				+2 * v[1];
		}
