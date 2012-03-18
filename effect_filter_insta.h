#ifndef __EFFECT_FILTER_14__
#define __EFFECT_FILTER_14__
#include "effect_filter.h"
#include <highgui.h>

namespace cngram
{
// 01
class EffectFilter01 : public BaseEffectFilter
{
public:
	EffectFilter01();
	~EffectFilter01();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;
	static const char * kCircleImagePath0;
	static const char * kCircleImagePath1;
private:
	IplImage * image_border;
	IplImage * image_circle0;
	IplImage * image_circle1;
};

// 02
class EffectFilter02 : public BaseEffectFilter
{
public:
	EffectFilter02();
	~EffectFilter02();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath0;
	static const char * kBorderImagePath1;
	static const char * kCircleImagePath0;
	static const char * kCircleImagePath1;
private:
	IplImage * image_border0;
	IplImage * image_border1;
	IplImage * image_circle0;
	IplImage * image_circle1;
};

// 03
class EffectFilter03 : public BaseEffectFilter
{
public:
	EffectFilter03();
	~EffectFilter03();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;
	static const char * kCircleImagePath0;
	static const char * kCircleImagePath1;
private:
	IplImage * image_border;
	IplImage * image_circle0;
	IplImage * image_circle1;	
};

// 04
class EffectFilter04 : public BaseEffectFilter
{
public:
	EffectFilter04();
	~EffectFilter04();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;
	static const char * kGrainImagePath0;
	static const char * kGrainImagePath1;
	static const char * kCircleImagePath0;
	static const char * kCircleImagePath1;

private:
	IplImage * image_border;
	IplImage * image_grain0;
	IplImage * image_grain1;
	IplImage * image_circle0;
	IplImage * image_circle1;
};

// 05
class EffectFilter05 : public BaseEffectFilter
{
public:
	EffectFilter05();
	~EffectFilter05();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;
	static const char * kGrainImagePath;
	static const char * kCircleImagePath1;
	static const char * kCircleImagePath0;
private:
	IplImage * image_border;
	IplImage * image_grain;
	IplImage * image_circle0;
	IplImage * image_circle1;
};

// 06
class EffectFilter06 : public BaseEffectFilter
{
public:
	EffectFilter06();
	~EffectFilter06();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const char * kBorderImagePath;

private:
	IplImage * image_border;
};

// 07
class EffectFilter07 : public BaseEffectFilter
{
public:
	EffectFilter07();
	~EffectFilter07();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;
	static const char * kGrainImagePath;
	static const char * kCircleImagePath1;
	static const char * kCircleImagePath0;

private:
	IplImage * image_border;
	IplImage * image_grain;
	IplImage * image_circle0;
	IplImage * image_circle1;
};

// 08
class EffectFilter08 : public BaseEffectFilter
{
public:
	EffectFilter08();
	~EffectFilter08();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;
	static const char * kGrainImagePath;
	static const char * kCircleImagePath;
private:
	IplImage * image_border;
	IplImage * image_grain;
	IplImage * image_circle;
};

// 09
class EffectFilter09 : public BaseEffectFilter
{
public:
	EffectFilter09();
	~EffectFilter09();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;
	static const char * kGrainImagePath;
	static const char * kCircleImagePath0;
	static const char * kCircleImagePath1;

private:
	IplImage * image_border;
	IplImage * image_grain;
	IplImage * image_circle0;
	IplImage * image_circle1;
};

// 10
class EffectFilter10 : public BaseEffectFilter
{
public:
	EffectFilter10();
	~EffectFilter10();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const char * kBorderImagePath;
	static const char * kBackgroundImagePath;
	static const char * kCircleImagePath0;
	static const char * kCircleImagePath1;
	static const char * kGrainImagePath;
private:
	IplImage * image_border;
	IplImage * image_grain;
	IplImage * image_circle0;
	IplImage * image_circle1;
	IplImage * image_background;
};

// 11
class EffectFilter11 : public BaseEffectFilter
{
public:
	EffectFilter11();
	~EffectFilter11();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;

private:
	IplImage * image_border;
};

// 12
class EffectFilter12 : public BaseEffectFilter
{
public:
	EffectFilter12();
	~EffectFilter12();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;

public:
	IplImage * image_border;
};

// 13
class EffectFilter13 : public BaseEffectFilter
{
public:
	EffectFilter13();
	~EffectFilter13();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;
	static const char * kBackgroundImagePath;
private:
	IplImage * image_border;
	IplImage * image_background;
};

// 14
class EffectFilter14 : public BaseEffectFilter
{
public:
	EffectFilter14();
	~EffectFilter14();
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
	static const uint8_t kRGBMap[][256];
	static const char * kBorderImagePath;

private:
	IplImage * image_border;
};

}

#endif
