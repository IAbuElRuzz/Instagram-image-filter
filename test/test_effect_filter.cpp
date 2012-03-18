#include "effect_filter.h"
#include "highgui.h"
using namespace cngram;
int main()
{
	IplImage * image = cvLoadImage("demo.png");
	for (int i = 0; i < 15; i ++)
	{
		IplImage * effect_image = NULL;
		BaseEffectFilter * effect_filter = EffectFilterFactory::GetEffectFilter(i);
		if (effect_filter == NULL)
		{
			printf("NULL\n");
		}
		else
		{
			printf("Name:%s Version:%s\n",
				effect_filter->name(),
				effect_filter->version());
		}

		FilterErrorCode ret = effect_filter->MakeEffect(image, effect_image);
		if (ret == ERROR_OK)
		{
			char save_file_name[1024];

			sprintf(save_file_name, "effect%.2d.jpg", i);
			cvSaveImage(save_file_name, effect_image);

			IplImage * logo_image = cvCreateImage(cvSize(64, 64), IPL_DEPTH_8U, 3);
			cvResize(effect_image, logo_image);
			sprintf(save_file_name, "logo%.2d.jpg", i);
			cvSaveImage(save_file_name, logo_image);
			cvReleaseImage(&logo_image);
		}
		else
		{
			printf("Error[%d]!\n", i);
		}


		cvReleaseImage(&effect_image);
	}
	cvReleaseImage(&image);
	return 0;
}
