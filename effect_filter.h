#ifndef __EFFECT_FILTER__
#define __EFFECT_FILTER__
#include <cv.h>

namespace cngram
{

enum FilterErrorCode
{
	ERROR_OK = 0,
	ERROR_INVALID_IMAGE_SIEZ = 1,
	ERROR_LOAD_FILTER = 2,
	ERROR_OTHER
};

// Filter Base
class BaseEffectFilter
{
public:
	BaseEffectFilter();

	BaseEffectFilter(const char * name, const char * version);

	virtual FilterErrorCode Initialize() = 0;
	virtual FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image) = 0;

	const char * name() { return _name; }
	const char * version() { return _version; }

protected:
	const char * const _name;
	const char * const _version;
};

class EffectFilterNormal : public BaseEffectFilter
{
public:
	EffectFilterNormal() : BaseEffectFilter("Normal", "1.0") {}
	FilterErrorCode Initialize()
	{
		return ERROR_OK;
	}
	FilterErrorCode MakeEffect(
		const IplImage * input_image, IplImage * &output_image)
	{
		output_image = cvCloneImage(input_image);
		return ERROR_OK;
	}
};

// Factory
class EffectFilterFactory
{
private:
	static BaseEffectFilter * filter[1024];

public:
	static BaseEffectFilter * GetEffectFilter(int32_t filter_type);
	static void Init();
};

}

#endif
