#pragma once

#include <wx/tokenzr.h>
#include <wx/string.h>
#include <wx/wxcrtvararg.h>

namespace StringTokenizerUsage
{
	void main()
	{
		wxStringTokenizer strToken("Cpp;Java;Python;Ruby", wxT(";"));
		while (strToken.HasMoreTokens())
		{
			const wxString token = strToken.GetNextToken();
			wxPrintf("%s\n", token);
		}
	}
}
