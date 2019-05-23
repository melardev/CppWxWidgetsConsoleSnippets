#pragma once
#include <wx/wxcrtvararg.h>

namespace WxStringConv
{
	void main()
	{
		wxString myString("Hola");
		const char* data = myString.mb_str(wxConvUTF8).data();

		wxPrintf(data);
	}
}
