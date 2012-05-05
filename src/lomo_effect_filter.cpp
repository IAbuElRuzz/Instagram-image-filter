#include "lomo_effect_filter.h"

namespace cngram
{

FilterErrorCode LomoEffectFilter::Initialize()
{
	return ERROR_OK;
}

FilterErrorCode LomoEffectFilter::MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image)
{
	output_image = cvCloneImage(input_image);
	return ERROR_OK;
}

}

