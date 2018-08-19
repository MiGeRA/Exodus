#ifndef __GENERICACCESSGROUP_H__
#define __GENERICACCESSGROUP_H__
#include "IGenericAccessGroup.h"
#include <string>
#include <list>

class GenericAccessGroup :public IGenericAccessGroup
{
public:
	// Constructors
	inline GenericAccessGroup(const std::wstring& name);
	inline ~GenericAccessGroup();

	// Interface version functions
	virtual unsigned int GetIGenericAccessGroupEntryVersion() const;
	virtual unsigned int GetIGenericAccessGroupVersion() const;

	// Type functions
	virtual GroupEntryType GetGroupEntryType() const;
	virtual bool IsGroup() const;

	// Parent functions
	virtual IGenericAccessGroup* GetParent() const;

	// Data context functions
	virtual const IGenericAccess::DataContext* GetDataContext() const;
	inline GenericAccessGroup* SetDataContext(const IGenericAccess::DataContext* dataContext);

	// Group info methods
	virtual Marshal::Ret<std::wstring> GetName() const;
	inline GenericAccessGroup* SetName(const std::wstring& name);
	virtual bool GetOpenByDefault() const;
	inline GenericAccessGroup* SetOpenByDefault(bool state);

	// Entry methods
	virtual unsigned int GetEntryCount() const;
	virtual Marshal::Ret<std::list<IGenericAccessGroupEntry*>> GetEntries() const;
	inline GenericAccessGroup* AddEntry(IGenericAccessGroupEntry* entry);
	inline GenericAccessGroup* RemoveEntry(IGenericAccessGroupEntry* entry);

protected:
	// Parent functions
	virtual void SetParent(IGenericAccessGroup* parent);

private:
	IGenericAccessGroup* _parent;
	const IGenericAccess::DataContext* _dataContext;
	std::wstring _name;
	bool _openByDefault;
	std::list<IGenericAccessGroupEntry*> _childEntries;
};

#include "GenericAccessGroup.inl"
#endif
