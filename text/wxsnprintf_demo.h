#pragma once
#include <wx/wx.h>

namespace wxSprintfUsage
{
	void main()
	{
		// https://codeforwin.org/2015/05/list-of-all-format-specifiers-in-c-programming.html
		char msgChar[50];
		wxSnprintf(msgChar, 50, "I ate %d apples today", 2);

		wxPrintf("%s", msgChar);
	}
}
