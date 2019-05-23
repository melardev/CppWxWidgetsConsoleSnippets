#pragma once
#include <wx/wx.h>

// Used to reduce compiler warnings
namespace WxUnusedMacroUsage
{
	int main(int WXUNUSED(argc), char** WXUNUSED(argv))
	{
		// WXUNUSED is used for function/method arguments
		wxPrintf("WXUNUSED snippet");
		return 0;
	}
}
