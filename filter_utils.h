#ifndef __FILTER_UTILS__
#define __FILTER_UTILS__
#include "cv.h"

namespace cngram
{
namespace FilterUtils
{
inline CvScalar Gray(CvScalar s)
{
	CvScalar t;
	t.val[0] = t.val[1] = t.val[2] = 
		s.val[0] * 0.3 + s.val[1] * 0.59 + s.val[2] * 0.11;
	return t;
}

// 变暗
inline CvScalar Darken(CvScalar a, CvScalar b, double rate = 1)
{
	CvScalar c;
	for (int i = 0; i < 3; i++)
	{
		if (b.val[i] < a.val[i])
		{
			c.val[i] = b.val[i];
		}
		else
		{
			c.val[i] = a.val[i];
		}
		c.val[i] = c.val[i] * rate + a.val[i] * (1 - rate);
	}
	return c;
}

// 变暗
inline CvScalar Lighten(CvScalar a, CvScalar b, double rate = 1)
{
	CvScalar c;
	for (int i = 0; i < 3; i++)
	{
		if (b.val[i] > a.val[i])
		{
			c.val[i] = b.val[i];
		}
		else
		{
			c.val[i] = a.val[i];
		}
		c.val[i] = c.val[i] * rate + a.val[i] * (1 - rate);
	}
	return c;
}

// 叠加
inline CvScalar Overlay(CvScalar a, CvScalar b, double rate = 1, int channel = 7)
{
	CvScalar c;
	for (int i = 0; i < 3; i++)
	{
		if (channel & (1 << i))
		{
			if (a.val[i] <= 128) c.val[i] = 2 * a.val[i] * b.val[i] / 255;
			else c.val[i] = 255 - 2 * (255 - a.val[i]) * (255 - b.val[i]) / 255;
			c.val[i] = c.val[i] * rate + a.val[i] * (1 - rate);
			if (c.val[i] < 0) c.val[i] = 0;
			if (c.val[i] > 255) c.val[i] = 255;
		}
		else
		{
			c.val[i] = a.val[i];
		}
	}
	return c;
}

// 正片叠底
inline CvScalar Multiply(CvScalar a, CvScalar b, double rate = 1)
{
	CvScalar c;
	for (int i = 0; i < 3; i++)
	{
		c.val[i] = a.val[i] * b.val[i] / 255;
		c.val[i] = c.val[i] * rate + a.val[i] * (1 - rate);
	}
	return c;
}

// 滤色
inline CvScalar Screen(CvScalar a, CvScalar b, double rate = 1)
{
	CvScalar c;
	for (int i = 0; i < 3; i++)
	{
		c.val[i] = 255 - (255 - a.val[i]) * (255 - b.val[i]) / 255;
		c.val[i] = c.val[i] * rate + a.val[i] * (1 - rate);
	}
	return c;
}

// 颜色减淡
inline CvScalar ColorDodge(CvScalar a, CvScalar b, double rate = 1)
{
	CvScalar c;
	for (int i = 0; i < 3; i++)
	{
		if (b.val[i] == 255)
		{
			c.val[i] = 255;
		}
		else
		{
			c.val[i] = 255 * a.val[i] / (255 - b.val[i]);
			if (c.val[i] > 255)
			{
				c.val[i] = 255;
			}
		}
		c.val[i] = c.val[i] * rate + a.val[i] * (1 - rate);
	}
	return c;
}

// 线性减淡
inline CvScalar LinearDodge(CvScalar a, CvScalar b, double rate = 1)
{
	CvScalar c;
	for (int i = 0; i < 3; i++)
	{
		c.val[i] = a.val[i] + b.val[i];
		c.val[i] = c.val[i] * rate + a.val[i] * (1 - rate);
		if (c.val[i] > 255) c.val[i] = 255;
	}
	return c;
}

}
}

#endif
