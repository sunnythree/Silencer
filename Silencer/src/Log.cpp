#include "Log.hpp"

namespace Silencer {
	void Log::v(string TAG, string content)
	{
		print_out(TAG,content,Verbose);
	}

	void Log::d(string TAG, string content)
	{
		print_out(TAG, content, Debug);
	}

	void Log::w(string TAG, string content)
	{
		print_out(TAG, content, Warning);
	}

	void Log::e(string TAG, string content)
	{
		print_out(TAG, content, Error);
	}

	void Log::print_out(string TAG, string content,LOG_LEVEL level)
	{
		if (level >= min_log_level) {
			cout << TAG <<" "<< content << endl;
		}
	}

	Log::LOG_LEVEL Log::min_log_level = Log::Debug;
}
