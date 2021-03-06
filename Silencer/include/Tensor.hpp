#pragma once
#include <iostream>
#include <memory>

using std::shared_ptr;
namespace Silencer {
	template<typename DType>
	class Tensor
	{
	public:
		Tensor();
		~Tensor();

	private:
		shared_ptr<DType> data;
	};

}
