#pragma once


namespace Silencer {
#define TEMPLATE_CLASS_INITIALIZE(classname) \
template class classname<float>;\
template class classname<double>

}
