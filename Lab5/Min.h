#pragma once

template <typename TMin>
inline TMin const& Min(TMin const& a, TMin const& b)
{
	return a > b ? b : a;
}