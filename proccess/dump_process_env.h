#pragma once
#include <wx/utils.h>
#include <wx/wxcrtvararg.h>

namespace DumpProcessEnv
{
	void main()
	{
		wxEnvVariableHashMap environment;
		wxGetEnvMap(&environment);

		auto size = environment.size();
		for (auto it = environment.begin(); it != environment.end(); ++it)
		{
			wxPrintf("%s: %s\n", it->first, it->second);
		}
	}
}
