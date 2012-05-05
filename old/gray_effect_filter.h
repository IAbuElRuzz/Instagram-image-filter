#ifndef __GRAY_EFFECT_FILTER__
#define __GRAY_EFFECT_FILTER__
#include "effect_filter.h"

namespace cngram
{

class GrayEffectFilter : public BaseEffectFilter
{
public:
	GrayEffectFilter() : BaseEffectFilter("GRAY", "1.0") {}
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
};

}

#endif
