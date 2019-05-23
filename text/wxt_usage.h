#pragma once
#include <wx/log.h>

namespace wxTUsage
{
	void main()
	{
		// wxT is intended to provide a wide string(unicode) or ANSI
		// depending on compilation, if compiler supports Unicode
		// then wxT("") will return a wide string that the compiler knows how to handle
		// If compiler does not support Unicode, then the SAME code, will still work, why?
		// because wxT will return in that case, an ANSI text, basically, wxT is recognizing
		// if the compiler supports or no Unicode, if it does, it returns something,
		// if does not it returns other thing, in both cases, the returned type is compatible.
		wxLogError(wxT("wxT Usage"));
	}
}
