#include "gray_effect_filter.h"
#include "filter_utils.h"

namespace cngram
{

FilterErrorCode GrayEffectFilter::Initialize()

{
	return ERROR_OK;
}

FilterErrorCode GrayEffectFilter::MakeEffect(
		const IplImage * input_image,
		IplImage * &output_image)
{
	output_image = cvCloneImage(input_image);
	for (int i = 0; i < output_image->height; i++)
	{
		for (int j = 0; j < output_image->width; j++)
		{
			CvScalar s = cvGet2D(output_image, i, j);
			CvScalar t = FilterUtils::Gray(s);
			cvSet2D(output_image, i, j, t);
		}
	}
	return ERROR_OK;
}

}

