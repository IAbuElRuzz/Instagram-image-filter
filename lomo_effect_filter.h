#ifndef __LOMO_EFFECT_FILTER__
#define __LOMO_EFFECT_FILTER__
#include "effect_filter.h"

namespace cngram
{

class LomoEffectFilter : public BaseEffectFilter
{
public:
	LomoEffectFilter() : BaseEffectFilter("LOMO", "1.0") {}
	FilterErrorCode Initialize();
	FilterErrorCode MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image);

protected:
};

}

#endif
