#pragma once

namespace Silencer {
	class Shape
	{
	public:
		Shape();
		~Shape();
		int GetAllSize();
		int Get1DSize();
		int Get2DSize();
		int Get3DSize();
		void set_firth_dim(int num);
		int get_firth_dim();
		void set_second_dim(int num);
		int get_second_dim();
		void set_third_dim(int num);
		int get_third_dim();
		void set_forth_dim(int num);
		int get_forth_dim();
		void set_dims(int num);
		int get_dims();

	private:
		int firth_dim;
		int second_dim;
		int third_dim;
		int forth_dim;
		int dims;
	};
}
