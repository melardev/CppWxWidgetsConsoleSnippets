#pragma once
#include <wx/wx.h>
#include <wx/except.h>

namespace TryCatchSnippet
{
	void main()
	{
		wxTRY
		{
			throw "I give up, sorry, I walk alone now";
		}
		wxCATCH_ALL(wxPrintf("Nop, you stay with me :)\n"); );
	}
}
