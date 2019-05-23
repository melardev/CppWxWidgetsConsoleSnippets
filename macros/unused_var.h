#pragma once
#include <wx/wx.h>

namespace WxUnusedUsage
{
	void main(int argc, char** argv)
	{
		int some;
		wxUnusedVar(some); // without this line I have a compiler warning stating unreferenced local variable
		// in other words that means the variable is not used
		wxPrintf("WxUnusedUsage snippet");
	}
}
