#pragma once
#include "Struct.h"
#include <qstring.h>
#include <qobject.h>
class TypeKindParent
{
public:
	TypeKindParent();
	~TypeKindParent();
signals:
	void sendSig(TypeKinds);

protected:
	virtual void createBtn(QString,TypeKinds)=0;
};

