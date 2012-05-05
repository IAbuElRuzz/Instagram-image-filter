#include "effect_filter.h"
#include "lomo_effect_filter.h"
#include "gray_effect_filter.h"
#include "effect_filter_insta.h"
namespace cngram
{
BaseEffectFilter::BaseEffectFilter() : _name(NULL), _version(NULL) {}

BaseEffectFilter::BaseEffectFilter(const char * name, const char * version):
	_name(name), _version(version) {}

void EffectFilterFactory::Init()
{
	memset(filter, 0, sizeof(filter));
	filter[0] = new EffectFilterNormal();
	filter[1] = new EffectFilter01();
	filter[2] = new EffectFilter02();
	filter[3] = new EffectFilter03();
	filter[4] = new EffectFilter04();
	filter[5] = new EffectFilter05();
	filter[6] = new EffectFilter06();
	filter[7] = new EffectFilter07();
	filter[8] = new EffectFilter08();
	filter[9] = new EffectFilter09();
	filter[0] = new EffectFilter10();
	filter[11] = new EffectFilter11();
	filter[12] = new EffectFilter12();
	filter[13] = new EffectFilter13();
	filter[14] = new EffectFilter14();
}

BaseEffectFilter * EffectFilterFactory::GetEffectFilter(int32_t type)
{
	if (type >= 0 && type < 20)
	{
		return filter[type];
	}
	return NULL;
}
BaseEffectFilter * EffectFilterFactory::filter[1024] = {NULL};

}

