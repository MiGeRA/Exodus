//----------------------------------------------------------------------------------------------------------------------
// Enumerations
//----------------------------------------------------------------------------------------------------------------------
enum class IMenuItem::Type
{
	Segment,
	SubMenu,
	SelectableOption
};

//----------------------------------------------------------------------------------------------------------------------
// Interface version functions
//----------------------------------------------------------------------------------------------------------------------
unsigned int IMenuItem::ThisIMenuItemVersion()
{
	return 1;
}
