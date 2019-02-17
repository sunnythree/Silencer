#pragma once

#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::shared_ptr;
using std::cout;
using std::endl;

namespace Silencer {

	class Log
	{
	public:
		enum LOG_LEVEL
		{
			Verbose,
			Debug,
			Warning,
			Error
		};
		static LOG_LEVEL min_log_level;
		static void v(string TAG, string content);
		static void d(string TAG, string content);
		static void w(string TAG, string content);
		static void e(string TAG, string content);

	private:
		static void print_out(string TAG, string content,LOG_LEVEL level);
	};
}
