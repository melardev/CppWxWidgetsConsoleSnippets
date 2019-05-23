#pragma once
#include <wx/string.h>
#include <wx/wxcrt.h>
#include <wx/wxcrtvararg.h>

namespace ToUpperToLower
{
	void main()
	{
		wxUniChar a = wxToupper('a');
		wxPrintf("%c\n\n", a);

		const wxString usernameUpper = wxString("Melardev").Upper();
		wxPrintf("%s\n", usernameUpper);

		wxUniChar b = wxTolower('B');
		wxPrintf("%c\n\n", b);

		const wxString wxWidgets("wxWidgets");
		for (int i = 0; i < wxWidgets.size(); i++)
		{
			wxPrintf("%c", wxToupper(wxWidgets.at(i)));
		}
		wxPrintf("\n\n");
	}
}
